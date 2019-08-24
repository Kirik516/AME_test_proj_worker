object Form1: TForm1
  Left = 700
  Top = 500
  Anchors = []
  Caption = 'Form1'
  ClientHeight = 156
  ClientWidth = 444
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  DesignSize = (
    444
    156)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 5
    Top = 11
    Width = 36
    Height = 13
    Caption = 'Value A'
  end
  object Label2: TLabel
    Left = 5
    Top = 44
    Width = 35
    Height = 13
    Caption = 'Value B'
  end
  object Label3: TLabel
    Left = 5
    Top = 73
    Width = 36
    Height = 13
    Caption = 'Value C'
  end
  object EditA: TEdit
    Left = 52
    Top = 8
    Width = 303
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    Text = 'EditA'
  end
  object EditB: TEdit
    Left = 52
    Top = 43
    Width = 303
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 1
    Text = 'EditB'
  end
  object EditC: TEdit
    Left = 52
    Top = 70
    Width = 303
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 2
    Text = 'EditC'
  end
  object Button1: TButton
    Left = 361
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 3
  end
  object Button2: TButton
    Left = 361
    Top = 39
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 4
  end
  object Button3: TButton
    Left = 361
    Top = 70
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 5
  end
  object Button4: TButton
    Left = 305
    Top = 117
    Width = 131
    Height = 31
    Anchors = [akRight, akBottom]
    Caption = 'Draw for me'
    TabOrder = 6
  end
  object Timer1: TTimer
    Interval = 33
    OnTimer = Timer1Timer
    Left = 272
    Top = 104
  end
end
