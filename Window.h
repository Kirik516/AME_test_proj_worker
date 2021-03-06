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
#include <map>

#include <System.SysUtils.hpp>

#include "coef_thread.h"
#include "file_write_thread.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *EditA;
    TEdit *EditB;
    TEdit *EditC;
    TButton *ButtonA;
    TButton *ButtonB;
    TButton *ButtonC;
    TLabel *LabelValA;
    TLabel *LabelValB;
    TLabel *LabelValC;
    TButton *ButtonDraw;
    TTimer *Timer1;
    TGroupBox *GroupBoxVal;
    TGroupBox *GroupBoxFreq;
    TLabel *LabelFreqA;
    TLabel *LabelFreqB;
    TLabel *LabelFreqC;
    TEdit *EditFreqA;
    TEdit *EditFreqB;
    TEdit *EditFreqC;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall EditFreqKeyPress(TObject *Sender, System::WideChar &Key);
    void __fastcall ButtonTrCntClick(TObject *Sender);
    void __fastcall ButtonDrawClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
    // threads
    CoefThread *coefA;
    CoefThread *coefB;
    CoefThread *coefC;
    FileWriteThread *fileWrite;

    // for freq set
    std::map<TEdit*, CoefThread*> freqMap;

    // for thread stop/start and  get value
    std::map<TButton*, std::pair<TEdit*, CoefThread*>> stopValMap;

    // 0 - on success; 1 - on fail
    // set freq from edit value to thread
    int setFreq(TEdit *edit, CoefThread *coefThread);
    // stop/start thread
    int stopStartThread(TButton *button, CoefThread *coefThread);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
