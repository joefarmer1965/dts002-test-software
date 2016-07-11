object IBITForm: TIBITForm
  Left = 861
  Top = 305
  Align = alCustom
  BorderIcons = [biSystemMenu]
  Caption = 'IBIT'
  ClientHeight = 568
  ClientWidth = 490
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poMainFormCenter
  ExplicitWidth = 320
  ExplicitHeight = 240
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 116
    Height = 24
    Alignment = taCenter
    Caption = 'IBIT Options'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 24
    Top = 56
    Width = 113
    Height = 33
    BevelEdges = []
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      'Select the IBIT option '
      'required from the list:')
    ReadOnly = True
    TabOrder = 1
  end
  object IBITListBox: TListBox
    Left = 8
    Top = 112
    Width = 145
    Height = 113
    BevelInner = bvLowered
    ItemHeight = 13
    Items.Strings = (
      '0x01 Calibration Mode'
      '0x02 Frimware Update Mode'
      '0x03 CBIT Errors'
      '0x04 ETI & Power Cycles'
      '0x05 Part Number'
      '0x06 Serial Number'
      '0x07 Firmware Version'
      'Exit')
    TabOrder = 0
    OnClick = IBITListBoxClick
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 240
  end
end
