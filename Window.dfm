object Form1: TForm1
  Left = 320
  Top = 291
  Anchors = []
  Caption = 'AME worker'
  ClientHeight = 189
  ClientWidth = 598
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  DesignSize = (
    598
    189)
  PixelsPerInch = 96
  TextHeight = 13
  object Button4: TButton
    Left = 459
    Top = 150
    Width = 131
    Height = 31
    Anchors = [akRight, akBottom]
    Caption = 'Draw for me'
    TabOrder = 0
    OnClick = Button4Click
  end
  object GroupBoxVal: TGroupBox
    Left = 151
    Top = 8
    Width = 439
    Height = 129
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Control coef values'
    TabOrder = 1
    DesignSize = (
      439
      129)
    object Label1: TLabel
      Left = 16
      Top = 28
      Width = 36
      Height = 13
      Caption = 'Value A'
    end
    object Label2: TLabel
      Left = 17
      Top = 58
      Width = 35
      Height = 13
      Caption = 'Value B'
    end
    object Label3: TLabel
      Left = 16
      Top = 88
      Width = 36
      Height = 13
      Caption = 'Value C'
    end
    object ButtonA: TButton
      Left = 353
      Top = 22
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Stop'
      TabOrder = 0
      OnClick = ButtonTrCntClick
    end
    object ButtonB: TButton
      Left = 353
      Top = 53
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Stop'
      TabOrder = 1
      OnClick = ButtonTrCntClick
    end
    object ButtonC: TButton
      Left = 353
      Top = 83
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Stop'
      TabOrder = 2
      OnClick = ButtonTrCntClick
    end
    object EditA: TEdit
      Left = 60
      Top = 25
      Width = 287
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Enabled = False
      TabOrder = 3
      Text = 'EditA'
    end
    object EditB: TEdit
      Left = 60
      Top = 55
      Width = 287
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Enabled = False
      TabOrder = 4
      Text = 'EditB'
    end
    object EditC: TEdit
      Left = 60
      Top = 85
      Width = 287
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      Enabled = False
      TabOrder = 5
      Text = 'EditC'
    end
  end
  object GroupBoxFreq: TGroupBox
    Left = 8
    Top = 8
    Width = 137
    Height = 129
    Anchors = [akLeft, akTop, akBottom]
    Caption = 'Control frequency'
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
    DesignSize = (
      137
      129)
    object LabelFreqA: TLabel
      Left = 16
      Top = 28
      Width = 32
      Height = 13
      Caption = 'Freq A'
    end
    object LabelFreqB: TLabel
      Left = 16
      Top = 58
      Width = 31
      Height = 13
      Caption = 'Freq B'
    end
    object LabelFreqC: TLabel
      Left = 16
      Top = 88
      Width = 32
      Height = 13
      Caption = 'Freq C'
    end
    object EditFreqA: TEdit
      Left = 54
      Top = 25
      Width = 74
      Height = 21
      Hint = 'Value A flow frequency (secs for period)'
      Anchors = [akLeft, akTop, akRight]
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Text = '1,0'
      OnKeyPress = EditFreqKeyPress
    end
    object EditFreqB: TEdit
      Left = 53
      Top = 55
      Width = 74
      Height = 21
      Hint = 'Value B flow frequency (secs for period)'
      Anchors = [akLeft, akTop, akRight]
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      Text = '1,0'
      OnKeyPress = EditFreqKeyPress
    end
    object EditFreqC: TEdit
      Left = 53
      Top = 85
      Width = 75
      Height = 21
      Hint = 'Value C flow frequency (secs for period)'
      Anchors = [akLeft, akTop, akRight]
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Text = '1,0'
      OnKeyPress = EditFreqKeyPress
    end
  end
  object Timer1: TTimer
    Interval = 33
    OnTimer = Timer1Timer
  end
end
