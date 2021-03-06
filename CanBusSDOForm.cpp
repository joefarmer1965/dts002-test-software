/*********************************************************************
 *
 *               DP414-3 & DG1236-3 Test Software V1.15
 *
 *********************************************************************
 * FileName:        	CanBusSDOForm.c
 * Dependencies:    	See INCLUDES section below
 * Processor:       	Cortex M3
 * Original Compiler:   C++Builder XE6 (used on Version 1.00)
 * Latest Compliler:	C++ Builder 10 Seattle

 * Company:         	For Daco Scientific Ltd.
 *
  Software License Agreement
*
* The software supplied herewith by Daco Scientific Ltd
* (the �Company�)  is intended and supplied to you, the Company�s
* customer, for use solely and exclusively on Daco Scientific
* minature joystick products. The software is owned by the Company and is
* protected under applicable copyright laws. All rights are reserved.
* Any use in violation of the foregoing restrictions may subject the
* user to criminal sanctions under applicable laws, as well as to
* civil liability for the breach of the terms and conditions of this
* license.
*
* THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
*
*
*
* Author              Date          Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Geoff Murray      08/07/15        V1.00 Original.
* Tony Oates 		11/11/15 		V1.10 Updates & Amendments
* Tony Oates 		19/11/15 		V1.11 Ammendments Ref CCN7994
* Tony Oates        23/11/15        V1.12 Amendments Ref CCN7998
* Tony Oates 		27/11/15		V1.14 Amendments Ref CCN8006
* Tony Oates 		18/01/16 		[V1.15] Amendment Ref. Log Book
* Tony Oates 		19/01/16		[V1.15] Amendment Ref Weekly log 19/01/16
* Tony Oates 		29/01/16		[V.15] Amendment Ref: Notes
*
*
* ********************************************************************/

 //---------------------------------------------------------------------------

#include <vcl.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include "windows.h"
#pragma hdrstop

#include "CanBusSDOForm.h"
#include "PCANBasic.h"
#include "PBITStatus.h"
#include "CBITStatus.h"
#include "IBITStatus.h"
#include "SetCurveFormCode.h"
#include "GetCurveDataForm.h"
#include "SelectCurveFormCode.h"
#include "CurveVersionSelect.h"
#include "SetTimingForm.h"
#include "SetOffsetForm.h"
#include "SetMaxValueForm.h"
#include "StartIBITForm.h"
#include "StopIBITForm.h"
#include "GetConfigForm.h"
#include "CheckCurveDataForm.h"
#include "TestEnvironmentSelectForm.h"
#include "time.h"
#include "stdio.h"
#include "string.h"
#include <fstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma comment (lib, "winmm.lib")

TCanBusForm *CanBusForm;
TPCANMsg rcvMsg;
TPCANMsg opMsg;
TPCANTimestamp timestamp;

unsigned long SWTimeDiff;
unsigned long SWNowTime;
unsigned long SWPrevTime;
unsigned long DataTimeDiff;
unsigned long DataNowTime;
unsigned long DataPrevTime;


DWORD err; //errors

DWORD dataMessPeriod,      //message addresses
	dataMessReq,
	switchMess,
	ModeErrorMess,
	ModeStatusMess,
	PBITMess,
	CBITMess,
	IBITMess,
	TimingMess,
	CurveVersionMess,
	CurveDataMess,
	MaxValMess,
	OffsetValMess,
	RawDefDataMess,
	ConfigDataMess;

unsigned int  syncNo    = 0,
			  dataCount = 0,
			  messCount = 0,
			  SWCount   = 0; // counters

int i = 0;  // counter

int switch0   = 0x00,
	switch3   = 0x00,
	switch4   = 0x00,
	XBar      = 8192,
	YBar      = 8192;

int	X_DeflectionDataStore = 0x00,
	Y_DeflectionDataStore = 0x00,
	X_NegAxis_DeflectionDataStore = 0x00,
	Y_NegAxis_DeflectionDataStore = 0x00;


	char address, HUMSLen;
	unsigned char hexString[9], HUMS[21];
	char hex[16] ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	// Version data  - DLC 8
	//  Byte 0  Curve ID - Azimuth
	//  Byte 1  Major Version No
	//  Byte 2  Minor Version No / Revision No
	//  Byte 3  Status
	//  Byte 4  Curve ID - Elevation
	//  Byte 5  Major Version No
	//  Byte 6  Minor Version No / Revision No
	//  Byte 7  Status

  int VersionData[8][8] = {{0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01},     // Curve Version for Code ID 0
						   {0x01, 0x01, 0x11, 0x01, 0x01, 0x01, 0x11, 0x01},     // Curve Version for Code ID 1
						   {0x02, 0x01, 0x21, 0x01, 0x02, 0x01, 0x21, 0x01},     // Curve Version for Code ID 2
						   {0x03, 0x01, 0x31, 0x01, 0x03, 0x01, 0x31, 0x01},     // Curve Version for Code ID 3
						   {0x04, 0x01, 0x41, 0x01, 0x04, 0x01, 0x41, 0x01},     // Curve Version for Code ID 4
						   {0x05, 0x01, 0x51, 0x01, 0x05, 0x01, 0x51, 0x01},     // Curve Version for Code ID 5
						   {0x06, 0x01, 0x61, 0x01, 0x06, 0x01, 0x61, 0x01},     // Curve Version for Code ID 6
						   {0x07, 0x01, 0x71, 0xFF, 0x07, 0x01, 0x71, 0xFF}};    // Curve Version for Code ID 7
 bool VersionDataGood;
 bool IBIT_AllCodesRequest = false;
 bool PBIT_AllCodesRequest = false;
 bool CBIT_AllCodesRequest = false;
 bool StartCANBusLoading = true;

  // part number  P1236-3
  const byte part_number1 [7]  = {0x50, 0x31, 0x32, 0x33, 0x36, 0x2D, 0x33};
  // part number  P414-3 (null)
  const byte part_number2 [7]  = {0x50, 0x34, 0x31, 0x34, 0x2D, 0x33, 0x00};
  // Serial number 999999 (null)
  const byte serial_number [7] = {0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x00};
  //Software Version V01-10 (null)
  const byte S_W_Version [7]   = {0x56, 0x30, 0x31, 0x2D, 0x31, 0x30, 0x00};

  /* Global variables for controller selection - this is for switch selection */
  bool DP414_Selected  = false;
  bool DP1236_Selected = false;
  bool InConfigMode = false;
  bool ModeRequest = false;





// CMI supplied Curve Data for curve 4
// CurveID, Data Point, Def Angle LSB, Def Angle MSB, Response Curve out LSB,
// Response Curve out MSB, Version LSB, Version MSB
//            0      1     2     3     4     5     6     7
const byte CurveData_4 [16][8] = {
		   { 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x01, 0x8F, 0x02, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x02, 0x1E, 0x05, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x03, 0xAE, 0x07, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x04, 0x3D, 0x0A, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x05, 0xCC, 0x0C, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x06, 0x5C, 0x0F, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x07, 0xEB, 0x11, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x08, 0xD6, 0x23, 0x00, 0x00, 0x01, 0x41},
		   { 0x04, 0x09, 0xEC, 0x63, 0x11, 0x00, 0x01, 0x41},
		   { 0x04, 0x0A, 0xFF, 0x7F, 0x18, 0x00, 0x01, 0x41},
		   { 0x04, 0x0B, 0x99, 0x99, 0x43, 0x00, 0x01, 0x41},
		   { 0x04, 0x0C, 0x32, 0xB3, 0x2E, 0x01, 0x01, 0x41},
		   { 0x04, 0x0D, 0xCC, 0xCC, 0x28, 0x04, 0x01, 0x41},
		   { 0x04, 0x0E, 0x65, 0xE6, 0x7A, 0x0C, 0x01, 0x41},
		   { 0x04, 0x0F, 0xFF, 0xFF, 0xFF, 0x1F, 0x01, 0x41}};

// CMI supplied Curve Data for CURVE 5
// CurveID, Data Point, Def Angle LSB, Def Angle MSB, Response Curve out LSB,
// Response Curve out MSB, Version LSB, Version MSB
//            0      1     2     3     4     5     6     7
const byte CurveData_5 [16][8] = {
		   { 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x01, 0x00, 0x20, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x02, 0x00, 0x30, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x03, 0x00, 0x40, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x04, 0x00, 0x50, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x05, 0x00, 0x60, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x06, 0x00, 0x70, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x07, 0x00, 0x80, 0x00, 0x00, 0x01, 0x51},
		   { 0x05, 0x08, 0x00, 0x90, 0xE8, 0x03, 0x01, 0x51},
		   { 0x05, 0x09, 0x00, 0xA0, 0xD0, 0x07, 0x01, 0x51},
		   { 0x05, 0x0A, 0x00, 0xB0, 0xB8, 0x0B, 0x01, 0x51},
		   { 0x05, 0x0B, 0x00, 0xC0, 0xA0, 0x0F, 0x01, 0x51},
		   { 0x05, 0x0C, 0x00, 0xD0, 0x88, 0x13, 0x01, 0x51},
		   { 0x05, 0x0D, 0x00, 0xE0, 0x70, 0x17, 0x01, 0x51},
		   { 0x05, 0x0E, 0x00, 0xF0, 0x58, 0x1B, 0x01, 0x51},
		   { 0x05, 0x0F, 0xFF, 0xFF, 0xFF, 0x1F, 0x01, 0x51}};

//---------------------------------------------------------------------------

__fastcall TCanBusForm::TCanBusForm(TComponent* Owner)
		: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::FormCreate(TObject *Sender)
{
	// can message data
	opMsg.ID      = 0x0E5A0000;
	opMsg.MSGTYPE = PCAN_MESSAGE_EXTENDED; // 29-bit ID
	opMsg.LEN     = 0x02;
	opMsg.DATA[0] = 0x00;
	opMsg.DATA[1] = 0x00;

	Reset();
	err = CAN_Initialize(PCAN_USBBUS1,PCAN_BAUD_1M);
	if(err != 0)
	{
		Message("Cannot open CAN interface.");
	}

	// set addresses
	address = AddressComboBox->ItemIndex;
	dataMessPeriod   = 0x0A5A41C0 + address;
	dataMessReq      = 0x0E5A81C0 + address;
	switchMess       = 0x0E5A82C0 + address;
	ModeErrorMess    = 0x0E5A84C0 + address;
	ModeStatusMess   = 0x0E5A85C0 + address;
	PBITMess         = 0x0E5A86C0 + address;
	CBITMess         = 0x0E5A87C0 + address;
	IBITMess         = 0x0E5A88C0 + address;
	TimingMess       = 0x0E5A89C0 + address;
	CurveVersionMess = 0x0E5A8FC0 + address;
	CurveDataMess    = 0x0E5A8EC0 + address;
	MaxValMess       = 0x0E5A8DC0 + address;
	OffsetValMess    = 0x0E5A8CC0 + address;
	RawDefDataMess   = 0x0E5AC2C0 + address;
	ConfigDataMess   = 0x0E5AC3C0 + address;

	// Setting Axes graphics box size as there is a problem with height/width attributes
	CanBusForm->XBarBox->Height = 25;
	CanBusForm->YBarBox->Height = 25;
	CanBusForm->XBarBox->Width = 401;
	CanBusForm->YBarBox->Width = 401;

}

//---------------------------------------------------------------------------

void __fastcall TCanBusForm::SelectEnvironClick(TObject *Sender)
{

  TestEnvironmentSelect->Visible = true;
  TestEnvironmentSelect->BringToFront();

}

//---------------------------------------------------------------------------

