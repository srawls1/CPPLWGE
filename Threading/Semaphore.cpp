#include "Semaphore.h"

Semaphore::Semaphore(i32 startingCount)
: count(startingCount)
{}

void Semaphore::acquire(i32 deltaCount)
{
    mutex.lock();
    count -= deltaCount;
    if (count < 0)
    {
        condition.wait(mutex);
    }
    mutex.unlock();
}

void Semaphore::release(i32 deltaCount)
{
    mutex.lock();
    count += deltaCount;
    mutex.unlock();
    if (count <= 0)
    {
        condition.signal();
    }
}

i32 Semaphore::getCount()
{
    return count;
}
