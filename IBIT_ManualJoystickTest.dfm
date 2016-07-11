object ManIBITJoy: TManIBITJoy
  Left = 0
  Top = 0
  Caption = 'Manual IBIT Joystick Test'
  ClientHeight = 325
  ClientWidth = 597
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 239
    Height = 24
    Alignment = taCenter
    Caption = 'IBIT Manual Joystick Test'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Instructions: TMemo
    Left = 8
    Top = 56
    Width = 393
    Height = 97
    BevelEdges = []
    BevelInner = bvNone
    BevelKind = bkFlat
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      
        'This is the Manual IBIT Joystick Test. The list box below is the' +
        ' sequence of '
      'instrucions to be performed. '
      
        'The method is to click the item (This will send the required IBI' +
        'T request message)'
      'THEN move the Joystick as instructed on  test panel.'
      ''
      
        'At any time through the sequence the STOP IBIT button on Test Co' +
        'ntrol can be '
      'clicked.')
    TabOrder = 0
  end
  object SelectListBox: TListBox
    Left = 8
    Top = 192
    Width = 513
    Height = 97
    ItemHeight = 13
    Items.Strings = (
      
        '1. Step 1 - Click Here and THEN Move the joystick fully RIGHT in' +
        ' the +X Axis Direction on test panel.'
      
        '2. Step 2 - Click Here and THEN Move the joystick fully LEFT in ' +
        'the -X Axis Direction on test panel.'
      
        '3. Step 3 - Click Here and THEN Move the joystick fully UP in th' +
        'e +Y Axis Direction on test panel.'
      
        '4. Step 4 - Click Here and THEN Move the joystick fully Down in ' +
        'the -Y Axis Direction on test panel.'
      '5.Test Completed  - Click Here to Get the Test Summary Report')
    TabOrder = 1
    OnClick = SelectListBoxClick
  end
end
