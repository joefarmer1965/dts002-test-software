//---------------------------------------------------------------------------

#ifndef IBIT_ManualSwitchTestH
#define IBIT_ManualSwitchTestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TManIBIT : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMemo *Instructions;
	TListBox *StepSelection;
	void __fastcall StepSelectionClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TManIBIT(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TManIBIT *ManIBIT;
//---------------------------------------------------------------------------
void WaitTime(int timeToWait);
#endif
