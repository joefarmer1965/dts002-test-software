//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopIBITForm.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
# include "IBIT_ManualSwitchTest.h"
# include "IBIT_ManualJoystickTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStopIBIT *StopIBIT;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TStopIBIT::TStopIBIT(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStopIBIT::StopIBITListBoxClick(TObject *Sender)
{
  opMsg.ID = 0x0E5A4500 + (address << 12);
  opMsg.LEN = 0x01;

  switch(StopIBITListBox->ItemIndex)
  {
	case 0: opMsg.DATA[0] = 0x01; // IBIT Code ID = 1
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 45 00 01      [ STOP IBIT Code ID = 1 ]");
			ProcessIBITResponse();   // check the response
			StopIBIT->Visible = false;
			break;
	case 1: ManIBIT->Visible   = false;
			opMsg.DATA[0] = 0x02; // IBIT Code ID = 2
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 45 00 02      [ STOP IBIT Code ID = 2 ]");
			ProcessIBITResponse();   // check the response
			StopIBIT->Visible = false;
			break;
	case 2: opMsg.DATA[0] = 0x03; // IBIT Code ID = 3
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 45 00 03      [ STOP IBIT Code ID = 3 ]");
			ProcessIBITResponse();   // check the response
			StopIBIT->Visible = false;
			break;
	case 3: ManIBITJoy->Visible = false;
			opMsg.DATA[0] = 0x04; // IBIT Code ID = 4
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 45 00 04      [ STOP IBIT Code ID = 4 ]");
			ProcessIBITResponse();   // check the response
			StopIBIT->Visible = false;
			break;
  }
}
//---------------------------------------------------------------------------

