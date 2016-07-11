//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetTimingForm.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTimingForm *TimingForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TTimingForm::TTimingForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTimingForm::TimingSelectionClick(TObject *Sender)
{
 opMsg.ID = 0x0E5A0900 + (address << 12);
 opMsg.LEN = 0x02;
 opMsg.DATA[0] = 0x00;
 opMsg.DATA[1] = 0x00;

 switch(TimingSelection->ItemIndex + 1)
   {
	   case 1: opMsg.DATA[0] = 0x02; // **changed on 15/11/15 value was 0x14;**
			   opMsg.DATA[1] = 0x01;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message(" Rx  0E 5A 09 00 14 00  [ DDUT - Set Time to 20ms ] (Min)");
			   Message(" Rx  0E 5A 09 00 00 81  [ SSTO - Set Time to 100ms ] (Min) ] ");
			   ProcessTimingResponse();
			   break;
	   case 2: opMsg.DATA[0] = 0x03; // **changed on 15/11/15 value was 0x1E;**
			   opMsg.DATA[1] = 0x05;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message(" Rx  0E 5A 09 00 1E 05  [ DDUT - Set Time to 30ms ] ");
			   Message(" Rx  0E 5A 09 00 1E 05  [ SSTO - Set Time to 500ms ] ");
			   ProcessTimingResponse();
			   break;
	   case 3: opMsg.DATA[0] = 0x05; // **changed on 15/11/15 value was 0xB2;**
			   opMsg.DATA[1] = 0x8A;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message(" Rx  0E 5A 09 00 B2 8A  [ DDUT - Set Time to 50ms ] (Default)");
			   Message(" Rx  0E 5A 09 00 B2 8A  [ SSTO - Set Time to 1sec  ] (Default)");
			   ProcessTimingResponse();
			   break;
	   case 4: opMsg.DATA[0] = 0x08; // **changed on 15/11/15 value was 0x50;**
			   opMsg.DATA[1] = 0x14;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message(" Rx  0E 5A 09 00 50 14  [ DDUT - Set Time to 80ms ] ");
			   Message(" Rx  0E 5A 09 00 50 14  [ SSTO - Set Time to 2sec  ] ");
			   ProcessTimingResponse();
			   break;
	   case 5: opMsg.DATA[0] = 0x0A; // **changed on 15/11/15 value was 0x64;**
			   opMsg.DATA[1] = 0x64;
			   err = CAN_Write(PCAN_USBBUS1, &opMsg);
			   Message(" Rx  0E 5A 09 00 64 64  [ DDUT - Set Time to 100ms ] (Max) ");
			   Message(" Rx  0E 5A 09 00 64 64  [ SSTO - Set Time to 10sec  ] (Max) ");
			   ProcessTimingResponse();
			   break;
	   case 6: TimingForm->Visible = false;

   }
}
//---------------------------------------------------------------------------

