object PBITCodeSelect: TPBITCodeSelect
  Left = 0
  Top = 0
  Caption = 'PBIT Code Select'
  ClientHeight = 385
  ClientWidth = 275
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
    Width = 222
    Height = 24
    Alignment = taCenter
    Caption = 'PBIT Code ID Selection'
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
    Caption = 'Please select the PBIT Code Required'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object PBITListBox: TListBox
    Left = 8
    Top = 96
    Width = 225
    Height = 245
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0 -   All Codes Request'
      '1 -   RAM Check'
      '2 -   Program Memory CRC'
      '3 -   Microcontroller Temp Check'
      '4 -   Cal & Curve CRC Check'
      '5 -   left Hand Switch 1'
      '7 -   Left Hand Switch 2'
      '9 -   Left hand TRIG'
      '11 - Left Hand PALM'
      '13 - Right Hand Switch 1'
      '15 - Right Hand Switch 2'
      '17 - Right Hand Switch 3'
      '19 - Right Hand Switch 4'
      '21 - Right Hand TRIG'
      '23 - Right Hand PALM'
      '25 - X Axis Check'
      '26 - Y Axis Check'
      'EXIT')
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
    OnClick = PBITListBoxClick
  end
end
