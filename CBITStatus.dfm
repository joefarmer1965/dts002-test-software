object CBITCodeSelect: TCBITCodeSelect
  Left = 0
  Top = 0
  Caption = 'CBIT Code Select'
  ClientHeight = 324
  ClientWidth = 264
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 223
    Height = 24
    Alignment = taCenter
    Caption = 'CBIT Code ID Selection'
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
    Width = 222
    Height = 16
    Alignment = taCenter
    Caption = 'Please select the CBIT Code Required'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object CBITListBox: TListBox
    Left = 8
    Top = 96
    Width = 225
    Height = 201
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0 -   All Codes Request'
      '3 -   Microcontroller Temperature'
      '6 -   Left Hand Switch 1'
      '8 -   Left Hand Switch 2'
      '10 - Left hand TRIG'
      '12 - Left Hand PALM'
      '14 - Right Hand Switch 1'
      '16 - Right Hand Switch 2'
      '18 - Right Hand Switch 3'
      '20 - Right Hand Switch 4'
      '22 - Right Hand TRIG'
      '24-  Right Hand PALM'
      '25 - X Axis Check'
      '26 - Y Axis Check'
      'EXIT')
    ParentFont = False
    TabOrder = 0
    OnClick = CBITListBoxClick
  end
end
