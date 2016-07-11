//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GetCurveDataForm.h"
#include "CanBusSDOForm.h"
#include "PCANBasic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TGetCurveForm *GetCurveForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;
//---------------------------------------------------------------------------
__fastcall TGetCurveForm::TGetCurveForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGetCurveForm::GetCurveDataListClick(TObject *Sender)
{
 int curveID;
 opMsg.ID = 0x0E5A0E00 + (address << 12);
 opMsg.LEN = 0x01;

 switch(GetCurveDataList->ItemIndex)
   {
   case 0: opMsg.DATA[0] = 0x00; //Curve ID 0
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  00    [ GET CURVE DATA - ID 0  ]");
		   curveID = 0;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 1: opMsg.DATA[0] = 0x01; //Curve ID 1
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  01    [ GET CURVE DATA - ID 1 ]");
		   curveID = 1;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 2: opMsg.DATA[0] = 0x02; //Curve ID 2
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  02    [ GET CURVE DATA - ID 2 ]");
		   curveID = 2;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 3: opMsg.DATA[0] = 0x03; //Curve ID  3
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  03    [ GET CURVE DATA - ID 3 ]");
		   curveID = 3;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 4: opMsg.DATA[0] = 0x04; //Curve ID  4
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  04    [ GET CURVE DATA - ID 4 ]");
		   curveID = 4;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 5: opMsg.DATA[0] = 0x05; //Curve ID 5
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  05    [ GET CURVE DATA - ID 5 ]");
		   curveID = 5;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 6: opMsg.DATA[0] = 0x06; //Curve ID  6
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  06    [ GET CURVE DATA - ID 6 ]");
		   curveID = 6;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 7: opMsg.DATA[0] = 0x07; //Curve ID 7
		   err = CAN_Write(PCAN_USBBUS1, &opMsg);
		   Message("Rx  0E 5A 0E 00  07    [ GET CURVE DATA - ID 7 ]");
		   curveID = 7;
		   Check_GetCurveDataResponse(curveID);
		   break;
   case 8: GetCurveForm->Visible = false;
		   break;
   }
}
//---------------------------------------------------------------------------
