//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartIBITForm.h"
#include "PCANBasic.h"
#include "CanBusSDOForm.h"
# include "IBIT_ManualSwitchTest.h"
# include "IBIT_ManualJoystickTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStartIBIT *StartIBIT;
extern TPCANMsg opMsg;
extern DWORD err;
extern char address;

//---------------------------------------------------------------------------
__fastcall TStartIBIT::TStartIBIT(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStartIBIT::StartIBITListBoxClick(TObject *Sender)
{
  opMsg.ID = 0x0E5A4400 + (address << 12);
  opMsg.LEN = 0x01;

  switch(StartIBITListBox->ItemIndex)
  {

	case 0: opMsg.DATA[0] = 0x01; // IBIT Code ID = 1
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 44 00 01      [ START IBIT Code ID = 1 ]");
			StartIBIT->Visible = false;
			ProcessIBITResponse();
			break;
	case 1: StartIBIT->Visible = false;
			ManIBIT->Visible   = true;
			break;
	case 2: opMsg.DATA[0] = 0x03; // IBIT Code ID = 3
			err = CAN_Write(PCAN_USBBUS1, &opMsg);
			Message("Rx  0E 5A 44 00 03      [ START IBIT Code ID = 3 ]");
			StartIBIT->Visible = false;
			ProcessIBITResponse();
			break;
	case 3: StartIBIT->Visible  = false;
			ManIBITJoy->Visible = true;
			break;
  }

}
//---------------------------------------------------------------------------

