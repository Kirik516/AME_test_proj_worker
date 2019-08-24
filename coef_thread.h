#include <chrono>
#include <atomic>
#include <thread>
#include <cmath>
#include <iostream>

class CoefThread
{
    bool isRunning;

    // sin frequency in sec
    float freq;

    // read only fields
    float startVal;
    float range;

    // write fields
    std::atomic<float> currentVal;
    std::chrono::time_point<std::chrono::system_clock> startTime;

    // thread obj
    std::thread currenThread;

    void flowCoef();

public:
    CoefThread(float startVal, float endVal);
    void setFreq(float freq);
    float getVal();
    void run();
};
