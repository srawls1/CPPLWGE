#pragma once

#include "Config.h"
#include "Assert.h"
#include "Thread.h"

#if PLATFORM == WINDOWS
#include "windows.h"
#else
#include <pthread.h>
#endif

class ConditionVariable;

class Mutex
{
    friend class ConditionVariable;
private:

    Thread* owningThread;

#if PLATFORM == WINDOWS

    HANDLE criticalSection;

#else

    pthread_mutex_t mutex;

#endif

public:
    Mutex();
    Mutex(const Mutex& copy) = delete;
    Mutex& operator=(const Mutex& copy) = delete;
    Mutex(Mutex&& move) = delete;
    Mutex& operator=(Mutex&& move) = delete;
    ~Mutex();

    void lock();
    bool trylock();
    void unlock();
    bool isLocked();
    bool isOwnedByCurrentThread();
};
