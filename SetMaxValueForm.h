//---------------------------------------------------------------------------

#ifndef SetMaxValueFormH
#define SetMaxValueFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TSetMaxValuesForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *SetMaxValLabel;
	TMemo *SetMaxLabel;
	TListBox *SetMaxValueListBox;
	void __fastcall SetMaxValueListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSetMaxValuesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSetMaxValuesForm *SetMaxValuesForm;
//---------------------------------------------------------------------------
#endif
