#include "ScopeLock.h"

ScopeLock::ScopeLock(Mutex* mutex)
{
    m = mutex;
    lock = !m->isOwnedByCurrentThread())
    if (lock)
    {
        m->lock();
    }
}

ScopeLock::~ScopeLock()
{
    if (lock)
    {
        m->unlock();
    }
}
