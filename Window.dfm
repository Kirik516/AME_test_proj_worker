object Form1: TForm1
  Left = 0
  Top = 0
  Anchors = []
  Caption = 'Form1'
  ClientHeight = 150
  ClientWidth = 300
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    300
    150)
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
  object Edit1: TEdit
    Left = 52
    Top = 8
    Width = 159
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    Text = 'Edit1'
    ExplicitWidth = 121
  end
  object Edit2: TEdit
    Left = 52
    Top = 43
    Width = 159
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 1
    Text = 'Edit2'
    ExplicitWidth = 121
  end
  object Edit3: TEdit
    Left = 52
    Top = 70
    Width = 159
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 2
    Text = 'Edit3'
    ExplicitWidth = 121
  end
  object Button1: TButton
    Left = 217
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 3
    ExplicitLeft = 596
  end
  object Button2: TButton
    Left = 217
    Top = 39
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 4
    ExplicitLeft = 596
  end
  object Button3: TButton
    Left = 217
    Top = 70
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 5
    ExplicitLeft = 596
  end
  object Button4: TButton
    Left = 161
    Top = 111
    Width = 131
    Height = 31
    Anchors = [akRight, akBottom]
    Caption = 'Draw for me'
    TabOrder = 6
  end
end
