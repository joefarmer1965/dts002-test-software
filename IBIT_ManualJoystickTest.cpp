//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IBIT_ManualJoystickTest.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
#include "StartIBITForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TManIBITJoy *ManIBITJoy;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TManIBITJoy::TManIBITJoy(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TManIBITJoy::SelectListBoxClick(TObject *Sender)
{

  opMsg.ID = 0x0E5A4400 + (address << 12);
  opMsg.LEN = 0x01;
  opMsg.DATA[0] = 0x04;       // IBIT Manual Joystick Test

  switch(SelectListBox->ItemIndex)
  {
	case 0: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 04      [ START IBIT Code 4 - Step 1 ]");
			WaitTime(5000);  // allow time for Joystick Movement - 5 seconds ?
			ProcessIBITResponse();   // check the response
			break;
	case 1: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request

			Message("Rx  0E 5A 44 00 04      [ START IBIT Code 4 - Step 2 ]");
			WaitTime(5000);  // allow time for Joystick Movement - 5 seconds ?
			ProcessIBITResponse();   // check the response
			break;

	case 2: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 04      [ START IBIT Code 4 - Step 3 ]");
			WaitTime(5000);  // allow time for Joystick Movement - 5 seconds ?
			ProcessIBITResponse();   // check the response
			break;

	case 3: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 04      [ START IBIT Code 4 - Step 4]");
			WaitTime(5000);  // allow time for Joystick Movement - 5 seconds ?
			ProcessIBITResponse();   // check the response
			break;

	case 4: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 04      [ TEST COMPLETED]");
			WaitTime(5000);  // allow time for Joystick Movement - 5 seconds ?
			ProcessIBITResponse();   // check the response
			break;
  }
}
//---------------------------------------------------------------------------
void WaitTime(int timeToWait)
{
   unsigned long localTime =0;
   unsigned long TimeNow =0;

   localTime = GetTickCount() + timeToWait;

   while (TimeNow < localTime)
	{
	  TimeNow = GetTickCount();
	}
}
//---------------------------------------------------------------------------