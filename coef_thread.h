#include <chrono>
#include <atomic>
#include <thread>
#include <cmath>
#include <iostream>

class CoefThread
{
    // read/write for outside
    // read only from inside
    bool running;

    // sin frequency in sec
    float freq;
    // read only from inside
    float maxFreq;

    // read only fields
    float startVal;
    float range;

    // write fields
    std::atomic<float> currentVal;
    std::chrono::time_point<std::chrono::system_clock> startTime;

    // thread
    std::thread::id threadId;
    std::thread currentThread;

    void flowCoef();

public:
    CoefThread(float startVal, float endVal, float freq = 1.0);
    void setFreq(float freq);
    float getVal();
    bool isRunning();
    void run();
    void stop();
};
