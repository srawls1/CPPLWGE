#include "../stdafx.h"
#include "Allocator.h"
#include "../Core/Math.h"

Allocator* Allocator::primaryInstance = nullptr;

Allocator* Allocator::getPrimaryInstance()
{
    return primaryInstance;
}

void Allocator::setPrimaryInstance(Allocator& instance)
{
    primaryInstance = &instance;
}

Allocator::~Allocator()
{
    Assert(numAllocations == 0 && numBytesAllocated == 0);
}

void* Allocator::nextAligned(void* startPoint, u32 alignment)
{
    u64 intStartPoint = (u64)startPoint;
    u32 padding = intStartPoint % alignment;
    u64 intRet = intStartPoint + (padding == 0) ? 0 : alignment - padding;
    return (void*)intRet;
}
