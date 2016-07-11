//---------------------------------------------------------------------------

#ifndef GetConfigFormH
#define GetConfigFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TGetConfig : public TForm
{
__published:	// IDE-managed Components
	TLabel *GetConfigLabel;
	TMemo *SelectValLabel;
	TListBox *GetConfigListBox;
	void __fastcall GetConfigListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TGetConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGetConfig *GetConfig;
//---------------------------------------------------------------------------
#endif
