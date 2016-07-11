//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IBIT_ManualSwitchTest.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
#include "StartIBITForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TManIBIT *ManIBIT;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern bool DP414_Selected;
//---------------------------------------------------------------------------
__fastcall TManIBIT::TManIBIT(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TManIBIT::StepSelectionClick(TObject *Sender)
{

  opMsg.ID = 0x0E5A4400 + (address << 12);
  opMsg.LEN = 0x01;
  opMsg.DATA[0] = 0x02;       // IBIT Manual Switch Test

  switch(StepSelection->ItemIndex)
  {
	case 0:  if (DP414_Selected == true)
			 {
				err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
				Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 1 ]");
				WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
				ProcessIBITResponse();   // check the response
			 }
			 else
			 {Message("*** This Switch is not available for this Controller ***"); }
			break;
	case 1: if (DP414_Selected == true)
			 {
				err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
				Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 2 ]");
				WaitTime(2000);  // allow time for switch press - 2 seconds ?
				ProcessIBITResponse();   // check the response
			 }
			 else
			 {Message("*** This Switch is not available for this Controller ***");}
			break;
	case 2: if (DP414_Selected == true)
			 {
				err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
				Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 3 ]");
				WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs] ?
				ProcessIBITResponse();   // check the response
			 }
			 else
			 {Message("*** This Switch is not available for this Controller ***"); }
			break;
	case 3: if (DP414_Selected == true)
			 {
				err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
				Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 4 ]");
				WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
				ProcessIBITResponse();   // check the response
			 }
			 else
			 {Message("*** This Switch is not available for this Controller ***");}
			break;
	case 4: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 5 ]");
			WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			ProcessIBITResponse();   // check the response
			break;
	case 5: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 6 ]");
			WaitTime(5000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			ProcessIBITResponse();   // check the response
			break;
	case 6: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 7 ]");
			WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			ProcessIBITResponse();   // check the response
			break;
	case 7: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 8 ]");
			WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs] ?
			ProcessIBITResponse();   // check the response
			break;
	case 8: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 9 ]");
			WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			ProcessIBITResponse();   // check the response
			break;
	case 9: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 10 ]");
			WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			ProcessIBITResponse();   // check the response
			break;
	case 10: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			 Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 11 ]");
			 WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			 ProcessIBITResponse();   // check the response
			break;
	case 11: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			 Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 12 ]");
			 WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs] ?
			 ProcessIBITResponse();   // check the response
			 break;
	case 12: err = CAN_Write(PCAN_USBBUS1, &opMsg);   // Send the request
			 Message("Rx  0E 5A 44 00 02      [ START IBIT Code 2 - Step 13 ]");
			 WaitTime(2000);  // allow time for switch press - 2 seconds [Changed to 5 secs]?
			 ProcessIBITResponse();   // check the response
			 break;
  }
}
//---------------------------------------------------------------------------
void WaitTime(int timeToWait)
{
   unsigned long localTime =0;
   unsigned long  TimeNow =0;

   localTime = GetTickCount() + timeToWait;

   while (TimeNow < localTime)
	{
	  TimeNow = GetTickCount();
    }
}
//---------------------------------------------------------------------------