//---------------------------------------------------------------------------

#ifndef CurveVersionSelectH
#define CurveVersionSelectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TCurveVersionForm : public TForm
{
__published:	// IDE-managed Components
        TMemo *CurveMemo;
        TLabel *SelectCurveLabel;
        TListBox *SelectCurveListBox;
        void __fastcall SelectCurveListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCurveVersionForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCurveVersionForm *CurveVersionForm;
//---------------------------------------------------------------------------
#endif
