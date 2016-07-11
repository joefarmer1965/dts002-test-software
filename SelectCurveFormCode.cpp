//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PCANBasic.h"
#include "CanBusSDOForm.h"
#include "SelectCurveFormCode.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TSelectCurveForm *SelectCurveForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
unsigned long timeSent;
//---------------------------------------------------------------------------
__fastcall TSelectCurveForm::TSelectCurveForm(TComponent* Owner)
		: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TSelectCurveForm::SelectCurve4XListBoxClick(TObject *Sender)
{
 int x_curve_id;

 opMsg.ID = 0x0E5A0B00 + (address << 12);     //changed from 0B00 to 0F08
 opMsg.LEN = 0x01;

 switch(SelectCurve4XListBox->ItemIndex)
   {
   case 0: opMsg.DATA[0] = 0x00; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  00    [ SELECT CURVE ID 0 for Azimuth  ]");
		   x_curve_id = 0;
		   break;
   case 1: opMsg.DATA[0] = 0x11; // Changed from 0x10 on the 19/11/15 as per R.F.
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  10    [ SELECT CURVE ID 1 for Azimuth ]");
		   x_curve_id = 1;
		   break;
   case 2: opMsg.DATA[0] = 0x20; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  22    [ SELECT CURVE ID 2 for Azimuth ]");
		   x_curve_id = 2;
		   break;
   case 3: opMsg.DATA[0] = 0x30; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  33    [ SELECT CURVE ID 3 for Azimuth ]");
		   x_curve_id = 3;
		   break;
   case 4: opMsg.DATA[0] = 0x44; //Curve ID //Changed from 0x40 on 19/11/15 as per R.F.
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  44    [ SELECT CURVE ID 4 for Azimuth ]");
		   x_curve_id = 4;
		   break;
   case 5: opMsg.DATA[0] = 0x50; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  55    [ SELECT CURVE ID 5 for Azimuth ]");
		   x_curve_id = 5;
		   break;
   case 6: opMsg.DATA[0] = 0x60; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  66    [ SELECT CURVE ID 6 for Azimuth  ]");
		   x_curve_id = 6;
		   break;
   case 7: opMsg.DATA[0] = 0x070; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  77    [ SELECT CURVE ID 7 for Azimuth ]");
		   x_curve_id = 7;
		   break;
   case 8: opMsg.DATA[0] = 0xFF; //Curve ID  //***Changed from 0xF0 to 0xFF by T.0.
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  FF    [CURVE ID 0xF for Azimuth & Elevation selected]");
		   /* The Default linear curve does not have a version therfore no response expected */
		   break;
   case 9: SelectCurveForm->Visible = false;
		   break;
   }
   // check the response message except for the linear curve (Default)
   if ((SelectCurveForm->Visible == true) && (SelectCurve4XListBox->ItemIndex != 8))
   {
	 /* Check Response Message  */
	 CheckCurveVersionResponse(x_curve_id);
   }
}
//---------------------------------------------------------------------------

void __fastcall TSelectCurveForm::SelectCurve4YListBoxClick(TObject *Sender)
{
 int y_curve_id;

 opMsg.ID = 0x0E5A0B00 + (address << 12);       //changed from 0B00 to 0F08
 opMsg.LEN = 0x01;

 switch(SelectCurve4YListBox->ItemIndex)
   {
   case 0: opMsg.DATA[0] = 0x00; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  00    [ SELECT CURVE ID 0 for Elevation  ]");
		   y_curve_id = 0;
		   break;
   case 1: opMsg.DATA[0] = 0x01; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  01    [ SELECT CURVE ID 1 for Elevation ]");
		   y_curve_id = 1;
		   break;
   case 2: opMsg.DATA[0] = 0x02; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  02    [ SELECT CURVE ID 2 for Elevation ]");
		   y_curve_id = 2;
		   break;
   case 3: opMsg.DATA[0] = 0x03; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  03    [ SELECT CURVE ID 3 for Elevation ]");
		   y_curve_id = 3;
		   break;
   case 4: opMsg.DATA[0] = 0x04; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  04    [ SELECT CURVE ID 4 for Elevation ]");
		   y_curve_id = 4;
		   break;
   case 5: opMsg.DATA[0] = 0x05; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  05    [ SELECT CURVE ID 5 for Elevation ]");
		   y_curve_id = 5;
		   break;
   case 6: opMsg.DATA[0] = 0x06; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  06    [ SELECT CURVE ID 6 for Elevation  ]");
		   y_curve_id = 6;
		   break;
   case 7: opMsg.DATA[0] = 0x007; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  07    [ SELECT CURVE ID 7 for Elevation ]");
		   y_curve_id = 7;
		   break;
   case 8: opMsg.DATA[0] = 0x0F; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0B 00  0F    [ SELECT CURVE ID 0xF for Elevation ]");
		   break;
		   /* The Default linear curve does not have a version therfore no response expected */
   case 9: SelectCurveForm->Visible = false;
		   break;
   }
	// check the response message except for the linear curve (Default)
	if ((SelectCurveForm->Visible == true) && (SelectCurve4YListBox->ItemIndex != 8))
	{
	  /* Check Response Message  */
	  CheckCurveVersionResponse(y_curve_id);
	}
}
//---------------------------------------------------------------------------

