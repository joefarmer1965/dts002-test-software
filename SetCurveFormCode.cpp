//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetCurveFormCode.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TSetCurveForm *SetCurveForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern int messFlags;
//---------------------------------------------------------------------------
__fastcall TSetCurveForm::TSetCurveForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSetCurveForm::SelectCurveListBoxClick(TObject *Sender)
{
 int set_curve_id;

 opMsg.ID = 0x0E5A0E00 + (address << 12);
 opMsg.LEN = 0x08;

 switch(SelectCurveListBox->ItemIndex)
   {
   case 0: Message("** my selectcurvelistbox ** ");
		   opMsg.DATA[0] = 0x00; //Curve ID
		   opMsg.DATA[1] = 0x00; //Data Point 0
		   opMsg.DATA[2] = 0x00; //Defelection Angle LSB
		   opMsg.DATA[3] = 0x00; //Defelection Angle MSB
		   opMsg.DATA[4] = 0x00; //Response Curve Out LSB
		   opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x01; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Delay();
		   opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0x66; //Defelection Angle LSB
           opMsg.DATA[3] = 0x66; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0x99; //Defelection Angle LSB
           opMsg.DATA[3] = 0x99; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 0;
		   Message("** Curve 0 Loaded ** ");
		   break;
   case 1: opMsg.DATA[0] = 0x01; //Curve ID
		   opMsg.DATA[1] = 0x00; //Data Point 0
		   opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x11; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Delay();
		   opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0x1E; //Defelection Angle LSB
           opMsg.DATA[3] = 0x05; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0xD6; //Defelection Angle LSB
           opMsg.DATA[3] = 0x63; //Defelection Angle MSB
           opMsg.DATA[4] = 0x11; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0x7F; //Defelection Angle MSB
           opMsg.DATA[4] = 0x18; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
		   opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0x99; //Defelection Angle LSB
           opMsg.DATA[3] = 0x99; //Defelection Angle MSB
           opMsg.DATA[4] = 0x43; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0x32; //Defelection Angle LSB
           opMsg.DATA[3] = 0xB3; //Defelection Angle MSB
           opMsg.DATA[4] = 0x2E; //Response Curve Out LSB
           opMsg.DATA[5] = 0x01; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0xCC; //Defelection Angle LSB
           opMsg.DATA[3] = 0xCC; //Defelection Angle MSB
           opMsg.DATA[4] = 0x51; //Response Curve Out LSB
           opMsg.DATA[5] = 0x04; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0x65; //Defelection Angle LSB
           opMsg.DATA[3] = 0xE6; //Defelection Angle MSB
           opMsg.DATA[4] = 0xC5; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0C; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 1;
           Message("**Curve 1 Loaded**");
           break;
   case 2: opMsg.DATA[0] = 0x02; //Curve ID
           opMsg.DATA[1] = 0x00; //Data Point 0
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x21; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Delay();
		   opMsg.DATA[1] = 0x01; //Data Point 1
		   opMsg.DATA[2] = 0xFE; //Defelection Angle LSB
		   opMsg.DATA[3] = 0x7F; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0x7F; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 2;
           Message("**Curve 2 Loaded**");
           break;
   case 3: opMsg.DATA[0] = 0x03; //Curve ID
           opMsg.DATA[1] = 0x00; //Data Point 0
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x31; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0x1E; //Defelection Angle LSB
           opMsg.DATA[3] = 0x05; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0x66; //Defelection Angle LSB
           opMsg.DATA[3] = 0x26; //Defelection Angle MSB
           opMsg.DATA[4] = 0x47; //Response Curve Out LSB
           opMsg.DATA[5] = 0x01; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0x51; //Defelection Angle LSB
           opMsg.DATA[3] = 0x38; //Defelection Angle MSB
           opMsg.DATA[4] = 0x33; //Response Curve Out LSB
           opMsg.DATA[5] = 0x03; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0xCC; //Defelection Angle LSB
           opMsg.DATA[3] = 0x4C; //Defelection Angle MSB
           opMsg.DATA[4] = 0x66; //Response Curve Out LSB
           opMsg.DATA[5] = 0x06; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0xB7; //Defelection Angle LSB
           opMsg.DATA[3] = 0x5E; //Defelection Angle MSB
           opMsg.DATA[4] = 0x99; //Response Curve Out LSB
           opMsg.DATA[5] = 0x09; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0x84; //Defelection Angle LSB
           opMsg.DATA[3] = 0x6B; //Defelection Angle MSB
           opMsg.DATA[4] = 0xCC; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0C; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0x32; //Defelection Angle LSB
           opMsg.DATA[3] = 0x73; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0xEA; //Defelection Angle LSB
           opMsg.DATA[3] = 0x91; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0x32; //Defelection Angle LSB
           opMsg.DATA[3] = 0xB3; //Defelection Angle MSB
           opMsg.DATA[4] = 0x47; //Response Curve Out LSB
           opMsg.DATA[5] = 0x11; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0x1D; //Defelection Angle LSB
           opMsg.DATA[3] = 0xC5; //Defelection Angle MSB
           opMsg.DATA[4] = 0x32; //Response Curve Out LSB
           opMsg.DATA[5] = 0x13; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0x98; //Defelection Angle LSB
           opMsg.DATA[3] = 0xD9; //Defelection Angle MSB
           opMsg.DATA[4] = 0x65; //Response Curve Out LSB
           opMsg.DATA[5] = 0x16; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0x84; //Defelection Angle LSB
           opMsg.DATA[3] = 0xEB; //Defelection Angle MSB
           opMsg.DATA[4] = 0x98; //Response Curve Out LSB
           opMsg.DATA[5] = 0x19; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0x50; //Defelection Angle LSB
           opMsg.DATA[3] = 0xF8; //Defelection Angle MSB
           opMsg.DATA[4] = 0xCB; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1C; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 3;
           Message("**Curve 3 Loaded**");
           break;
   case 4: opMsg.DATA[0] = 0x04; //Curve ID
           opMsg.DATA[1] = 0x00; //Data Point 0
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x41; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Delay();
           opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0x8F; //Defelection Angle LSB
           opMsg.DATA[3] = 0x02; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0x1E; //Defelection Angle LSB
           opMsg.DATA[3] = 0x05; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0xAE; //Defelection Angle LSB
           opMsg.DATA[3] = 0x07; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0x3D; //Defelection Angle LSB
           opMsg.DATA[3] = 0x0A; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0xCC; //Defelection Angle LSB
           opMsg.DATA[3] = 0x0C; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0x5C; //Defelection Angle LSB
           opMsg.DATA[3] = 0x0F; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0xEB; //Defelection Angle LSB
           opMsg.DATA[3] = 0x11; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0xD6; //Defelection Angle LSB
           opMsg.DATA[3] = 0x23; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0xEC; //Defelection Angle LSB
           opMsg.DATA[3] = 0x63; //Defelection Angle MSB
           opMsg.DATA[4] = 0x11; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0x7F; //Defelection Angle MSB
           opMsg.DATA[4] = 0x18; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0x99; //Defelection Angle LSB
           opMsg.DATA[3] = 0x99; //Defelection Angle MSB
           opMsg.DATA[4] = 0x43; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0x32; //Defelection Angle LSB
           opMsg.DATA[3] = 0xB3; //Defelection Angle MSB
           opMsg.DATA[4] = 0x2E; //Response Curve Out LSB
           opMsg.DATA[5] = 0x01; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0xCC; //Defelection Angle LSB
           opMsg.DATA[3] = 0xCC; //Defelection Angle MSB
           opMsg.DATA[4] = 0x28; //Response Curve Out LSB
           opMsg.DATA[5] = 0x04; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0x65; //Defelection Angle LSB
           opMsg.DATA[3] = 0xE6; //Defelection Angle MSB
           opMsg.DATA[4] = 0x7A; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0C; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 4;
		   Message("**Curve 4 Loaded**");
           break;
   case 5: opMsg.DATA[0] = 0x05; //Curve ID
           opMsg.DATA[1] = 0x00; //Data Point 0
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x51; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Delay();
		   opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x20; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x30; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x40; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x50; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x60; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x70; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x80; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x90; //Defelection Angle MSB
           opMsg.DATA[4] = 0xE8; //Response Curve Out LSB
           opMsg.DATA[5] = 0x03; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xA0; //Defelection Angle MSB
           opMsg.DATA[4] = 0xD0; //Response Curve Out LSB
           opMsg.DATA[5] = 0x07; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xB0; //Defelection Angle MSB
           opMsg.DATA[4] = 0xB8; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0B; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xC0; //Defelection Angle MSB
           opMsg.DATA[4] = 0xA0; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xD0; //Defelection Angle MSB
           opMsg.DATA[4] = 0x88; //Response Curve Out LSB
           opMsg.DATA[5] = 0x13; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xE0; //Defelection Angle MSB
           opMsg.DATA[4] = 0x70; //Response Curve Out LSB
           opMsg.DATA[5] = 0x17; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xF0; //Defelection Angle MSB
           opMsg.DATA[4] = 0x58; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1B; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 5;
           Message("**Curve 5 Loaded**");
           break;
   case 6: opMsg.DATA[0] = 0x06; //Curve ID
           opMsg.DATA[1] = 0x00; //Data Point 0
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x61; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0xEB; //Defelection Angle LSB
           opMsg.DATA[3] = 0x51; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0x7A; //Defelection Angle LSB
           opMsg.DATA[3] = 0x54; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0x65; //Defelection Angle LSB
           opMsg.DATA[3] = 0xA6; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0xF5; //Defelection Angle LSB
           opMsg.DATA[3] = 0xA8; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0E; //Data Point 14
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0F; //Data Point 15
           opMsg.DATA[2] = 0xFF; //Defelection Angle LSB
           opMsg.DATA[3] = 0xFF; //Defelection Angle MSB
           opMsg.DATA[4] = 0xFF; //Response Curve Out LSB
           opMsg.DATA[5] = 0x1F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 6;
           Message("**Curve 6 Loaded**");
           break;
   case 7: opMsg.DATA[0] = 0x05; //Curve ID
           opMsg.DATA[1] = 0x00; //Data Point 0
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x00; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
           opMsg.DATA[6] = 0x01; //Version LSB
		   opMsg.DATA[7] = 0x71; //Version MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Delay();
		   opMsg.DATA[1] = 0x01; //Data Point 1
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x20; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x02; //Data Point 2
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x30; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x03; //Data Point 3
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x40; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x04; //Data Point 4
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x50; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x05; //Data Point 5
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x60; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x06; //Data Point 6
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x70; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x07; //Data Point 7
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x80; //Defelection Angle MSB
           opMsg.DATA[4] = 0x00; //Response Curve Out LSB
           opMsg.DATA[5] = 0x00; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x08; //Data Point 8
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0x90; //Defelection Angle MSB
           opMsg.DATA[4] = 0xE8; //Response Curve Out LSB
           opMsg.DATA[5] = 0x03; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x09; //Data Point 9
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xA0; //Defelection Angle MSB
           opMsg.DATA[4] = 0xD0; //Response Curve Out LSB
           opMsg.DATA[5] = 0x07; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0A; //Data Point 10
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xB0; //Defelection Angle MSB
           opMsg.DATA[4] = 0xB8; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0B; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0B; //Data Point 11
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xC0; //Defelection Angle MSB
           opMsg.DATA[4] = 0xA0; //Response Curve Out LSB
           opMsg.DATA[5] = 0x0F; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0C; //Data Point 12
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xD0; //Defelection Angle MSB
           opMsg.DATA[4] = 0x88; //Response Curve Out LSB
           opMsg.DATA[5] = 0x13; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
           Delay();
           opMsg.DATA[1] = 0x0D; //Data Point 13
           opMsg.DATA[2] = 0x00; //Defelection Angle LSB
           opMsg.DATA[3] = 0xE0; //Defelection Angle MSB
           opMsg.DATA[4] = 0x70; //Response Curve Out LSB
           opMsg.DATA[5] = 0x17; //Response Curve Out MSB
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   set_curve_id = 7;
		   Message("** Incomplete Curve Loaded - 2 Data Points Missing **");
		   break;
   case 8: SetCurveForm->Visible = false;
		   break;
   }

   if (SetCurveForm->Visible == true)
   {
	 /* Check Response Message  */
	 CheckCurveVersionResponse(set_curve_id);
   }

}
//---------------------------------------------------------------------------


