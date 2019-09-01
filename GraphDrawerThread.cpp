//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "GraphDrawerThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall GraphDrawer::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall GraphDrawer::GraphDrawer(bool CreateSuspended)
    : TThread(CreateSuspended)
    , graph(NULL)
{
    this->FreeOnTerminate = true;
}
//---------------------------------------------------------------------------

void __fastcall GraphDrawer::Execute()
{
    NameThreadForDebugging(System::String(L"GraphDrawer1"));
    //---- Place thread code here ----

    this->draw(this->width, this->height);
}
//---------------------------------------------------------------------------

float GraphDrawer::drawindFunstion(float coefA, float coefB, float coefC, float t)
{
    return coefA + coefB * std::sinf(coefC * t);
}
//---------------------------------------------------------------------------

int GraphDrawer::toScreen(float val, float start, float stop, int space)
{
    float range = stop - start;
    float fInPx = range / space;
    return std::round((val - start) / fInPx);
}
//---------------------------------------------------------------------------

void GraphDrawer::draw(int width, int height)
{
    TCanvas *canv = this->graph->Canvas;

    this->graph->SetSize(width, height);

    // beautiful border
    canv->Pen->Color = clSkyBlue;
    canv->Brush->Color = TColor(0x00404040);
    canv->Rectangle(0, 0, width, height);

    // drawing Axis
    canv->Pen->Color = clDkGray;
    // X
    canv->MoveTo(1, height/2);
    canv->LineTo(width - 3, height/2);
    // Y
    canv->MoveTo(width/2, 1);
    canv->LineTo(width/2, height - 3);

    // drawing graph
    canv->Pen->Color = clLime;
    canv->Pen->Width = 2;

    float h = (this->stopGraphX - this->startGraphX) / this->sampling;
    float px1 = this->startGraphX;
    float py1 = this->drawindFunstion(this->coefA, this->coefB, this->coefC,
                                                            this->startGraphX);
    float px2;
    float py2;

    for (int i = 0; i < this->sampling; i++)
    {
        px2 = px1 + h;
        py2 = this->drawindFunstion(this->coefA, this->coefB, this->coefC, px2);
        canv->MoveTo(this->toScreen(px1, this->startGraphX, this->stopGraphX, width),
                     this->toScreen(py1, this->startGraphY, this->stopGraphY, height));

        canv->LineTo(this->toScreen(px2, this->startGraphX, this->stopGraphX, width),
                     this->toScreen(py2, this->startGraphY, this->stopGraphY, height));
        px1 = px2;
        py1 = py2;
    }
}
//---------------------------------------------------------------------------

void GraphDrawer::setImageForGraph(TImage *image)
{
    this->imageForGraph = image;
}
//---------------------------------------------------------------------------

void GraphDrawer::setGraphBitmap(TBitmap *bitmap)
{
    this->graph = bitmap;
}
//---------------------------------------------------------------------------

void GraphDrawer::setDim(int width, int height)
{
    this->width = width;
    this->height = height;
}
//---------------------------------------------------------------------------

void GraphDrawer::setSampling(int sampling)
{
    this->sampling = sampling;
}
//---------------------------------------------------------------------------

void GraphDrawer::setXRange(float startX, float stopX)
{
    this->startGraphX = startX;
    this->stopGraphX = stopX;
}
//---------------------------------------------------------------------------

void GraphDrawer::setYRange(float startY, float stopY)
{
    this->startGraphY = startY;
    this->stopGraphY = stopY;
}
//---------------------------------------------------------------------------

void GraphDrawer::setCoefs(float coefA, float coefB, float coefC)
{
    this->coefA = coefA;
    this->coefB = coefB;
    this->coefC = coefC;
}
