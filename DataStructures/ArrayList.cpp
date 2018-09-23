#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList(u32 startingCapacity, Allocator* alloc)
: Array(startingCapacity, alloc)
{}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other)
{
    copy(other);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
{
    dispose();
    copy(other);
    return *this;
}

template <typename T>
ArrayList<T>::ArrayList(ArrayList<T>&& other)
{
    move(other);
    lock = std::move(other.lock);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T>&& other)
{
    dispose();
    move(other);
    lock = std::move(other.lock);
    return *this;
}

template <typename T>
void ArrayList<T>::forEach(std::function<void(T)> callback)
{
    for (u32 i = 0; i < size; ++i)
    {
        callback(data[i]);
    }
}

template <typename T>
ArrayList<T>::Iterator ArrayList<T>::begin()
{
    return data;
}

template <typename T>
ArrayList<T>::Iterator ArrayList<T>::end()
{
    return data + size;
}


template <typename T>
i32 ArrayList<T>::indexOf(T elem, i32 searchStart)
{
    Assert(searchStart >= 0);
    Assert(searchStart < size);
    for (i32 i = searchStart; i < size; ++i)
    {
        if (data[i] == elem)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
i32 ArrayList<T>::lastIndexOf(T elem, i32 searchEnd)
{
    Assert(searchEnd >= 0);
    Assert(searchEnd < size);
    for (i32 i = searchEnd; i >= 0; --i)
    {
        if (data[i] == elem)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
ArrayList<T> ArrayList<T>::findAll(std::function<bool(T)> predicate)
{
    ArrayList<T> ret;
    for (u32 i = 0; i < size; ++i)
    {
        if (predicate(data[i]))
        {
            ret.add(data[i]);
        }
    }

    return ret;
}

template <typename T>
i32 ArrayList<T>::findFirst(std::function<bool(T)> predicate, i32 searchStart)
{
    for (i32 i = searchStart; i < size; ++i)
    {
        if (predicate(data[i]))
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
i32 ArrayList<T>::findLast(std::function<bool(T)> predicate, i32 searchEnd)
{
    for (i32 i = searchEnd; i >= 0; --i)
    {
        if (predicate(data[i]))
        {
            return i;
        }
    }

    return -1;
}


template <typename T>
const T& ArrayList<T>::getAt(i32 index)
{
    lock.lockShared();
    u32 i = Math::mod(index, size);
    T& ret = data[i];
    lock.unlockShared();
    return ret;
}

template <typename T>
T* ArrayList<T>::quickRange(u32 start, u32 end)
{
    Assert(start >= 0);
    Assert(end < size);
    return data + start;
}

template <typename T>
ArrayList<T> ArrayList<T>::copyRange(i32 start, i32 end)
{
    u32 modStart = Math::mod(start, size);
    u32 modEnd = Math::mod(end, size);
    u32 cap = Math::mod(end - start);

    lock.lockShared();

    ArrayList<T> ret(cap);
    for (u32 i = modStart; i != modEnd; i = Math::mod(i + 1, size))
    {
        ret.data[ret.size++] = data[i];
    }

    lock.unlockShared();
    return ret;
}

template <typename T>
void ArrayList<T>::setAt(i32 index, T elem)
{
    lock.lockExclusive();
    u32 i = Math::mod(index, size);
    data[i] = elem;
    lock.unlockExclusive();
}

template <typename T>
void ArrayList<T>::setRange(i32 start, ArrayList<T> otherList)
{
    setRange(start, otherList.data, otherList.size);
}

template <typename T>
void ArrayList<T>::setRange(i32 start, T* rawData, u32 length)
{
    lock.lockExclusive();
    u32 modStart = Math::mod(start, size);
    for (u32 i = 0; i < length; ++i)
    {
        u32 modI = Math::mod(i, size);
        data[modI] = rawData[i];
    }
    lock.unlockExclusive();
}


template <typename T>
void ArrayList<T>::add(T elem)
{
    lock.lockExclusive();
    ensureCapacity(size + 1, capacity * 2);
    data[size++] = elem;
    lock.unlockExclusive();
}

template <typename T>
void ArrayList<T>::addAll(ArrayList<T> otherList)
{
    addAll(otherList.data, otherList.size);
}

template <typename T>
void ArrayList<T>::addAll(T* rawData, u32 length)
{
    lock.lockExclusive();
    u32 newCap = capacity;
    u32 newSize = size + otherList.size;
    while (newCap < newSize)
    {
        newCap <<= 1;
    }

    ensureCapacity(newSize, newCap);
    for (u32 i = 0; i < length; ++i)
    {
        data[size++] = rawData[i];
    }
    lock.unlockExclusive();
}

void insert(T elem, i32 index);
u32 insertUnique(T elem);
u32 insertOrdered(T elem, std::function<i32(T, T)> comparison);

void remove(T elem);
void removeAt(i32 index);
void removeIf(std::function<bool(T)> predicate);
void removeRange(i32 start, i32 end);
void removeAtAll(ArrayList<i32> indices);
void removeAll(ArrayList<T> elements);

virtual Transactable* beginWriteTransaction();
virtual void commitTransaction(Transactable* modified);
virtual void rollbackTransaction();

virtual void beginReadOnlyTransaction();
virtual void endReadOnlyTransaction();

void sort(std::function<i32(T, T)> comparison);
