#pragma once

#include "Assert.h"
#include "Types.h"

#if PLATFORM == WINDOWS
#include "winbase.h"
#else
#include <pthread.h>
#endif

class Barrier
{
private:

#if PLATFORM == WINDOWS
    HANDLE barrier;
#else
    pthread_barrier_t barrier;
#endif

public:

    Barrier(u32 count);
    Barrier(const Barrier& copy) = delete;
    Barrier& operator=(const Barrier& copy) = delete;
    ~Barrier();

    void wait();
}
