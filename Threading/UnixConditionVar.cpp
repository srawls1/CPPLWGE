#include "ConditionVariable.h"
#include "Math.h"

#if PLATFORM != WINDOWS

ConditionVariable::ConditionVariable()
{
    pthread_cond_init(&condition, nullptr);
}

ConditionVariable::~ConditionVariable()
{
    pthread_cond_destroy(&condition);
}

void ConditionVariable::wait(Mutex& mutex)
{
    pthread_cond_wait(&condition, &mutex.mutex);
}

bool ConditionVariable::timedWait(Mutex& mutex, f32 time)
{
    struct timespec timeout;
    timeout.tv_sec = Math::floor(time);
    timeout.tv_nsec = Math::round((time - timeout.tv_sec) * 1000000000);
    i32 ret =pthread_cond_timedwait(&condition, &mutex.mutex, &timeout);
    Assert(ret == 0 || ret == ETIMEDOUT);
    return ret == 0;
}

void ConditionVariable::signal()
{
    pthread_cond_signal(&condition);
}

#endif
