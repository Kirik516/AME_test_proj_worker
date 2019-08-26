//---------------------------------------------------------------------------

#ifndef GraphH
#define GraphH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
#include <cmath>
#include <thread>
//---------------------------------------------------------------------------
#include "GraphDrawerThread.h"
//---------------------------------------------------------------------------
class TGraph1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Titile;
    TImage *Graph;
    TLabel *LabelY;
    TLabel *LabelX;
    TImage *BackGraph;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
    void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);

private:	// User declarations
    int graphResolution; // graph sampling
    float startGraphX, stopGraphX;
    float startGraphY, stopGraphY;

    float coefA;
    float coefB;
    float coefC;

    int test;

//    TPicture pic;

    // special thread handle for drawing
    GraphDrawer *drawThread;

    void configDrawThread();
    void zoom(int direction);
    void __fastcall threadend(TObject *Sender);

public:		// User declarations
    __fastcall TGraph1(TComponent* Owner);
        void setCoefs(float coefA, float coefB, float coefC);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraph1 *Graph1;
//---------------------------------------------------------------------------
#endif

