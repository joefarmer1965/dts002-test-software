object TestEnvironmentSelect: TTestEnvironmentSelect
  Left = 0
  Top = 0
  Caption = ' Select Test Environment'
  ClientHeight = 369
  ClientWidth = 304
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 94
    Top = 140
    Width = 85
    Height = 14
    Caption = 'Enter Password'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TestEnvironmentListBox: TListBox
    Left = 8
    Top = 8
    Width = 288
    Height = 113
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Items.Strings = (
      '1) Calibration & Setup'
      '2) Factory Acceptance Testing (FAT)'
      '3) Firmware Verification Testing (FVT)'
      '4) Low Temperature Verification Testing (LTVT)'
      '5) Shock & Vibration Testing (S&V)'
      '6) EMC Compliance Testing ')
    ParentFont = False
    TabOrder = 0
    OnClick = TestEnvironmentListBoxClick
  end
  object Edit1: TEdit
    Left = 80
    Top = 160
    Width = 121
    Height = 22
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    PasswordChar = '*'
    TabOrder = 1
  end
  object Button1: TButton
    Left = 104
    Top = 188
    Width = 75
    Height = 25
    Caption = 'Accept'
    TabOrder = 2
    OnClick = Button1Click
  end
end
