//---------------------------------------------------------------------------

#ifndef CanBusSDOFormH
#define CanBusSDOFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCanBusForm : public TForm
{
__published:	// IDE-managed Components
		TLabel *Title;
		TButton *StartNodeButton;
		TLabel *MessagesLabel;
		TMemo *Messages;
		TPanel *PassFailPanel;
		TButton *QuitButton;
		TPanel *Panel1;
		TLabel *ReadDeviceLabel;
		TComboBox *AddressComboBox;
		TLabel *AddressLabel;
		TLabel *IDLabel;
		TPanel *Panel2;
		TLabel *MessLabel;
		TButton *ResetNodeButton;
		TButton *SelectCurveButton;
		TButton *SetOffsetButton;
		TButton *SetMaxButton;
		TButton *DataRequestButton;
		TButton *SetCurveDataButton;
		TButton *RequestCurveVerButton;
		TButton *ClearMessButton;
		TButton *EnterConfig;
		TLabel *Label3;
		TButton *StopButton;
		TButton *ExitConfigButton;
		TButton *RawDataButton;
	    TButton *SetTimingButton;
		TButton *GetTimingButton;
		TButton *GetCurveButton;
	TButton *GetOffsetButton;
	TButton *GetMaxValButton;
	TButton *StopIBITButton;
	TButton *GetConfigButton;
	TPanel *Panel3;
	TLabel *ControllerLabel;
	TLabel *Label8;
	TComboBox *ControllerComboBox;
	TButton *CheckCurveButton;
	TButton *Button1;
	TPanel *Panel5;
	TButton *StartIBITButton;
	TButton *PBITButton;
	TButton *CBITButton;
	TButton *IBITButton;
	TButton *ModeButton;
	TButton *ResetSwitchesButton;
	TPanel *SwitchPanelLeft;
	TPanel *SW1Button;
	TPanel *SW2Button;
	TPanel *SW3Button;
	TPanel *SW4Button;
	TPanel *SwitchPanelRight;
	TPanel *SW5Button;
	TPanel *SW6Button;
	TPanel *SW7Button;
	TPanel *SW8Button;
	TPanel *SW9Button;
	TPanel *SW12Button;
	TPanel *SW13Button;
	TPanel *SW10Button;
	TPanel *SW11Button;
	TTimer *SyncTimer;
	TPanel *Panel7;
	TEdit *IDText;
	TEdit *RTRText;
	TEdit *DataLenText;
	TEdit *DataNo;
	TEdit *DataTime;
	TLabel *RTRLabel;
	TLabel *DataLenLabel;
	TLabel *DataNoLabel;
	TLabel *Label4;
	TLabel *DataLabel;
	TEdit *Byte0Text;
	TEdit *Byte1Text;
	TEdit *Byte2Text;
	TEdit *Byte3Text;
	TLabel *DataBytesLabel;
	TLabel *DataByteLabel;
	TLabel *Label2;
	TLabel *Label7;
	TPanel *Panel4;
	TEdit *SWID;
	TEdit *SWRTR;
	TEdit *SWDataLen;
	TEdit *SWNo;
	TEdit *SwitchTime;
	TLabel *SWIDLabel;
	TLabel *SWRTRLabel;
	TLabel *SWDataLenLabel;
	TLabel *SWNoLabel;
	TLabel *Label6;
	TLabel *SWLabel;
	TEdit *SWByte0;
	TEdit *SWByte1;
	TEdit *SWByte2;
	TEdit *SWByte3;
	TEdit *SWByte4;
	TEdit *SWByte5;
	TLabel *Label5;
	TLabel *SWByteLabel;
	TEdit *MessID;
	TEdit *MessRTR;
	TEdit *MessDataLen;
	TEdit *MessNo;
	TLabel *MessIDLabel;
	TLabel *MessRTRLabel;
	TLabel *MessDataLenLabel;
	TLabel *MessNoLabel;
	TLabel *MessageLabel;
	TEdit *MessByte0;
	TEdit *MessByte1;
	TEdit *MessByte2;
	TEdit *MessByte3;
	TEdit *MessByte4;
	TEdit *MessByte5;
	TEdit *MessByte6;
	TEdit *MessByte7;
	TLabel *MessBytesLabel;
	TLabel *MessByteLabel;
	TPanel *Panel6;
	TEdit *XData;
	TLabel *XDataLabel;
	TPaintBox *XBarBox;
	TLabel *XAxisLabel;
	TEdit *YData;
	TPaintBox *YBarBox;
	TLabel *YAxisLabel;
	TLabel *YDataLabel;
	TButton *PrintToFileButton;
	TPanel *MaxDefPanel;
	TEdit *MaxDefMinusXBox;
	TEdit *MaxDefPosXBox;
	TLabel *Label1;
	TLabel *Label9;
	TEdit *MaxDefMinusYBox;
	TEdit *MaxDefPosYBox;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TButton *ResetMaxMinButton;

		void __fastcall StartNodeButtonClick(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);
		void __fastcall QuitButtonClick(TObject *Sender);
		void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
		void __fastcall XBarBoxPaint(TObject *Sender);
		void __fastcall YBarBoxPaint(TObject *Sender);
		void __fastcall SyncTimerTimer(TObject *Sender);
		void __fastcall AddressComboBoxChange(TObject *Sender);
		void __fastcall IBITButtonClick(TObject *Sender);
		void __fastcall ModeButtonClick(TObject *Sender);
		void __fastcall ResetNodeButtonClick(TObject *Sender);
		void __fastcall PBITButtonClick(TObject *Sender);
		void __fastcall CBITButtonClick(TObject *Sender);
		void __fastcall DataRequestButtonClick(TObject *Sender);
		void __fastcall StartIBITButtonClick(TObject *Sender);
		void __fastcall SelectCurveButtonClick(TObject *Sender);
		void __fastcall SetOffsetButtonClick(TObject *Sender);
		void __fastcall SetMaxButtonClick(TObject *Sender);
		void __fastcall SetCurveDataButtonClick(TObject *Sender);
		void __fastcall RequestCurveVerButtonClick(TObject *Sender);
		void __fastcall ClearMessButtonClick(TObject *Sender);
		void __fastcall EnterConfigClick(TObject *Sender);
		void __fastcall StopButtonClick(TObject *Sender);
		void __fastcall ExitConfigButtonClick(TObject *Sender);
		void __fastcall RawDataButtonClick(TObject *Sender);
		void __fastcall SetTimingButtonClick(TObject *Sender);
		void __fastcall GetTimingButtonClick(TObject *Sender);
		void __fastcall GetCurveButtonClick(TObject *Sender);
		void __fastcall GetOffsetButtonClick(TObject *Sender);
		void __fastcall GetMaxValButtonClick(TObject *Sender);
		void __fastcall StopIBITButtonClick(TObject *Sender);
		void __fastcall GetConfigButtonClick(TObject *Sender);
		void __fastcall ControllerComboBoxChange(TObject *Sender);
		void __fastcall CheckCurveButtonClick(TObject *Sender);
		void __fastcall SelectEnvironClick(TObject *Sender);
		void __fastcall ResetSwitchesButtonClick(TObject *Sender);
	void __fastcall SwitchTestButtonClick(TObject *Sender);
	void __fastcall PrintToFileButtonClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);


