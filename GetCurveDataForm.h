//---------------------------------------------------------------------------

#ifndef GetCurveDataFormH
#define GetCurveDataFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TGetCurveForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *SelectCurveLabel;
	TMemo *CurveMemo;
	TListBox *GetCurveDataList;
		void __fastcall GetCurveDataListClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TGetCurveForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGetCurveForm *GetCurveForm;
//---------------------------------------------------------------------------
void Check_GetCurveDataResponse(int curve_id);
#endif
