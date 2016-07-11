//---------------------------------------------------------------------------

#ifndef IBITStatusH
#define IBITStatusH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TIBITCodeSelect : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TListBox *IBITListBox;
	void __fastcall IBITListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TIBITCodeSelect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIBITCodeSelect *IBITCodeSelect;
//---------------------------------------------------------------------------
#endif
