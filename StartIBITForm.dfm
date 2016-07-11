object StartIBIT: TStartIBIT
  Left = 0
  Top = 0
  Caption = 'Start IBIT'
  ClientHeight = 283
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
  object IBITStartLabel: TLabel
    Left = 8
    Top = 8
    Width = 89
    Height = 24
    Alignment = taCenter
    Caption = 'Start IBIT'
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
  object StartIBITListBox: TListBox
    Left = 8
    Top = 96
    Width = 201
    Height = 81
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
    OnClick = StartIBITListBoxClick
  end
  object IBITWarning: TMemo
    Left = 8
    Top = 216
    Width = 241
    Height = 49
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
      'NOTE: For code 1 and 3 ensure no switches are '
      'pressed and that the joystick in in the middle / zero '
      'position.')
    ParentFont = False
    TabOrder = 2
  end
end
