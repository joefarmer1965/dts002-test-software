//---------------------------------------------------------------------------

#ifndef CheckCurveDataFormH
#define CheckCurveDataFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TCheckCurveForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *SelectCurveLabel;
	TMemo *CurveSelectMemo;
	TListBox *SelectListBox;
	void __fastcall SelectListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCheckCurveForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCheckCurveForm *CheckCurveForm;
//---------------------------------------------------------------------------
void Delay(void);
#endif
