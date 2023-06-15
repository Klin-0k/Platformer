object Game: TGame
  Left = 0
  Top = 0
  BiDiMode = bdLeftToRight
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsNone
  Caption = 'Game'
  ClientHeight = 404
  ClientWidth = 337
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  ParentBiDiMode = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Fon: TImage
    Left = 0
    Top = 0
    Width = 337
    Height = 404
    Stretch = True
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 368
    Top = 120
  end
end
