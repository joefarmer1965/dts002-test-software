//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CBITStatus.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCBITCodeSelect *CBITCodeSelect;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern bool CBIT_AllCodesRequest;
extern bool DP414_Selected;
extern bool DP1236_Selected;
//---------------------------------------------------------------------------
__fastcall TCBITCodeSelect::TCBITCodeSelect(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCBITCodeSelect::CBITListBoxClick(TObject *Sender)
{

  opMsg.ID = 0x0E5A0700 + (address << 12);
  opMsg.LEN = 0x02;

 if (DP414_Selected == true)
 {
	  switch(CBITListBox->ItemIndex + 1)
	   {
		   case 1: opMsg.DATA[0] = 0x00;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 00 00  [ CBIT - ALL Codes Request ] ");
				   CBIT_AllCodesRequest = true;
				   ProcessCBITResponse ();
				   break;
		   case 2: opMsg.DATA[0] = 0x03;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 03 00  [ CBIT - Microcontroller Temp ] ");
				   ProcessCBITResponse ();
				   break;
		   case 3: opMsg.DATA[0] = 0x06;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 06 00  [ CBIT - LH SW1 ] ");
				   ProcessCBITResponse ();
				   break;
		   case 4: opMsg.DATA[0] = 0x08;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 08 00  [ CBIT - LH SW2 ] ");
				   ProcessCBITResponse ();
				   break;
		   case 5: opMsg.DATA[0] = 0x0A;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 0A 00  [ CBIT - LH TRIG ] ");
				   ProcessCBITResponse ();
				   break;
		   case 6: opMsg.DATA[0] = 0x0C;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 0C 00  [ CBIT - LH PALM ] ");
				   ProcessCBITResponse ();
				   break;
		   case 7: opMsg.DATA[0] = 0x0E;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 0E 00  [ CBIT - RH SW1 ] ");
				   ProcessCBITResponse ();
				   break;
		   case 8: opMsg.DATA[0] = 0x10;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 10 00  [ CBIT - RH SW2] ");
				   ProcessCBITResponse ();
				   break;
		   case 9: opMsg.DATA[0] = 0x12;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 12 00  [ CBIT - RH SW3 ] ");
				   ProcessCBITResponse ();
				   break;
		   case 10: opMsg.DATA[0] = 0x14;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 14 00  [ CBIT - RH SW4 ] ");
					ProcessCBITResponse ();
					break;
		   case 11: opMsg.DATA[0] = 0x16;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 16 00  [ CBIT - RH TRIG ] ");
					ProcessCBITResponse ();
					break;
		   case 12: opMsg.DATA[0] = 0x18;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 18 00  [ CBIT - RH PALM ] ");
					ProcessCBITResponse ();
					break;
		   case 13: opMsg.DATA[0] = 0x19;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 19 00  [ CBIT - X Axis ] ");
					ProcessCBITResponse ();
					break;
		   case 14: opMsg.DATA[0] = 0x1A;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 1A 00  [ CBIT - Y Axis ] ");
					ProcessCBITResponse ();
					break;
		   case 15: CBITCodeSelect->Visible = false;
					break;
	   }
 }
 else if (DP1236_Selected == true)
 {
	  switch(CBITListBox->ItemIndex + 1)
	   {
		   case 1: opMsg.DATA[0] = 0x00;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 00 00  [ CBIT - ALL Codes Request ] ");
				   CBIT_AllCodesRequest = true;
				   ProcessCBITResponse ();
				   break;
		   case 2: opMsg.DATA[0] = 0x03;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 03 00  [ CBIT - Microcontroller Temp ] ");
				   ProcessCBITResponse ();
				   break;
		   case 3: Message(" Not Available for this Controller ");
				   break;
		   case 4: Message(" Not Available for this Controller ");
				   break;
		   case 5: Message(" Not Available for this Controller ");
				   break;
		   case 6: Message(" Not Available for this Controller ");
				   break;
		   case 7: opMsg.DATA[0] = 0x0E;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 0E 00  [ CBIT - RH SW1 ] ");
				   ProcessCBITResponse ();
				   break;
		   case 8: opMsg.DATA[0] = 0x10;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 10 00  [ CBIT - RH SW2] ");
				   ProcessCBITResponse ();
				   break;
		   case 9: opMsg.DATA[0] = 0x12;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 07 00 12 00  [ CBIT - RH SW3 ] ");
				   ProcessCBITResponse ();
				   break;
		   case 10: opMsg.DATA[0] = 0x14;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 14 00  [ CBIT - RH SW4 ] ");
					ProcessCBITResponse ();
					break;
		   case 11: opMsg.DATA[0] = 0x16;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 16 00  [ CBIT - RH TRIG ] ");
					ProcessCBITResponse ();
					break;
		   case 12: opMsg.DATA[0] = 0x18;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 18 00  [ CBIT - RH PALM ] ");
					ProcessCBITResponse ();
					break;
		   case 13: opMsg.DATA[0] = 0x19;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 19 00  [ CBIT - X Axis ] ");
					ProcessCBITResponse ();
					break;
		   case 14: opMsg.DATA[0] = 0x1A;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 07 00 1A 00  [ CBIT - Y Axis ] ");
					ProcessCBITResponse ();
					break;
		   case 15: CBITCodeSelect->Visible = false;
					break;
	   }



 }
}
//---------------------------------------------------------------------------
