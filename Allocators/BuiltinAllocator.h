#include "Allocator.h"

class BuiltinAllocator : public Allocator
{
protected:

    virtual void* inner_allocate(u32 numBytes, u32 alignment) override;
    virtual void inner_free(void* mem) override;
    virtual void* inner_reallocate(void* orig, u32 newNumBytes, u32 alignment) override;

public:

    BuiltinAllocator();
    virtual ~BuiltinAllocator();
}
