#include "BitPacker.h"
#include "Allocator.h"
#include "Math.h"

BitPacker::BitPacker(u32 buffSize, u32* buff)
: Array(0)
{
    capacity = buffSize;
    size = buffSize;
    readIndex = 0;
    if (buff)
    {
        data = buff;
    }
    else
    {
        buffer = Allocator::allocate<u32>(size);
        size = 0;
    }
}

BitPacker::BitPacker(const BitPacker& other)
{
    copy(other);
}

BitPacker& BitPacker::operator=(const BitPacker& other)
{
    dispose();
    copy(other);
    return *this;
}

BitPacker::BitPacker(BitPacker&& other)
{
    move(other);
}

void BitPacker::writeBits(u32 bits, u32 numBits)
{
    Assert(numBits <= 32);
    Assert(bits < (1 << numBits));
    scratch <<= numBits;
    scratch |= bits;
    scratchBits += numBits;
    if (scratchBits >= 32)
    {
        checkResize();
        scratchBits -= 32;
        data[size++] = (scratch >> scratchBits) & 0xFFFFFFFF;
        scratch &= (1 << scratchBits) - 1;
    }
}

u32 BitPacker::readBits(u32 numBits)
{
    Assert(numBits <= numBits);
    if (scratchBits < numBits)
    {
        scratch <<= 32;
        scratch |= data[readIndex++];
        scratchBits += 32;
    }
    scratchBits -= numBits;
    u32 bits = scratch >> scratchBits;
    scratch &= (1 << scratchBits) - 1;
    bits &= (1 << numBits) - 1;
    return bits;
}


void BitPacker::writeInt(i32 val, i32 min, i32 max)
{
    Assert(min <= val && val < max);
    u32 range = max - min;
    u32 relativeVal = val - min;
    u32 bitsNeeded = Math::logKnownPowOf2(Math::nextPowerOf2(range - 1));
    writeBits(relativeVal, bitsNeeded);
}

i32 BitPacker::readInt(i32 min, i32 max)
{
    Assert(min < max);
    u32 range = max - min;
    u32 bitsNeeded = Math::logKnownPowOf2(Math::nextPowerOf2(range - 1));
    i32 ret = readBits(bitsNeeded) + min;
    Assert(min <= ret && ret < max);
    return ret;
}


void BitPacker::writeFloat(f32 val, f32 min, f32 max, f32 planck)
{
    Assert(min <= val && val <= max);
    f32 numPlancks = (max - min) / planck;
    u32 valPlanck = Math::round((val - min) / planck);
    u32 bitsNeeded = Math::ceil(Math::log2(numPlancks));
    writeBits(valPlanck, bitsNeeded);
}

f32 BitPacker::readFloat(f32 min, f32 max, f32 planck)
{
    Assert(min < max);
    f32 numPlancks = (max - min) / planck;
    u32 bitsNeeded = Math::ceil(Math::log2(numPlancks));
    u32 bits = readBits(bitsNeeded);
    f32 ret = (bits * planck) + min;
    Assert(min <= ret && ret <= max);
    return ret;
}

void BitPacker::flush()
{
    Assert(scratchBits <= 32);
    ensureCapacity(++size, 2 * capacity);
    u32 padBits = 32 - scratchBits;
    i32 paddedScratch = scratch << padBits;
    data[size - 1] = paddedScratch & 0xFFFFFFFF;
    scratchBits = 0;
    scratch = 0;
}


void BitPacker::copy(const BitPacker& other)
{
    Array::copy(other);

    scratch = other.scratch;
    scratchBits = other.scratchBits;
}

void BitPacker::move(BitPacker&& other)
{
    Array::move(other);

    scratch = other.scratch;
    scratchBits = other.scratchBits;

    other.scratch = 0;
    other.scratchBits = 0;
}
