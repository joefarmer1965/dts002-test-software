//---------------------------------------------------------------------------

#ifndef IBIT_ManualJoystickTestH
#define IBIT_ManualJoystickTestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TManIBITJoy : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMemo *Instructions;
	TListBox *SelectListBox;
	void __fastcall SelectListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
 	__fastcall TManIBITJoy(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TManIBITJoy *ManIBITJoy;
//---------------------------------------------------------------------------
void WaitTime(int timeToWait);
#endif
