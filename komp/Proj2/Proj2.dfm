object MyForm: TMyForm
  Left = 0
  Top = 0
  Caption = 'MyForm'
  ClientHeight = 674
  ClientWidth = 976
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StaticArray: TButton
    Left = 0
    Top = 488
    Width = 329
    Height = 185
    Caption = 'StaticArray'
    TabOrder = 0
    OnClick = StaticArrayClick
  end
  object DynamicArray: TButton
    Left = 320
    Top = 312
    Width = 329
    Height = 177
    Caption = 'DynamicArray'
    TabOrder = 1
    OnClick = DynamicArrayClick
  end
  object SetDemo: TButton
    Left = 648
    Top = 488
    Width = 329
    Height = 185
    Caption = 'SetDemo'
    TabOrder = 2
    OnClick = SetDemoClick
  end
  object StudentGenerator: TButton
    Left = 320
    Top = 488
    Width = 329
    Height = 185
    Caption = 'StudentGenerator'
    TabOrder = 3
    OnClick = StudentGeneratorClick
  end
  object StringCount: TButton
    Left = 448
    Top = 168
    Width = 75
    Height = 25
    Caption = 'StringCount'
    TabOrder = 4
    OnClick = StringCountClick
  end
  object Button1: TButton
    Left = 720
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 5
    OnClick = Button1Click
  end
end
