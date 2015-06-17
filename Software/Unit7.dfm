object Settings: TSettings
  Left = 1112
  Top = 22
  Width = 272
  Height = 698
  Align = alCustom
  Caption = 'Settings'
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 24
    Width = 207
    Height = 16
    Align = alCustom
    Caption = 'Set structuring element'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Gothic'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 56
    Top = 168
    Width = 99
    Height = 20
    Caption = 'Count pixels'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 8
    Top = 48
    Width = 209
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 72
    Top = 88
    Width = 75
    Height = 25
    Caption = 'SET'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 48
    Top = 200
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Button2: TButton
    Left = 72
    Top = 232
    Width = 73
    Height = 25
    Caption = 'COUNT'
    TabOrder = 3
    OnClick = Button2Click
  end
end
