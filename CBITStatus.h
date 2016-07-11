//---------------------------------------------------------------------------

#ifndef CBITStatusH
#define CBITStatusH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TCBITCodeSelect : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TListBox *CBITListBox;
	void __fastcall CBITListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCBITCodeSelect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCBITCodeSelect *CBITCodeSelect;
//---------------------------------------------------------------------------
#endif
