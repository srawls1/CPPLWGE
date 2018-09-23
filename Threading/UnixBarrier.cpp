#inlude "Barrier.h"

#if PLATFORM != WINDOWS

Barrier::Barrier(u32 count)
{
    i32 ret = pthread_barrier_init(&barrier, nullptr, count);
    Assert(ret == 0);
}

Barrier::~Barrier()
{
    i32 ret = pthread_barrier_destroy(&barrier);
    Assert(ret == 0);
}

void Barrier::wait()
{
    i32 ret = pthread_barrier_wait(&barrier);
    Assert(ret == 0);
}
