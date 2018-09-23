#include "BuddySystemAllocator.h"
#include "ScopeLock.h"

u32 BuddySystemAllocator::getTierNumForSize(u32 size)
{
    return Math::logKnownPowOf2(totalSize / size);
}

u32 BuddySystemAllocator::getSizeForTierNum(u32 tierNum)
{
    return totalSize >> tierNum;
}

void BuddySystemAllocator::checkForMerges(u32 tierNum)
{
    Block* header = freeListTiers[tierNum];
    u32 size = getSizeForTierNum(tierNum);
    Block* buddy = getBuddyAddress(header, size);

    Block* prevIter = header;
    for (Block* iter = header->next; iter != nullptr; iter = iter->next)
    {
        if (iter == buddy)
        {
            ScopeLock lock(tierLocks[tierNum - 1]);
            prevIter->next = iter->next;
            freeListTiers[tierNum] = header->next;
            header->next = freeListTiers[tierNum - 1];
            freeListTiers[tierNum - 1] = header;
            return checkForMerges(tierNum - 1);
        }
        prevIter = iter;
    }
}

void BuddySystemAllocator::split(u32 tierNum)
{
    if (freeListTiers[tierNum] == nullptr)
    {
        split(tierNum - 1);
    }
    Block* header = freeListTiers[tierNum];
    freeListTiers[tierNum] = header->next;
    u32 resultingSize = getSizeForTierNum(tierNum + 1);
    Block* buddy = getBuddyAddress(header, resultingSize);
    header->next = buddy;

    ScopeLock lock(tierNum + 1);
    buddy->next = freeListTiers[tierNum + 1];
    freeListTiers[tierNum + 1] = header;
}

Block* BuddySystemAllocator::getBuddyAddress(Block* firstAddress, u32 size)
{
    u64 intAddress = (u64)firstAddress - (u64)allotted;
    u64 buddyIntAddress = intAddress ^ size;
    return (Block*)(buddyIntAddress + (u64)allotted);
}

void* Allocator::inner_allocate(u32 numBytes, u32 alignment)
{
    numBytes = Math::nextPowerOf2(numBytes + sizeof(Block) - 1);
    numBytesAllocated += numBytes;
    u32 tierNum = getTierNumForSize(numBytes);
    Block* header;
    if (freeListTiers[tierNum] == nullptr)
    {
        split(tierNum - 1);
    }

    ScopeLock lock(tierLocks[tierNum]);
    Block* header = freeListTiers[tierNum];
    freeListTiers[tierNum] = header->next;
    header->tierNum = tierNum;

    return (void*)header + sizeof(Block);
}

void Allocator::inner_free(void* mem, u32 alignment)
{
    Block* header = (Block*)(mem - sizeof(Block));
    numBytesAllocated -= getSizeForTierNum(header->tierNum);
    u32 tierNum = header->tierNum;

    ScopeLock lock(tierLocks[tierNum]);
    header->next = freeListTiers[tierNum];
    freeListTiers[tierNum] = header;
    checkForMerges(tierNum);
}

void Allocator::inner_reallocate(void* orig, u32 newNumBytes, u32 alignment)
{
    Block* header = (Block*)(orig - sizeof(Block));
    u32 currentAllocatedSize = getSizeForTierNum(header->tierNum);
    if (currentAllocatedSize >= newNumBytes)
    {
        return orig;
    }

    if (newNumBytes <= (currentAllocatedSize << 1))
    {
        Block* buddy = getBuddyAddress(header, currentAllocatedSize);
        if (buddy > orig)
        {
            ScopeLock lock(tierLocks[header->tierNum]);
            Block* prevIter = freeListTiers[header->tierNum];
            if (prevIter == buddy)
            {
                freeListTiers[header->tierNum] = prevIter->next;
                --header->tierNum;
                numBytesAllocated += currentAllocatedSize;
                return orig;
            }
            if (prevIter != null)
            {
                for (Block* iter = prevIter->next; iter != null; iter = iter->next)
                {
                    if (iter == buddy)
                    {
                        prevIter->next = iter->next;
                        --header->tierNum;
                        numBytesAllocated += currentAllocatedSize;
                        return orig;
                    }
                    prevIter = iter;
                }
            }
        }

        void* newMem = inner_allocate(newNumBytes, alignment);
        memcpy(newMem, orig, currentAllocatedSize);
        inner_free(orig);
        return newMem;
    }
}

BuddySystemAllocator::BuddySystemAllocator(Allocator& parent, u32 memSize, u32 minBlockSize)
{
    this.parent = &parent;
    totalSize = Math::nextPowerOf2(memSize - 1);
    allotted = parent->allocate<u8>(totalSize);

    minBlockSize = Math::nextPowerOf2(minBlockSize - 1);
    numTiers = Math::logKnownPowOf2(totalSize / minBlockSize) + 1;
    freeListTiers = parent->allocate<Block*>(numTiers);
    tierLocks = parent->allocate<Mutex>(numTiers);
}

BuddySystemAllocator::BuddySystemAllocator(u32 memSize, u32 minBlockSize)
{
    this.parent = getPrimaryInstance();
    totalSize = Math::nextPowerOf2(memSize - 1);
    allotted = parent->allocate<u8>(totalSize);

    minBlockSize = Math::nextPowerOf2(minBlockSize - 1);
    numTiers = Math::logKnownPowOf2(totalSize / minBlockSize) + 1;
    freeListTiers = parent->allocate<Block*>(numTiers);
    tierLocks = parent->allocate<Mutex>(numTiers);
}

BuddySystemAllocator::~BuddySystemAllocator()
{
    parent.free(allotted);
    parent.free(freeListTiers);
}

BuddySystemAllocator::BuddySystemAllocator(BuddySystemAllocator&& other)
{
    parent = other.parent;
    allotted = other.allotted;
    freeListTiers = other.freeListTiers;
    tierLocks = other.tierLocks;
    totalSize = other.totalSize;
    numTiers = other.numTiers;
    numAllocations = other.numAllocations;
    numBytesAllocated = other.numBytesAllocated;

    other.parent = nullptr;
    other.allotted = nullptr;
    other.freeListTiers = nullptr;
    other.tierLocks = nullptr;
    other.totalSize = 0;
    other.numTiers = 0;
    other.numAllocations = 0;
    other.numBytesAllocated = 0;
}
