//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("SelectCurveFormCode.cpp", SelectCurveForm);
USEFORM("SetCurveFormCode.cpp", SetCurveForm);
USEFORM("SetMaxValueForm.cpp", SetMaxValuesForm);
USEFORM("StopIBITForm.cpp", StopIBIT);
USEFORM("TestEnvironmentSelectForm.cpp", TestEnvironmentSelect);
USEFORM("StartIBITForm.cpp", StartIBIT);
USEFORM("SetOffsetForm.cpp", OffsetSelectionForm);
USEFORM("SetTimingForm.cpp", TimingForm);
USEFORM("PBITStatus.cpp", PBITCodeSelect);
USEFORM("CurveVersionSelect.cpp", CurveVersionForm);
USEFORM("CheckCurveDataForm.cpp", CheckCurveForm);
USEFORM("CanBusSDOForm.cpp", CanBusForm);
USEFORM("CBITStatus.cpp", CBITCodeSelect);
USEFORM("GetConfigForm.cpp", GetConfig);
USEFORM("IBIT_ManualJoystickTest.cpp", ManIBITJoy);
USEFORM("IBIT_ManualSwitchTest.cpp", ManIBIT);
USEFORM("IBITStatus.cpp", IBITCodeSelect);
USEFORM("GetCurveDataForm.cpp", GetCurveForm);
USEFORM("IBITFormCode.cpp", IBITForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TCanBusForm), &CanBusForm);
		Application->CreateForm(__classid(TCBITCodeSelect), &CBITCodeSelect);
		Application->CreateForm(__classid(TCheckCurveForm), &CheckCurveForm);
		Application->CreateForm(__classid(TCurveVersionForm), &CurveVersionForm);
		Application->CreateForm(__classid(TGetConfig), &GetConfig);
		Application->CreateForm(__classid(TGetCurveForm), &GetCurveForm);
		Application->CreateForm(__classid(TManIBITJoy), &ManIBITJoy);
		Application->CreateForm(__classid(TManIBIT), &ManIBIT);
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
		Application->CreateForm(__classid(TTestEnvironmentSelect), &TestEnvironmentSelect);
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
