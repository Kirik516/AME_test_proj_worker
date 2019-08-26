//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Graph.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraph1 *Graph1;
//---------------------------------------------------------------------------

__fastcall TGraph1::TGraph1(TComponent* Owner)
    : TForm(Owner)
    , graphResolution(1000)
    , startGraphX(-10.0)
    , stopGraphX(10.0)
    , startGraphY(-10.0)
    , stopGraphY(10.0)
    , coefA(0.0)
    , coefB(3.0)
    , coefC(1.0)
{}
//---------------------------------------------------------------------------

void TGraph1::setCoefs(float coefA, float coefB, float coefC)
{
    this->coefA = coefA;
    this->coefB = coefB;
    this->coefC = coefC;
}

void TGraph1::configDrawThread()
{
    this->drawThread = new GraphDrawer(true);
    this->drawThread->OnTerminate = threadend;
    this->drawThread->setImageForGraph(this->Graph);
    this->drawThread->setImageForBackGraph(this->BackGraph);
    this->drawThread->setDim(this->Graph->Width, this->Graph->Height);
    this->drawThread->setSampling(this->graphResolution);
    this->drawThread->setXRange(this->startGraphX, this->stopGraphX);
    this->drawThread->setYRange(this->startGraphY, this->stopGraphY);
    this->drawThread->setCoefs(this->coefA, this->coefB, this->coefC);
    this->drawThread->Resume();
}
//---------------------------------------------------------------------------

void TGraph1::zoom(int direction)
{
    if ( ((this->stopGraphX - direction) - (this->startGraphX + direction)) == 0
        || ((this->stopGraphY - direction) - (this->startGraphY + direction)) == 0)
    {
        return;
    }

    this->startGraphX += direction;
    this->startGraphY += direction;
    this->stopGraphX -= direction;
    this->stopGraphY -= direction;

//    if (this->drawThread.joinable())
//    {
//        this->drawThread.join();
//        return;
//    }
//    drawThread = std::thread(&TGraph1::draw, this,
//                                             this->Graph->Canvas,
//                                             this->Graph->Width,
//                                             this->Graph->Height);
//    this->draw(this->Graph->Canvas, this->Graph->Width, this->Graph->Height);

    if (this->drawThread != NULL)
    {
        return;
    }

    this->configDrawThread();
}
//---------------------------------------------------------------------------

void __fastcall TGraph1::threadend(TObject *Sender)
{
    this->drawThread = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TGraph1::FormShow(TObject *Sender)
{
//    if (this->drawThread.joinable())
//    {
//        this->drawThread.join();
//    }
//    drawThread = std::thread(&TGraph1::draw, this,
//                                             this->Graph->Canvas,
//                                             this->Graph->Width,
//                                             this->Graph->Height);

//    this->draw(this->Graph->Canvas, this->Graph->Width, this->Graph->Height);

    if (this->drawThread != NULL)
    {
        return;
    }

    this->configDrawThread();
}
//---------------------------------------------------------------------------

void __fastcall TGraph1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    this->zoom(-1);
}
//---------------------------------------------------------------------------

void __fastcall TGraph1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    this->zoom(1);
}
//---------------------------------------------------------------------------

