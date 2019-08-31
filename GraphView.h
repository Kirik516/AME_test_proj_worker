//---------------------------------------------------------------------------

#ifndef GraphViewH
#define GraphViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
#include <cmath>
//---------------------------------------------------------------------------
#include "GraphDrawerThread.h"
//---------------------------------------------------------------------------
class TGraphView1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Titile;
    TLabel *LabelY;
    TLabel *LabelX;
    TLabel *GraphLabel;
    TTimer *ResizeTimer;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
    void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall ResizeTimerTimer(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);

private:	// User declarations
    int graphResolution; // graph sampling
    float startGraphX, stopGraphX;
    float startGraphY, stopGraphY;

    float coefA;
    float coefB;
    float coefC;

    int test;

    TBitmap *graphBack;
    TBitmap *graphFront;

    // special thread handle for drawing
    GraphDrawer *drawThread;

    void configDrawThread();
    void zoom(int direction);
    void __fastcall threadEnd(TObject *Sender);

public:		// User declarations
    __fastcall TGraphView1(TComponent* Owner);
    void setCoefs(float coefA, float coefB, float coefC);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraphView1 *GraphView1;
//---------------------------------------------------------------------------
#endif

