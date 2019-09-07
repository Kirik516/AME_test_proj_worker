#ifndef COEF_THREAD_H
#define COEF_THREAD_H

#include <chrono>
#include <atomic>
#include <thread>
#include <cmath>
#include <iostream>

#include "thread_wrap.h"

class CoefThread : public ThreadWrap
{
    // write only from outside
    // read only from inside
    // sin frequency in sec
    float freq;
    // read only from inside
    float maxFreq;

    // read only fields
    float startVal;
    float range;

    // write from intside fields
    std::atomic<float> currentVal;
    std::chrono::time_point<std::chrono::system_clock> startTime;

    // thread
    std::thread::id threadId;

    void flowCoef();
    virtual void run();

public:
    CoefThread(float startVal, float endVal, float freq = 1.0);
    void setFreq(float freq);
    float getVal();
};

#endif // COEF_THREAD_H

