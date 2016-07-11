//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GetConfigForm.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGetConfig *GetConfig;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern unsigned long MsgSentTime;
//---------------------------------------------------------------------------
__fastcall TGetConfig::TGetConfig(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGetConfig::GetConfigListBoxClick(TObject *Sender)
{

  opMsg.ID = 0x0E5A4300 + (address << 12);
  opMsg.LEN = 0x01;

  switch(GetConfigListBox->ItemIndex)
  {
	case 0: opMsg.DATA[0] = 0x01;        // Get Part Number
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 43 00 01      [ GET CONFIG DATA - Part No]");
			break;
	case 1: opMsg.DATA[0] = 0x02;        // Get Serial Number
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 43 00 02      [ GET CONFIG DATA - Serial No]");
			break;
	case 2: opMsg.DATA[0] = 0x03;        // Get Software Version
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 43 00 03      [ GET CONFIG DATA - S/W Version]");
			break;
	case 3: opMsg.DATA[0] = 0x04;        // Get ETI and power cycle count
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 43 00 04      [ GET CONFIG DATA - ETI & Pwr Cycles]");
			break;
	case 4: GetConfig->Visible = false;
			break;

  }
}
//---------------------------------------------------------------------------
