//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetOffsetForm.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOffsetSelectionForm *OffsetSelectionForm;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;

//---------------------------------------------------------------------------
__fastcall TOffsetSelectionForm::TOffsetSelectionForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOffsetSelectionForm::SetAzimuthListBoxClick(TObject *Sender)
{
  /* Azimuth Offset values use Bytes 0 and 1 */
  /* Azimuth Slope values use Byte 4         */

  opMsg.ID = 0x0E5A0C00 + (address << 12);
  opMsg.LEN = 0x06;

  switch(SetAzimuthListBox->ItemIndex)
  {
	case 0: opMsg.DATA[0] = 0x00; // Default AZ Deflection Offset of 0
			opMsg.DATA[1] = 0x00;
			opMsg.DATA[4] = 0x00;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to default (0x0000)");
			Message("Set Azimuth Slope to default (0x00)");
			break;

	case 1: opMsg.DATA[0] = 0xFA; // Default AZ Deflection Offset of 250
			opMsg.DATA[1] = 0x00;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 FA 00 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to default (250)");
			break;

	case 2: opMsg.DATA[0] = 0xF4; // Default AZ Deflection Offset of 500
			opMsg.DATA[1] = 0x01;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 FA 01 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to default (500)");
			break;

	case 3: opMsg.DATA[0] = 0xE8; // Default AZ Deflection Offset of 1000
			opMsg.DATA[1] = 0x03;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 E8 03 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to default (1000)");
			break;

	case 4:	opMsg.DATA[0] = 0xD0; // Default AZ Deflection Offset of 2000
			opMsg.DATA[1] = 0x07;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 D0 07 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to default (2000)");
			break;

	case 5:	opMsg.DATA[0] = 0xB8; // Default AZ Deflection Offset of 3000
			opMsg.DATA[1] = 0x0B;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 B8 0B 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to default (3000)");
			break;

	case 6: opMsg.DATA[0] = 0xA0; // Set AZ Deflection Offset to 4000
			opMsg.DATA[1] = 0x0F;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 A0 0F 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to 4000");
			ProcessOffsetDataResponse();
			break;

	case 7: opMsg.DATA[0] = 0x88; // Set AZ Deflection Offset to 5000
			opMsg.DATA[1] = 0x13;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 88 13 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to 5000");
			ProcessOffsetDataResponse();
			break;

	case 8: opMsg.DATA[0] = 0x70; // Set AZ Deflection Offset to 6000
			opMsg.DATA[1] = 0x17;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 70 17 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to 6000");
			ProcessOffsetDataResponse();
			break;

	case 9: opMsg.DATA[0] = 0x58; // Set AZ Deflection Offset to 7000
			opMsg.DATA[1] = 0x1B;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 58 1B 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to 7000");
			ProcessOffsetDataResponse();
			break;

	case 10: opMsg.DATA[0]= 0x40; // Set AZ Deflection Offset to 8000
			opMsg.DATA[1] = 0x1F;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 40 1F 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to 8000");
			break;

	case 11: opMsg.DATA[0] = 0x60; // Set AZ Deflection Offset to -4000
			opMsg.DATA[1] = 0xF0;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 60 F0 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to -4000");
			break;

	case 12: opMsg.DATA[0] = 0xC0; // Set AZ Deflection Offset to -8000
			opMsg.DATA[1] = 0xE0;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 C0 E0 00 00 FF 00 [ SET AZ OFFSET VALUE ]");
			Message("Set Azimuth Offset to -8000");
			break;

   case 13: opMsg.DATA[0] = 0x28; // Set AZ Deflection Offset to 9000
			opMsg.DATA[1] = 0x23;
			opMsg.DATA[4] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 28 23 00 00 FF 00 [ SET AZ OFFSET OUT OF RANGE VALUE ]");
			Message("Set Azimuth Offset to 9000");
			break;


	case 14: OffsetSelectionForm->Visible = false;
			 break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TOffsetSelectionForm::SetElevationListBoxClick(TObject *Sender)
{
  /* Elevation Offset values use Bytes 2 and 3 */
  /* Elevation Slope values use Byte 5         */

  opMsg.ID = 0x0E5A0C00 + (address << 12);
  opMsg.LEN = 0x06;

  switch(SetElevationListBox->ItemIndex)
  {
	case 0: opMsg.DATA[2] = 0x00; // Default EL Deflection Offset of 0
			opMsg.DATA[3] = 0x00;
			opMsg.DATA[5] = 0x00;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 00 00 00 00 [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to default (0x0000) ");
			Message("Set Elevation Slope to default (0x00) ");
			break;


			////////
	case 1: opMsg.DATA[2] = 0xFA; // Set EL Deflection Offset to 250
			opMsg.DATA[3] = 0x00;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 FA 00 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 250");
			break;

	case 2: opMsg.DATA[2] = 0xF4; // Set EL Deflection Offset to 500
			opMsg.DATA[3] = 0x01;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 F4 01 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 500");
			break;

   case 3: 	opMsg.DATA[2] = 0xE8; // Set EL Deflection Offset to 1000
			opMsg.DATA[3] = 0x03;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 E8 03 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 1000");
			break;

   case 4: 	opMsg.DATA[2] =  0xD0; // Set EL Deflection Offset to 2000
			opMsg.DATA[3] = 0x07;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 D0 07 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 2000");
			break;

   case 5:  opMsg.DATA[2] = 0xB8; // Set EL Deflection Offset to 3000
			opMsg.DATA[3] = 0x0B;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 B8 0B 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 3000");
			break;

	case 6: opMsg.DATA[2] = 0xA0; // Set EL Deflection Offset to 4000
			opMsg.DATA[3] = 0x0F;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 A0 0F 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 4000");
			break;

	case 7: opMsg.DATA[2] = 0x88; // Set EL Deflection Offset to 5000
			opMsg.DATA[3] = 0x13;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 88 13 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 5000");
			break;

	case 8: opMsg.DATA[2] = 0x70; // Set EL Deflection Offset to 6000
			opMsg.DATA[3] = 0x17;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 70 17 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 6000");
			break;


	case 9: opMsg.DATA[2] = 0x58; // Set EL Deflection Offset to 7000
			opMsg.DATA[3] = 0x1B;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 58 1B 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 7000");
			break;

   case 10: opMsg.DATA[2] = 0x40; // Set EL Deflection Offset to 8000
			opMsg.DATA[3] = 0x1F;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 40 1F 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 8000");
			break;

   case 11: opMsg.DATA[2] = 0x60; // Set EL Deflection Offset to -4000
			opMsg.DATA[3] = 0xF0;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 60 F0 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to -4000");
			break;

   case 12: opMsg.DATA[2] = 0xC0; // Set EL Deflection Offset to -8000
			opMsg.DATA[3] = 0xE0;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 C0 E0 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to -8000");
			break;

   case 13: opMsg.DATA[2] = 0x28; // Set EL Deflection Offset to 9000
			opMsg.DATA[3] = 0x23;
			opMsg.DATA[5] = 0xFF;
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 0C 00 00 00 28 23 00 FF [ SET EL OFFSET VALUE ]");
			Message("Set Elevation Offset to 9000 Over Range");
			break;


	case 14: OffsetSelectionForm->Visible = false;
			 break;
  }
}
//---------------------------------------------------------------------------
