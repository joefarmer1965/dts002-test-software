//---------------------------------------------------------------------------

#ifndef IBITFormCodeH
#define IBITFormCodeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TIBITForm : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TListBox *IBITListBox;
        TLabel *Label1;
	TMainMenu *MainMenu1;
        void __fastcall IBITListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TIBITForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIBITForm *IBITForm;
//---------------------------------------------------------------------------
#endif
