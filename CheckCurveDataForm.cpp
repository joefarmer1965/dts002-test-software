//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CheckCurveDataForm.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCheckCurveForm *CheckCurveForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TCheckCurveForm::TCheckCurveForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCheckCurveForm::SelectListBoxClick(TObject *Sender)
{
   int i;
  // Send repeated RAW Data and Deflection Data requests for 2 seconds
  // PCAN-View times this loop at approx 30ms therefore looping 70 times
  // is approximately 2 seconds.

  for (i = 0; i < 70; i++)
  {
	opMsg.ID = 0x0E5A4200 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	opMsg.ID = 0x0E5A0A00 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	Delay();
  }

  CheckCurveForm->Visible = false;
  Message("DATA Capture has finished...");

}
//---------------------------------------------------------------------------
