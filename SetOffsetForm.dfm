object OffsetSelectionForm: TOffsetSelectionForm
  Left = 0
  Top = 0
  Caption = 'Set Offset Form'
  ClientHeight = 441
  ClientWidth = 509
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
  object SetOffsetsLabel: TLabel
    Left = 8
    Top = 8
    Width = 162
    Height = 24
    Alignment = taCenter
    Caption = 'Set Offset Values'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object AzimuthLabel: TMemo
    Left = 16
    Top = 64
    Width = 225
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
      'Select the Azimuth Deflection Offset value'
      'and / or'
      'Select the Azimuth Max Slope Value')
    ParentFont = False
    TabOrder = 0
  end
  object ElevationLabel: TMemo
    Left = 280
    Top = 64
    Width = 225
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
      'Select the Elevation Deflection Offset value'
      'and / or'
      'Select the Elevation Max Slope Value')
    ParentFont = False
    TabOrder = 1
  end
  object SetAzimuthListBox: TListBox
    Left = 16
    Top = 128
    Width = 217
    Height = 233
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0.   Set Default 0x0000'
      '1.   Set Offset to 250'
      '2.   Set Offset to 500'
      '3.   Set Offset to 1000'
      '4.   Set Offset to 2000'
      '5.   Set Offset to 3000 '
      '6.   Set Offset to 4000 '
      '7.   Set Offset to 5000'
      '8.   Set Offset to 6000'
      '9.   Set Offset to 7000'
      '10. Set Offset to 8000 '
      '11. Set Offset to -4000 '
      '12. Set Offset to -8000 '
      '13. Set Out of Range Value 9000'
      '14. Exit')
    ParentFont = False
    TabOrder = 2
    OnClick = SetAzimuthListBoxClick
  end
  object SetElevationListBox: TListBox
    Left = 280
    Top = 128
    Width = 217
    Height = 233
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '0.  Set Default 0x0000'
      '1.  Set Offset to 250'
      '2.  Set Offset to 500'
      '3.  Set Offset to 1000'
      '4.  Set Offset to 2000'
      '5.  Set Offset to 3000'
      '6.  Set Offset to 4000'
      '7.  Set Offset to 5000'
      '8.  Set Offset to 6000 '
      '9.  Set Offset to 7000 '
      '10.Set Offset to 8000 '
      '11. Set Offset to -4000 '
      '12. Set Offset to -8000 '
      '13. Set Out of Range Value 9000'
      '14. Exit')
    ParentFont = False
    TabOrder = 3
    OnClick = SetElevationListBoxClick
  end
end
