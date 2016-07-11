object IBITCodeSelect: TIBITCodeSelect
  Left = 0
  Top = 0
  Caption = 'IBIT Code Select'
  ClientHeight = 236
  ClientWidth = 278
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 214
    Height = 24
    Alignment = taCenter
    Caption = 'IBIT Code ID Selection'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 216
    Height = 16
    Alignment = taCenter
    Caption = 'Please select the IBIT Code Required'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object IBITListBox: TListBox
    Left = 8
    Top = 88
    Width = 225
    Height = 105
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0 - ALL IBIT Codes'
      '1 - Automatic Switch Test'
      '2 - Manual Switch Test'
      '3 - Automatic Deflection Test'
      '4 - Manual Deflection Test'
      '5 - EXIT')
    ParentFont = False
    TabOrder = 0
    OnClick = IBITListBoxClick
  end
end
