object ManIBIT: TManIBIT
  Left = 0
  Top = 0
  Caption = 'Manual IBIT Switch Test'
  ClientHeight = 422
  ClientWidth = 446
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
    Width = 224
    Height = 24
    Alignment = taCenter
    Caption = 'IBIT Manual Switch Test'
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
      
        'This is the Manual IBIT switch Test. The list box below is the s' +
        'equence of '
      'instrucions to be performed. '
      
        'The method is to click the item (This will send the required IBI' +
        'T request message)'
      'THEN press the switch on the test panel.'
      ''
      
        'At any time through the sequence the STOP IBIT button on Test Co' +
        'ntrol can be '
      'clicked.')
    TabOrder = 0
  end
  object StepSelection: TListBox
    Left = 8
    Top = 165
    Width = 393
    Height = 204
    ItemHeight = 13
    Items.Strings = (
      
        '1.   Step 1 -   Click Here and THEN Press LH SW1 on test panel (' +
        '2CH)'
      
        '2.   Step 2 -   Click Here and THEN Press LH SW2 on test panel (' +
        '2CH)'
      
        '3.   Step 3 -   Click Here and THEN Press LH TRIG on test panel ' +
        '(2CH)'
      
        '4.   Step 4 -   Click Here and THEN Press LH PALM on test panel ' +
        '(2CH)'
      '5.   Step 5 -   Click Here and THEN Press RH SW1 on test panel'
      
        '6.   Step 6 -   Click Here and THEN Press RH SW2 UP on test pane' +
        'l'
      
        '7.   Step 7 -   Click Here and THEN Press RH SW2 DOWN  on test p' +
        'anel'
      
        '8.   Step 8 -   Click Here and THEN Press RH SW2 LEFT on test pa' +
        'nel '
      
        '9.   Step 9 -   Click Here and THEN Press RH SW2 RIGHT  on test ' +
        'panel'
      '10. Step 10 - Click Here and THEN Press RH SW3 on test panel '
      '11. Step 11 - Click Here and THEN Press RH SW4 on test panel '
      '12. Step 12 - Click Here and THEN Press RH TRIG on test panel'
      '13. Step 13 - Click Here and THEN Press RH PALM on test panel ')
    TabOrder = 1
    OnClick = StepSelectionClick
  end
end