void __fastcall TCanBusForm::StartNodeButtonClick(TObject *Sender)
{
	time_t t;
	Reset();

	// Send a "Start" node message on the CAN Bus
	opMsg.ID = 0x0E5A0000 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg );

	CanBusForm->PassFailPanel->Color      = clBtnFace;
	CanBusForm->PassFailPanel->Caption    = "STARTING";
	CanBusForm->PassFailPanel->BevelOuter = bvNone;
	Update();
	Message("Rx  0E 5A 00 00 00      [ START ]");

	t = time(NULL) + 4;

	err = PCAN_ERROR_QRCVEMPTY;

	// Poll the CAN Bus for the response message and time it
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
		if(rcvMsg.ID == 0x01) //Discard spurious message
		err = PCAN_ERROR_QRCVEMPTY;
	}
	if (err == PCAN_ERROR_OK)   // We have a message
	{
	  messCount++;
	  DisplayMess();

		// Check the Mode Status that we have transitioned into 'Operational' Mode
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x02)
		{
		  CanBusForm->PassFailPanel->Color      = clBtnFace;
		  CanBusForm->PassFailPanel->Caption    = "OPERATIONAL MODE";
		  CanBusForm->PassFailPanel->BevelOuter = bvNone;
		  AddressComboBox->Enabled = false;

		  Message("Tx  0E 5A 85 C0 02      [ MODE STATUS - Operational ]");
		}
		// Start button has been pressed while in Config Mode hence a Mode Error is reported
		else if (rcvMsg.ID == ModeErrorMess && rcvMsg.DATA[0] == 0x23)
		{
		  Message("Tx  0E 5A 84 C0 23      [ MODE ERROR ]");
		}
	}
	else
	{
		// No Valid reply or timed out.
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}

//---------------------------------------------------------------------------

void __fastcall TCanBusForm::StopButtonClick(TObject *Sender)
{
	time_t t;
	Reset();

	CanBusForm->SwitchTime->Text = 0;
	CanBusForm->DataTime->Text = 0;
	// Send a "Stop" node message on the CAN Bus
	opMsg.ID = 0x0E5A0100 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	CanBusForm->PassFailPanel->Color = clBtnFace;
	CanBusForm->PassFailPanel->Caption = "STOPPING";
	CanBusForm->PassFailPanel->BevelOuter = bvNone;
	Update();

	Message("Rx  0E 5A 01 00 00      [ STOP ]");

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// Poll the CAN Bus for the response message and time it
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))

		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();
		// check message is Mode Status
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x01)
		{
			CanBusForm->PassFailPanel->Caption = "IDLE MODE";
			AddressComboBox->Enabled = true;
			Message("Tx  0E 5A 85 C0 01      [ MODE STATUS - Idle ]");
		}
		// Stop button has been pressed while in Config Mode
		else if (rcvMsg.ID == ModeErrorMess && rcvMsg.DATA[0] == 0x13)
		{
			Message("Tx  0E 5A 84 C0 13      [ MODE ERROR ]");
		}
	}
	else
	{
		// No Valid reply or timed out.
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::ResetNodeButtonClick(TObject *Sender)
{
	time_t t;
	Reset();
	CanBusForm->DataTime->Text = 0;
	CanBusForm->SwitchTime->Text = 0;

	opMsg.ID = 0x0E5A0400 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	CanBusForm->PassFailPanel->Color = clBtnFace;
	CanBusForm->PassFailPanel->Caption = "RESETING";
	CanBusForm->PassFailPanel->BevelOuter = bvNone;
	Update();
	Message("Rx  0E 5A 04 00 00      [ RESET ]");

	t = time(NULL) + 4;

	err = PCAN_ERROR_QRCVEMPTY;
	while(((err == PCAN_ERROR_QRCVEMPTY) ||
		   (rcvMsg.ID == dataMessPeriod) ||
		   (rcvMsg.ID == switchMess))&&
		   (t > time(NULL))) // if no messages loop)

		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();
		// check mode
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x01)
		{
			CanBusForm->PassFailPanel->Caption = "IDLE MODE";
			AddressComboBox->Enabled = true;
			Message("Tx  0E 5A 85 C0 01      [ MODE STATUS - Idle ]");
		}
		else
		{
			Message("Node not stopped!");
			MessageInt("Message ID is ", rcvMsg.ID);
		}
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::EnterConfigClick(TObject *Sender)
{
	time_t t;
	Reset();
	opMsg.ID = 0x0E5A0200 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	CanBusForm->PassFailPanel->Color = clBtnFace;
	CanBusForm->PassFailPanel->Caption = "ENTERING CONFIG MODE";
	CanBusForm->PassFailPanel->BevelOuter = bvNone;
	Update();
	Message("Rx  0E 5A 02 00 00      [ ENTER CONFIG ]");
	// set global flag to true
	InConfigMode = true;

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;
	while(((err == PCAN_ERROR_QRCVEMPTY)||
		   (rcvMsg.ID == dataMessPeriod)||
		   (rcvMsg.ID == switchMess))&&
		   (t > time(NULL))) // if no messages loop

		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();
		// check mode
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x03)
		{
			CanBusForm->PassFailPanel->Caption = "CONFIG MODE";
			Update();
			Message("Tx  0E 5A 85 C0 03      [ MODE STATUS - Config Mode ]");
		}
		// Attempt to Enter Config button when in Operational Mode
		else if (rcvMsg.ID == ModeErrorMess && rcvMsg.DATA[0] == 0x32)
		{
			Message("Tx  0E 5A 84 C0 32      [ MODE ERROR ]");
		}
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}

//---------------------------------------------------------------------------

