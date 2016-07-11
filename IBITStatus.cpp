//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IBITStatus.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TIBITCodeSelect *IBITCodeSelect;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern bool IBIT_AllCodesRequest;
//---------------------------------------------------------------------------
__fastcall TIBITCodeSelect::TIBITCodeSelect(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TIBITCodeSelect::IBITListBoxClick(TObject *Sender)
{
  opMsg.ID = 0x0E5A0800 + (address << 12);
  opMsg.LEN = 0x01;

  switch(IBITListBox->ItemIndex + 1)
  {
	   case 1: opMsg.DATA[0] = 0x00;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   IBIT_AllCodesRequest = true;
			   Message("Rx  0E 5A 08 00 00      [ IBIT - ALL Codes Request ] ");
			   ProcessIBITResponse();
			   break;
	   case 2: opMsg.DATA[0] = 0x01;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message("Rx  0E 5A 08 00 01      [ IBIT - Auto Switch Test ] ");
			   ProcessIBITResponse();
			   break;
	   case 3: opMsg.DATA[0] = 0x02;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message("Rx  0E 5A 08 00 02      [ IBIT - Manual Switch Test ] ");
			   ProcessIBITResponse();
			   break;
	   case 4: opMsg.DATA[0] = 0x03;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message("Rx  0E 5A 08 00 03      [ IBIT - Auto Deflection Test ] ");
			   ProcessIBITResponse();
			   break;
	   case 5: opMsg.DATA[0] = 0x04;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message("Rx  0E 5A 08 00 04      [ IBIT - Manual Deflection Test ] ");
			   ProcessIBITResponse();
			   break;
	   case 6: IBITCodeSelect->Visible = false;
			  break;
  }

}
//---------------------------------------------------------------------------





