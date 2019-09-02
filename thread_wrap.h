#ifndef THREAD_WRAP_H
#define THREAD_WRAP_H

#include <thread>
#include <future>

class ThreadWrap
{
    std::promise<void> terminateSig;
    std::future<void> futureObj;

    std::thread threadObj;


public:
    ThreadWrap();
    ~ThreadWrap();
    virtual void run() = 0;
    void stop();
};

#endif // THREAD_WRAP_H

