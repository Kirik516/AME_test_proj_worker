#ifndef THREAD_WRAP_H
#define THREAD_WRAP_H

#include <thread>
#include <future>

class ThreadWrap
{
    std::promise<void> terminateSig;
    std::future<void> futureObj;

    std::thread threadObj;

    virtual void run() = 0;

public:
    ThreadWrap();
    ~ThreadWrap();
    void start();
    void stop();
    bool isRunning();
};

#endif // THREAD_WRAP_H

