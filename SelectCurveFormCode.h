//---------------------------------------------------------------------------

#ifndef SelectCurveFormCodeH
#define SelectCurveFormCodeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSelectCurveForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *SelectCurve4XListBox;
        TLabel *SelectCurveLabel;
	TMemo *XAxisMemo;
	TMemo *YAxisMemo;
	TListBox *SelectCurve4YListBox;
	TMemo *Memo1;
	void __fastcall SelectCurve4XListBoxClick(TObject *Sender);
	void __fastcall SelectCurve4YListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSelectCurveForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectCurveForm *SelectCurveForm;
//---------------------------------------------------------------------------
#endif
