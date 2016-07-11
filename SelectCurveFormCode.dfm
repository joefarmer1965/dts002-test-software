object SelectCurveForm: TSelectCurveForm
  Left = 1017
  Top = 370
  BorderIcons = [biSystemMenu]
  Caption = 'Select Curve'
  ClientHeight = 329
  ClientWidth = 456
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object SelectCurveLabel: TLabel
    Left = 16
    Top = 16
    Width = 121
    Height = 24
    Alignment = taCenter
    Caption = 'Select Curve'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object SelectCurve4XListBox: TListBox
    Left = 8
    Top = 95
    Width = 177
    Height = 154
    BevelInner = bvLowered
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0.  - Curve 0                    '
      '1.  - Curve 1 - Exp            '
      '2.  - Curve 2 - Step     '
      '3.-   Curve 3 - Double Exp'
      '4.  - CMI Curve 0   '
      '5.  - CMI Curve 5    '
      '6.  - Curve 6 - Steps'
      '7.  - Incomplete Curve  '
      '0xF  - Linear Curve (Default)'
      'Exit')
    ParentFont = False
    TabOrder = 0
    OnClick = SelectCurve4XListBoxClick
  end
  object XAxisMemo: TMemo
    Left = 8
    Top = 56
    Width = 113
    Height = 33
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
      'Please Select a Curve '
      'for the  X Axis')
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
  object YAxisMemo: TMemo
    Left = 232
    Top = 56
    Width = 113
    Height = 33
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
      'Please Select a Curve '
      'for the  Y Axis')
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object SelectCurve4YListBox: TListBox
    Left = 232
    Top = 100
    Width = 177
    Height = 154
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0.  - Curve 0     '
      '1.  - Curve 1 - Exp   '
      '2.  - Curve 2 - Step  '
      '3.-   Curve 3 - Double Exp '
      '4.  - CMI Curve 0'
      '5.  - CMI Curve 5   '
      '6.  - Curve 6 - Steps    '
      '7.  - Incomplete Curve '
      '0xF  - Linear Curve (Default)'
      'Exit')
    ParentFont = False
    TabOrder = 3
    OnClick = SelectCurve4YListBoxClick
  end
  object Memo1: TMemo
    Left = 120
    Top = 283
    Width = 257
    Height = 22
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
      'Select EXIT in either List Box to Close')
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
  end
end
