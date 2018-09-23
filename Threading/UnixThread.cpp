#include "Thread.h"

static void* startThread(void* param)
{
    Thread* t = (Thread*)param;
    t->func();
}

Thread::Thread(std::function<void()> f)
: running(false),
  func(f),
{
    do
    {
        next = first;
    } while (!first.compare_exchange_weak(next, this));
}

Thread::~Thread()
{
    if (running)
    {
        join();
    }
    for (Thread* iter = first; iter != nullptr; iter = iter->next)
    {
        // hopefully won't need to replace this with something more thread-safe
        if (iter->next == this)
        {
            iter->next = next;
        }
    }
}

void Thread::start()
{
    i32 ret = pthread_create(&thread, NULL, startThread, this);
    running = true;
    Assert(ret == 0);
}

void Thread::join()
{
    i32 ret = pthread_join(thread, NULL);
    running = false;
    Assert(ret == 0);
}

void Thread::terminate()
{
    i32 ret = pthread_cancel(thread);
    Assert(ret == 0);
}

Thread* Thread::current()
{
    pthread_t self = pthread_self();
    for (Thread* iter = first; iter != nullptr; iter = iter->next)
    {
        if (pthread_equal(self, iter->thread))
        {
            return iter;
        }
    }
    return nullptr;
}
