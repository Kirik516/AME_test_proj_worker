#ifndef FILE_WRITE_THREAD_H
#define FILE_WRITE_THREAD_H

#include "thread_wrap.h"

#include <cstdlib>

class FileWriteThread : public ThreadWrap
{
    float coefA, coefB, coefC;

    void fileWrite(float coefA, float coefB, float coefC);
    virtual void run();

public:
    void setCoefs(float coefA, float coefB, float coefC);
};

#endif // FILE_WRITE_THREAD_H

