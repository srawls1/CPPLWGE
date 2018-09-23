#pragma once

#include "Assert.h"
#include "Types.h"
#include "Mutex.h"

#if PLATFORM == WINDOWS
#include "windows.h"
#else
#include <pthread.h>
#endif

class ConditionVariable
{
private:
#if PLATFORM == WINDOWS

    HANDLE condition;

#else

    pthread_cond_t condition;

#endif

public:
    ConditionVariable();
    ConditionVariable(const ConditionVariable& copy) = delete;
    ConditionVariable& operator=(const ConditionVariable& copy) = delete;
    ~ConditionVariable();

    void wait(Mutex& mutex);
    // true if was signaled, false if timeout
    bool timedWait(Mutex& mutex, f32 time);
    void signal();

};
