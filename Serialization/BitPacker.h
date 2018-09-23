#pragma once

#include "Types.h"
#include "Assert.h"
#include "Array.h"

class BitPacker : private Array<u32>
{
    u64 scratch;
    u32 readIndex;
    u32 scratchBits;

    inline void copy(const BitPacker& other);
    inline void move(BitPacker&& other);

public:
    BitPacker(u32 size = 32, u32* buff = nullptr);
    BitPacker(const BitPacker& other);
    BitPacker& operator=(const BitPacker& other);
    BitPacker(BitPacker&& other);

    void writeBits(u32 data, u32 numBits);
    u32 readBits(u32 numBits);

    void writeInt(i32 val, i32 min, i32 max);
    i32 readInt(i32 min, i32 max);

    void writeFloat(f32 val, f32 min, f32 max, f32 planck);
    f32 readFloat(f32 min, f32 max, f32 planck);

    void flush();

    char* getData() { return (char*)data; }
    u32 getSize() { return size * sizeof(u32); }
};
