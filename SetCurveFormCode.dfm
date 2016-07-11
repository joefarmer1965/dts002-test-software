object SetCurveForm: TSetCurveForm
  Left = 852
  Top = 138
  BorderIcons = [biSystemMenu]
  Caption = 'SetCurve'
  ClientHeight = 300
  ClientWidth = 258
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
    Left = 8
    Top = 16
    Width = 145
    Height = 24
    Caption = 'Set Curve Data'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object CurveMemo: TMemo
    Left = 8
    Top = 56
    Width = 169
    Height = 17
    BevelEdges = []
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Microsoft Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Please select the Curve to load'
      '')
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
  end
  object SelectCurveListBox: TListBox
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
      '0.  - Curve 0    '
      '1.  - Curve 1 - Exp   '
      '2.  - Curve 2 - Step '
      '3.-   Curve 3 - Double Exp  '
      '4.  - CMI Curve 0  '
      '5.  - CMI Curve 5   '
      '6.  - Curve 6 - Steps  '
      '7.  - Incomplete Curve  '
      'Exit')
    ParentFont = False
    TabOrder = 1
    OnClick = SelectCurveListBoxClick
  end
end
