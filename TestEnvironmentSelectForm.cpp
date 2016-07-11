//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestEnvironmentSelectForm.h"
#include "CanBusSDOForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTestEnvironmentSelect *TestEnvironmentSelect;
 int password_correct = 0;
 int password = 0;

 int CAL_Password = 2678;
 int FAT_Password = 3212;
 int FVT_Password = 7777;
 int LTV_Password = 4444;
 int SVT_Password = 5555;
 int EMC_Password = 3333;

 bool CAL_Password_Correct = False;
 bool FAT_Password_Correct = False;
 bool FVT_Password_Correct = False;
 bool LTV_Password_Correct = False;
 bool SVT_Password_Correct = False;
 bool EMC_Password_Correct = False;

//---------------------------------------------------------------------------
__fastcall TTestEnvironmentSelect::TTestEnvironmentSelect(TComponent* Owner)
	: TForm(Owner)
{





}
//---------------------------------------------------------------------------

void __fastcall TTestEnvironmentSelect::TestEnvironmentListBoxClick(TObject *Sender)

{



		  switch(TestEnvironmentListBox->ItemIndex + 1)
	   {


		  case CAL:

				   if (CAL_Password_Correct == True) {
				   CanBusForm->Messages->Lines->Clear();
				   Message(" -> Calibration & Set-up Environment Selected");
				   Realtime_StampDateTime ();
				   CanBusForm->Color = clHighlight;
				   SetUpFormForCal();
				   CAL_Password_Correct = False;

				   }   else
						Message("Enter Password and Click Accept");

				   break;

		   case FAT:

				   if (FAT_Password_Correct == True) {
				   CanBusForm->Messages->Lines->Clear();
				   Message(" -> Factory Acceptance Test Environment Selected");
				   Realtime_StampDateTime ();

				   CanBusForm->Color = clSilver;
				   FAT_Password_Correct = False;

				   SetUpFormForFat();

				   }  else
						Message("Enter Password and Click Accept");



				   break;

		   case FVT:

				   if (FVT_Password_Correct == True) {
				   CanBusForm->Messages->Lines->Clear();
				   Message(" -> Firmware Verification Test Environment Selected ");
				   Realtime_StampDateTime ();
				   SetpFormForFVT();

				   FVT_Password_Correct = False;

				   } else
						Message("Enter Password and Click Accept");

				   break;

		   case LTV:
				   if (LTV_Password_Correct == True) {
				   CanBusForm->Messages->Lines->Clear();
				   Message(" -> Low Temperature Verification Test Environment Selected");
				   Realtime_StampDateTime ();
				   TestEnvironmentSelect->Visible = False;
				   CanBusForm->ResetSwitchesButton->Visible = True;
				   TestEnvironmentSelect->Visible = False;
				   CanBusForm->Color = clGreen;

				   SetUpFormForLTV();

				   LTV_Password_Correct = False;

				   } else
						Message("Enter Password and Click Accept");

				   break;

		   case SVT:
				   if (SVT_Password_Correct == True) {
				   CanBusForm->Messages->Lines->Clear();
				   Message(" -> Shock & Vibration Test Environment Selected");
				   Realtime_StampDateTime ();
				   CanBusForm->Panel2->Visible = False;
				   CanBusForm->Panel5->Visible = True;
				   TestEnvironmentSelect->Visible = False;
				   CanBusForm->ResetSwitchesButton->Visible = True;
				   TestEnvironmentSelect->Visible = False;
				   CanBusForm->Color = clGreen;

				   SetUpFormForSVT();

				   SVT_Password_Correct = False;

				   } else
						Message("Enter Password and Click Accept");

				   break;

			case EMC:

				   if (EMC_Password_Correct == True) {
				   CanBusForm->Messages->Lines->Clear();
				   Message(" -> EMC Test Environment Selected");
				   Realtime_StampDateTime ();

				   SetUpFormForEMC();

				   EMC_Password_Correct = False;

				   }  else
						Message("Enter Password and Click Accept");


				   break;

		}


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TTestEnvironmentSelect::Button1Click(TObject *Sender)


{
	 if (TestEnvironmentSelect->Edit1->Text == CAL_Password) {CAL_Password_Correct = True;
	 Message("Password Accepted - Select Calibration & Setup From List To Begin.");}

	 else if (TestEnvironmentSelect->Edit1->Text == FAT_Password) {FAT_Password_Correct = True;
	 Message("Password Accepted - Select Factory Acceptance Test From List To Begin.");}

	 else if (TestEnvironmentSelect->Edit1->Text == FVT_Password) {FVT_Password_Correct = True;
	 Message("Password Accepted - Select Firmware Verification From List To Begin.");}

	 else if (TestEnvironmentSelect->Edit1->Text == LTV_Password) {LTV_Password_Correct = True;
	 Message("Password Accepted - Select Low Temperature Verification Test From List To Begin.");}

	 else if (TestEnvironmentSelect->Edit1->Text == SVT_Password) {SVT_Password_Correct = True;
	 Message("Password Accepted - Select Shock & Vibration Test From List To Begin.");}

	 else if (TestEnvironmentSelect->Edit1->Text == EMC_Password) {EMC_Password_Correct = True;
	 Message("Password Accepted - Select EMC Test From List To Begin.");}

	 else Message("Password Incorrect");
	 TestEnvironmentSelect->Edit1->Text = "";


}
//---------------------------------------------------------------------------

  void SetUpFormForEMC() {


  //Add / Remove Panels & Buttons
   CanBusForm->Panel2->Visible = False;
   CanBusForm->Panel5->Visible = True;
   CanBusForm->Panel4->Visible = True;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->MaxDefPanel->Visible = True;
   CanBusForm->ResetSwitchesButton->Visible = True;
   CanBusForm->ResetMaxMinButton->Visible = True;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->PrintToFileButton->Visible = False;
   CanBusForm->Title->Font->Color = clWhite;

   //Setup Buttons Positions Layout
   CanBusForm->Color = clGreen;
   CanBusForm->Messages->Top = 112;
   CanBusForm->Messages->Height = 455;
   CanBusForm->ClearMessButton->Top = 170;
   CanBusForm->ClearMessButton->Left = 923;
   CanBusForm->MaxDefPanel->Top = 588;
   CanBusForm->MaxDefPanel->Left = 556;
   CanBusForm->ResetMaxMinButton->Top = 676;
   //CanBusForm->ResetSwitchesButton->Top = 600;
   CanBusForm->PrintToFileButton->Top = 116;
   CanBusForm->PrintToFileButton->Left = 932;
   CanBusForm->QuitButton->Left = 1086;
   CanBusForm->QuitButton->Top = 687;

   //Setup Switches Font Colour
   CanBusForm->SW1Button->Font->Color = clWhite;
   CanBusForm->SW2Button->Font->Color = clWhite;
   CanBusForm->SW3Button->Font->Color = clWhite;
   CanBusForm->SW4Button->Font->Color = clWhite;
   CanBusForm->SW5Button->Font->Color = clWhite;
   CanBusForm->SW6Button->Font->Color = clWhite;
   CanBusForm->SW7Button->Font->Color = clWhite;
   CanBusForm->SW8Button->Font->Color = clWhite;
   CanBusForm->SW9Button->Font->Color = clWhite;
   CanBusForm->SW10Button->Font->Color = clWhite;
   CanBusForm->SW11Button->Font->Color = clWhite;
   CanBusForm->SW12Button->Font->Color = clWhite;
   CanBusForm->SW13Button->Font->Color = clWhite;

   //Setup BUtton Colour

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


 //Set-up For Shock & Vibration Testing


   void SetUpFormForSVT() {


  //Add / Remove Panels & Buttons
   CanBusForm->Panel2->Visible = False;
   CanBusForm->Panel5->Visible = True;
   CanBusForm->Panel4->Visible = True;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->MaxDefPanel->Visible = True;
   CanBusForm->ResetSwitchesButton->Visible = True;
   CanBusForm->ResetMaxMinButton->Visible = True;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->PrintToFileButton->Visible = False;
   CanBusForm->Title->Font->Color = clWhite;

   //Setup Buttons Positions Layout
   CanBusForm->Color = clGreen;
   CanBusForm->Messages->Top = 112;
   CanBusForm->Messages->Height = 455;
   CanBusForm->ClearMessButton->Top = 170;
   CanBusForm->ClearMessButton->Left = 923;
   CanBusForm->MaxDefPanel->Top = 588;
   CanBusForm->MaxDefPanel->Left = 556;
   CanBusForm->ResetMaxMinButton->Top = 676;
   //CanBusForm->ResetSwitchesButton->Top = 600;
   CanBusForm->PrintToFileButton->Top = 116;
   CanBusForm->PrintToFileButton->Left = 932;
   CanBusForm->QuitButton->Left = 1086;
   CanBusForm->QuitButton->Top = 687;

   //Setup Switches Font Colour
   CanBusForm->SW1Button->Font->Color = clWhite;
   CanBusForm->SW2Button->Font->Color = clWhite;
   CanBusForm->SW3Button->Font->Color = clWhite;
   CanBusForm->SW4Button->Font->Color = clWhite;
   CanBusForm->SW5Button->Font->Color = clWhite;
   CanBusForm->SW6Button->Font->Color = clWhite;
   CanBusForm->SW7Button->Font->Color = clWhite;
   CanBusForm->SW8Button->Font->Color = clWhite;
   CanBusForm->SW9Button->Font->Color = clWhite;
   CanBusForm->SW10Button->Font->Color = clWhite;
   CanBusForm->SW11Button->Font->Color = clWhite;
   CanBusForm->SW12Button->Font->Color = clWhite;
   CanBusForm->SW13Button->Font->Color = clWhite;

   //Setup BUtton Colour

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

 void SetUpFormForLTV() {


  //Add / Remove Panels & Buttons
   CanBusForm->Panel2->Visible = False;
   CanBusForm->Panel5->Visible = True;
   CanBusForm->Panel4->Visible = True;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->MaxDefPanel->Visible = False;
   CanBusForm->ResetSwitchesButton->Visible = True;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->PrintToFileButton->Visible = True;

   //Setup Buttons Positions Layout
   CanBusForm->Color = clGreen;
   CanBusForm->Messages->Top = 116;
   CanBusForm->Messages->Height = 465;
   CanBusForm->ClearMessButton->Top = 600;
   CanBusForm->ClearMessButton->Left = 690;
   CanBusForm->MaxDefPanel->Top = 410;
   CanBusForm->MaxDefPanel->Left = 17;
   CanBusForm->ResetSwitchesButton->Top = 600;
   CanBusForm->PrintToFileButton->Top = 600;
   CanBusForm->PrintToFileButton->Left = 556;
   CanBusForm->PrintToFileButton->Top = 640;

   //Setup Switches Font Colour
   CanBusForm->SW1Button->Font->Color = clWhite;
   CanBusForm->SW2Button->Font->Color = clWhite;
   CanBusForm->SW3Button->Font->Color = clWhite;
   CanBusForm->SW4Button->Font->Color = clWhite;
   CanBusForm->SW5Button->Font->Color = clWhite;
   CanBusForm->SW6Button->Font->Color = clWhite;
   CanBusForm->SW7Button->Font->Color = clWhite;
   CanBusForm->SW8Button->Font->Color = clWhite;
   CanBusForm->SW9Button->Font->Color = clWhite;
   CanBusForm->SW10Button->Font->Color = clWhite;
   CanBusForm->SW11Button->Font->Color = clWhite;
   CanBusForm->SW12Button->Font->Color = clWhite;
   CanBusForm->SW13Button->Font->Color = clWhite;

   //Setup BUtton Colour

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

//////Firmware Verification Testing////////

  void SetpFormForFVT(){

   CanBusForm->Panel2->Visible = True;
   CanBusForm->Panel5->Visible = True;
   CanBusForm->MaxDefPanel->Visible = False;
   CanBusForm->ResetMaxMinButton->Visible = False;
   TestEnvironmentSelect->Visible = False;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->Color = clSilver;
   CanBusForm->Title->Font->Color = clBlack;

   CanBusForm->Messages->Top = 392;
   CanBusForm->Messages->Height = 233;

   //Setup Switches Button Font Colour
   CanBusForm->SW1Button->Font->Color = clBlue;
   CanBusForm->SW2Button->Font->Color = clBlue;
   CanBusForm->SW3Button->Font->Color = clBlue;
   CanBusForm->SW4Button->Font->Color = clBlue;
   CanBusForm->SW5Button->Font->Color = clRed;
   CanBusForm->SW6Button->Font->Color = clBlack;
   CanBusForm->SW7Button->Font->Color = clBlack;
   CanBusForm->SW8Button->Font->Color = clBlack;
   CanBusForm->SW9Button->Font->Color = clBlack;
   CanBusForm->SW10Button->Font->Color = clGreen;
   CanBusForm->SW11Button->Font->Color = clGreen;
   CanBusForm->SW12Button->Font->Color = clRed;
   CanBusForm->SW13Button->Font->Color = clRed;

   CanBusForm->SW1Button->Color = clBtnFace;
   CanBusForm->SW2Button->Color = clBtnFace;
   CanBusForm->SW3Button->Color = clBtnFace;
   CanBusForm->SW4Button->Color = clBtnFace;
   CanBusForm->SW5Button->Color = clBtnFace;
   CanBusForm->SW6Button->Color = clBtnFace;
   CanBusForm->SW7Button->Color = clBtnFace;
   CanBusForm->SW8Button->Color = clBtnFace;
   CanBusForm->SW9Button->Color = clBtnFace;
   CanBusForm->SW10Button->Color = clBtnFace;
   CanBusForm->SW11Button->Color = clBtnFace;
   CanBusForm->SW12Button->Color = clBtnFace;
   CanBusForm->SW13Button->Color = clBtnFace;

   CanBusForm->ClearMessButton->Top = 645;
   CanBusForm->ClearMessButton->Left = 556;

   //Add / Remove Buttons
   CanBusForm->PrintToFileButton->Visible = False;
   CanBusForm->ResetSwitchesButton->Visible = False;

  }



 void SetUpFormForCal(){


   //Add / Remove Panels
   CanBusForm->Panel2->Visible = True;
   CanBusForm->Panel5->Visible = True;
   CanBusForm->Panel2->Height = 110;
   CanBusForm->Messages->Height = 410;
   CanBusForm->Messages->Top = 245;
   CanBusForm->MessagesLabel->Top = 225;
   CanBusForm->ClearMessButton->Top = 670;
   CanBusForm->ClearMessButton->Left = 556;

   //Add / Remove Buttons
   TestEnvironmentSelect->Visible = False;
   CanBusForm->ResetSwitchesButton->Visible = False;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->PrintToFileButton->Visible = False;
   CanBusForm->IBITButton->Visible = False;
   CanBusForm->RawDataButton->Visible = False;
   CanBusForm->SetTimingButton->Visible = False;
   CanBusForm->SetOffsetButton->Visible = False;
   CanBusForm->SetMaxButton->Visible = False;
   CanBusForm->StartIBITButton->Visible = False;
   CanBusForm->GetTimingButton->Visible = True;
   CanBusForm->GetOffsetButton->Visible = False;
   CanBusForm->GetMaxValButton->Visible = False;
   CanBusForm->StopIBITButton->Visible = False;
   CanBusForm->CheckCurveButton->Visible = False;
   //CanBusForm->AddMilCANTrafficButton->Visible = False;

   //Button Positions
   CanBusForm->SetCurveDataButton->Left = 16;
   CanBusForm->SetCurveDataButton->Top = 30;
   CanBusForm->SelectCurveButton->Top = 30;
   CanBusForm->SelectCurveButton->Left = 97;
   CanBusForm->GetCurveButton->Top = 30;
   CanBusForm->GetCurveButton->Left = 178;
   CanBusForm->GetTimingButton->Top = 65;
   CanBusForm->ModeButton->Top = 16;
   CanBusForm->ModeButton->Left = 178;
   CanBusForm->GetTimingButton->Left = 179;
   CanBusForm->RequestCurveVerButton->Top = 30;
   CanBusForm->RequestCurveVerButton->Left = 259;
   CanBusForm->RawDataButton->Top = 65;
   CanBusForm->RawDataButton->Left = 17;
   CanBusForm->GetConfigButton->Top = 65;
   CanBusForm->GetConfigButton->Left = 98;
   CanBusForm->DataRequestButton->Top = 65;
   CanBusForm->DataRequestButton->Left = 17;

  }

	void SetUpFormForFat(){

   //Add / Remove Panels
   CanBusForm->Panel2->Visible = True;
   CanBusForm->Panel5->Visible = True;
   CanBusForm->Panel2->Height = 110;
   CanBusForm->Messages->Height = 410;
   CanBusForm->Messages->Top = 245;
   CanBusForm->MessagesLabel->Top = 225;
   CanBusForm->ClearMessButton->Top = 670;
   CanBusForm->ClearMessButton->Left = 556;

   //Add / Remove Buttons
   TestEnvironmentSelect->Visible = False;
   CanBusForm->ResetSwitchesButton->Visible = False;
   TestEnvironmentSelect->Visible = False;
   CanBusForm->PrintToFileButton->Visible = False;
   CanBusForm->IBITButton->Visible = True;
   CanBusForm->RawDataButton->Visible = False;
   CanBusForm->SetTimingButton->Visible = False;
   CanBusForm->SetOffsetButton->Visible = False;
   CanBusForm->SetMaxButton->Visible = False;
   CanBusForm->StartIBITButton->Visible = False;
   CanBusForm->GetTimingButton->Visible = False;
   CanBusForm->GetOffsetButton->Visible = False;
   CanBusForm->GetMaxValButton->Visible = False;
   CanBusForm->StopIBITButton->Visible = False;
   CanBusForm->CheckCurveButton->Visible = False;
   CanBusForm->SetCurveDataButton->Visible = False;
   CanBusForm->SelectCurveButton->Visible = False;
   CanBusForm->RequestCurveVerButton->Visible = False;
   CanBusForm->GetCurveButton->Visible = False;
   //CanBusForm->AddMilCANTrafficButton->Visible = False;

   //Button Positions

   CanBusForm->ModeButton->Top = 16;
   CanBusForm->ModeButton->Left = 259;
   CanBusForm->IBITButton->Top = 16;
   CanBusForm->IBITButton->Left = 178;

   CanBusForm->GetConfigButton->Top = 65;
   CanBusForm->GetConfigButton->Left = 98;
   CanBusForm->DataRequestButton->Top = 65;
   CanBusForm->DataRequestButton->Left = 17;


 }








