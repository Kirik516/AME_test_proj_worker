#include "thread_wrap.h"

ThreadWrap::ThreadWrap()
    : futureObj(this->terminateSig.get_future())
{}
//---------------------------------------------------------------------------

ThreadWrap::~ThreadWrap()
{
    if (this->threadObj.joinable())
    {
        this->stop();
        this->threadObj.join();
    }
}
//---------------------------------------------------------------------------

void ThreadWrap::start()
{
    this->terminateSig = std::promise<void>();
    this->futureObj = this->terminateSig.get_future();

    if (this->threadObj.joinable())
    {
        this->threadObj.join();
    }
    this->threadObj = std::thread(&ThreadWrap::run, this);
}
//---------------------------------------------------------------------------

void ThreadWrap::stop()
{
    this->terminateSig.set_value();
}
//---------------------------------------------------------------------------

bool ThreadWrap::isRunning()
{
    if (this->futureObj.wait_for(std::chrono::milliseconds(0))
                                        == std::future_status::timeout)
    {
        return true;
    }

    return false;
}
//---------------------------------------------------------------------------

