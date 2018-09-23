#pragma once

#include "Assert.h"
#include <functional>
#include <atomic>

#if PLATFORM == WINDOWS
#include "winbase.h"
#else
#include <pthread>
#endif

static void* startThread(void* param);

class Thread
{
private:

    static std::atomic<Thread*> first;

    bool running;
    Thread* next;
    std::function<void()> func;

#if PLATFORM == WINDOWS
    HANDLE thread;
#else
    pthread_t thread;
#endif

public:

    Thread(std::function<void()> f);
    Thread(const Thread& other) = delete;
    Thread& operator=(const Thread& other) = delete;
    ~Thread();

    void start();
    void join();
    void terminate();

    static Thread* current();

    friend void* startThread(void*);
};
