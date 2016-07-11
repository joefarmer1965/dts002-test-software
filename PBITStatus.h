//---------------------------------------------------------------------------

#ifndef PBITStatusH
#define PBITStatusH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TPBITCodeSelect : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TListBox *PBITListBox;
	void __fastcall PBITListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPBITCodeSelect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPBITCodeSelect *PBITCodeSelect;
//---------------------------------------------------------------------------
#endif
