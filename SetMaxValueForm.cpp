//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetMaxValueForm.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSetMaxValuesForm *SetMaxValuesForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TSetMaxValuesForm::TSetMaxValuesForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSetMaxValuesForm::SetMaxValueListBoxClick(TObject *Sender)
{

  opMsg.ID = 0x0E5A0D00 + (address << 12);
  opMsg.LEN = 0x04;

  switch(SetMaxValueListBox->ItemIndex)
  {
	case 0: opMsg.DATA[0] = 0x00;        // Azimuth Data
			opMsg.DATA[1] = 0x00;        // Azimuth Data
			opMsg.DATA[2] = 0x00;        // Elevation Data
			opMsg.DATA[3] = 0x00;        // Elevation Data
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0D 00 00 00 00 00 [ SET MAX VALUE ]");
			Message("Set to zero - use whole range -8191  to +8191");
			SetMaxValuesForm->Visible = false;
			break;
	case 1: opMsg.DATA[0] = 0xF4;        // Azimuth Data
			opMsg.DATA[1] = 0x01;        // Azimuth Data
			opMsg.DATA[2] = 0xF4;        // Elevation Data
			opMsg.DATA[3] = 0x01;        // Elevation Data
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0D 00 F4 01 F4 01 [ SET MAX VALUE ]");
			Message("Set to 500 - use from now on ");
			SetMaxValuesForm->Visible = false;
			break;
	case 2: opMsg.DATA[0] = 0xE8;        // Azimuth Data
			opMsg.DATA[1] = 0x03;        // Azimuth Data
			opMsg.DATA[2] = 0xE8;        // Elevation Data
			opMsg.DATA[3] = 0x03;        // Elevation Data
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0D 00 E8 03 E8 03 [ SET MAX VALUE ]");
			Message("Set to 1000 - use from now on ");
			SetMaxValuesForm->Visible = false;
			break;
	case 3: opMsg.DATA[0] = 0x88;        // Azimuth Data
			opMsg.DATA[1] = 0x13;        // Azimuth Data
			opMsg.DATA[2] = 0x88;        // Elevation Data
			opMsg.DATA[3] = 0x13;        // Elevation Data
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0D 00 88 13 88 13 [ SET MAX VALUE ]");
			Message("Set to 5000 - use from now on ");
			SetMaxValuesForm->Visible = false;
			break;
	case 4: opMsg.DATA[0] = 0x40;        // Azimuth Data
			opMsg.DATA[1] = 0x1F;        // Azimuth Data
			opMsg.DATA[2] = 0x40;        // Elevation Data
			opMsg.DATA[3] = 0x1F;        // Elevation Data
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0D 00 40 1F 40 1F [ SET MAX VALUE ]");
			Message("Set to 8000 - use from now on ");
			SetMaxValuesForm->Visible = false;
			break;

  }
}
//---------------------------------------------------------------------------

