object CheckCurveForm: TCheckCurveForm
  Left = 0
  Top = 0
  Caption = 'Check Curve Data Form'
  ClientHeight = 327
  ClientWidth = 387
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object SelectCurveLabel: TLabel
    Left = 8
    Top = 16
    Width = 172
    Height = 24
    Alignment = taCenter
    Caption = 'Check Curve Data'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object CurveSelectMemo: TMemo
    Left = 8
    Top = 56
    Width = 361
    Height = 153
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      
        'Checking of the Curve requires the '#39'Start'#39' item being clicked be' +
        'low and '
      
        'then the tester moving the Joystick from the zero position to po' +
        'sitive full '
      'scale deflection within 2 seconds. i.e Forwards or right'
      
        'A message will appear in the message window stating test complet' +
        'e.'
      ''
      
        'NOTE: Once the '#39'Start'#39' item is clicked the Test Control will sen' +
        'd repeated '
      
        'RAW Data  and Deflection Data requests for a period of 2 seconds' +
        '. '
      'PCAN-View will capture the data into a Trace file.'
      
        'The object of the exercise is to compare each piece of data with' +
        ' the data '
      'in the Test Procedure.')
    TabOrder = 0
  end
  object SelectListBox: TListBox
    Left = 8
    Top = 232
    Width = 305
    Height = 57
    ItemHeight = 13
    Items.Strings = (
      'START - Click here to begin data capture ')
    TabOrder = 1
    OnClick = SelectListBoxClick
  end
end
