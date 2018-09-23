#include "Mutex.h"
#include "Types.h"

#if PLATFORM != WINDOWS

Mutex::Mutex()
{
    i32 ret = pthread_mutex_init(&mutex, nullptr);
    owningThread = nullptr;
    Assert(ret == 0);
}

Mutex::~Mutex()
{
    i32 ret = pthread_mutex_destroy(&mutex);
    Assert(ret == 0);
}

void Mutex::lock()
{
    i32 ret = pthread_mutex_lock(&mutex);
    owningThread = Thread::current();
    Assert(ret == 0);
}

bool Mutex::trylock()
{
    i32 ret = pthread_mutex_trylock(&mutex);
    return ret == 0;
}

void Mutex::unlock()
{
    owningThread = nullptr;
    i32 ret = pthread_mutex_unlock(&mutex);
    Assert(ret == 0);
}

bool Mutex::isLocked()
{
    return owningThread != nullptr;
}

bool Mutex::isOwnedByCurrentThread()
{
    owningThread == Thread::current();
}

#endif
