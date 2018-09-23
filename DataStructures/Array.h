#include "Assert.h"
#include "Types.h"

template <typename T>
class Array
{
protected:
    u32 size;
    u32 capacity;
    T* data;

    inline void ensureCapacity(u32 min, u32 ifMustResize);
    inline void copy(const Array<T>& other);
    inline void move(Array<T>&& other);
    inline void dispose();

    Array(u32 initialCapacity = 8);

public:
    virtual ~Array();
};


#include "Math.h"
#include "Allocator.h"
#include <cstring>

template <typename T>
void Array<T>::ensureCapacity(u32 desired, u32 ifMustResize)
{
    if (capacity < desired)
    {
        capacity = ifMustResize;
        data = Allocator::reallocate(data, capacity);
    }
}

template <typename T>
void Array<T>::copy(const Array<T>& other)
{
    capacity = other.capacity;
    size = other.size;
    data = Allocator::allocate<T>(capacity);
    memcpy(data, other.data, sizeof(T) * size);
}

template <typename T>
void Array<T>::move(Array<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

template <typename T>
void Array<T>::dispose()
{
    Allocator::free<T>(data);
}

template <typename T>
Array<T>::Array(u32 initialCapacity)
{
    size = 0;
    capacity = initialCapacity;
    data = Allocator::allocate<T>(capacity);
}

template <typename T>
Array<T>::~Array()
{
    dispose();
}
