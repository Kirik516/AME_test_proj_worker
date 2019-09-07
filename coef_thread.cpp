#include "coef_thread.h"

void CoefThread::flowCoef()
{
    float val;
    while (this->isRunning())
    {
        std::chrono::duration<float> time =
                             std::chrono::system_clock::now() - this->startTime;
        this->currentVal = std::sinf(time.count() * M_PI / this->freq)
                           * this->range/2.0 + this->startVal + this->range/2.0;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}
//---------------------------------------------------------------------------

void CoefThread::run()
{
    this->startTime = std::chrono::system_clock::now();
    this->threadId = std::this_thread::get_id();
    this->flowCoef();
}
//---------------------------------------------------------------------------

CoefThread::CoefThread(float startVal, float endVal, float freq)
    : maxFreq(0.00001)
    , freq(freq)
    , startVal(startVal)
    , range(endVal - startVal)
    , currentVal(startVal)
{}
//---------------------------------------------------------------------------

void CoefThread::setFreq(float freq)
{
    if (freq < this->maxFreq)
    {
        freq = this->maxFreq;
    }

    this->startTime = std::chrono::system_clock::now();
    this->freq = freq;
}
//---------------------------------------------------------------------------

float CoefThread::getVal()
{
    return this->currentVal.load();
}
//---------------------------------------------------------------------------

