//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PCANBasic.h"
#include "CanBusSDOForm.h"
#include "CurveVersionSelect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TCurveVersionForm *CurveVersionForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
extern int messFlags;
//---------------------------------------------------------------------------
__fastcall TCurveVersionForm::TCurveVersionForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCurveVersionForm::SelectCurveListBoxClick(TObject *Sender)
{
 int curve_ver;

 opMsg.ID = 0x0E5A0F00 + (address << 12);
 opMsg.LEN = 0x01;

 switch(SelectCurveListBox->ItemIndex)
   {
   case 0: opMsg.DATA[0] = 0x00; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  00     [ GET CURVE VERSION - ID 0  ]");
		   curve_ver = 0;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 1: opMsg.DATA[0] = 0x01; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  01     [ GET CURVE VERSION - ID 1 ]");
		   curve_ver = 1;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 2: opMsg.DATA[0] = 0x02; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  02     [ GET CURVE VERSION - ID 2 ]");
		   curve_ver = 2;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 3: opMsg.DATA[0] = 0x03; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  03     [ GET CURVE VERSION - ID 3 ]");
		   curve_ver = 3;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 4: opMsg.DATA[0] = 0x04; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  04     [ GET CURVE VERSION - ID 4 ]");
		   curve_ver = 4;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 5: opMsg.DATA[0] = 0x05; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  05     [ GET CURVE VERSION - ID 5 ]");
		   curve_ver = 5;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 6: opMsg.DATA[0] = 0x06; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  06     [ GET CURVE VERSION - ID 6 ]");
		   curve_ver = 6;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 7: opMsg.DATA[0] = 0x07; //Curve ID
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0F 00  07     [ GET CURVE VERSION - ID 7 ]");
		   curve_ver = 7;
		   CheckCurveVersionResponse(curve_ver);
		   break;
   case 8: CurveVersionForm->Visible = false;
		   break;
   }
}
//---------------------------------------------------------------------------


