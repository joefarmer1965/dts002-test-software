//---------------------------------------------------------------------------

#ifndef SetTimingFormH
#define SetTimingFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TTimingForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TListBox *TimingSelection;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	void __fastcall TimingSelectionClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTimingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTimingForm *TimingForm;
//---------------------------------------------------------------------------
#endif
