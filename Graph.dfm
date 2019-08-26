object Graph1: TGraph1
  Left = 0
  Top = 0
  Caption = 'Function graph'
  ClientHeight = 281
  ClientWidth = 429
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnResize = FormShow
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Titile: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 423
    Height = 17
    Align = alTop
    AutoSize = False
    Caption = 'Graph for function: y = A + B + C'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Font.Quality = fqClearType
    ParentFont = False
    Layout = tlCenter
    ExplicitLeft = 8
    ExplicitTop = 8
    ExplicitWidth = 619
  end
  object Graph: TImage
    AlignWithMargins = True
    Left = 26
    Top = 26
    Width = 400
    Height = 230
    Align = alClient
    ExplicitLeft = 34
    ExplicitTop = 32
    ExplicitWidth = 608
    ExplicitHeight = 305
  end
  object LabelY: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 262
    Width = 423
    Height = 16
    Align = alBottom
    Alignment = taCenter
    Caption = 'Y - Axis'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitTop = 281
    ExplicitWidth = 50
  end
  object LabelX: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 26
    Width = 17
    Height = 230
    Align = alLeft
    Alignment = taCenter
    Caption = 'X - Axis'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Orientation = 900
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitHeight = 51
  end
  object BackGraph: TImage
    Left = 26
    Top = 26
    Width = 105
    Height = 105
    Visible = False
  end
end
