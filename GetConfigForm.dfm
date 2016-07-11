object GetConfig: TGetConfig
  Left = 0
  Top = 0
  Caption = 'Get Config Form'
  ClientHeight = 202
  ClientWidth = 266
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
  object GetConfigLabel: TLabel
    Left = 0
    Top = 8
    Width = 215
    Height = 24
    Alignment = taCenter
    Caption = 'Get Configuration Data'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object SelectValLabel: TMemo
    Left = 8
    Top = 38
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
  object GetConfigListBox: TListBox
    Left = 8
    Top = 72
    Width = 225
    Height = 89
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0.  Config ID 0x01 - Part Number'
      '1.  Config ID 0x02 - Serial Number'
      '2.  Config ID 0x03 - Software Version'
      '3.  Config ID 0x04 - ETI & Power Cycles'
      '4.  Exit')
    ParentFont = False
    TabOrder = 1
    OnClick = GetConfigListBoxClick
  end
end
