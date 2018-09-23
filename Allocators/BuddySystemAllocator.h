#include "Allocator.h"
#include "Mutex.h"

class BuddySystemAllocator : public Allocator
{
private:

    union Block
    {
        u32 tierNum;
        Block* next;
    };

    Block** freeListTiers;
    Mutex* tierLocks;
    u32 numTiers;

    Allocator* parent;

private:

    u32 getTierNumForSize(u32 size);
    u32 getSizeForTierNum(u32 tierNum);
    Block* getBuddyAddress(Block* firstAddress, u32 size);
    void checkForMerges(u32 tierNum);
    void split(u32 tierNum);


protected:

    virtual void* inner_allocate(u32 numBytes, u32 alignment) override;
    virtual void inner_free(void* mem) override;
    virtual void* inner_reallocate(void* orig, u32 newNumBytes, u32 alignment) override;

public:

    BuddySystemAllocator(Allocator& parent, u32 memSize, u32 minBlockSize);
    BuddySystemAllocator(u32 memSize, u32 minBlockSize);
    virtual ~BuddySystemAllocator();
    BuddySystemAllocator(BuddySystemAllocator&& other);

    BuddySystemAllocator(const BuddySystemAllocator& copy) = delete;
    BuddySystemAllocator& operator=(const BuddySystemAllocator& copy) = delete;

}
