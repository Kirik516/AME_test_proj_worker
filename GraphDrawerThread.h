//---------------------------------------------------------------------------

#ifndef GraphDrawerThreadH
#define GraphDrawerThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class GraphDrawer : public TThread
{
    int width;
    int height;

    int sampling; // graph sampling
    float startGraphX, stopGraphX;
    float startGraphY, stopGraphY;

    float coefA;
    float coefB;
    float coefC;

    // backstoring bitmap
    TBitmap *graph;

    float drawindFunstion(float coefA, float coefB, float coefC, float t);
    int toScreen(float val, float start, float stop, int space);
    void draw(int width, int height);

protected:
    void __fastcall Execute();

public:
    __fastcall GraphDrawer(bool CreateSuspended);
    void setGraphBitmap(TBitmap *bitmap);
    void setDim(int width, int height);
    void setSampling(int sampling);
    void setXRange(float startX, float stopX);
    void setYRange(float startY, float stopY);
    void setCoefs(float coefA, float coefB, float coefC);
};
//---------------------------------------------------------------------------
#endif

