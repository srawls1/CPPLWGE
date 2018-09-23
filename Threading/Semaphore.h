#pragma once

#include "ConditionVariable.h"
#include "Mutex.h"

class Semaphore
{
private:
    Mutex mutex;
    ConditionVariable condition;
    i32 count;

public:
    Semaphore(i32 startingCount);
    Semaphore(const Semaphore& copy) = delete;
    Semaphore& operator=(const Semaphore& copy) = delete;

    void acquire(i32 deltaCount = 1);
    void release(i32 deltaCount = 1);
    i32 getCount();
};
