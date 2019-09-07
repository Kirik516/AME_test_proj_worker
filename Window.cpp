//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Window.h"
#include "GraphView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
    , coefA(new CoefThread(3.0, 7.0))
    , coefB(new CoefThread(1.0, 3.0))
    , coefC(new CoefThread(1.0, 10.0))
{
    this->freqMap[EditFreqA] = this->coefA;
    this->freqMap[EditFreqB] = this->coefB;
    this->freqMap[EditFreqC] = this->coefC;

    this->stopValMap[ButtonA] = std::pair<TEdit*, CoefThread*>(this->EditA, this->coefA);
    this->stopValMap[ButtonB] = std::pair<TEdit*, CoefThread*>(this->EditB, this->coefB);
    this->stopValMap[ButtonC] = std::pair<TEdit*, CoefThread*>(this->EditC, this->coefC);

    this->coefA->start();
    this->coefB->start();
    this->coefC->start();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    // setting current values to edits
    std::string val;

    auto mapIt = this->stopValMap.begin();
    for (; mapIt != this->stopValMap.end(); ++mapIt)
    {
        if (mapIt->second.first->Enabled == false)
        {
            val = std::to_string(mapIt->second.second->getVal());
            mapIt->second.first->Text = val.c_str();
        }
    }
}
//---------------------------------------------------------------------------
int TForm1::setFreq(TEdit *edit, CoefThread *coefThread)
{
    float freqVal = edit->Text.ToDouble();
    if (!std::isfinite(freqVal))
    {
        return 1;
    }

    coefThread->setFreq(freqVal);
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditFreqKeyPress(TObject *Sender, System::WideChar &Key)

{
    System::WideChar enterKey = 13;
    if (Key != enterKey)
    {
        return;
    }

    TEdit *edit = dynamic_cast<TEdit*>(Sender);
    if (!edit)
    {
        return;
    }

    if (!this->freqMap.count(edit))
    {
        return;
    }

    if (this->setFreq(edit, this->freqMap[edit]))
    {
        edit->Text = "Bad";
    }
}
//---------------------------------------------------------------------------
int TForm1::stopStartThread(TButton *button, CoefThread *coefThread)
{
    if (coefThread->isRunning())
    {
        coefThread->stop();
        this->stopValMap[button].first->Enabled = true;
        button->Caption = "Run";
        return 0;
    }

    coefThread->start();
    this->stopValMap[button].first->Enabled = false;
    button->Caption = "Stop";

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonTrCntClick(TObject *Sender)
{
    TButton *button = dynamic_cast<TButton*>(Sender);
    if (!button)
    {
        return;
    }

    if (!this->stopValMap.count(button))
    {
        return;
    }

    if (this->stopStartThread(button, this->stopValMap[button].second))
    {
        this->stopValMap[button].first->Text = "Bad";
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    GraphView1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete this->coefA;
    delete this->coefB;
    delete this->coefC;
}
//---------------------------------------------------------------------------

