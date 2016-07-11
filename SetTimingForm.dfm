object TimingForm: TTimingForm
  Left = 0
  Top = 0
  Caption = 'Set Timing Selection'
  ClientHeight = 250
  ClientWidth = 326
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
    Width = 152
    Height = 24
    Alignment = taCenter
    Caption = 'Timing Selection'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object TimingSelection: TListBox
    Left = 8
    Top = 123
    Width = 281
    Height = 102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      '1.  DDUT time  = 20ms,  SSTO time  = 100ms (Min)'
      '2.  DDUT time  = 30ms,  SSTO time  = 500ms'
      '3.  DDUT time  = 50ms,  SSTO time  = 1sec (Default)'
      '4.  DDUT time  = 80ms,  SSTO time  = 2sec'
      '5.  DDUT time  = 100ms, SSTO time = 10sec (Max)'
      '6.  Exit')
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
    OnClick = TimingSelectionClick
  end
  object Memo1: TMemo
    Left = 8
    Top = 61
    Width = 321
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
      'SSTO Time range [100ms .. 10secs] (Default 1s) ')
    ParentFont = False
    TabOrder = 1
  end
  object Memo2: TMemo
    Left = 8
    Top = 38
    Width = 297
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
      'DDUT Time range [200 .. 1000] (Default 500)ms')
    ParentFont = False
    TabOrder = 2
  end
  object Memo3: TMemo
    Left = 8
    Top = 92
    Width = 281
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
      'Please Select the Timing Required - then Exit')
    ParentFont = False
    TabOrder = 3
  end
end
