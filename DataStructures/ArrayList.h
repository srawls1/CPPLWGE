#include "Assert.h"
#include "Types.h"
#include "Allocator.h"
#include "SharedLock.h"
#include "Transactable.h"
#include "Iterable.h"

template <typename T>
class ArrayList : private Array, public Iterable<T>, public Transactable
{
private:
    SharedLock lock;

public:
    ArrayList(u32 startingCapacity = 8, Allocator* alloc = nullptr);
    ArrayList(const ArrayList<T>& other);
    ArrayList<T>& operator=(const ArrayList<T>& other);
    ArrayList(ArrayList<T>&& other);
    ArrayList<T>& operator=(ArrayList<T>&& other);

    // TODO move add/insert
    // TODO emplace
    // TODO

    typedef T* Iterator;

    virtual void forEach(std::function<void(T)> callback) const;
    inline Iterator begin();
    inline Iterator end();

    i32 indexOf(T elem, i32 searchStart = 0) const;
    i32 lastIndexOf(T elem, i32 searchEnd) const;
    i32 lastIndexOf(T elem) const
    { return lastIndexOf(elem, size - 1); }

    bool contains(T elem) const
    { return indexOf(elem) != -1; }

    ArrayList<T> findAll(std::function<bool(T)> predicate) const;
    i32 findFirst(std::function<bool(T)> predicate, i32 searchStart = 0) const;
    i32 findLast(std::function<bool(T)> predicate, i32 searchEnd) const;
    i32 findLast(std::function<bool(T)> predicate) const
    { return findLast(predicate, size - 1); }

    bool hasMatch(std::function<bool(T)> predicate) const
    { return findFirst(predicate) != -1; }

    const T& operator[](u32 index) const { return data[index]; }
    T& operator[](u32 index) { return data[index]; }

    const T& getAt(i32 index) const;
    T* quickRange(u32 start, u32 end) const;
    ArrayList<T> copyRange(i32 start, i32 end) const;

    void setAt(i32 index, T elem);
    void setRange(i32 start, ArrayList<T> otherList);
    void setRange(i32 start, T* rawData, u32 length);

    void add(T elem);
    void addAll(ArrayList<T> otherList);
    void addAll(T* rawData, u32 length);
    void insert(T elem, i32 index);
    u32 insertUnique(T elem);
    u32 insertOrdered(T elem, std::function<i32(T, T)> comparison);
    u32 insertOrderedUnique(T elem, std::function<i32(T, T)> comparison);

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

    inline u32 getSize() const
    { return size; }
    inline bool isEmpty() const
    { return size == 0; }
};
