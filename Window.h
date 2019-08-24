//---------------------------------------------------------------------------

#ifndef WindowH
#define WindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include <string>

#include "coef_thread.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *EditA;
    TEdit *EditB;
    TEdit *EditC;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button4;
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations
    CoefThread coefA;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
