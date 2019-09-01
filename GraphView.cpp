//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GraphView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraphView1 *GraphView1;
//---------------------------------------------------------------------------

__fastcall TGraphView1::TGraphView1(TComponent* Owner)
    : TForm(Owner)
    , graphResolution(1000)
    , startGraphX(-10.0)
    , stopGraphX(10.0)
    , startGraphY(-10.0)
    , stopGraphY(10.0)
    , coefA(0.0)
    , coefB(3.0)
    , coefC(1.0)
    , graphBack(new TBitmap)
    , graphFront(new TBitmap)
{
    this->graphBack->SetSize(this->GraphLabel->Width, this->GraphLabel->Height);
    this->graphFront->SetSize(this->GraphLabel->Width, this->GraphLabel->Height);
}
//---------------------------------------------------------------------------

void TGraphView1::setCoefs(float coefA, float coefB, float coefC)
{
    this->coefA = coefA;
    this->coefB = coefB;
    this->coefC = coefC;
}

void TGraphView1::configDrawThread()
{
    this->drawThread = new GraphDrawer(true);
    this->drawThread->OnTerminate = threadEnd;
    this->drawThread->setGraphBitmap(this->graphBack);
    this->drawThread->setDim(this->GraphLabel->Width, this->GraphLabel->Height);
    this->drawThread->setSampling(this->graphResolution);
    this->drawThread->setXRange(this->startGraphX, this->stopGraphX);
    this->drawThread->setYRange(this->startGraphY, this->stopGraphY);
    this->drawThread->setCoefs(this->coefA, this->coefB, this->coefC);
    this->drawThread->Resume();
}
//---------------------------------------------------------------------------

void TGraphView1::zoom(int direction)
{
    if (this->drawThread != NULL)
    {
        return;
    }

    if ( ((this->stopGraphX - direction) - (this->startGraphX + direction)) == 0
        || ((this->stopGraphY - direction) - (this->startGraphY + direction)) == 0)
    {
        return;
    }

    float fDirection = direction/4.0;
    this->startGraphX += fDirection;
    this->startGraphY += fDirection;
    this->stopGraphX -= fDirection;
    this->stopGraphY -= fDirection;

    this->FormShow(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::threadEnd(TObject *Sender)
{
    std::swap(this->graphBack, this->graphFront);
    this->drawThread = NULL;
    this->GraphLabel->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::FormShow(TObject *Sender)
{
    if (this->drawThread != NULL)
    {
        return;
    }

    this->configDrawThread();
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    this->zoom(-1);
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    this->zoom(1);
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::FormPaint(TObject *Sender)
{
    this->GraphLabel->Canvas->Draw(0, 0, this->graphFront);
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::ResizeTimerTimer(TObject *Sender)
{
    this->ResizeTimer->Enabled = false;
    this->FormShow(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TGraphView1::FormResize(TObject *Sender)
{
    // allows start redraw after resize has been end
    if (this->ResizeTimer->Enabled)
    {
        this->ResizeTimer->Enabled = false;
        this->ResizeTimer->Enabled = true;
        return;
    }

    this->ResizeTimer->Enabled = true;
}
//---------------------------------------------------------------------------

