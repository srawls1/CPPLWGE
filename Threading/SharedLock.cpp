#include "SharedLock.h"

SharedLock::SharedLock()
: numReaders(0)
{}

void SharedLock::lockShared()
{
    shared.lock();
    if (numReaders++ == 1)
    {
        exclusive.lock();
    }
    shared.unlock();
}

bool SharedLock::tryLockShared()
{
    // TODO
}

void SharedLock::unlockShared()
{
    shared.lock();
    if (numReaders-- == 0)
    {
        exclusive.unlock();
    }
    shared.unlock();
}

void SharedLock::lockExclusive()
{
    exclusive.lock();
}

bool SharedLock::tryLockExclusive()
{
    // TODO
}

void SharedLock::unlockExclusive()
{
    exclusive.unlock();
}
