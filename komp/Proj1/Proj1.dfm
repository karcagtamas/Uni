object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 693
  ClientWidth = 1095
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ConvertButton: TButton
    Left = 432
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Input text'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = ConvertButtonClick
  end
  object ErrorButton: TButton
    Left = 616
    Top = 240
    Width = 75
    Height = 25
    Caption = 'ErrorButton'
    TabOrder = 1
    OnClick = ErrorButtonClick
  end
  object Circle: TButton
    Left = 152
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Circle'
    TabOrder = 2
    OnClick = CircleClick
  end
  object Solver: TButton
    Left = 560
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Solver'
    TabOrder = 3
    OnClick = SolverClick
  end
  object Divider: TButton
    Left = 296
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Divider'
    TabOrder = 4
    OnClick = DividerClick
  end
end
