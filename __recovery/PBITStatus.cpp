//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PBITStatus.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPBITCodeSelect *PBITCodeSelect;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern bool PBIT_AllCodesRequest;
extern bool DP414_Selected;
extern bool DP1236_Selected;
//---------------------------------------------------------------------------
__fastcall TPBITCodeSelect::TPBITCodeSelect(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPBITCodeSelect::PBITListBoxClick(TObject *Sender)
{
 opMsg.ID = 0x0E5A0600 + (address << 12);
 opMsg.LEN = 0x02;

 if (DP414_Selected == true)
 {
	 switch(PBITListBox->ItemIndex + 1)
	   {
		   case 1: opMsg.DATA[0] = 0x00;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 00 00   [ PBIT - ALL Codes Request ] ");
				   PBIT_AllCodesRequest = true;
				   ProcessPBITResponse();
				   break;
		   case 2: opMsg.DATA[0] = 0x01;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 01 00   [ PBIT - RAM ] ");
				   ProcessPBITResponse();
				   break;
		   case 3: opMsg.DATA[0] = 0x02;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 02 00   [ PBIT - Program Memory CRC ] ");
				   ProcessPBITResponse();
				   break;
		   case 4: opMsg.DATA[0] = 0x03;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 03 00   [ PBIT - Microcontroller Temp] ");
				   ProcessPBITResponse();
				   break;
		   case 5: opMsg.DATA[0] = 0x04;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 04 00   [ PBIT - Cal & Curve CRC] ");
				   ProcessPBITResponse();
				   break;
		   case 6: opMsg.DATA[0] = 0x05;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 06 00 05 00  [ PBIT - LH SW1 ] ");
				   ProcessPBITResponse();
				   break;
		   case 7: opMsg.DATA[0] = 0x07;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 07 00   [ PBIT - LH SW2 ] ");
				   ProcessPBITResponse();
				   break;
		   case 8: opMsg.DATA[0] = 0x09;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 09 00   [ PBIT - LH TRIG ] ");
				   ProcessPBITResponse();
				   break;
		   case 9: opMsg.DATA[0] = 0x0B;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 0B 00   [ PBIT - LH PALM  ] ");
				   ProcessPBITResponse();
				   break;
		   case 10: opMsg.DATA[0] = 0x0D;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 0D 00   [ PBIT - RH SW1 ] ");
					ProcessPBITResponse();
					break;
		   case 11: opMsg.DATA[0] = 0x0F;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 0F 00   [ PBIT - RH SW2 ] ");
					ProcessPBITResponse();
					break;
		   case 12: Message("Not Available for this Controller ");
					break;
		   case 13: Message("Not Available for this Controller ");
					break;
		   case 14: opMsg.DATA[0] = 0x15;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 15 00   [ PBIT - RH TRIG ] ");
					ProcessPBITResponse();
					break;
		   case 15: opMsg.DATA[0] = 0x17;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message(" Rx  0E 5A 06 00 17 00  [ PBIT - RH PALM ] ");
					ProcessPBITResponse();
					break;
		   case 16: opMsg.DATA[0] = 0x19;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 19 00   [ PBIT - X Axis ] ");
					ProcessPBITResponse();
					break;
		   case 17: opMsg.DATA[0] = 0x1A;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 1A 00   [ PBIT - Y Axis ] ");
					ProcessPBITResponse();
					break;
		   case 18: PBITCodeSelect->Visible = false;
					break;

	   }
 }
 else if (DP1236_Selected == true)
 {

	 switch(PBITListBox->ItemIndex + 1)
	   {
		   case 1: opMsg.DATA[0] = 0x00;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 00 00  [ PBIT - ALL Codes Request ] ");
				   PBIT_AllCodesRequest = true;
				   ProcessPBITResponse();
				   break;
		   case 2: opMsg.DATA[0] = 0x01;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 01 00  [ PBIT - RAM ] ");
				   ProcessPBITResponse();
				   break;
		   case 3: opMsg.DATA[0] = 0x02;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 02 00  [ PBIT - Program Memory CRC ] ");
				   ProcessPBITResponse();
				   break;
		   case 4: opMsg.DATA[0] = 0x03;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message("Rx  0E 5A 06 00 03 00  [ PBIT - Microcontroller Temp] ");
				   ProcessPBITResponse();
				   break;
		   case 5: opMsg.DATA[0] = 0x04;
				   opMsg.DATA[1] = 0x00;
				   err = CAN_Write(PCAN_USBBUS1, &opMsg);
				   Message(" Rx  0E 5A 06 00 04 00  [ PBIT - Cal & Curve CRC] ");
				   ProcessPBITResponse();
				   break;
		   case 6: Message("Not Available for this Controller ");
				   break;
		   case 7: Message("Not Available for this Controller ");
				   break;
		   case 8: Message("Not Available for this Controller ");
				   break;
		   case 9: Message("Not Available for this Controller ");
				   break;
		   case 10: opMsg.DATA[0] = 0x0D;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 0D 00  [ PBIT - RH SW1 ] ");
					ProcessPBITResponse();
					break;
		   case 11: opMsg.DATA[0] = 0x0F;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 0F 00  [ PBIT - RH SW2 ] ");
					ProcessPBITResponse();
					break;
		   case 12: opMsg.DATA[0] = 0x11;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 11 00  [ PBIT - RH SW3 ] ");
					ProcessPBITResponse();
					break;
		   case 13: opMsg.DATA[0] = 0x13;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 13 00  [ PBIT - RH SW4 ] ");
					ProcessPBITResponse();
					break;
		   case 14: opMsg.DATA[0] = 0x15;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 15 00  [ PBIT - RH TRIG ] ");
					ProcessPBITResponse();
					break;
		   case 15: opMsg.DATA[0] = 0x17;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 17 00  [ PBIT - RH PALM ] ");
					ProcessPBITResponse();
					break;
		   case 16: opMsg.DATA[0] = 0x19;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 19 00  [ PBIT - X Axis ] ");
					ProcessPBITResponse();
					break;
		   case 17: opMsg.DATA[0] = 0x1A;
					opMsg.DATA[1] = 0x00;
					err = CAN_Write(PCAN_USBBUS1, &opMsg);
					Message("Rx  0E 5A 06 00 1A 00  [ PBIT - Y Axis ] ");
					ProcessPBITResponse();
					break;
		   case 18: PBITCodeSelect->Visible = false;
					break;

	   }
 }
}
//---------------------------------------------------------------------------

