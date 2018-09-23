#pragma once

#include "Mutex.h"
#include "ConditionVariable.h"

class SharedLock
{
private:
    Mutex shared;
    Mutex exclusive;
    u32 numReaders;

public:
    SharedLock();
    SharedLock(const SharedLock& copy) = delete;
    SharedLock& operator=(const SharedLock& copy) = delete;

    void lockShared();
    bool tryLockShared();
    void unlockShared();

    void lockExclusive();
    bool tryLockExclusive();
    void unlockExclusive();
};
