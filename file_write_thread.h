#ifndef FILE_WRITE_THREAD_H
#define FILE_WRITE_THREAD_H

#include "thread_wrap.h"

#include <fstream>

class FileWriteThread : public ThreadWrap
{
    float coefA, coefB, coefC;

    std::string fileName;

    void fileWrite(float coefA, float coefB, float coefC);
    virtual void run();

public:
    FileWriteThread(std::string fileName);
    void setCoefs(float coefA, float coefB, float coefC);
};

#endif // FILE_WRITE_THREAD_H

