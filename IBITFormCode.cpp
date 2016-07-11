//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IBITFormCode.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TIBITForm *IBITForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TIBITForm::TIBITForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TIBITForm::IBITListBoxClick(TObject *Sender)
{
 opMsg.ID = 0x0E5A0800 + (address << 12);
 opMsg.LEN = 0x07;
 opMsg.DATA[0] = 0x00; //Message ID
 opMsg.DATA[1] = 0x00; //No password
 opMsg.DATA[2] = 0x00;
 opMsg.DATA[3] = 0x00;
 opMsg.DATA[4] = 0x00;
 opMsg.DATA[5] = 0x00;
 opMsg.DATA[6] = 0x00;

 switch(IBITListBox->ItemIndex + 1)
   {
   case 1: Message("**Calibration Mode Not implemented!**");
           break;
   case 2: Message("**Firmware Update Mode Not implemented!**");
           break;
   case 3: Message("**CBIT Errors!**");
           opMsg.DATA[0] = 0x03; //Message ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           break;
   case 4: Message("**ETI & Power Cycles!**");
           opMsg.DATA[0] = 0x04; //Message ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           break;
   case 5: Message("**Part Number!**");
           opMsg.DATA[0] = 0x05; //Message ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           break;
   case 6: Message("**Serial Number!**");
           opMsg.DATA[0] = 0x06; //Message ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           break;
   case 7: Message("**Firmware Version!**");
           opMsg.DATA[0] = 0x07; //Message ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           break;
   }
 IBITForm->Visible = false;


}
//---------------------------------------------------------------------------
