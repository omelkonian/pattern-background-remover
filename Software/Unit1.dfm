object Form1: TForm1
  Left = 5
  Top = 22
  Width = 1115
  Height = 700
  Align = alCustom
  Caption = 'Pattern Removal'
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 904
    Top = 40
    Width = 48
    Height = 28
    Caption = 'PDH'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Palatino Linotype'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 904
    Top = 112
    Width = 46
    Height = 28
    Caption = 'PDV'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Palatino Linotype'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 32
    Width = 140
    Height = 24
    Caption = 'INITIAL IMAGE'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 704
    Top = 32
    Width = 86
    Height = 24
    Caption = 'RESULT '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 376
    Top = 32
    Width = 97
    Height = 24
    Caption = 'PATTERN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 936
    Top = 272
    Width = 72
    Height = 24
    Caption = 'SCORE'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 328
    Top = 304
    Width = 229
    Height = 24
    Caption = 'INITIAL WITH PATTERN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 1032
    Top = 312
    Width = 17
    Height = 24
    Caption = '%'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 912
    Top = 384
    Width = 126
    Height = 24
    Caption = 'Save Filename'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ImagXpress7_1: TImagXpress7_
    Left = 600
    Top = 56
    Width = 281
    Height = 553
    ParentColor = False
    ParentFont = False
    Align = alCustom
    TabOrder = 0
    OnMouseMove = ImagXpress7_1MouseMove
    ControlData = {
      0800420000004200310033004200300035004600460036003100330042003200
      4200390042003300300030003100300037004100420032004600390044004600
      380046003800000056571C1B10EEBE57030001000000100700000B1D00002739
      000008000200000000000300050000001300C0C0C0000B00FFFF09000352E30B
      918FCE119DE300AA004BB85101A10000BC024442010005417269616C09000000
      0000000000000000000000000000130000000000130000000000090000000000
      0000000000000000000000000B0000000300000000000B0000000B0000000B00
      00000B0000000B0000000B0000000300000000000B0000000B00FFFF03000000
      00000300000000000300000000000300000000000B0000000B00000003000000
      00000B0000000B000000080002000000000002000A0002000A00030002000000
      03000100000003000100000003000100000003000D0000000300000000000B00
      FFFF03000A0000000300010000000300010000000B00FFFF0300000000000300
      0A00000003000100000003000000000008000200000000000300000000000300
      000000000300010000000300010000000B000000030000000000030000000000
      0300000000000300000000000B0000000B00FFFF030000000000030000000000
      0300000000000B00FFFF0B0000000300000000000B00FFFF0300010000000B00
      FFFF0B00FFFF0B00FFFF0300102700000B000000030000000000080002000000
      00000300000000000B00FFFF0800020000000000080002000000000008000200
      0000000008000200000000000300000000000300000000000300000000000300
      000000000B00FFFF0B0000000300080000000B0000000B000000030000000000
      0800020000000000080002000000000008000200000000000300010000000300
      010000000300010000000B000000030004000000030000000000030000000000
      0B00000003000000000003000000000003000100000003000100000003000A00
      0000030000000000020000000300000000000300000000000300000000000300
      000000000300000000000300000000000300000000000B000000030000000000
      020001000B0000000B0000000B00000003000000000003000000000003000000
      00000B0000000B00000003000000000003000000000002000000020000000B00
      FFFF030000000000020000000500000000000000F03F0200FF000B0000000300
      00000000}
  end
  object Panel1: TPanel
    Left = 0
    Top = 610
    Width = 1099
    Height = 32
    Align = alBottom
    TabOrder = 1
    object Label1: TLabel
      Left = 560
      Top = 0
      Width = 73
      Height = 29
      Caption = 'Label1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object Edit1: TEdit
    Left = 952
    Top = 40
    Width = 121
    Height = 26
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI Emoji'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 952
    Top = 112
    Width = 121
    Height = 29
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ProgressBar1: TProgressBar
    Left = 896
    Top = 72
    Width = 185
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 4
  end
  object ProgressBar2: TProgressBar
    Left = 900
    Top = 144
    Width = 181
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 5
  end
  object ImagXpress7_2: TImagXpress7_
    Left = 0
    Top = 56
    Width = 273
    Height = 553
    ParentColor = False
    ParentFont = False
    TabOrder = 6
    ControlData = {
      0800420000004200310033004200300035004600460036003100330042003200
      4200390042003300300030003100300037004100420032004600390044004600
      380046003800000056571C1B10EEBE5703000100000010070000371C00002739
      000008000200000000000300050000001300C0C0C0000B00FFFF09000352E30B
      918FCE119DE300AA004BB85101A10000BC024442010005417269616C09000000
      0000000000000000000000000000130000000000130000000000090000000000
      0000000000000000000000000B0000000300000000000B0000000B0000000B00
      00000B0000000B0000000B0000000300000000000B0000000B00FFFF03000000
      00000300000000000300000000000300000000000B0000000B00000003000000
      00000B0000000B000000080002000000000002000A0002000A00030002000000
      03000100000003000100000003000100000003000D0000000300000000000B00
      FFFF03000A0000000300010000000300010000000B00FFFF0300000000000300
      0A00000003000100000003000000000008000200000000000300000000000300
      000000000300010000000300010000000B000000030000000000030000000000
      0300000000000300000000000B0000000B00FFFF030000000000030000000000
      0300000000000B00FFFF0B0000000300000000000B00FFFF0300020000000B00
      FFFF0B00FFFF0B00FFFF0300102700000B000000030000000000080002000000
      00000300000000000B00FFFF0800020000000000080002000000000008000200
      0000000008000200000000000300000000000300000000000300000000000300
      000000000B00FFFF0B0000000300080000000B0000000B000000030000000000
      0800020000000000080002000000000008000200000000000300010000000300
      010000000300010000000B000000030004000000030000000000030000000000
      0B00000003000000000003000000000003000100000003000100000003000A00
      0000030000000000020000000300000000000300000000000300000000000300
      000000000300000000000300000000000300000000000B000000030000000000
      020001000B0000000B0000000B00000003000000000003000000000003000000
      00000B0000000B00000003000000000003000000000002000000020000000B00
      FFFF030000000000020000000500000000000000F03F0200FF000B0000000300
      00000000}
  end
  object Button1: TButton
    Left = 900
    Top = 552
    Width = 165
    Height = 41
    Caption = 'SETTINGS'
    TabOrder = 7
    OnClick = Button1Click
  end
  object ImagXpress7_3: TImagXpress7_
    Left = 280
    Top = 56
    Width = 313
    Height = 241
    ParentColor = False
    ParentFont = False
    TabOrder = 8
    ControlData = {
      0800420000004200310033004200300035004600460036003100330042003200
      4200390042003300300030003100300037004100420032004600390044004600
      380046003800000056571C1B10EEBE570300010000001007000059200000E818
      000008000200000000000300050000001300C0C0C0000B00FFFF09000352E30B
      918FCE119DE300AA004BB85101A10000BC024442010005417269616C09000000
      0000000000000000000000000000130000000000130000000000090000000000
      0000000000000000000000000B0000000300000000000B0000000B0000000B00
      00000B0000000B0000000B0000000300000000000B0000000B00FFFF03000000
      00000300000000000300000000000300000000000B0000000B00000003000000
      00000B0000000B000000080002000000000002000A0002000A00030002000000
      03000100000003000100000003000100000003000D0000000300000000000B00
      FFFF03000A0000000300010000000300010000000B00FFFF0300000000000300
      0A00000003000100000003000000000008000200000000000300000000000300
      000000000300010000000300010000000B000000030000000000030000000000
      0300000000000300000000000B0000000B00FFFF030000000000030000000000
      0300000000000B00FFFF0B0000000300000000000B00FFFF0300030000000B00
      FFFF0B00FFFF0B00FFFF0300102700000B000000030000000000080002000000
      00000300000000000B00FFFF0800020000000000080002000000000008000200
      0000000008000200000000000300000000000300000000000300000000000300
      000000000B00FFFF0B0000000300080000000B0000000B000000030000000000
      0800020000000000080002000000000008000200000000000300010000000300
      010000000300010000000B000000030004000000030000000000030000000000
      0B00000003000000000003000000000003000100000003000100000003000A00
      0000030000000000020000000300000000000300000000000300000000000300
      000000000300000000000300000000000300000000000B000000030000000000
      020001000B0000000B0000000B00000003000000000003000000000003000000
      00000B0000000B00000003000000000003000000000002000000020000000B00
      FFFF030000000000020000000500000000000000F03F0200FF000B0000000300
      00000000}
  end
  object Edit3: TEdit
    Left = 920
    Top = 304
    Width = 105
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object ImagXpress7_4: TImagXpress7_
    Left = 280
    Top = 336
    Width = 313
    Height = 273
    ParentColor = False
    ParentFont = False
    TabOrder = 10
    ControlData = {
      0800420000004200310033004200300035004600460036003100330042003200
      4200390042003300300030003100300037004100420032004600390044004600
      380046003800000056571C1B10EEBE570300010000001007000059200000371C
      000008000200000000000300050000001300C0C0C0000B00FFFF09000352E30B
      918FCE119DE300AA004BB85101A10000BC024442010005417269616C09000000
      0000000000000000000000000000130000000000130000000000090000000000
      0000000000000000000000000B0000000300000000000B0000000B0000000B00
      00000B0000000B0000000B0000000300000000000B0000000B00FFFF03000000
      00000300000000000300000000000300000000000B0000000B00000003000000
      00000B0000000B000000080002000000000002000A0002000A00030002000000
      03000100000003000100000003000100000003000D0000000300000000000B00
      FFFF03000A0000000300010000000300010000000B00FFFF0300000000000300
      0A00000003000100000003000000000008000200000000000300000000000300
      000000000300010000000300010000000B000000030000000000030000000000
      0300000000000300000000000B0000000B00FFFF030000000000030000000000
      0300000000000B00FFFF0B0000000300000000000B00FFFF0300040000000B00
      FFFF0B00FFFF0B00FFFF0300102700000B000000030000000000080002000000
      00000300000000000B00FFFF0800020000000000080002000000000008000200
      0000000008000200000000000300000000000300000000000300000000000300
      000000000B00FFFF0B0000000300080000000B0000000B000000030000000000
      0800020000000000080002000000000008000200000000000300010000000300
      010000000300010000000B000000030004000000030000000000030000000000
      0B00000003000000000003000000000003000100000003000100000003000A00
      0000030000000000020000000300000000000300000000000300000000000300
      000000000300000000000300000000000300000000000B000000030000000000
      020001000B0000000B0000000B00000003000000000003000000000003000000
      00000B0000000B00000003000000000003000000000002000000020000000B00
      FFFF030000000000020000000500000000000000F03F0200FF000B0000000300
      00000000}
  end
  object Edit4: TEdit
    Left = 912
    Top = 424
    Width = 121
    Height = 21
    TabOrder = 11
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object N1: TMenuItem
      Caption = 'File'
      Hint = 'Save As|Saves the active file with a new name'
      ImageIndex = 30
      object N2: TMenuItem
        Caption = 'Open Image...'
        OnClick = N2Click
      end
      object SaveImage1: TMenuItem
        Caption = 'Save Image'
        OnClick = SaveImage1Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object N7: TMenuItem
        Caption = 'Binary Convert'
        OnClick = N7Click
      end
    end
    object Steps1: TMenuItem
      Caption = 'Steps'
      object Find1: TMenuItem
        Caption = 'Find PDH/PDV'
        OnClick = Find1Click
      end
      object Findpattern1: TMenuItem
        Caption = 'Find pattern'
        OnClick = Findpattern1Click
      end
      object Removepattern1: TMenuItem
        Caption = 'Remove pattern'
        OnClick = Removepattern1Click
      end
      object Optimize1: TMenuItem
        Caption = 'Optimize'
        OnClick = Optimize1Click
      end
    end
    object Morphology1: TMenuItem
      Caption = 'Morphology'
      object Dilate1: TMenuItem
        Caption = 'Dilation'
        OnClick = Dilate1Click
      end
      object Erode1: TMenuItem
        Caption = 'Erosion'
        OnClick = Erode1Click
      end
      object Opening1: TMenuItem
        Caption = 'Opening'
        OnClick = Opening1Click
      end
      object Closing1: TMenuItem
        Caption = 'Closing'
        OnClick = Closing1Click
      end
    end
    object Generate1: TMenuItem
      Caption = 'Generate'
      object Addrandompattern1: TMenuItem
        Caption = 'Add random pattern'
        OnClick = Addrandompattern1Click
      end
      object Addlines1: TMenuItem
        Caption = 'Add lines'
        OnClick = Addlines1Click
      end
      object AddSquares1: TMenuItem
        Caption = 'Add squares'
        OnClick = AddSquares1Click
      end
      object Addcrosses1: TMenuItem
        Caption = 'Add crosses'
        OnClick = Addcrosses1Click
      end
      object Adddots1: TMenuItem
        Caption = 'Add dots'
        OnClick = Adddots1Click
      end
    end
    object Evaluation1: TMenuItem
      Caption = 'Evaluation'
      object GetScore1: TMenuItem
        Caption = 'Get Score'
        OnClick = GetScore1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '*.tif'
    Left = 40
    Top = 8
  end
end