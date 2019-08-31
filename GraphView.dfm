object GraphView1: TGraphView1
  Left = 0
  Top = 0
  Caption = 'Function graph'
  ClientHeight = 423
  ClientWidth = 541
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
  OnPaint = FormPaint
  OnResize = FormResize
  OnShow = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Titile: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 535
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
  object LabelY: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 404
    Width = 535
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
    ExplicitWidth = 50
  end
  object LabelX: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 26
    Width = 17
    Height = 372
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
  object GraphLabel: TLabel
    Left = 23
    Top = 23
    Width = 518
    Height = 378
    Align = alClient
    ExplicitWidth = 3
    ExplicitHeight = 13
  end
  object ResizeTimer: TTimer
    Enabled = False
    Interval = 200
    OnTimer = ResizeTimerTimer
    Left = 24
    Top = 24
  end
end
