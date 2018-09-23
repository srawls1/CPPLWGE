#include "BuiltinAllocator.h"

BuiltinAllocator::BuiltinAllocator()
: allotted(nullptr),
  totalSize(0),
  numBytesAllocated(0),
  numAllocations(0)
{}

BuiltinAllocator::~BuiltinAllocator()
{}

void* BuiltinAllocator::inner_allocate(u32 numBytes, u32 alignment)
{
    return malloc(numBytes);
}

void BuiltinAllocator::inner_free(void* mem)
{
    free(mem);
}

void* BuiltinAllocator::inner_reallocate(void* orig, u32 newNumBytes, u32 alignment)
{
    return realloc(orig, newNumBytes);
}
