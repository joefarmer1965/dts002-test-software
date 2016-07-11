//---------------------------------------------------------------------------

#ifndef SetCurveFormCodeH
#define SetCurveFormCodeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSetCurveForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *SelectCurveLabel;
        TMemo *CurveMemo;
        TListBox *SelectCurveListBox;
        void __fastcall SelectCurveListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSetCurveForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSetCurveForm *SetCurveForm;
//---------------------------------------------------------------------------
void Delay(void);
#endif
