VERSION 5.00
Object = "{E2FF4C59-7110-49DA-9D97-4868DE797B88}#1.0#0"; "PlayGif.ocx"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmMain 
   Caption         =   "Demo"
   ClientHeight    =   5880
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6855
   LinkTopic       =   "Form1"
   ScaleHeight     =   5880
   ScaleWidth      =   6855
   StartUpPosition =   2  'CenterScreen
   Begin MSComDlg.CommonDialog dlgGif 
      Left            =   360
      Top             =   3360
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton cmdLoad 
      Caption         =   "Load a gif file and play ..."
      Height          =   375
      Left            =   3480
      TabIndex        =   2
      Top             =   120
      Width           =   3255
   End
   Begin VB.CommandButton cmdPlay 
      Caption         =   "Play the GIF Comes with this example"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Width           =   3255
   End
   Begin PLAYGIFLib.PlayGif PlayGif1 
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   720
      Width           =   375
      _Version        =   65536
      _ExtentX        =   661
      _ExtentY        =   661
      _StockProps     =   0
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command2_Click()
    
End Sub

Private Sub cmdLoad_Click()
On Error Resume Next
    dlgGif.Filter = "Animated GIF Files(*.gif)|*.gif"
    dlgGif.ShowOpen
    If dlgGif.FileName <> "" Then
        Me.PlayGif1.AutoSize = True
        Me.PlayGif1.LoadGif dlgGif.FileName
        Me.PlayGif1.Width = Me.PlayGif1.GetWidth * Screen.TwipsPerPixelX
        Me.PlayGif1.Height = Me.PlayGif1.GetHeight * Screen.TwipsPerPixelY
        Me.PlayGif1.Play
    End If
End Sub

Private Sub cmdPlay_Click()
    On Error Resume Next
    Me.PlayGif1.AutoSize = True
    Me.PlayGif1.LoadGif App.Path & "\example.gif"
    Me.PlayGif1.Width = Me.PlayGif1.GetWidth * Screen.TwipsPerPixelX
    Me.PlayGif1.Height = Me.PlayGif1.GetHeight * Screen.TwipsPerPixelY
    Me.PlayGif1.Play
End Sub

' .AboutBox
' .AddBitmap(strFileName As String) As Boolean
' .AddGif(strFileName As String) As Boolean
' .AutoSize = True/False
'.Avi2Gif
' .BackGroundColor
' .Close
' .Format
'.GetFrameCount
'.GetHeight
'.GetWidth
'.Height
'.Width
'.Left
'.License
'.LoadGif (strFileName As String) As Boolean
'.Loop
'.Pause
'.Play
'.SaveAsGif(strFileName As String) As Boolean
'.SaveBmpFile(index As Long, bmpFileName As String) As Boolean
'.SaveFrameToGif(index As Long, strGifName As String) As Boolean
'.SetFrameInterval(index As Long, interval As Long) As Boolean
'.SetFrameTransColor(index As Long, transcolor As Long) As Boolean
'.SetFrameTransPixel(index As Long, x As Long, y As Long)As Boolean
'.Stretch = True/False

