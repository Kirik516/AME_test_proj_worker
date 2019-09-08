#include "file_write_thread.h"

void FileWriteThread::fileWrite(float coefA, float coefB, float coefC)
{
    std::ofstream fileWrite(fileName, std::ios_base::out);
    if (fileWrite.fail())
    {
        return;
    }

    fileWrite << this->coefA << std::endl
              << this->coefB << std::endl
              << this->coefC << std::endl;
}
//---------------------------------------------------------------------------

void FileWriteThread::run()
{
    this->fileWrite(this->coefA, this->coefB, this->coefC);
}
//---------------------------------------------------------------------------

FileWriteThread::FileWriteThread(std::string fileName)
    : fileName(fileName)
{}
//---------------------------------------------------------------------------

void FileWriteThread::setCoefs(float coefA, float coefB, float coefC)
{
    this->coefA = coefA;
    this->coefB = coefB;
    this->coefC = coefC;
}
//---------------------------------------------------------------------------

