#pragma once

class Allocator
{
protected:

    static Allocator* primaryInstance;

    void* allotted;
    u32 totalSize;

    u32 numBytesAllocated;
    u32 numAllocations;

protected:

    Allocator();
    inline void* nextAligned(void* startPoint, u32 alignment);

    virtual void* inner_allocate(u32 numBytes, u32 alignment) = 0;
    virtual void inner_free(void* mem) = 0;
    virtual void* inner_reallocate(void* orig, u32 newNumBytes, u32 alignment);

public:

    static Allocator* getPrimaryInstance();
    static void setPrimaryInstance(Allocator& instance);

    virtual ~Allocator();

    template <typename T>
    T* allocate(u32 numObjects = 1, bool initialize = true);

    template <typename T>
    T* reallocate(T* orig, u32 newNumObjects);

    template <typename T>
    void free(T* object, bool destruct = true);

};

template<typename T>
T* Allocator::allocate(u32 numObjects) // TODO
{
    if (numObjects == 0)
    {
        return nullptr;
    }
    ++numAllocations;
    u32 size = sizeof(T) * numObjects;
    void* rawMem = inner_allocate(size, sizeof(T));
    return (T*)rawMem;
}

template<typename T>
T* Allocator::reallocate(T* orig, u32 newNumObjects)
{
    if (orig == nullptr)
    {
        return allocate<T>(newNumObjects);
    }
    if (newNumObjects == 0)
    {
        free(orig);
        return nullptr;
    }
    u32 newSize = sizeof(T) * newNumObjects;
    void* rawMem = inner_reallocate(orig, newSize, sizeof(T));
    return (T*)rawMem;
}

template<typename T>
void Allocator::free(T* object) // TODO
{
    if (object == nullptr)
    {
        return;
    }
    --numAllocations;
    void* rawMem = (void*)object;
    alloc.inner_free(rawMem);
}
