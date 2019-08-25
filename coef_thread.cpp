#include "coef_thread.h"

void CoefThread::flowCoef()
{
    float val;
    while (this->running)
    {
        std::chrono::duration<float> time =
                             std::chrono::system_clock::now() - this->startTime;
        this->currentVal = std::sinf(time.count() * M_PI / this->freq)
                           * this->range/2.0 + this->startVal + this->range/2.0;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

CoefThread::CoefThread(float startVal, float endVal, float freq)
    : running(false)
    , maxFreq(0.00001)
    , freq(freq)
    , startVal(startVal)
    , range(endVal - startVal)
    , currentVal(startVal)
{}

CoefThread::~CoefThread()
{
    if (this->running)
    {
        this->running = false;
    }

    this->currentThread.join();
}

void CoefThread::setFreq(float freq)
{
    if (freq < this->maxFreq)
    {
        freq = this->maxFreq;
    }

    this->startTime = std::chrono::system_clock::now();
    this->freq = freq;
}

float CoefThread::getVal()
{
    return this->currentVal.load();
}

bool CoefThread::isRunning()
{
    return this->running;
}

void CoefThread::run()
{
    this->running = true;
    this->startTime = std::chrono::system_clock::now();
    this->currentThread = std::thread(&CoefThread::flowCoef, this);
    this->threadId = this->currentThread.get_id();
}

void CoefThread::stop()
{
    this->running = false;
    this->currentThread.join();
}
