//---------------------------------------------------------------------------

#ifndef SetOffsetFormH
#define SetOffsetFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TOffsetSelectionForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *SetOffsetsLabel;
	TMemo *AzimuthLabel;
	TMemo *ElevationLabel;
	TListBox *SetAzimuthListBox;
	TListBox *SetElevationListBox;
	void __fastcall SetAzimuthListBoxClick(TObject *Sender);
	void __fastcall SetElevationListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TOffsetSelectionForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOffsetSelectionForm *OffsetSelectionForm;
//---------------------------------------------------------------------------
#endif
