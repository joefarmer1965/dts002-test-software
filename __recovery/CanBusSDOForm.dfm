object CanBusForm: TCanBusForm
  Left = 309
  Top = 56
  Caption = 'Test Control'
  ClientHeight = 745
  ClientWidth = 1173
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlue
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 20
  object Title: TLabel
    Left = 535
    Top = 8
    Width = 394
    Height = 33
    Alignment = taCenter
    AutoSize = False
    Caption = 'DTS0002 DP414-3 & DP1236-3 Test Control  V2.01'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object MessagesLabel: TLabel
    Left = 556
    Top = 370
    Width = 95
    Height = 16
    Caption = 'Message Box'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object IDLabel: TLabel
    Left = 615
    Top = 433
    Width = 41
    Height = 16
    AutoSize = False
    Caption = 'ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 408
    Top = 235
    Width = 70
    Height = 16
    Caption = 'STATUS: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label13: TLabel
    Left = 393
    Top = 300
    Width = 112
    Height = 20
    Caption = 'Switch Status'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StartNodeButton: TButton
    Left = 354
    Top = 108
    Width = 81
    Height = 33
    Caption = 'Start Node'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = StartNodeButtonClick
  end
  object Messages: TMemo
    Left = 556
    Top = 392
    Width = 353
    Height = 233
    Color = clBtnFace
    Ctl3D = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    HideSelection = False
    ParentCtl3D = False
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object PassFailPanel: TPanel
    Left = 354
    Top = 256
    Width = 182
    Height = 32
    BevelOuter = bvNone
    Color = clInactiveBorder
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 3
  end
  object QuitButton: TButton
    Left = 834
    Top = 691
    Width = 75
    Height = 26
    Caption = 'QUIT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = QuitButtonClick
  end
  object Panel1: TPanel
    Left = 354
    Top = 8
    Width = 81
    Height = 89
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 4
    object ReadDeviceLabel: TLabel
      Left = 8
      Top = 6
      Width = 50
      Height = 16
      Alignment = taCenter
      Caption = 'Device'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object AddressLabel: TLabel
      Left = 8
      Top = 28
      Width = 59
      Height = 16
      Caption = 'Address'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object AddressComboBox: TComboBox
      Left = 8
      Top = 54
      Width = 57
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnChange = AddressComboBoxChange
      Items.Strings = (
        '0'
        '1'
        '2'
        '3')
    end
  end
  object Panel2: TPanel
    Left = 556
    Top = 114
    Width = 353
    Height = 207
    Color = clActiveBorder
    ParentBackground = False
    ShowCaption = False
    TabOrder = 5
    Visible = False
    object MessLabel: TLabel
      Left = 96
      Top = 8
      Width = 155
      Height = 20
      Alignment = taCenter
      Caption = 'Message Requests'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SelectCurveButton: TButton
      Left = 259
      Top = 30
      Width = 75
      Height = 26
      Caption = 'Select Curve'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = SelectCurveButtonClick
    end
    object SetOffsetButton: TButton
      Left = 16
      Top = 97
      Width = 75
      Height = 26
      Caption = 'Set Offset'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = SetOffsetButtonClick
    end
    object SetMaxButton: TButton
      Left = 16
      Top = 129
      Width = 75
      Height = 26
      Caption = 'Set Max Val'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = SetMaxButtonClick
    end
    object DataRequestButton: TButton
      Left = 97
      Top = 30
      Width = 75
      Height = 26
      Caption = 'Data Request'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = DataRequestButtonClick
    end
    object SetCurveDataButton: TButton
      Left = 178
      Top = 30
      Width = 75
      Height = 26
      Caption = 'Set Curve '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = SetCurveDataButtonClick
    end
    object RequestCurveVerButton: TButton
      Left = 260
      Top = 62
      Width = 75
      Height = 26
      Caption = 'Curve Version'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = RequestCurveVerButtonClick
    end
    object RawDataButton: TButton
      Left = 16
      Top = 30
      Width = 75
      Height = 26
      Caption = 'Get Raw Data'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = RawDataButtonClick
    end
    object SetTimingButton: TButton
      Left = 17
      Top = 65
      Width = 75
      Height = 26
      Caption = 'Set Timing'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = SetTimingButtonClick
    end
    object GetTimingButton: TButton
      Left = 98
      Top = 65
      Width = 75
      Height = 26
      Caption = 'Get Timing'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = GetTimingButtonClick
    end
    object GetCurveButton: TButton
      Left = 179
      Top = 62
      Width = 75
      Height = 26
      Caption = 'Get Curve'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = GetCurveButtonClick
    end
    object GetOffsetButton: TButton
      Left = 98
      Top = 97
      Width = 75
      Height = 26
      Caption = 'Get Offset'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = GetOffsetButtonClick
    end
    object GetMaxValButton: TButton
      Left = 97
      Top = 129
      Width = 75
      Height = 26
      Caption = 'Get Max Val'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
      OnClick = GetMaxValButtonClick
    end
    object StopIBITButton: TButton
      Left = 97
      Top = 161
      Width = 75
      Height = 26
      Caption = 'Stop IBIT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 12
      OnClick = StopIBITButtonClick
    end
    object GetConfigButton: TButton
      Left = 179
      Top = 97
      Width = 75
      Height = 26
      Caption = 'Get Config'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
      OnClick = GetConfigButtonClick
    end
    object CheckCurveButton: TButton
      Left = 260
      Top = 97
      Width = 75
      Height = 26
      Caption = 'Check Curve'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 14
      OnClick = CheckCurveButtonClick
    end
    object StartIBITButton: TButton
      Left = 16
      Top = 161
      Width = 75
      Height = 26
      Caption = 'Start IBIT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 15
      OnClick = StartIBITButtonClick
    end
  end
  object ResetNodeButton: TButton
    Left = 353
    Top = 147
    Width = 183
    Height = 37
    Caption = 'Reset Node'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = ResetNodeButtonClick
  end
  object ClearMessButton: TButton
    Left = 556
    Top = 635
    Width = 121
    Height = 36
    Caption = 'Clear Messages'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = ClearMessButtonClick
  end
  object EnterConfig: TButton
    Left = 354
    Top = 190
    Width = 81
    Height = 33
    Caption = 'Enter Config'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = EnterConfigClick
  end
  object StopButton: TButton
    Left = 453
    Top = 109
    Width = 84
    Height = 32
    Caption = 'Stop Node'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = StopButtonClick
  end
  object ExitConfigButton: TButton
    Left = 453
    Top = 190
    Width = 84
    Height = 32
    Caption = 'Exit Config'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ExitConfigButtonClick
  end
  object Panel3: TPanel
    Left = 453
    Top = 8
    Width = 84
    Height = 89
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 11
    object ControllerLabel: TLabel
      Left = 8
      Top = 10
      Width = 68
      Height = 16
      Alignment = taCenter
      Caption = 'Controller'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 8
      Top = 28
      Width = 45
      Height = 16
      Caption = 'Select'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ControllerComboBox: TComboBox
      Left = 8
      Top = 54
      Width = 63
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = ControllerComboBoxChange
      Items.Strings = (
        'DP414'
        'DP1236')
    end
  end
  object Button1: TButton
    Left = 17
    Top = 8
    Width = 320
    Height = 41
    Caption = 'Select Test Environment'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 12
    OnClick = SelectEnvironClick
  end
  object Panel5: TPanel
    Left = 556
    Top = 35
    Width = 353
    Height = 62
    Color = clActiveBorder
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clSilver
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 13
    Visible = False
    object PBITButton: TButton
      Left = 16
      Top = 16
      Width = 75
      Height = 35
      Caption = 'PBIT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = PBITButtonClick
    end
    object CBITButton: TButton
      Left = 97
      Top = 16
      Width = 75
      Height = 35
      Caption = 'CBIT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = CBITButtonClick
    end
    object IBITButton: TButton
      Left = 178
      Top = 16
      Width = 75
      Height = 35
      Caption = 'IBIT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = IBITButtonClick
    end
    object ModeButton: TButton
      Left = 259
      Top = 16
      Width = 75
      Height = 35
      Caption = 'MODE'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = ModeButtonClick
    end
  end
  object ResetSwitchesButton: TButton
    Left = 355
    Top = 531
    Width = 181
    Height = 39
    Caption = 'Reset Switches'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
    Visible = False
    OnClick = ResetSwitchesButtonClick
  end
  object SwitchPanelLeft: TPanel
    Left = 355
    Top = 330
    Width = 57
    Height = 195
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 15
    object Label7: TLabel
      Left = 17
      Top = 7
      Width = 23
      Height = 13
      Caption = 'L/H'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SW1Button: TPanel
      Left = 8
      Top = 32
      Width = 41
      Height = 25
      Caption = 'SW1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
    end
    object SW2Button: TPanel
      Left = 8
      Top = 63
      Width = 41
      Height = 25
      Caption = 'SW2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
    end
    object SW3Button: TPanel
      Left = 8
      Top = 94
      Width = 41
      Height = 25
      Caption = 'TRIG'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
    end
    object SW4Button: TPanel
      Left = 8
      Top = 125
      Width = 41
      Height = 25
      Caption = 'PALM'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 3
    end
  end
  object SwitchPanelRight: TPanel
    Left = 435
    Top = 330
    Width = 101
    Height = 195
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 16
    object Label2: TLabel
      Left = 33
      Top = 7
      Width = 25
      Height = 13
      Caption = 'R/H'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SW5Button: TPanel
      Left = 7
      Top = 29
      Width = 41
      Height = 25
      Caption = 'SW1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
    end
    object SW6Button: TPanel
      Left = 7
      Top = 60
      Width = 41
      Height = 25
      Caption = 'UP'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
    end
    object SW7Button: TPanel
      Left = 54
      Top = 60
      Width = 41
      Height = 25
      Caption = 'DOWN'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
    end
    object SW8Button: TPanel
      Left = 7
      Top = 91
      Width = 41
      Height = 25
      Caption = 'LEFT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 3
    end
    object SW9Button: TPanel
      Left = 54
      Top = 91
      Width = 41
      Height = 25
      Caption = 'RIGHT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 4
    end
    object SW12Button: TPanel
      Left = 7
      Top = 122
      Width = 41
      Height = 25
      Caption = 'TRIG'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 5
    end
    object SW13Button: TPanel
      Left = 7
      Top = 153
      Width = 41
      Height = 25
      Caption = 'PALM'
      DoubleBuffered = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentBackground = False
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 6
    end
    object SW10Button: TPanel
      Left = 54
      Top = 122
      Width = 41
      Height = 25
      Caption = 'SW3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 7
    end
    object SW11Button: TPanel
      Left = 54
      Top = 153
      Width = 41
      Height = 25
      Caption = 'SW4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Locked = True
      ParentBackground = False
      ParentFont = False
      TabOrder = 8
    end
  end
  object Panel7: TPanel
    Left = 17
    Top = 233
    Width = 320
    Height = 154
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 17
    object RTRLabel: TLabel
      Left = 87
      Top = 31
      Width = 53
      Height = 15
      AutoSize = False
      Caption = 'RTR'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DataLenLabel: TLabel
      Left = 135
      Top = 31
      Width = 81
      Height = 16
      AutoSize = False
      Caption = 'DLC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DataNoLabel: TLabel
      Left = 181
      Top = 31
      Width = 41
      Height = 16
      AutoSize = False
      Caption = 'Count'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 228
      Top = 31
      Width = 65
      Height = 16
      AutoSize = False
      Caption = 'Time / ms'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DataLabel: TLabel
      Left = 8
      Top = 5
      Width = 193
      Height = 20
      Caption = 'Data Message   (DDUT)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DataBytesLabel: TLabel
      Left = 16
      Top = 100
      Width = 121
      Height = 16
      Caption = '0          1           2          3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DataByteLabel: TLabel
      Left = 8
      Top = 80
      Width = 32
      Height = 16
      Caption = 'Byte'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object IDText: TEdit
      Left = 8
      Top = 53
      Width = 73
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object RTRText: TEdit
      Left = 87
      Top = 53
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object DataLenText: TEdit
      Left = 126
      Top = 53
      Width = 41
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object DataNo: TEdit
      Left = 173
      Top = 53
      Width = 41
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 3
    end
    object DataTime: TEdit
      Left = 228
      Top = 53
      Width = 49
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object Byte0Text: TEdit
      Left = 8
      Top = 122
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
    end
    object Byte1Text: TEdit
      Left = 47
      Top = 122
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
    end
    object Byte2Text: TEdit
      Left = 86
      Top = 122
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 7
    end
    object Byte3Text: TEdit
      Left = 125
      Top = 122
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 8
    end
  end
  object Panel4: TPanel
    Left = 17
    Top = 410
    Width = 320
    Height = 160
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 18
    object SWIDLabel: TLabel
      Left = 10
      Top = 36
      Width = 39
      Height = 14
      AutoSize = False
      Caption = 'ID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SWRTRLabel: TLabel
      Left = 87
      Top = 34
      Width = 41
      Height = 16
      AutoSize = False
      Caption = 'RTR'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SWDataLenLabel: TLabel
      Left = 126
      Top = 33
      Width = 81
      Height = 16
      AutoSize = False
      Caption = 'DLC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SWNoLabel: TLabel
      Left = 173
      Top = 33
      Width = 65
      Height = 16
      AutoSize = False
      Caption = 'Count'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 228
      Top = 33
      Width = 59
      Height = 16
      AutoSize = False
      Caption = 'Time / ms'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SWLabel: TLabel
      Left = 7
      Top = 7
      Width = 200
      Height = 20
      Caption = 'Switch Message  (SSTO)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 13
      Top = 104
      Width = 201
      Height = 16
      Caption = '0          1           2           3           4          5'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SWByteLabel: TLabel
      Left = 7
      Top = 83
      Width = 32
      Height = 16
      Caption = 'Byte'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SWID: TEdit
      Left = 8
      Top = 56
      Width = 73
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object SWRTR: TEdit
      Left = 87
      Top = 55
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object SWDataLen: TEdit
      Left = 126
      Top = 55
      Width = 41
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object SWNo: TEdit
      Left = 173
      Top = 55
      Width = 41
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 3
    end
    object SwitchTime: TEdit
      Left = 228
      Top = 55
      Width = 42
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object SWByte0: TEdit
      Left = 7
      Top = 126
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
    end
    object SWByte1: TEdit
      Left = 46
      Top = 126
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
    end
    object SWByte2: TEdit
      Left = 85
      Top = 126
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 7
    end
    object SWByte3: TEdit
      Left = 124
      Top = 126
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 8
    end
    object SWByte4: TEdit
      Left = 163
      Top = 126
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 9
    end
    object SWByte5: TEdit
      Left = 202
      Top = 126
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 10
    end
  end
  object TPanel
    Left = 17
    Top = 63
    Width = 320
    Height = 153
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 19
    object MessIDLabel: TLabel
      Left = 9
      Top = 29
      Width = 41
      Height = 16
      AutoSize = False
      Caption = 'ID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object MessRTRLabel: TLabel
      Left = 75
      Top = 29
      Width = 41
      Height = 16
      AutoSize = False
      Caption = 'RTR'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object MessDataLenLabel: TLabel
      Left = 119
      Top = 29
      Width = 81
      Height = 16
      AutoSize = False
      Caption = 'DLC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object MessNoLabel: TLabel
      Left = 170
      Top = 29
      Width = 65
      Height = 16
      AutoSize = False
      Caption = 'Count'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object MessageLabel: TLabel
      Left = 4
      Top = 3
      Width = 73
      Height = 20
      Caption = 'Message'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object MessBytesLabel: TLabel
      Left = 24
      Top = 98
      Width = 281
      Height = 16
      Caption = 
        '0          1           2          3           4           5     ' +
        '      6           7'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object MessByteLabel: TLabel
      Left = 8
      Top = 78
      Width = 32
      Height = 16
      Caption = 'Byte'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object MessID: TEdit
      Left = 4
      Top = 51
      Width = 73
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object MessRTR: TEdit
      Left = 83
      Top = 51
      Width = 33
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object MessDataLen: TEdit
      Left = 122
      Top = 51
      Width = 41
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object MessNo: TEdit
      Left = 169
      Top = 51
      Width = 41
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 3
    end
    object MessByte0: TEdit
      Left = 8
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 4
    end
    object MessByte1: TEdit
      Left = 47
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
    end
    object MessByte2: TEdit
      Left = 86
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
    end
    object MessByte3: TEdit
      Left = 125
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 7
    end
    object MessByte4: TEdit
      Left = 164
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 8
    end
    object MessByte5: TEdit
      Left = 203
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 9
    end
    object MessByte6: TEdit
      Left = 242
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 10
    end
    object MessByte7: TEdit
      Left = 281
      Top = 120
      Width = 33
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 11
    end
  end
  object Panel6: TPanel
    Left = 17
    Top = 589
    Width = 519
    Height = 124
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 20
    object XDataLabel: TLabel
      Left = 7
      Top = 11
      Width = 52
      Height = 16
      AutoSize = False
      Caption = 'X Data'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object XBarBox: TPaintBox
      Left = 87
      Top = 32
      Width = 401
      Height = 25
      Color = clBtnHighlight
      ParentColor = False
      OnPaint = XBarBoxPaint
    end
    object XAxisLabel: TLabel
      Left = 259
      Top = 9
      Width = 43
      Height = 16
      Caption = 'X Axis'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object YBarBox: TPaintBox
      Left = 87
      Top = 85
      Width = 401
      Height = 25
      Color = clWhite
      ParentColor = False
      OnPaint = YBarBoxPaint
    end
    object YAxisLabel: TLabel
      Left = 259
      Top = 63
      Width = 44
      Height = 16
      Caption = 'Y Axis'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object YDataLabel: TLabel
      Left = 10
      Top = 69
      Width = 52
      Height = 14
      AutoSize = False
      Caption = 'Y Data'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object XData: TEdit
      Left = 8
      Top = 33
      Width = 65
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object YData: TEdit
      Left = 8
      Top = 89
      Width = 65
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
  end
  object PrintToFileButton: TButton
    Left = 788
    Top = 649
    Width = 121
    Height = 36
    Caption = 'Print To File'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 21
    Visible = False
    OnClick = PrintToFileButtonClick
  end
  object MaxDefPanel: TPanel
    Left = 923
    Top = 428
    Width = 353
    Height = 125
    Color = clActiveBorder
    ParentBackground = False
    TabOrder = 22
    Visible = False
    object Label1: TLabel
      Left = 42
      Top = 43
      Width = 24
      Height = 20
      Caption = '-X '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 117
      Top = 43
      Width = 23
      Height = 20
      Caption = '+X'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 214
      Top = 43
      Width = 19
      Height = 20
      Caption = '-Y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 281
      Top = 43
      Width = 23
      Height = 20
      Caption = '+Y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 40
      Top = 9
      Width = 266
      Height = 20
      Caption = ' Max / Min Axis Deflection Values'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object MaxDefMinusXBox: TEdit
      Left = 26
      Top = 69
      Width = 55
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object MaxDefPosXBox: TEdit
      Left = 106
      Top = 69
      Width = 53
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object MaxDefMinusYBox: TEdit
      Left = 192
      Top = 69
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object MaxDefPosYBox: TEdit
      Left = 272
      Top = 69
      Width = 55
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 3
    end
  end
  object ResetMaxMinButton: TButton
    Left = 923
    Top = 669
    Width = 109
    Height = 38
    Caption = 'Reset Values'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 23
    Visible = False
    OnClick = Button2Click
  end
  object SyncTimer: TTimer
    Interval = 2
    OnTimer = SyncTimerTimer
    Left = 704
    Top = 338
  end
end
