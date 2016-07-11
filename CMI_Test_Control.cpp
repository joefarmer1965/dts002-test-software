//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("SelectCurveFormCode.cpp", SelectCurveForm);
USEFORM("SetCurveFormCode.cpp", SetCurveForm);
USEFORM("PBITStatus.cpp", PBITCodeSelect);
USEFORM("StartIBITForm.cpp", StartIBIT);
USEFORM("StopIBITForm.cpp", StopIBIT);
USEFORM("SetTimingForm.cpp", TimingForm);
USEFORM("SetMaxValueForm.cpp", SetMaxValuesForm);
USEFORM("SetOffsetForm.cpp", OffsetSelectionForm);
USEFORM("IBIT_ManualSwitchTest.cpp", ManIBIT);
USEFORM("CurveVersionSelect.cpp", CurveVersionForm);
USEFORM("CanBusSDOForm.cpp", CanBusForm);
USEFORM("CBITStatus.cpp", CBITCodeSelect);
USEFORM("IBITStatus.cpp", IBITCodeSelect);
USEFORM("IBIT_ManualJoystickTest.cpp", ManIBITJoy);
USEFORM("IBITFormCode.cpp", IBITForm);
USEFORM("GetConfigForm.cpp", GetConfig);
USEFORM("GetCurveDataForm.cpp", GetCurveForm);
USEFORM("CheckCurveDataForm.cpp", CheckCurveForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TCanBusForm), &CanBusForm);
		Application->CreateForm(__classid(TCBITCodeSelect), &CBITCodeSelect);
		Application->CreateForm(__classid(TCurveVersionForm), &CurveVersionForm);
		Application->CreateForm(__classid(TGetConfig), &GetConfig);
		Application->CreateForm(__classid(TGetCurveForm), &GetCurveForm);
		Application->CreateForm(__classid(TIBITForm), &IBITForm);
		Application->CreateForm(__classid(TIBITCodeSelect), &IBITCodeSelect);
		Application->CreateForm(__classid(TPBITCodeSelect), &PBITCodeSelect);
		Application->CreateForm(__classid(TSelectCurveForm), &SelectCurveForm);
		Application->CreateForm(__classid(TSetCurveForm), &SetCurveForm);
		Application->CreateForm(__classid(TSetMaxValuesForm), &SetMaxValuesForm);
		Application->CreateForm(__classid(TOffsetSelectionForm), &OffsetSelectionForm);
		Application->CreateForm(__classid(TTimingForm), &TimingForm);
		Application->CreateForm(__classid(TStartIBIT), &StartIBIT);
		Application->CreateForm(__classid(TStopIBIT), &StopIBIT);
		Application->CreateForm(__classid(TManIBIT), &ManIBIT);
		Application->CreateForm(__classid(TManIBITJoy), &ManIBITJoy);
		Application->CreateForm(__classid(TCheckCurveForm), &CheckCurveForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
