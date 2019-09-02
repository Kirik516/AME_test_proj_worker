#include "thread_wrap.h"

ThreadWrap::ThreadWrap()
    : futureObj(this->terminateSig.get_future())
{}

ThreadWrap::~ThreadWrap()
{
    if (this->threadObj.joinable())
    {
        this->stop();
        this->threadObj.join();
    }
}

void ThreadWrap::stop()
{
    this->terminateSig.set_value();
}

