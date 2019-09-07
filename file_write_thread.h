#ifndef FILE_WRITE_THREAD_H
#define FILE_WRITE_THREAD_H

#include <windows.h>

#include "thread_wrap.h"

class FileWrite
{
    void mappedFileWrite(float coefA, float coefB, float coefC);
    virtual void run();
};

#endif // FILE_WRITE_THREAD_H

