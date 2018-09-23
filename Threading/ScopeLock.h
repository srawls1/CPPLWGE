#pragma once

#include "Mutex.h"

class ScopeLock
{
private:

    Mutex* m;
    bool lock;

public:

    ScopeLock(Mutex* mutex);
    ~ScopeLock();
};
