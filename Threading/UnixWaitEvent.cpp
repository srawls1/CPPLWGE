#include "WaitEvent.h"

#if PLATFORM != WINDOWS

WaitEvent::WaitEvent(bool initiallySet)
    : activated(initiallySet)
{}

WaitEvent::~WaitEvent()
{}

void WaitEvent::wait()
{
    if (activated)
    {
        return;
    }
    mutex.lock();
    while (!activated)
    {
        cond.wait(mutex);
    }
    mutex.unlock();
}

bool WaitEvent::timedWait(f32 timeout)
{
    if (activated)
    {
        return true;
    }
    f32 startTime = 0; // TODO
    mutex.lock();
    while (!activated)
    {
        cond.timedWait(mutex, timeout);
    }
    mutex.unlock();
    f32 endTime = 0; // TODO
    return endTime - startTime < timeout;
}

void WaitEvent::set()
{
    mutex.lock();
    activated = true;
    cond.signal();
    mutex.unlock();
}

void WaitEvent::reset()
{
    mutex.lock();
    activated = false;
    mutex.unlock();
}

#endif