private:  // User declarations
public:   // User declarations

        __fastcall TCanBusForm(TComponent* Owner);

};
//------------------------------------------------------------------------
extern PACKAGE TCanBusForm *CanBusForm;
//---------------------------------------------------------------------------



void DisplayData();
void DisplayMess();
void DisplaySwitches();
void SwitchGraphics();
void SwitchGraphicsESS();
void AxesGraphics();
void MessageStr(char *string[80]);
void Message(char *mess);
void MessageInt(char *mess, int num);
void MessageInt2(char *mess0, int num0, char *mess1,int num1,char *mess2);
void MessageData( char *mess, int codelsb, int codemsb, int state, int errors);
char * HexTwo(int num);
char * HexThree(int num);
char * HexEight(unsigned long num);
void Reset();
void ProcessCBITResponse();
void ProcessPBITResponse();
void ProcessIBITResponse();
void DisplayDataTime(unsigned int time);
void DisplaySwitchTime(unsigned int time);
void ProcessTimingResponse();
void CheckCurveVersionResponse(int curve_id );
void Check_Data(int curve_id);
void ProcessConfigDataResponse();
void ProcessConfigDataResponse_CAL();
void Check_GetCurveDataResponse(int curveID);
void ProcessOffsetDataResponse ();
void ProcessMaxValueResponse ();
void Realtime_StampDateTime ();
void MaxDeflectionGraphics(); //**New Added on the 26/11/15**
#endif