void __fastcall TCanBusForm::ExitConfigButtonClick(TObject *Sender)
{
	time_t t;
	Reset();
	opMsg.ID = 0x0E5A0300 + (address << 12);
	opMsg.LEN = 0x00;

	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	CanBusForm->PassFailPanel->Color = clBtnFace;
	CanBusForm->PassFailPanel->Caption = "Stopping";
	CanBusForm->PassFailPanel->BevelOuter = bvNone;
	Update();
	Message("Rx  0E 5A 03 00 00      [ EXIT CONFIG ]");

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))

		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();
		// check mode
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x01)
		{
			CanBusForm->PassFailPanel->Caption = "IDLE MODE";
			Message("Tx  0E 5A 85 C0 01      [ MODE STATUS - Idle ]");
		}
		// Exit Config button pressed when in Operational mode
		else if (rcvMsg.ID == ModeErrorMess && rcvMsg.DATA[0] == 0x12)
		{
			Message("Tx  0E 5A 84 C0 12      [ MODE ERROR ]");
			CanBusForm->PassFailPanel->Caption = "Operational";
		}
		// Exit Config button pressed when in Idle mode
		else if (rcvMsg.ID == ModeErrorMess && rcvMsg.DATA[0] == 0xF1)
		{
			Message("Tx  0E 5A 84 C0 F1      [ MODE ERROR ]");
			CanBusForm->PassFailPanel->Caption = "Idle";
		}
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::PBITButtonClick(TObject *Sender)
{
	PBITCodeSelect->Visible = true;
	PBITCodeSelect->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::CBITButtonClick(TObject *Sender)
{
	CBITCodeSelect->Visible = true;
	CBITCodeSelect->BringToFront();
}
 //---------------------------------------------------------------------------

void __fastcall TCanBusForm::IBITButtonClick(TObject *Sender)
{
	IBITCodeSelect->Visible = true;
	IBITCodeSelect->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::ModeButtonClick(TObject *Sender)
{
	time_t t;
	Reset();
	opMsg.ID = 0x0E5A0500 + (address << 12);
	opMsg.LEN = 0x00;

	err = CAN_Write(PCAN_USBBUS1, &opMsg);
	Message("Rx  0E 5A 05 00 00      [ MODE REQUEST ]");
	// set global flag to true
	ModeRequest = true;

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
	}
	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();

		// Check Mode Status
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x00)
		{
			Message("Tx  0E 5A 85 C0 00      [ MODE STATUS - Init in Progress ]");
		}
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x01)
		{
			Message("Tx  0E 5A 85 C0 01      [ MODE STATUS - Idle ]");
		}
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x02)
		{
			Message("Tx  0E 5A 85 C0 02      [ MODE STATUS - Operational ]");
		}
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x03)
		{
			Message("Tx  0E 5A 85 C0 03      [ MODE STATUS - Config Mode ]");
		}
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x0E)
		{
			Message("Tx  0E 5A 85 C0 0E      [ MODE STATUS - Invalid Command ]");
		}
		if(rcvMsg.ID == ModeStatusMess && rcvMsg.DATA[0] == 0x0F)
		{
			Message("Tx  0E 5A 85 C0 0F      [ MODE STATUS - Error ]");
		}
		ModeRequest = false;
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::DataRequestButtonClick(TObject *Sender)
{
	time_t t;
	byte Byte_0;
	byte Byte_1;
	byte Byte_2;
	byte Byte_3;

	Reset();
	opMsg.ID = 0x0E5A0A00 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	Message("Rx  0E 5A 0A 00 00      [ DEFL DATA REQUEST ]");

	t = time(NULL) + 2;


	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
	}

	// Check response message is the correct one
	if (err == PCAN_ERROR_OK )
	{
		messCount++;
		DisplayMess();

	   if (rcvMsg.ID == dataMessReq)
	   {
		  Byte_0 = rcvMsg.DATA[0];
		  Byte_1 = rcvMsg.DATA[1];
		  Byte_2 = rcvMsg.DATA[2];
		  Byte_3 = rcvMsg.DATA[3];

		  // DISPLAY THE DATA RECEIVED.
		  MessageData("Tx  0E 5A 81 C0 ", Byte_0, Byte_1, Byte_2, Byte_3);
	   }
	   else
	   {
		  Message("Not a Deflection Data response messsage");
	   }
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::RawDataButtonClick(TObject *Sender)
{
	time_t t;

	byte Byte_0;
	byte Byte_1;
	byte Byte_2;
	byte Byte_3;

	float Float_FactorValue = (4.9/65536);

	int X_RawData16Bit;
	int X_VoltageInteger = 0;
	float Float_X_RawData16Bit;
	float X_VoltageFraction = 0;

	int Y_RawData16Bit;
	int Y_VoltageInteger = 0;
	float Float_Y_RawData16Bit;
	float Y_VoltageFraction = 0;



	Reset();

	opMsg.ID = 0x0E5A4200 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	Update();
	Message("Rx  0E 5A 42 00 00      [ RAW DATA REQUEST ]");

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))

		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();
		// check mode
		if(rcvMsg.ID == RawDefDataMess)
		{
			Byte_0 = rcvMsg.DATA[0];
			Byte_1 = rcvMsg.DATA[1];
			Byte_2 = rcvMsg.DATA[2];
			Byte_3 = rcvMsg.DATA[3];

			// DISPLAY THE DATA RECEIVED.
			MessageData("Tx  0E 5A 81 C0:  ", Byte_0, Byte_1, Byte_2, Byte_3);
			//**Process Voltage Reading for the X-Axis**

			X_RawData16Bit = (int)rcvMsg.DATA[1];
			X_RawData16Bit = (X_RawData16Bit << 8) + (int)rcvMsg.DATA[0];
			X_RawData16Bit = X_RawData16Bit;

			Float_X_RawData16Bit = (Float_FactorValue * X_RawData16Bit);
			X_VoltageInteger = Float_X_RawData16Bit;
			X_VoltageFraction = (Float_X_RawData16Bit - X_VoltageInteger);
			X_VoltageFraction = X_VoltageFraction * 100;

			MessageInt2("Raw Data Conversion for the X-Axis is: ",X_VoltageInteger, ".",X_VoltageFraction,"V");

				//**Process Voltage Reading for the Y-Axis**

			Y_RawData16Bit = (int)rcvMsg.DATA[3];
			Y_RawData16Bit = (Y_RawData16Bit << 8) + (int)rcvMsg.DATA[2];
			Y_RawData16Bit =  Y_RawData16Bit;

			Float_Y_RawData16Bit = (Float_FactorValue * Y_RawData16Bit);
			Y_VoltageInteger = Float_Y_RawData16Bit;
			Y_VoltageFraction = (Float_Y_RawData16Bit - Y_VoltageInteger);
			Y_VoltageFraction = Y_VoltageFraction * 100;

			MessageInt2("Raw Data Conversion for the Y-Axis is: ",Y_VoltageInteger, ".",Y_VoltageFraction,"V");


			Y_RawData16Bit = (int)rcvMsg.DATA[3];
			Y_RawData16Bit = (Y_RawData16Bit << 8) + (int)rcvMsg.DATA[2];
			Y_RawData16Bit = Y_RawData16Bit;


		}
		// MODE ERROR
		else if (rcvMsg.ID == ModeErrorMess)
		{
		  Message("Tx  0E 5A 84 C0 F2      [ MODE ERROR ]");
		}
		else
		{
		  Message("Not a Raw Data response messsage");
		}

	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::SetTimingButtonClick(TObject *Sender)
{
	TimingForm->Visible = true;
	TimingForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::GetTimingButtonClick(TObject *Sender)
{
	time_t t;

	opMsg.ID = 0x0E5A0900 + (address << 12);
	opMsg.LEN = 0x00;
	err = CAN_Write(PCAN_USBBUS1, &opMsg);

	Update();
	Message("Rx  0E 5A 09 00         [ GET TIMING PARAMETERS ]");

	ProcessTimingResponse();

}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::SetCurveDataButtonClick(TObject *Sender)
{
	SetCurveForm->Visible = true;
	SetCurveForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::GetCurveButtonClick(TObject *Sender)
{
	GetCurveForm->Visible = true;
	GetCurveForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::SelectCurveButtonClick(TObject *Sender)
{
	SelectCurveForm->Visible = true;
	SelectCurveForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::RequestCurveVerButtonClick(TObject *Sender)
{
	CurveVersionForm->Visible = true;
	CurveVersionForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::SetOffsetButtonClick(TObject *Sender)
{
	OffsetSelectionForm->Visible = true;
	OffsetSelectionForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::GetOffsetButtonClick(TObject *Sender)
{
  time_t t;
  int byte_0;
  int byte_1;
  int byte_2;
  int byte_3;
  int byte_4;
  int byte_5;

  opMsg.ID = 0x0E5A0C00 + (address << 12);
  opMsg.LEN = 0x00;

  err = CAN_Write(PCAN_USBBUS1, &opMsg);
  Update();
  Message("Rx  0E 5A 0C 00 00      [ GET OFFSET VALUES ]");

  ProcessOffsetDataResponse( );
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::CheckCurveButtonClick(TObject *Sender)
{

	CheckCurveForm->Visible = true;
	CheckCurveForm->BringToFront();

}
//---------------------------------------------------------------------------
void __fastcall TCanBusForm::SetMaxButtonClick(TObject *Sender)
{
	SetMaxValuesForm->Visible = true;
	SetCurveForm->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::GetMaxValButtonClick(TObject *Sender)
{

  opMsg.ID = 0x0E5A0D00 + (address << 12);
  opMsg.LEN = 0x00;

  err = CAN_Write(PCAN_USBBUS1, &opMsg);
  Update();
  Message("Rx  0E 5A 0D 00 00      [ GET MAX VALUES ]");

  // Process max value response
   ProcessMaxValueResponse ( );
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::GetConfigButtonClick(TObject *Sender)
{
	GetConfig->Visible = true;
	GetConfig->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::StartIBITButtonClick(TObject *Sender)
{

	StartIBIT->Visible = true;
	StartIBIT->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::StopIBITButtonClick(TObject *Sender)
{
	StopIBIT->Visible = true;
	StopIBIT->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::QuitButtonClick(TObject *Sender)
{
	CanBusForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	err = CAN_Uninitialize(PCAN_USBBUS1);
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::ControllerComboBoxChange(TObject *Sender)
{
  if (	ControllerComboBox->ItemIndex == 0 )
  {
	   CanBusForm->SwitchPanelLeft->Visible = True; //**MY ADDITION**


	 if (DP1236_Selected == true)
	 {


	   Message("DP1236 has already been selected, to change: restart Application");


	 }
	 else
	 {
	   // Set controller variable to DP414 selected
	   DP414_Selected = true;
	   DP1236_Selected = false;
	   Message("CONTROLLER INTERNAL VARIABLE SET TO DP414");

	   CanBusForm->SwitchPanelLeft->Visible = True; //**MY ADDITION**
	 }
  }
  else if (ControllerComboBox->ItemIndex == 1)
  {

   CanBusForm->SwitchPanelLeft->Visible = False; //**MY ADDITION**

	 if (DP414_Selected == true)
	 {
	   Message("DP414 has already been selected, to change: restart Application");
	 }
	 else
	 {
	   // Set controller variable to DP1236 selected


	   DP414_Selected = false;
	   DP1236_Selected = true;
	   Message("CONTROLLER INTERNAL VARIABLE SET TO DP1236");


	 }
  }
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::ClearMessButtonClick(TObject *Sender)
{
	Messages->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::XBarBoxPaint(TObject *Sender)
{
	int boxWidth  = XBarBox->Width  - 1;
	int boxHeight = XBarBox->Height - 1;

	CanBusForm->XBarBox->Canvas->Pen->Width = 1;
	XBarBox->Canvas->Pen->Color = clBlack;
	XBarBox->Canvas->MoveTo(0, 0);
	XBarBox->Canvas->LineTo(boxWidth, 0);
	XBarBox->Canvas->LineTo(boxWidth, boxHeight);
	XBarBox->Canvas->LineTo(0, boxHeight);
	XBarBox->Canvas->LineTo(0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::YBarBoxPaint(TObject *Sender)
{
	int boxWidth  = YBarBox->Width  - 1;
	int boxHeight = YBarBox->Height - 1;

	CanBusForm->YBarBox->Canvas->Pen->Width = 1;
	YBarBox->Canvas->Pen->Color = clBlack;
	YBarBox->Canvas->MoveTo(0, 0);
	YBarBox->Canvas->LineTo(boxWidth, 0);
	YBarBox->Canvas->LineTo(boxWidth, boxHeight);
	YBarBox->Canvas->LineTo(0, boxHeight);
	YBarBox->Canvas->LineTo(0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::SyncTimerTimer(TObject *Sender)
{
	char i;

	SyncTimer->Enabled = false;

	err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK )
	{
		// Get the CAN Timestamp
		DataNowTime = timestamp.millis;
		SWNowTime   = timestamp.millis;

		// check vaild messages
		switch((rcvMsg.ID & 0x0000FF00) >> 8)
		{
			// DEFLECTION DATA (automatic)  DDUT timeout
			case 0x41: if ((DataNowTime > DataPrevTime) && (DataPrevTime != 0))
					   {
						 DataTimeDiff =  (DataNowTime - DataPrevTime);
						 DisplayDataTime(DataTimeDiff);
					   }
						dataCount++;   // increment count on each data message
						DisplayData(); // Deflection Data (automatic)
						AxesGraphics();
						MaxDeflectionGraphics(); // Max/Min Deflection Graphics
						if(rcvMsg.ID != dataMessPeriod)
							Message("Invalid Data ID!");
						/*copy now time into prev    */
						DataPrevTime = DataNowTime;
						break;
			// SWITCH STATUS (automatic)  SSTO Timeout
			case 0x82: if ((SWNowTime > SWPrevTime) && (SWPrevTime != 0))
					   {
						 SWTimeDiff =  (SWNowTime - SWPrevTime);
						 DisplaySwitchTime(SWTimeDiff);
					   }
						SWCount++;
						DisplaySwitches();

						  if (((TestEnvironmentSelect->TestEnvironmentListBox->ItemIndex + 1 == EMC)|
						  (TestEnvironmentSelect->TestEnvironmentListBox->ItemIndex + 1 == SVT) |
						  (TestEnvironmentSelect->TestEnvironmentListBox->ItemIndex + 1 == LTV))){

						  SwitchGraphicsESS();

						  }else  {

						 SwitchGraphics(); // Switch Status
						 }

						if(rcvMsg.ID != switchMess)
							Message("Invalid Switch ID!");
						/*copy sw_now time into sw_prev    */
						SWPrevTime = SWNowTime;
						break;
		   case 0x8C:   ProcessOffsetDataResponse();
						break;
		   case 0x8D:   ProcessMaxValueResponse();
						break;
		   case 0xC3:   
						if ((TestEnvironmentSelect->TestEnvironmentListBox->ItemIndex + 1 == CAL) ||
						(TestEnvironmentSelect->TestEnvironmentListBox->ItemIndex + 1 == FAT)){

						ProcessConfigDataResponse_CAL();

						} else

							{ProcessConfigDataResponse();}

						break;

		   case 0x84:  Message("Tx  0E 5A 84 C0 F1      [ MODE ERROR ]");
						break;
		   case 0x85:  // trap when the software forceably exits Config Mode due to time out (2mins)
					   // and sends a MODE STATUS message
					  if ((InConfigMode == true) && (ModeRequest == false))
					   {
						  // Reset Status back to idle
						  CanBusForm->PassFailPanel->Caption = "Idle Mode";
						  Message("*** CONFIG MODE TIMEOUT - Reset to Idle Mode ***");
						  Update();
						  // reset the global flag
						  ModeRequest = false;
					   }
		}

	}
	else // no messages
	{
		//if (err != PCAN_ERROR_QRCVEMPTY)      //!
		//MessageInt("CanBus Error ",err); // CanBus error
	}

	SyncTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::AddressComboBoxChange(TObject *Sender)
{
	address = AddressComboBox->ItemIndex;
	dataMessPeriod   = 0x0A5A41C0 + address;
	dataMessReq      = 0x0E5A81C0 + address;
	switchMess       = 0x0E5A82C0 + address;
	ModeErrorMess    = 0x0E5A84C0 + address;
	ModeStatusMess   = 0x0E5A85C0 + address;
	PBITMess         = 0x0E5A86C0 + address;
	CBITMess         = 0x0E5A87C0 + address;
	IBITMess         = 0x0E5A88C0 + address;
	TimingMess       = 0x0E5A89C0 + address;
	CurveVersionMess = 0x0E5A8FC0 + address;
	CurveDataMess    = 0x0E5A8EC0 + address;
	MaxValMess       = 0x0E5A8DC0 + address;
	OffsetValMess    = 0x0E5A8CC0 + address;
	RawDefDataMess   = 0x0E5AC2C0 + address;
	ConfigDataMess   = 0x0E5AC3C0 + address;
}
//---------------------------------------------------------------------------

void DisplayData()
{
	CanBusForm->IDText->Text      = HexEight(rcvMsg.ID);
	CanBusForm->RTRText->Text     = HexTwo(rcvMsg.MSGTYPE);
	CanBusForm->DataLenText->Text = HexTwo(rcvMsg.LEN);
	CanBusForm->Byte0Text->Text   = HexTwo(rcvMsg.DATA[0]);
	CanBusForm->Byte1Text->Text   = HexTwo(rcvMsg.DATA[1]);
	CanBusForm->Byte2Text->Text   = HexTwo(rcvMsg.DATA[2]);
	CanBusForm->Byte3Text->Text   = HexTwo(rcvMsg.DATA[3]);
	CanBusForm->DataNo->Text      = dataCount;
}
//---------------------------------------------------------------------------

void DisplayMess()
{
	CanBusForm->MessID->Text      = HexEight(rcvMsg.ID);
	CanBusForm->MessRTR->Text     = HexTwo(rcvMsg.MSGTYPE);
	CanBusForm->MessDataLen->Text = HexTwo(rcvMsg.LEN);
	CanBusForm->MessByte0->Text   = HexTwo(rcvMsg.DATA[0]);
	CanBusForm->MessByte1->Text   = HexTwo(rcvMsg.DATA[1]);
	CanBusForm->MessByte2->Text   = HexTwo(rcvMsg.DATA[2]);
	CanBusForm->MessByte3->Text   = HexTwo(rcvMsg.DATA[3]);
	CanBusForm->MessByte4->Text   = HexTwo(rcvMsg.DATA[4]);
	CanBusForm->MessByte5->Text   = HexTwo(rcvMsg.DATA[5]);
	CanBusForm->MessByte6->Text   = HexTwo(rcvMsg.DATA[6]);
	CanBusForm->MessByte7->Text   = HexTwo(rcvMsg.DATA[7]);
	CanBusForm->MessNo->Text      =  messCount;
	if(rcvMsg.LEN < 8)
		CanBusForm->MessByte7->Text = "";
	if(rcvMsg.LEN < 7)
		CanBusForm->MessByte6->Text = "";
	if(rcvMsg.LEN < 6)
		CanBusForm->MessByte5->Text = "";
	if(rcvMsg.LEN < 5)
		CanBusForm->MessByte4->Text = "";
	if(rcvMsg.LEN < 4)
		CanBusForm->MessByte3->Text = "";
	if(rcvMsg.LEN < 3)
		CanBusForm->MessByte2->Text = "";
	if(rcvMsg.LEN < 2)
		CanBusForm->MessByte1->Text = "";
}
//---------------------------------------------------------------------------

void DisplaySwitches()
{
	CanBusForm->SWID->Text      = HexEight(rcvMsg.ID);
	CanBusForm->SWRTR->Text     = HexTwo(rcvMsg.MSGTYPE);
	CanBusForm->SWDataLen->Text = HexTwo(rcvMsg.LEN);
	CanBusForm->SWByte0->Text   = HexTwo(rcvMsg.DATA[0]);
	CanBusForm->SWByte1->Text   = HexTwo(rcvMsg.DATA[1]);
	CanBusForm->SWByte2->Text   = HexTwo(rcvMsg.DATA[2]);
	CanBusForm->SWByte3->Text   = HexTwo(rcvMsg.DATA[3]);
	CanBusForm->SWByte4->Text   = HexTwo(rcvMsg.DATA[4]);
	CanBusForm->SWByte5->Text   = HexTwo(rcvMsg.DATA[5]);
	CanBusForm->SWNo->Text      = SWCount;
}

//---------------------------------------------------------------------------

 void DisplayDataTime(unsigned int time)
{
	CanBusForm->DataTime->Text = time;
}
//---------------------------------------------------------------------------

 void DisplaySwitchTime(unsigned int time)
{
	CanBusForm->SwitchTime->Text = time;
}
//---------------------------------------------------------------------------
void Delay()
{
int i, j;
 for(i = 0; i <62500;) //62500
   {

   i++;
   for(j = 0; j <100; j++);  //100
   }
}
//---------------------------------------------------------------------------

void SwitchGraphics()
{
  if (DP414_Selected == true)    // Dual controller
  {
   //Process left hand switches only for Dual controller
   /*************************** BYTE 0 LEFT HAND **************************/
   /* Copy the contents of Byte 0  for Left Hand Switches*/
   switch0 = rcvMsg.DATA[0];

   if(switch0 == 0x01)           // LH SW1
   {
	 CanBusForm->SW1Button->Color = clLime;
	 CanBusForm->SW1Button->BevelOuter = bvLowered;
	 Message("Tx  0E 5A 82 C0 01 00 00 00 00 00 [ SWITCH STATUS - LHSW1 ]");
   }
   else
   {
	 CanBusForm->SW1Button->Color = clBtnFace;
	 CanBusForm->SW1Button->BevelOuter = bvRaised;
   }
   if(switch0 == 0x08)           // LH SW2
   {
	 CanBusForm->SW2Button->Color = clLime;
	 CanBusForm->SW2Button->BevelOuter = bvLowered;
	 Message("Tx  0E 5A 82 C0 08 00 00 00 00 00 [ SWITCH STATUS - LHSW2 ]");
   }
   else
   {
	 CanBusForm->SW2Button->Color = clBtnFace;
	 CanBusForm->SW2Button->BevelOuter = bvRaised;
   }
   if(switch0 == 0x40)           // LH TRIG
   {
	 CanBusForm->SW3Button->Color = clLime;
	 CanBusForm->SW3Button->BevelOuter = bvLowered;
	 Message("Tx  0E 5A 82 C0 40 00 00 00 00 00 [ SWITCH STATUS - LHTRIG ]");
   }
   else
   {
	 CanBusForm->SW3Button->Color = clBtnFace;
	 CanBusForm->SW3Button->BevelOuter = bvRaised;
   }
   if(switch0 == 0x80)           // LH PALM
   {
	 CanBusForm->SW4Button->Color = clLime;
	 CanBusForm->SW4Button->BevelOuter = bvLowered;
	 Message("Tx  0E 5A 82 C0 80 00 00 00 00 00 [ SWITCH STATUS - LHPALM ]");
   }
   else
   {
	 CanBusForm->SW4Button->Color = clBtnFace;
	 CanBusForm->SW4Button->BevelOuter = bvRaised;
   }
  }

  if ((DP414_Selected == true)|| (DP1236_Selected == true))
  {
	 //Process right hand switches for both controllers

	/*************************** BYTE 3 RIGHT HAND **************************/
	/* Copy the contents of Byte 3  for Right Hand Switches */
	switch3 = rcvMsg.DATA[3];

	if(switch3 == 0x01)           // RH SW1
	{
		CanBusForm->SW5Button->Color = clLime;
		CanBusForm->SW5Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 01 00 00 [ SWITCH STATUS - RHSW1 ]");
	}
	else
	{
		CanBusForm->SW5Button->Color = clBtnFace;
		CanBusForm->SW5Button->BevelOuter = bvRaised;
	}
	/* ************ 4 WAY TRIM SWITCH  Start *************** */
	if(switch3 == 0x08)           // RH SW2 - DOWN
	{
		CanBusForm->SW7Button->Color = clLime;
		CanBusForm->SW7Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 08 00 00 [ SWITCH STATUS - RHSW2 /DOWN ]");
	}
	else
	{
		CanBusForm->SW7Button->Color       = clBtnFace;
		CanBusForm->SW7Button->BevelOuter  = bvRaised;
	}
	if(switch3 == 0x28)           // RH SW2 - UP
	{
		CanBusForm->SW6Button->Color = clLime;
		CanBusForm->SW6Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 28 00 00 [ SWITCH STATUS - RHSW2 /UP ]");
	}
	else
	{
		CanBusForm->SW6Button->Color       = clBtnFace;
		CanBusForm->SW6Button->BevelOuter  = bvRaised;
	}
	if(switch3 == 0x18)           // RH SW2 - LEFT
	{
		CanBusForm->SW8Button->Color = clLime;
		CanBusForm->SW8Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 18 00 00 [ SWITCH STATUS - RHSW2 /LEFT ]");
	}
	else
	{
		CanBusForm->SW8Button->Color       = clBtnFace;
		CanBusForm->SW8Button->BevelOuter  = bvRaised;
	}
	if(switch3 == 0x38)         // RH SW2 - RIGHT
	{
		CanBusForm->SW9Button->Color = clLime;
		CanBusForm->SW9Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 01 00 00 38 00 00 [ SWITCH STATUS - RHSW2 /RIGHT ]");
	}
	else
	{
		CanBusForm->SW9Button->Color       = clBtnFace;
		CanBusForm->SW9Button->BevelOuter  = bvRaised;
	}
	/* ************ 4 WAY TRIM SWITCH  End *************** */

	if(switch3 == 0x40)           // RH TRIG
	{
		CanBusForm->SW12Button->Color = clLime;
		CanBusForm->SW12Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 40 00 00 [ SWITCH STATUS - RHTRIG ]");
	}
	else
	{
		CanBusForm->SW12Button->Color = clBtnFace;
		CanBusForm->SW12Button->BevelOuter = bvRaised;
	}
	if(switch3 == 0x80)           // RH PALM
	{
		CanBusForm->SW13Button->Color = clLime;
		CanBusForm->SW13Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 80 00 00 [ SWITCH STATUS - RHPALM ]");
	}
	else
	{
		CanBusForm->SW13Button->Color = clBtnFace;
		CanBusForm->SW13Button->BevelOuter = bvRaised;
	}
  }

  if (DP1236_Selected == true)
  {
	 // Process Right hand switch 3 & 4 for single controller only

	/*************************** BYTE 4 RIGHT HAND **************************/

	switch4 = rcvMsg.DATA[4];

	if(switch4 == 0x01)           // RH SW3
	{
		CanBusForm->SW10Button->Color = clLime;
		CanBusForm->SW10Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 00 01 00 [ SWITCH STATUS - RHSW3 ]");
	}
	else
	{
		CanBusForm->SW10Button->Color = clBtnFace;
		CanBusForm->SW10Button->BevelOuter = bvRaised;
	}

	if((switch4 & 0x08) > 0)      // RH SW4
	{
		CanBusForm->SW11Button->Color = clLime;
		CanBusForm->SW11Button->BevelOuter = bvLowered;
		Message("Tx  0E 5A 82 C0 00 00 00 00 08 00 [ SWITCH STATUS - RHSW4 ]");
	}
	else
	{
		CanBusForm->SW11Button->Color = clBtnFace;
		CanBusForm->SW11Button->BevelOuter = bvRaised;
	}
  }
 }
//---------------------------------------------------------------------------


void SwitchGraphicsESS()
 {


  if (DP414_Selected == true)    // Dual controller
  {
   //Process left hand switches only for Dual controller
   /*************************** BYTE 0 LEFT HAND **************************/
   /* Copy the contents of Byte 0  for Left Hand Switches*/


   switch0 = rcvMsg.DATA[0];

   bool LHSwitch1;
   bool LHSwitch2;
   bool LHTrig;
   bool LHPalm;
   bool RHSwitch1;
   bool RHSwitch2Down;
   bool	RHSwitch2Up;
   bool RHSwitch2Left;
   bool RHSwitch2Right;
   bool RHSwitch2Trig;
   bool RHSwitch2Palm;

   LHSwitch1 =  (switch0 & 0x01);
   LHSwitch2 =  (switch0 & 0x08);
   LHTrig = (switch0 & 0x40);
   LHPalm = (switch0 & 0x80);
   RHSwitch1 = (switch0 & 0x01);
   RHSwitch2Down = (switch0 & 0x08);
   RHSwitch2Up = (switch0 & 0x28);
   RHSwitch2Left = (switch0 & 0x18);
   RHSwitch2Right = (switch0 & 0x38);
   RHSwitch2Trig = (switch0 & 0x40);
   RHSwitch2Palm = (switch0 & 0x80);




  if(LHSwitch1 == true)           // LH SW1
   {
	 CanBusForm->SW1Button->Color = clRed;
	 CanBusForm->SW1Button->BevelOuter = bvLowered;
	 Message(" [ SWITCH ACTIVATION - LHSW1 ]");
	 Realtime_StampDateTime ();

   }

   if(LHSwitch2 == true)           // LH SW2
   {
	 CanBusForm->SW2Button->Color = clRed;
	 CanBusForm->SW2Button->BevelOuter = bvLowered;
	 Message(" [ SWITCH ACTIVATION - LHSW2 ]");
	 Realtime_StampDateTime ();

   }

   if(LHTrig == true)           // LH TRIG
   {
	 CanBusForm->SW3Button->Color = clRed;
	 CanBusForm->SW3Button->BevelOuter = bvLowered;
	 Message(" [ SWITCH ACTIVATION - LHTRIG ]");
	 Realtime_StampDateTime ();

   }

   if(LHPalm == true)           // LH PALM
   {
	 CanBusForm->SW4Button->Color = clRed;
	 CanBusForm->SW4Button->BevelOuter = bvLowered;
	 Message(" [ SWITCH ACTIVATION - LHPALM ]");
	 Realtime_StampDateTime ();
   }

  }

  if ((DP414_Selected == true)|| (DP1236_Selected == true))
  {
	 //Process right hand switches for both controllers

	/*************************** BYTE 3 RIGHT HAND **************************/
	/* Copy the contents of Byte 3  for Right Hand Switches */

   switch3 = rcvMsg.DATA[3];

   bool RHSwitch1;
   bool RHSwitch2Down;
   bool	RHSwitch2Up;
   bool RHSwitch2Left;
   bool RHSwitch2Right;
   bool RHSwitch2Trig;
   bool RHSwitch2Palm;


   RHSwitch1 = (switch3 & 0x01);
   RHSwitch2Down = (switch3 & 0x08);
   RHSwitch2Up = (switch3 & 0x28);
   RHSwitch2Left = (switch3 & 0x18);
   RHSwitch2Right = (switch3 & 0x38);
   RHSwitch2Trig = (switch3 & 0x40);
   RHSwitch2Palm = (switch3 & 0x80);





	if(RHSwitch1 == true)           // RH SW1
	{
		CanBusForm->SW5Button->Color = clRed;
		CanBusForm->SW5Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW1 ]");
		Realtime_StampDateTime ();

	}

	if(RHSwitch2Trig == true)           // RH TRIG
	{
		CanBusForm->SW12Button->Color = clRed;
		CanBusForm->SW12Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHTRIG ]");
		Realtime_StampDateTime ();

	}

	if(RHSwitch2Palm == true)           // RH PALM
	{
		CanBusForm->SW13Button->Color = clRed;
		CanBusForm->SW13Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHPALM ]");
		Realtime_StampDateTime ();
	}



	/* ************ 4 WAY TRIM SWITCH  Start *************** */
	if(switch3 == 0x08)           // RH SW2 - DOWN
	{
		CanBusForm->SW7Button->Color = clRed;
		CanBusForm->SW7Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW2 /DOWN ]");
		Realtime_StampDateTime ();

	}

	if(switch3 == 0x28)           // RH SW2 - UP
	{
		CanBusForm->SW6Button->Color = clRed;
		CanBusForm->SW6Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW2 /UP ]");
		Realtime_StampDateTime ();

	}

	if(switch3 == 0x18)           // RH SW2 - LEFT
	{
		CanBusForm->SW8Button->Color = clRed;
		CanBusForm->SW8Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW2 /LEFT ]");
		Realtime_StampDateTime ();

	}

	if(switch3 == 0x38)         // RH SW2 - RIGHT
	{
		CanBusForm->SW9Button->Color = clRed;
		CanBusForm->SW9Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW2 /RIGHT ]");
		Realtime_StampDateTime ();

	}

	/* ************ 4 WAY TRIM SWITCH  End *************** */


  }

  if (DP1236_Selected == true)
	{
	 // Process Right hand switch 3 & 4 for single controller only

	/*************************** BYTE 4 RIGHT HAND **************************/

		switch4 = rcvMsg.DATA[4];

		bool RHSwitch3;
		bool RHSwitch4;

		RHSwitch3 = (switch4 & 0x01);
		RHSwitch4 = (switch4 & 0x08);




		if(RHSwitch3 == true)           // RH SW3
		{
		CanBusForm->SW10Button->Color = clRed;
		CanBusForm->SW10Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW3 ]");
		Realtime_StampDateTime ();

		}



	   if (RHSwitch4 == true)  //NOTE: Was: if((switch4 & 0x08) > 0)      // RH SW4
	   {

		CanBusForm->SW11Button->Color = clRed;
		CanBusForm->SW11Button->BevelOuter = bvLowered;
		Message(" [ SWITCH ACTIVATION - RHSW4 ]");
		Realtime_StampDateTime ();

	   }



	}



 }



//---------------------------------------------------------------------------


void AxesGraphics()
 {

 int bar;

 int boxHeight = CanBusForm->XBarBox->Height;
 CanBusForm->XBarBox->Canvas->Pen->Width = 5;
 CanBusForm->XBarBox->Canvas->Pen->Color = clBtnFace;
 CanBusForm->XBarBox->Canvas->MoveTo(XBar, 3);
 CanBusForm->XBarBox->Canvas->LineTo(XBar,boxHeight - 4);

 bar = (int)rcvMsg.DATA[1];
 bar = (bar << 8) + (int)rcvMsg.DATA[0];
 bar = bar & 0x3FFF;

 if((bar & 0x2000) > 0)
   {
   bar = (bar ^ 0x3FFF) + 1;
   bar = bar & 0x3FFF;
   bar = bar * -1;
   }

 CanBusForm->XData->Text = bar;
 XBar = ((bar + 8192)/42)+5;  // bar length 401 - (5 * 2)(pen width * 2)
 CanBusForm->XBarBox->Canvas->Pen->Color = clBlack;
 CanBusForm->XBarBox->Canvas->MoveTo(XBar, 3);
 CanBusForm->XBarBox->Canvas->LineTo(XBar,boxHeight - 4);

 boxHeight = CanBusForm->YBarBox->Height;

 CanBusForm->YBarBox->Canvas->Pen->Width = 5;
 CanBusForm->YBarBox->Canvas->Pen->Color = clBtnFace;
 CanBusForm->YBarBox->Canvas->MoveTo(YBar, 3);
 CanBusForm->YBarBox->Canvas->LineTo(YBar,boxHeight - 4);

 bar = (int)rcvMsg.DATA[3];
 bar = (bar << 8) + (int)rcvMsg.DATA[2];
 bar = bar & 0x3FFF;

 if((bar & 0x2000) > 0)
   {
   bar = (bar ^ 0x3FFF) + 1;
   bar = bar & 0x3FFF;
   bar = bar * -1;
   }
 CanBusForm->YData->Text = bar;
 YBar = ((bar + 8192)/42)+5;  // bar length 401 - (5 * 2)(pen width * 2)
 CanBusForm->YBarBox->Canvas->Pen->Color = clBlack;
 CanBusForm->YBarBox->Canvas->MoveTo(YBar, 3);
 CanBusForm->YBarBox->Canvas->LineTo(YBar,boxHeight - 4);


}



//*****************THE MAXIMUM DEFLECTION FUNCTION***********************
//***********************************************************************

void MaxDeflectionGraphics(){


int AxisData;

int PosXAxisData,
	NegXAxisData,
	PosYAxisData,
	NegYAxisData;


 AxisData = (int)rcvMsg.DATA[1];
 AxisData = (AxisData << 8) + (int)rcvMsg.DATA[0];
 AxisData = AxisData & 0x3FFF;

 if((AxisData & 0x2000) > 0)    								//**CHECK THE 14th BIT 2's COMP No, TO SEE iF NEG (1 = NEG))
   {                                                     		//**IF THE ABOVE iS TRUE, EXTRACT THE 2's COMP VALUE FOR -X AXIS
   AxisData = (AxisData ^ 0x3FFF) + 1;                   		//**AND DISPLAY THE OUTPUT IN THE TEXT BOX
   AxisData = AxisData & 0x3FFF;
   AxisData = AxisData * -1;
   NegXAxisData = AxisData;

	if (NegXAxisData < X_NegAxis_DeflectionDataStore) {

	 X_NegAxis_DeflectionDataStore =  NegXAxisData;
	 CanBusForm->MaxDefMinusXBox->Text = NegXAxisData;
	 CanBusForm->MaxDefMinusXBox->Font->Color = clRed;

	}


   }  else {
			 PosXAxisData = AxisData;                     		//**IF WE GET THIS FAR THEN THE NUMBER MUST BE POSITIVE
																//**SO STORE IT TO DO A CAMPARISON WITH HISTORICAL VALUE
			 if (PosXAxisData > X_DeflectionDataStore) {  		//**IF THE VALUE IS GREATER THAN LAST TIME THEN UPDATE THE DISPLAY
																//**DO NOTHING IF NOT.
			 X_DeflectionDataStore = PosXAxisData;        		//**STORE THE NEW CURRENT VALUE IF GREATER THAN BEFORE
			 CanBusForm->MaxDefPosXBox->Text = PosXAxisData;
			 CanBusForm->MaxDefPosXBox->Font->Color = clRed;
			 }

		   }



 AxisData = (int)rcvMsg.DATA[3];
 AxisData = (AxisData << 8) + (int)rcvMsg.DATA[2];
 AxisData = AxisData & 0x3FFF;

 if((AxisData & 0x2000) > 0)    						 		//**CHECK THE 14th BIT 2's COMP No, TO SEE iF NEG (1 = NEG))
   {                                                     		//**IF THE ABOVE iS TRUE, EXTRACT THE 2's COMP VALUE FOR -X AXIS
	AxisData = (AxisData ^ 0x3FFF) + 1;                   		//**AND DISPLAY THE OUTPUT IN THE TEXT BOX
	AxisData = AxisData & 0x3FFF;
	AxisData = AxisData * -1;
	NegYAxisData = AxisData;

	 if (NegYAxisData < Y_NegAxis_DeflectionDataStore) {

	 Y_NegAxis_DeflectionDataStore =  NegYAxisData;
	 CanBusForm->MaxDefMinusYBox->Text = NegYAxisData;
	 CanBusForm->MaxDefMinusYBox->Font->Color = clRed;
   }


  } else {
			 PosYAxisData = AxisData;                     		//**IF WE GET THIS FAR THEN THE NUMBER MUST BE POSITIVE
																//**SO STORE IT TO DO A CAMPARISON WITH HISTORICAL VALUE
			 if (PosYAxisData > Y_DeflectionDataStore) {  		//**IF THE VALUE IS GREATER THAN LAST TIME THEN UPDATE THE DISPLAY
																//**DO NOTHING IF NOT.
			 Y_DeflectionDataStore = PosYAxisData;        		//**STORE THE NEW CURRENT VALUE IF GREATER THAN BEFORE
			 CanBusForm->MaxDefPosYBox->Text = PosYAxisData;
			 CanBusForm->MaxDefPosYBox->Font->Color = clRed;
			 }

		   }

}

//--------------------------------------------------------------------------

  void MessageStr(char *string)  // string message
{
	CanBusForm->Messages->Lines->Add(string);
}

//---------------------------------------------------------------------------

void Message(char *mess)  // string message
{
	CanBusForm->Messages->Lines->Add(mess);
}
//---------------------------------------------------------------------------

void MessageInt(char *mess, int num)  //string message + integer value
{
	CanBusForm->Messages->Lines->Add(mess + AnsiString(num));
}
//---------------------------------------------------------------------------

void MessageInt2(char *mess0, int num0, char *mess1,int num1, char *mess2)  //string message + integer value
{
	CanBusForm->Messages->Lines->Add(mess0 + AnsiString(num0) + mess1 + AnsiString(num1)+ mess2);
}
//---------------------------------------------------------------------------


void MessageData( char *mess, int byte_0, int byte_1, int byte_2, int byte_3)   // 4 byte message display
{
  CanBusForm->Messages->Lines->Add(mess + AnsiString(HexTwo(byte_0)) +
										  AnsiString(HexTwo(byte_1)) +
										  AnsiString(HexTwo(byte_2)) +
										  AnsiString(HexTwo(byte_3)));
}
//---------------------------------------------------------------------------
 void MessageData2( char *mess, int byte_0, int byte_1, int byte_2)   // 3 byte message display
{
  CanBusForm->Messages->Lines->Add(mess + AnsiString(HexTwo(byte_0)) +
										  AnsiString(HexTwo(byte_1)) +
										  AnsiString(HexTwo(byte_2)));
}
//---------------------------------------------------------------------------
void MessageData6( char *mess, int byte_0, int byte_1, int byte_2, int byte_3, int byte_4,int byte_5)   // 6 byte message display
{
  CanBusForm->Messages->Lines->Add(mess + AnsiString(HexTwo(byte_0)) +
										  AnsiString(HexTwo(byte_1)) +
										  AnsiString(HexTwo(byte_2)) +
										  AnsiString(HexTwo(byte_3)) +
										  AnsiString(HexTwo(byte_4)) +
										  AnsiString(HexTwo(byte_5)));
}
//--------------------------------------------------------------------------
void MessageData8( char *mess, char *mess0, int byte_0, char *mess1, int byte_1, char *mess2, int byte_2,
char *mess3, int byte_3, char *mess4, int byte_4, char *mess5, int byte_5, char *mess6, int byte_6, char *mess7, int byte_7)   // 8 byte message display
{
  CanBusForm->Messages->Lines->Add(mess + AnsiString(HexTwo(byte_0)) +
										  AnsiString(HexTwo(byte_1)) +
										  AnsiString(HexTwo(byte_2)) +
										  AnsiString(HexTwo(byte_3)) +
										  AnsiString(HexTwo(byte_4)) +
										  AnsiString(HexTwo(byte_5)) +
										  AnsiString(HexTwo(byte_6)) +
										  AnsiString(HexTwo(byte_7)));
}




//---------------------------------------------------------------------------
char * HexTwo(int num)  // convert to 2 digit hex number
{
	hexString[0] = hex[num/16];
	hexString[1] = hex[num%16];
	hexString[2] = '\0';
	return hexString;
}
//---------------------------------------------------------------------------

char * HexThree(int num)  // convert to 3 digit hex number
{
	hexString[0] = hex[num/256];
	hexString[1] = hex[(num-((num/256)*256))/16];
	hexString[2] = hex[num%16] ;
	hexString[3] = '\0';
	return hexString;
}
//---------------------------------------------------------------------------

char * HexEight(unsigned long num)  // convert to 8 digit hex number
{
	unsigned long temp;
	temp = num >> 28;
	hexString[0] = hex[temp];
	num = num - (temp <<28);
	temp = num >>24;
	hexString[1] = hex[temp];
	num = num - (temp <<24);
	temp = num >>20;
	hexString[2] = hex[temp];
	num = num - (temp <<20);
	temp = num >>16;
	hexString[3] = hex[temp];
	num = num - (temp <<16);
	temp = num >>12;
	hexString[4] = hex[temp];
	num = num - (temp <<12);
	temp = num >>8;
	hexString[5] = hex[temp];
	num = num - (temp <<8);
	temp = num >>4;
	hexString[6] = hex[temp];
	num = num - (temp <<4);
	hexString[7] = hex[num];
	hexString[8] = '\0';
	return hexString;
}
//---------------------------------------------------------------------------

void Reset()  // Set received data to zero
{
	rcvMsg.ID      = 0x00;
	rcvMsg.MSGTYPE = 0 ;
	rcvMsg.LEN     = 0x00;
	rcvMsg.DATA[0] = 0x00;
	rcvMsg.DATA[1] = 0x00;
	rcvMsg.DATA[2] = 0x00;
	rcvMsg.DATA[3] = 0x00;
	rcvMsg.DATA[4] = 0x00;
	rcvMsg.DATA[5] = 0x00;
	rcvMsg.DATA[6] = 0x00;
	rcvMsg.DATA[7] = 0x00;
}
//---------------------------------------------------------------------------

void ProcessPBITResponse()
 {
	time_t t;
	int byte_0;
	int byte_1;
	int byte_2;
	int byte_3;

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
	}

	// Check messsage has been received and that it is a PBIT Response
	if ((err == PCAN_ERROR_OK ) && (rcvMsg.ID == PBITMess ))
	{
		// if an All codes request expect 16 response messages to be sent.
		if ((PBIT_AllCodesRequest == true) && (DP414_Selected == true))
		{
		  // Process the first response
		  byte_0 = rcvMsg.DATA[0];
		  byte_1 = rcvMsg.DATA[1];
		  byte_2 = rcvMsg.DATA[2];
		  byte_3 = rcvMsg.DATA[3];

		  MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
		  Delay();

		  // get the rest of the messages - expecting 15 more responses
		  for (i = 0; i < 15; i++)
		  {
			err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
			byte_2 = rcvMsg.DATA[2];
			byte_3 = rcvMsg.DATA[3];

			MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
			Delay();
		  }
		  // reset global var  PBIT_AllCodesRequest
		  PBIT_AllCodesRequest = false;
		}
		else if ((PBIT_AllCodesRequest == true) && (DP1236_Selected == true))
		{
		  // Process the first response
		  byte_0 = rcvMsg.DATA[0];
		  byte_1 = rcvMsg.DATA[1];
		  byte_2 = rcvMsg.DATA[2];
		  byte_3 = rcvMsg.DATA[3];

		  MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
		  Delay();

		  // get the messages - expecting 11 responses
		  for (i = 0; i < 11; i++)
		  {
			err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
			byte_2 = rcvMsg.DATA[2];
			byte_3 = rcvMsg.DATA[3];

			MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
			Delay();
		  }
		  // reset global var  PBIT_AllCodesRequest
		  PBIT_AllCodesRequest = false;

		}

		// Copy the data to local variables
		byte_0 = rcvMsg.DATA[0];
		byte_1 = rcvMsg.DATA[1];
		byte_2 = rcvMsg.DATA[2];
		byte_3 = rcvMsg.DATA[3];

		if (DP414_Selected == true)
		{

			// Process individual Code ID's Responses for 2CH
			switch(rcvMsg.DATA[0] & 0xFF)
			{
				case 0x01: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x02: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x03: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x04: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x05: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x07: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x09: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0B: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0D: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0F: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x11: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x13: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x15: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x17: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x19: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x1A: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
			}
		}
		else if (DP1236_Selected == true)
		{
			// Process individual Code ID's Responses for 1CH
			switch(rcvMsg.DATA[0] & 0xFF)
			{
				case 0x01: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x02: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x03: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x04: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0D: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0F: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x11: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x13: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x15: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x17: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x19: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x1A: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 86 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
			}

		}
		// Reset local variables
		byte_0 = 0;
		byte_1 = 0;
		byte_2 = 0;
		byte_3 = 0;
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
		MessageInt("ID = ",rcvMsg.ID);
	}
}
//---------------------------------------------------------------------------

void ProcessCBITResponse()
 {
	time_t t;
	int byte_0;
	int byte_1;
	int byte_2;
	int byte_3;

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
	}

	// Check messsage has been received and that it is a CBIT Response
	if ((err == PCAN_ERROR_OK ) && (rcvMsg.ID == CBITMess ))
	{
		// if an All codes request expect 12 response messages to be sent.
		if ((CBIT_AllCodesRequest == true) && (DP414_Selected == true))
		{

		  CBIT_AllCodesRequest = false;
		  //Process the first response

		  byte_0 = rcvMsg.DATA[0];
		  byte_1 = rcvMsg.DATA[1];
		  byte_2 = rcvMsg.DATA[2];
		  byte_3 = rcvMsg.DATA[3];

		  MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
		  Delay();

		  // get the rest of the messages - expecting 12 more responses
		  for (i = 0; i < 10; i++)
		  {

			err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
			byte_2 = rcvMsg.DATA[2];
			byte_3 = rcvMsg.DATA[3];


			MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
			Delay();
		  }
		  // reset global var  CBIT_AllCodesRequest
		  CBIT_AllCodesRequest = false;
		}
		else if ((CBIT_AllCodesRequest == true) && (DP1236_Selected == true))
		{
		  // Process the first response
		  byte_0 = rcvMsg.DATA[0];
		  byte_1 = rcvMsg.DATA[1];
		  byte_2 = rcvMsg.DATA[2];
		  byte_3 = rcvMsg.DATA[3];

		  MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
		  Delay();

		  // get the rest of the messages - expecting 8 more responses
		  for (i = 0; i < 8; i++)
		  {
			err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
			byte_2 = rcvMsg.DATA[2];
			byte_3 = rcvMsg.DATA[3];

			MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
			Delay();
		  }
		  // reset global var  CBIT_AllCodesRequest
		  CBIT_AllCodesRequest = false;
		}
		// Copy the data to local variables
		byte_0 = rcvMsg.DATA[0];
		byte_1 = rcvMsg.DATA[1];
		byte_2 = rcvMsg.DATA[2];
		byte_3 = rcvMsg.DATA[3];


		if (DP414_Selected == true)
		{
			// Process individual Code ID  for 2CH
			switch(rcvMsg.DATA[0] & 0xFF)
			{
				case 0x03: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x06: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x08: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0A: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0C: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0E: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x10: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x12: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x14: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x16: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x18: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x19: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x1A: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
			}
		}
		else if (DP1236_Selected == true)
		{
			// Process individual Code ID  for 1CH
			switch(rcvMsg.DATA[0] & 0xFF)
			{
				case 0x03: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x0E: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x10: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x12: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x14: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x16: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x18: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x19: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
				case 0x1A: 	messCount++;
							DisplayMess();
							MessageData("Tx  0E 5A 87 C0 - ",byte_0, byte_1, byte_2, byte_3);
							break;
			}
		 }

		// Reset local variables
		byte_0 = 0;
		byte_1 = 0;
		byte_2 = 0;
		byte_3 = 0;
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
 }
//---------------------------------------------------------------------------

void ProcessIBITResponse()
{
	time_t t;
	unsigned int Byte_0;
	unsigned int Byte_1;
	unsigned int Byte_2;

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
	}

	// Check messsage has been received and that it is a IBIT Response
	if ((err == PCAN_ERROR_OK ) && (rcvMsg.ID == IBITMess ))
	{
		if (IBIT_AllCodesRequest == true)
		{
		  // Process the first response
		  Byte_0 = rcvMsg.DATA[0];
		  Byte_1 = rcvMsg.DATA[1];
		  Byte_2 = rcvMsg.DATA[2];
		  MessageData2("Tx  0E 5A 88 C0 - ",Byte_0, Byte_1, Byte_2);
		  Delay();

		  // get the rest of the messages - expecting 3 more responses
		  for (i = 0; i < 3; i++)
		  {
			err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
			Byte_0 = rcvMsg.DATA[0];
			Byte_1 = rcvMsg.DATA[1];
			Byte_2 = rcvMsg.DATA[2];
			MessageData2("Tx  0E 5A 88 C0 - ",Byte_0, Byte_1, Byte_2);
			Delay();
		  }
		}

		// reset global var  IBIT_AllCodesRequest
		IBIT_AllCodesRequest = false;
		// Copy the data to local variables
		Byte_0 = rcvMsg.DATA[0];
		Byte_1 = rcvMsg.DATA[1];
		Byte_2 = rcvMsg.DATA[2];

		// Process individual codes
		switch(rcvMsg.DATA[0] & 0xFF)
		{
			case 0x01: 	messCount++;
						DisplayMess();
						MessageData2("Tx  0E 5A 88 C0 - ",Byte_0, Byte_1, Byte_2);
						break;
			case 0x02: 	messCount++;
						DisplayMess();
						MessageData2("Tx  0E 5A 88 C0 - ",Byte_0, Byte_1, Byte_2);
						break;
			case 0x03: 	messCount++;
						DisplayMess();
						MessageData2("Tx  0E 5A 88 C0 - ",Byte_0, Byte_1, Byte_2);
						break;
			case 0x04: 	messCount++;
						DisplayMess();
						MessageData2("Tx  0E 5A 88 C0 - ",Byte_0, Byte_1, Byte_2);
						break;
		}
	}
	else
	{
	Message("No (valid) reply!");
	MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------
void ProcessTimingResponse()
{
	time_t t;
	int byte_0;
	int byte_1;
	int byte_2;
	int byte_3;
	int byte_4;
	int byte_5;

	t = time(NULL) + 2;

	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))
	{
		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);
	}

	// Check messsage has been received.
	if ((err == PCAN_ERROR_OK )  && (rcvMsg.ID == TimingMess))
	{
	  // DISPLAY THE DATA RECEIVED.
	  byte_0 = rcvMsg.DATA[0];
	  byte_1 = rcvMsg.DATA[1];
	  byte_2 = rcvMsg.DATA[2];
	  byte_3 = rcvMsg.DATA[3];
	  byte_4 = rcvMsg.DATA[4];
	  byte_5 = rcvMsg.DATA[5];

	  Message("                        [ TIMING RESPONSE ]");
	  MessageData6("Tx  0E 5A 89 C0 ", byte_0, byte_1, byte_2, byte_3, byte_4, byte_5 );
	}
	// MODE ERROR
	else if (rcvMsg.ID == ModeErrorMess)
	{
	Message("Tx  0E 5A 84 C0 F3       [ MODE ERROR ]");
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
 //---------------------------------------------------------------------------

void CheckCurveVersionResponse(int curve_id)
{
	VersionDataGood = false;
	time_t t;

	t = time(NULL) + 2;
	err = PCAN_ERROR_QRCVEMPTY;

	// if no messages loop)
	while((err == PCAN_ERROR_QRCVEMPTY) && (t > time(NULL)))

		err = CAN_Read(PCAN_USBBUS1, &rcvMsg, &timestamp);

	if (err == PCAN_ERROR_OK)
	{
		messCount++;
		DisplayMess();

		// check we have the right message
		if(rcvMsg.ID == CurveVersionMess)
		{
		   Message("Tx 0E 5A 8F C0 00       [ CURVE VERSION REPONSE ]");
		  // Check Curve ID 0
		  if ((rcvMsg.DATA[0] == 0x00 ) && (curve_id == 0))
			  Check_Data(curve_id);
			  if (VersionDataGood == true)
			  {
				Message("CURVE Id 0 - Version is 1.0.1 ");
				VersionDataGood = false;
			  }
		  // Check Curve ID 1
		  if ((rcvMsg.DATA[0] == 0x01 ) && (curve_id == 1))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				 Message("CURVE Id 1 - Version is 1.1.1 ");
				 VersionDataGood = false;
			   }
		  // Check Curve ID 2
		  if ((rcvMsg.DATA[0] == 0x02 ) && (curve_id == 2))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				Message("CURVE Id 2 - Version is 1.2.1 ");
				VersionDataGood = false;
			   }
		  // Check Curve ID 3
		  if ((rcvMsg.DATA[0] == 0x03 ) && (curve_id == 3))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				Message("CURVE Id 3 - Version is 1.3.1 ");
				VersionDataGood = false;
			   }
		  // Check Curve ID 4
		  if ((rcvMsg.DATA[0] == 0x04 ) && (curve_id == 4))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				Message("CURVE Id 4 - Version is 1.4.1 ");
				VersionDataGood = false;
			   }
		  // Check Curve ID 5
		  if ((rcvMsg.DATA[0] == 0x05 ) && (curve_id == 5))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				Message("CURVE Id 5 - Version is 1.5.1 ");
				VersionDataGood = false;
			   }
		  // Check Curve ID 6
		  if ((rcvMsg.DATA[0] == 0x06 ) && (curve_id == 6))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				Message("CURVE Id 6 - Version is 1.6.1 ");
				VersionDataGood = false;
			   }
		  // Check Curve ID 7
		  if ((rcvMsg.DATA[0] == 0x07 ) && (curve_id == 7))
			   Check_Data(curve_id);
			   if (VersionDataGood == true)
			   {
				Message("CURVE Id 7 - Version is 1.7.1 ");
				VersionDataGood = false;
			   }
		}
		else if (rcvMsg.ID == ModeErrorMess)
		{
		   Message("Tx  0E 5A 84 C0 31      [ MODE ERROR ]");
		}
		else
		{
		   Message("Not a valid curve version message! ");
		}
	}
	else
	{
		Message("No (valid) reply!");
		MessageInt("CAN error = ", err);
	}
}
//---------------------------------------------------------------------------

void  Check_Data(int curve_id)
{
  // Check the Message Data matches Pre configured data
	if ((rcvMsg.DATA[1] == VersionData[curve_id][1]) &&    // Byte 1 - Version LSB  (Major Version No)
		(rcvMsg.DATA[2] == VersionData[curve_id][2]) &&    // Byte 2 - Version MSB  (Minor Version No / Revision No)
		(rcvMsg.DATA[3] == VersionData[curve_id][3]) &&    // Byte 3 - Status Code
		(rcvMsg.DATA[4] == VersionData[curve_id][4]) &&    // Byte 4 - Curve ID for Elevation
		(rcvMsg.DATA[5] == VersionData[curve_id][5]) &&    // Byte 5 - Version LSB  (Major Version No)
		(rcvMsg.DATA[6] == VersionData[curve_id][6]) &&    // Byte 6 - Version MSB  (Minor Version No / Revision No)
		(rcvMsg.DATA[7] == VersionData[curve_id][7]))      // Byte 7 - Status Code

	{
	  VersionDataGood = true;
	}
	else
	{
	  // OutPut message
	  //Message("**** CURVE NOT LOADED.****");
	  VersionDataGood = false;
	}

}
//---------------------------------------------------------------------------

void Check_GetCurveDataResponse(int curveID)
{
  int i;
  int count;
  byte StoreCurveData [16][8];

  // We are expecting 16 messsages
  for (i=0; i <16; i++)
  {
  Message("in for lOOP");
	err = CAN_Read(PCAN_USBBUS1, &rcvMsg, NULL);

	// Check we have the correct response
	if(rcvMsg.ID == CurveDataMess)
	{
	  count = i;
	  /* Check only Curve ID 4 & 5  fully  */
	  if ((curveID == 4)|| (curveID == 5))
	  {
		 // save the data for post processing
		 StoreCurveData[i][0] = rcvMsg.DATA[0];
		 StoreCurveData[i][1] = rcvMsg.DATA[1];
		 StoreCurveData[i][2] = rcvMsg.DATA[2];
		 StoreCurveData[i][3] = rcvMsg.DATA[3];
		 StoreCurveData[i][4] = rcvMsg.DATA[4];
		 StoreCurveData[i][5] = rcvMsg.DATA[5];
		 StoreCurveData[i][6] = rcvMsg.DATA[6];
		 StoreCurveData[i][7] = rcvMsg.DATA[7];
	  }
	  else
	  {
		// just check the message count
		if (count == 15)
		{
		  MessageInt("Correct number of Curve Points have been received. No = ", i+1);
		}
	  }
   }
   else
   {
	  Message("Not a valid Curve Data Message");
	  break;
   }
   // check if no more messages - less than 16 have been received
   if (err == false)
   {
	 MessageInt("Not ALL Curve Points have been received. No = ", i+1);
	 // quit the loop
	 break;

   }
  }
  // check if we got all the messages.
  if (count != 15)
  {
	 Message("Not all messages have been received");
  }
  else
  {
	 // Now check the saved data matches the constant data.
	 for (i = 0; i < 16; i++)
	 {
	   if  (curveID == 4)
	   {
		 Message("Tx  0E 5A 8E C0         [ CURVE DATA RESPONSE ]");
		 if ((StoreCurveData[i][1] == CurveData_4[i][1]) &&
			 (StoreCurveData[i][2] == CurveData_4[i][2]) &&
			 (StoreCurveData[i][3] == CurveData_4[i][3]) &&
			 (StoreCurveData[i][4] == CurveData_4[i][4]) &&
			 (StoreCurveData[i][5] == CurveData_4[i][5]) &&
			 (StoreCurveData[i][6] == CurveData_4[i][6]) &&
			 (StoreCurveData[i][7] == CurveData_4[i][7]))
		 {
		   MessageInt("Curve ID 4 Data is correct for point = ", i+1);
		 }
		 else
		 {
		   MessageInt("ERROR - Curve ID 4 Data is Incorrect for point = ", i+1);
		 }
	   }
	   else if  (curveID == 5)
	   {
		 Message("Tx  0E 5A 8E C0         [ CURVE DATA RESPONSE ]");
		 if ((StoreCurveData[i][1] == CurveData_5[i][1]) &&
			 (StoreCurveData[i][2] == CurveData_5[i][2]) &&
			 (StoreCurveData[i][3] == CurveData_5[i][3]) &&
			 (StoreCurveData[i][4] == CurveData_5[i][4]) &&
			 (StoreCurveData[i][5] == CurveData_5[i][5]) &&
			 (StoreCurveData[i][6] == CurveData_5[i][6]) &&
			 (StoreCurveData[i][7] == CurveData_5[i][7]))
		 {
		   MessageInt("Curve ID 5 Data is correct for point = ", i+1);
		 }
		 else
		 {
		   MessageInt("ERROR - Curve ID 5 Data is Incorrect for point = ", i+1);
		 }
	   }
	 }
  }
}
//---------------------------------------------------------------------------

void ProcessOffsetDataResponse ()
{
  int byte_0;
  int byte_1;
  int byte_2;
  int byte_3;
  int byte_4;
  int byte_5;

	// check we have the right message
	if(rcvMsg.ID == OffsetValMess)
	{
	  // DISPLAY THE DATA RECEIVED.
	  byte_0 = rcvMsg.DATA[0];
	  byte_1 = rcvMsg.DATA[1];
	  byte_2 = rcvMsg.DATA[2];
	  byte_3 = rcvMsg.DATA[3];
	  byte_4 = rcvMsg.DATA[4];
	  byte_5 = rcvMsg.DATA[5];

	  MessageData6("Tx  0E 5A 0C 00 ", byte_0, byte_1, byte_2, byte_3, byte_4, byte_5 );
	}
}
//---------------------------------------------------------------------------

void ProcessMaxValueResponse ()
{
  int byte_0_data;
  int byte_1_data;
  int byte_2_data;
  int byte_3_data;

	if (rcvMsg.ID == MaxValMess)
	{
	  // DISPLAY THE DATA RECEIVED.
	  byte_0_data = rcvMsg.DATA[0];
	  byte_1_data = rcvMsg.DATA[1];
	  byte_2_data = rcvMsg.DATA[2];
	  byte_3_data = rcvMsg.DATA[3];
	  MessageData("Tx  0E 5A 8D C0 - ",byte_0_data, byte_1_data, byte_2_data, byte_3_data);
	}
}
//---------------------------------------------------------------------------

void ProcessConfigDataResponse()
{
	int i;
	int  eti_byte1;
	int  eti_byte2;
	int  eti_byte3;
	int  pwr_cyc_byte5;
	int  pwr_cyc_byte6;
	int total_eti;
	int total_pwr_cyc;
	int part_number [7];


	if (DP1236_Selected == true) {

	   for (i = 0; i < 7; i++) {

		  part_number[i] = part_number1[i];
	   }

	}  else


		if (DP414_Selected == true) {

			for (i = 0; i < 7; i++) {

				part_number[i] = part_number2[i];
			}

		}


	  // check we have the right message
	  if(rcvMsg.ID == ConfigDataMess)
	  {
		Message("Tx  0E 5A C3 C0 00      [ CONFIG MANAGEMENT RESPONSE ]");
		if (rcvMsg.DATA[0] == 0X01)   // Part Number requested
		{
		  // Check the Data is as expected
		  for (i = 0; i < 7; i++)
		  {
			if (rcvMsg.DATA[i+1] == part_number[i] )
			{
			  MessageInt("Part Number is as expected for Byte No.", i+1);
			}
			else
			{
			  MessageInt("Part Number is NOT as expected for Byte No.",i+1);
			}
		  }
		}
		else if (rcvMsg.DATA[0] == 0X02)   // Serial Number requested
		{
		  // Check the Data is as expected
		  for (i = 0; i < 7; i++)
		  {
			if (rcvMsg.DATA[i+1] == serial_number[i] )
			{
			  MessageInt("Serial Number is as expected for Byte No.",i+1);
			}
			else
			{
			  MessageInt("Serial Number is NOT as expected for Byte No.",i+1);
			}
		  }
		}
		else if (rcvMsg.DATA[0] == 0X03)   // Software Version requested
		{
		  // Check the Data is as expected
		  for (i = 0; i < 7; i++)
		  {
			if (rcvMsg.DATA[i+1] == S_W_Version[i] )
			{
			  MessageInt("Software Version is as expected for Byte No.",i+1);
			}
			else
			{
			  MessageInt("Software Version is NOT as expected for Byte No.",i+1);
			}
		  }
		}
		else if (rcvMsg.DATA[0] == 0X04)   // ETI and PWR cycles requested
		{

			eti_byte1     = rcvMsg.DATA[1];
			eti_byte2     = rcvMsg.DATA[2];
			eti_byte3     = rcvMsg.DATA[3];
			pwr_cyc_byte5 = rcvMsg.DATA[5];
			pwr_cyc_byte6 = rcvMsg.DATA[6];
			total_eti = ((eti_byte1) + (eti_byte2 * 255) + (eti_byte3));
			total_pwr_cyc = (pwr_cyc_byte5 + pwr_cyc_byte6);

			MessageInt("Total ETI in minutes = ",total_eti);
			MessageInt("Total Power Cycles   = ",total_pwr_cyc);
		}
	 }
}

///PROCESS CONFIG DAT RESPONSE CAL////

void ProcessConfigDataResponse_CAL()
{
	int i;
	int  eti_byte1;
	int  eti_byte2;
	int  eti_byte3;
	int  pwr_cyc_byte5;
	int  pwr_cyc_byte6;
	int total_eti;
	int total_pwr_cyc;

	int byte_0;
    int byte_1;
    int byte_2;
    int byte_3;
    int byte_4;
    int byte_5;
    int byte_6;
	int byte_7;
    int byte_8;


	  // check we have the right message
	  if(rcvMsg.ID == ConfigDataMess)
	  {
		//Message("Tx  0E 5A C3 C0 00      [ CONFIG MANAGEMENT RESPONSE ]");
		if (rcvMsg.DATA[0] == 0X01)   // Part Number Requested: DP414-3
		{

			// DISPLAY THE DATA RECEIVED
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
	  		byte_2 = rcvMsg.DATA[2];
			byte_3 = rcvMsg.DATA[3];
			byte_4 = rcvMsg.DATA[4];
	  		byte_5 = rcvMsg.DATA[5];
			byte_6 = rcvMsg.DATA[6];
			byte_7 = rcvMsg.DATA[7];
			//byte_8 = rcvMsg.DATA[8];

				MessageData8("[Tx  0E 5A C3 C0 ]:      ", " ", byte_0,  "",byte_1,  "",byte_2, "",byte_3,  "",byte_4,  "",byte_5,  "",byte_6,  "",byte_7);


			//} //else { MessageInt("Part Number NOT received for No.",1);}

		} //else  {MessageInt("Part Number NOT received for No.",1);]

		else

			if (rcvMsg.DATA[0] == 0X02)   // Serial Number requested
		
		{
		 // DISPLAY THE DATA RECEIVED
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
			byte_2 = rcvMsg.DATA[2];
	  		byte_3 = rcvMsg.DATA[3];
			byte_4 = rcvMsg.DATA[4];
	  		byte_5 = rcvMsg.DATA[5];
			byte_6 = rcvMsg.DATA[6];
	  		byte_7 = rcvMsg.DATA[7];
			//byte_8 = rcvMsg.DATA[8];

				MessageData8("[Tx  0E 5A C3 C0 ]:      "," ", byte_0,  "",byte_1,  "",byte_2, "",byte_3,  "",byte_4,  "",byte_5,  "",byte_6,  "",byte_7);

			//else {MessageInt("Serial Number is NOT as expected for No.",i+1);}		 
		}
		else

			if (rcvMsg.DATA[0] == 0X03)   // Firmware Version Requested

		{
		 // DISPLAY THE DATA RECEIVED
			byte_0 = rcvMsg.DATA[0];
			byte_1 = rcvMsg.DATA[1];
	  		byte_2 = rcvMsg.DATA[2];
			byte_3 = rcvMsg.DATA[3];
			byte_4 = rcvMsg.DATA[4];
	  		byte_5 = rcvMsg.DATA[5];
	  		byte_6 = rcvMsg.DATA[6];
			byte_7 = rcvMsg.DATA[7];
			//byte_8 = rcvMsg.DATA[8];

				MessageData8("[Tx  0E 5A C3 C0 ]:      ","B0", byte_0,  "B1",byte_1,  "B2",byte_2, "B3",byte_3,  "B4",byte_4,  "B5",byte_5,  "B6",byte_6,  "B7",byte_7);

			//else {MessageInt("Software Version is NOT as expected for No.",i+1);}

		}
		else

			if (rcvMsg.DATA[0] == 0X04)   // ETI and PWR cycles requested
		{

			eti_byte1     = rcvMsg.DATA[1];
			eti_byte2     = rcvMsg.DATA[2];
			eti_byte3     = rcvMsg.DATA[3];
			pwr_cyc_byte5 = rcvMsg.DATA[5];
			pwr_cyc_byte6 = rcvMsg.DATA[6];
			total_eti = ((eti_byte1) + (eti_byte2 * 255) + (eti_byte3));
			total_pwr_cyc = (pwr_cyc_byte5 + pwr_cyc_byte6);

			MessageInt("Total ETI in minutes = ",total_eti);
			MessageInt("Total Power Cycles   = ",total_pwr_cyc);
		}

	 }

}




void __fastcall TCanBusForm::ResetSwitchesButtonClick(TObject *Sender)
{


	  Realtime_StampDateTime ();

   /*************************** BYTE 0 LEFT HAND **************************/


	 CanBusForm->SW1Button->Color = clGreen;
	 CanBusForm->SW1Button->BevelOuter = bvRaised;


	 CanBusForm->SW2Button->Color = clGreen;
	 CanBusForm->SW2Button->BevelOuter = bvRaised;



	 CanBusForm->SW3Button->Color = clGreen;
	 CanBusForm->SW3Button->BevelOuter = bvRaised;


	 CanBusForm->SW4Button->Color = clGreen;
	 CanBusForm->SW4Button->BevelOuter = bvRaised;
   

	/*************************** BYTE 3 RIGHT HAND **************************/
	/* Copy the contents of Byte 3  for Right Hand Switches */
	
	
		CanBusForm->SW5Button->Color = clGreen;
		CanBusForm->SW5Button->BevelOuter = bvRaised;
	
	/* ************ 4 WAY TRIM SWITCH  Start *************** */
	
	
		CanBusForm->SW7Button->Color       = clGreen;
		CanBusForm->SW7Button->BevelOuter  = bvRaised;
	
	
		CanBusForm->SW6Button->Color       = clGreen;
		CanBusForm->SW6Button->BevelOuter  = bvRaised;
		
	
		CanBusForm->SW8Button->Color       = clGreen;
		CanBusForm->SW8Button->BevelOuter  = bvRaised;
	

		CanBusForm->SW9Button->Color       = clGreen;
		CanBusForm->SW9Button->BevelOuter  = bvRaised;
	
	/* ************ 4 WAY TRIM SWITCH  End *************** */

	
		CanBusForm->SW12Button->Color = clGreen;
		CanBusForm->SW12Button->BevelOuter = bvRaised;
	
	
		CanBusForm->SW13Button->Color = clGreen;
		CanBusForm->SW13Button->BevelOuter = bvRaised;


	 // Process Right hand switch 3 & 4 for single controller only

	/*************************** BYTE 4 RIGHT HAND **************************/

	
		CanBusForm->SW10Button->Color = clGreen;
		CanBusForm->SW10Button->BevelOuter = bvRaised;
	
		CanBusForm->SW11Button->Color = clGreen;
		CanBusForm->SW11Button->BevelOuter = bvRaised;


}
//---------------------------------------------------------------------------


void Realtime_StampDateTime (){

time_t timer;
struct tm *tblock;
/* gets time of day */
timer = time(NULL);

/* converts date/time to a structure */
tblock = localtime(&timer);


MessageStr(asctime(tblock));



}



void __fastcall TCanBusForm::SwitchTestButtonClick(TObject *Sender)
{

switch0 = 0x40;


}
//---------------------------------------------------------------------------

void __fastcall TCanBusForm::PrintToFileButtonClick(TObject *Sender)
{

String MessageBoxString[100];
char sampledata [100] = "Trigger Pressed";


//MessageBoxString[100] = CanBusForm->Messages->Text;

CanBusForm->Messages->Text = "Test";

  ofstream myfile ("TestResults.txt");

  if (myfile.is_open())
  {
	myfile << "Daco Scientific Ltd.\n";
	myfile << "Shock & Vibration Environmental Testing.\n";
	myfile <<MessageBoxString<<"hello at";
	myfile.close();
  }
  //else cout << "Unable to open file";
}
//---------------------------------------------------------------------------





void __fastcall TCanBusForm::Button2Click(TObject *Sender)
{


  for (i = 0; i < 30; i++) {

 //*************READ THE CURRENT X-AXIS DEFLECTION DATA*************************\\

 X_DeflectionDataStore = (int)rcvMsg.DATA[1];
 X_DeflectionDataStore = (X_DeflectionDataStore << 8) + (int)rcvMsg.DATA[0];
 X_DeflectionDataStore = 0x00;
 X_NegAxis_DeflectionDataStore = 0x00;
 X_DeflectionDataStore, X_NegAxis_DeflectionDataStore = X_DeflectionDataStore & 0x3FFF;


 //*************READ THE CURRENT Y-AXIS DEFLECTION DATA*************************\\

 Y_DeflectionDataStore = (int)rcvMsg.DATA[3];
 Y_DeflectionDataStore = (Y_DeflectionDataStore << 8) + (int)rcvMsg.DATA[2];
 Y_DeflectionDataStore = 0x00;
 Y_NegAxis_DeflectionDataStore = 0x00;
 Y_DeflectionDataStore, Y_NegAxis_DeflectionDataStore = Y_DeflectionDataStore & 0x3FFF;


 CanBusForm->MaxDefPosXBox->Text = X_DeflectionDataStore;
 CanBusForm->MaxDefMinusXBox->Text = X_DeflectionDataStore;

 CanBusForm->MaxDefPosYBox->Text = Y_DeflectionDataStore;
 CanBusForm->MaxDefMinusYBox->Text = Y_DeflectionDataStore;

  CanBusForm->MaxDefPosXBox->Font->Color = clBlack;
  CanBusForm->MaxDefMinusXBox->Font->Color = clBlack;
  CanBusForm->MaxDefPosYBox->Font->Color = clBlack;
  CanBusForm->MaxDefMinusYBox->Font->Color = clBlack;
 }


}
//---------------------------------------------------------------------------


