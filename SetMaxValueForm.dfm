object SetMaxValuesForm: TSetMaxValuesForm
  Left = 0
  Top = 0
  Caption = 'Set Maximum Form'
  ClientHeight = 224
  ClientWidth = 296
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
  object SetMaxValLabel: TLabel
    Left = 8
    Top = 8
    Width = 192
    Height = 24
    Alignment = taCenter
    Caption = 'Set Maximum Values'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object SetMaxLabel: TMemo
    Left = 8
    Top = 48
    Width = 185
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
      'Please select a Value from the list')
    ParentFont = False
    TabOrder = 0
  end
  object SetMaxValueListBox: TListBox
    Left = 8
    Top = 96
    Width = 265
    Height = 105
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0.  Set to Zero - whole range used (-8191 to +8191)'
      '1.  Set to 500    - (0x01F4)'
      '2.  Set to 1000  - (0x03E8)'
      '3.  Set to 5000  - (0x1388)'
      '4.  Set to 8000  - (0x1F40)')
    ParentFont = False
    TabOrder = 1
    OnClick = SetMaxValueListBoxClick
  end
end
