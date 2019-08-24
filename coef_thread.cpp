#include "coef_thread.h"

void CoefThread::flowCoef()
{
    float val;
    while (this->isRunning)
    {
        std::chrono::duration<float> time =
                            std::chrono::system_clock::now() - this->startTime;
        this->currentVal = std::sinf(time.count() * this->freq)
                            * this->range + this->startVal + this->range/2.0;
//        std::cout << "value generated: " << this->currentVal << std::endl;
//        std::cout << "asd" << std::endl;
//        this->currentVal
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

CoefThread::CoefThread(float startVal, float endVal)
    : isRunning(0)
    , freq(M_PI)
    , startVal(startVal)
    , range(endVal - startVal)
    , currentVal(startVal)
{}

void CoefThread::setFreq(float freq)
{
    this->freq = freq;
}

float CoefThread::getVal()
{
    return this->currentVal.load();
}

void CoefThread::run()
{
    this->isRunning = true;
    this->startTime = std::chrono::system_clock::now();
    currenThread = std::thread(&CoefThread::flowCoef, this);
}