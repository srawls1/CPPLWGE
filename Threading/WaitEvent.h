#pragma once

#include "Assert.h"
#include "Types.h"

#if PLATFORM == WINDOWS
#include "winbase.h"
#else
#include "ConditionVariable.h"
#endif

class WaitEvent
{
private:

#if PLATFORM == WINDOWS
    HANDLE event;
#else
    bool activated;
    ConditionVariable cond;
    Mutex mutex;
#endif

public:

    WaitEvent(bool initiallySet);
    WaitEvent(const WaitEvent& copy) = delete;
    WaitEvent& operator=(const WaitEvent& copy) = delete;
    ~WaitEvent();

    void wait();
    // true if signaled, false if timeout
    bool timedWait(f32 timeout);
    void set();
    void reset();

};
