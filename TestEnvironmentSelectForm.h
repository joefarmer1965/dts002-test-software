//---------------------------------------------------------------------------

#ifndef TestEnvironmentSelectFormH
#define TestEnvironmentSelectFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#define CAL 1
#define FAT 2
#define FVT 3
#define LTV 4
#define SVT 5
#define EMC 6

extern bool EMC_Selected = true;

//---------------------------------------------------------------------------
class TTestEnvironmentSelect : public TForm
{
__published:	// IDE-managed Components
	TListBox *TestEnvironmentListBox;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	void __fastcall TestEnvironmentListBoxClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTestEnvironmentSelect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTestEnvironmentSelect *TestEnvironmentSelect;
//---------------------------------------------------------------------------

 void SetUpFormForEMC();
 void SetUpFormForSVT();
 void SetpFormForFVT();
 void SetUpFormForLTV();
 void SetUpFormForCal();
 void SetUpFormForFat();

#endif


