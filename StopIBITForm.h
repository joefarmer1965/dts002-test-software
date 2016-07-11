//---------------------------------------------------------------------------

#ifndef StopIBITFormH
#define StopIBITFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TStopIBIT : public TForm
{
__published:	// IDE-managed Components
	TLabel *IBITStopLabel;
	TMemo *IBITSelectLabel;
	TListBox *StopIBITListBox;
	void __fastcall StopIBITListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStopIBIT(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStopIBIT *StopIBIT;
//---------------------------------------------------------------------------
#endif
