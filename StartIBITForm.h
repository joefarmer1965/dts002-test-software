//---------------------------------------------------------------------------

#ifndef StartIBITFormH
#define StartIBITFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TStartIBIT : public TForm
{
__published:	// IDE-managed Components
	TLabel *IBITStartLabel;
	TMemo *IBITSelectLabel;
	TListBox *StartIBITListBox;
	TMemo *IBITWarning;
	void __fastcall StartIBITListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStartIBIT(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStartIBIT *StartIBIT;
//---------------------------------------------------------------------------
#endif
