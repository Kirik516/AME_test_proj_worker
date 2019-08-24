//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Window.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
    , coefA(3.0, 7.0)
{
    this->coefA.run();
    std::cout << "programm started" << std::endl;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    std::string valA = std::to_string(this->coefA.getVal());
    this->EditA->Text = valA.c_str();
}
//---------------------------------------------------------------------------

