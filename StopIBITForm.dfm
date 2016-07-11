object StopIBIT: TStopIBIT
  Left = 0
  Top = 0
  Caption = 'Stop IBIT'
  ClientHeight = 231
  ClientWidth = 267
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
  object IBITStopLabel: TLabel
    Left = 8
    Top = 8
    Width = 87
    Height = 24
    Alignment = taCenter
    Caption = 'Stop IBIT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object IBITSelectLabel: TMemo
    Left = 8
    Top = 48
    Width = 185
    Height = 25
    BevelEdges = []
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Please select an IBIT Code from the list')
    ParentFont = False
    TabOrder = 0
  end
  object StopIBITListBox: TListBox
    Left = 8
    Top = 104
    Width = 201
    Height = 97
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '1.  Code 1 - Auto Switch Test'
      '2.  Code 2 - Manual Switch Test'
      '3.  Code 3 - Auto Deflection Test'
      '4.  Code 4 - Manual Deflection Test')
    ParentFont = False
    TabOrder = 1
    OnClick = StopIBITListBoxClick
  end
end
