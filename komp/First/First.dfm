object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Alma VCLVisual Component Library'
  ClientHeight = 500
  ClientWidth = 719
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
    Left = 112
    Top = 104
    Width = 277
    Height = 33
    Caption = 'Alma Mivan????????'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 152
    Top = 144
    Width = 200
    Height = 100
    Caption = 'Nincs is ilyen'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
  end
  object Alma: TScrollBar
    Left = 32
    Top = 312
    Width = 400
    Height = 40
    Hint = 'H'#250'zd el'
    Max = 2000000
    Min = 1000
    PageSize = 1000
    Position = 1000
    TabOrder = 1
  end
  object Button3: TButton
    Left = 32
    Top = 8
    Width = 416
    Height = 81
    Caption = 'Nincs is ilyen'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = NemAlma
    OnMouseEnter = Button3MouseEnter
    OnMouseLeave = Button3MouseLeave
  end
  object Button4: TButton
    Left = 8
    Top = 123
    Width = 138
    Height = 183
    Hint = 'ALma'
    Caption = 'Nincs is ilyen'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = Button4Click
  end
  object ColorPicker: TColorBox
    Left = 472
    Top = 222
    Width = 145
    Height = 22
    TabOrder = 5
    OnChange = ColorChange
  end
  object GridPanel1: TGridPanel
    Left = 416
    Top = 328
    Width = 185
    Height = 100
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        Value = 30.773673162902310000
      end
      item
        Value = 49.447376312212630000
      end
      item
        Value = 19.778950524885060000
      end>
    ControlCollection = <
      item
        Column = 0
        Row = 0
      end>
    RowCollection = <
      item
        Value = 20.224254578259070000
      end
      item
        Value = 20.309199494266300000
      end
      item
        Value = 19.357892075539110000
      end
      item
        Value = 19.781914203138470000
      end
      item
        Value = 20.326739648797050000
      end>
    TabOrder = 6
  end
  object Button2: TButton
    Left = 152
    Top = 384
    Width = 200
    Height = 100
    Caption = 'Nincs is ilyen'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object OpenDialog1: TOpenDialog
    Left = 512
    Top = 272
  end
  object ColorDialog1: TColorDialog
    Left = 432
    Top = 144
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 352
    Top = 256
  end
  object Timer: TTimer
    Interval = 100
    OnTimer = TimerTimer
    Left = 408
    Top = 208
  end
end
