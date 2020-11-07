VERSION 5.00
Object = "{82351433-9094-11D1-A24B-00A0C932C7DF}#1.5#0"; "ANIGIF.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Animation GIF ActiveX Demo"
   ClientHeight    =   6732
   ClientLeft      =   1752
   ClientTop       =   2028
   ClientWidth     =   8400
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   PaletteMode     =   1  'UseZOrder
   Picture         =   "VB5Demo.frx":0000
   ScaleHeight     =   561
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   700
   Begin VB.CheckBox Check2 
      Caption         =   "AutoSize"
      Height          =   255
      Left            =   4440
      TabIndex        =   17
      Top             =   5160
      Width           =   1215
   End
   Begin VB.CheckBox Check1 
      Caption         =   "Transparent"
      Height          =   255
      Left            =   4440
      TabIndex        =   16
      Top             =   4800
      Value           =   1  'Checked
      Width           =   1215
   End
   Begin VB.Frame Frame2 
      Caption         =   "Sequence"
      Height          =   1095
      Left            =   5880
      TabIndex        =   11
      Top             =   5280
      Width           =   2295
      Begin VB.OptionButton optSequence 
         Caption         =   "Pingpong Sequence"
         Height          =   255
         Index           =   2
         Left            =   120
         TabIndex        =   14
         Top             =   720
         Width           =   2055
      End
      Begin VB.OptionButton optSequence 
         Caption         =   "Reverse Sequence"
         Height          =   255
         Index           =   1
         Left            =   120
         TabIndex        =   13
         Top             =   480
         Width           =   2055
      End
      Begin VB.OptionButton optSequence 
         Caption         =   "Normal Sequence"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   12
         Top             =   240
         Value           =   -1  'True
         Width           =   2055
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Stretch Mode"
      Height          =   1095
      Left            =   5880
      TabIndex        =   7
      Top             =   4080
      Width           =   2295
      Begin VB.OptionButton optStretch 
         Caption         =   "Proportional"
         Height          =   255
         Index           =   2
         Left            =   120
         TabIndex        =   10
         Top             =   720
         Width           =   2055
      End
      Begin VB.OptionButton optStretch 
         Caption         =   "Stretch"
         Height          =   255
         Index           =   1
         Left            =   120
         TabIndex        =   9
         Top             =   480
         Width           =   2055
      End
      Begin VB.OptionButton optStretch 
         Caption         =   "No Stretch"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   8
         Top             =   240
         Value           =   -1  'True
         Width           =   2055
      End
   End
   Begin AniGIFCtrl.AniGIF AniGIF1 
      Height          =   3708
      Left            =   240
      TabIndex        =   6
      Top             =   240
      Width           =   7920
      BackColor       =   16761024
      PLaying         =   -1  'True
      Transparent     =   -1  'True
      Speed           =   1
      Stretch         =   0
      AutoSize        =   0   'False
      SequenceString  =   ""
      Sequence        =   0
      HTTPProxy       =   ""
      HTTPUserName    =   ""
      HTTPPassword    =   ""
      MouseIcon       =   "VB5Demo.frx":4B146
      MousePointer    =   14
      GIF             =   "VB5Demo.frx":4B162
      ExtendWidth     =   13970
      ExtendHeight    =   6540
      Loop            =   0
      AutoRewind      =   0   'False
      Synchronized    =   -1  'True
   End
   Begin VB.CommandButton cmdStop 
      Caption         =   "Stop"
      Height          =   375
      Left            =   4440
      TabIndex        =   5
      Top             =   6000
      Width           =   1215
   End
   Begin VB.CommandButton cmdPlay 
      Caption         =   "Play"
      Height          =   375
      Left            =   4440
      TabIndex        =   4
      Top             =   5520
      Width           =   1215
   End
   Begin VB.FileListBox File1 
      Height          =   2184
      Left            =   2400
      Pattern         =   "*.gif;*.jpg;*.jpeg;*.bmp"
      TabIndex        =   2
      Top             =   4200
      Width           =   1935
   End
   Begin VB.DirListBox Dir1 
      Height          =   1665
      Left            =   240
      TabIndex        =   1
      Top             =   4680
      Width           =   2055
   End
   Begin VB.DriveListBox Drive1 
      Height          =   315
      Left            =   240
      TabIndex        =   0
      Top             =   4200
      Width           =   2055
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Height          =   255
      Left            =   4440
      TabIndex        =   15
      Top             =   4440
      Width           =   1215
   End
   Begin VB.Label lblFrame 
      BackStyle       =   0  'Transparent
      Caption         =   "Frame"
      Height          =   255
      Left            =   4440
      TabIndex        =   3
      Top             =   4200
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub AniGIF1_Step()
    Label1 = "Frame " & AniGIF1.Frame
End Sub

Private Sub Check1_Click()
    AniGIF1.Transparent = Check1.Value
End Sub

Private Sub Check2_Click()
    AniGIF1.AutoSize = Check2.Value
End Sub

Private Sub cmdPlay_Click()
    AniGIF1.Play
End Sub

Private Sub cmdStop_Click()
    AniGIF1.Stop
End Sub

Private Sub Dir1_Change()
    File1 = Dir1
End Sub
Private Sub Drive1_Change()
    Dir1 = Drive1
End Sub
Private Sub File1_Click()
    s = File1.Path
    If Right$(s, 1) = "\" Then
        s = s & File1
    Else
        s = s & "\" & File1
    End If
    If Not AniGIF1.ReadGIF(s) Then
        MsgBox "Read Wrong", 16
    End If
    AniGIF1.Frame = 0
    lblFrame = AniGIF1.Frames & " Frames"
End Sub

Private Sub Form_Load()
    lblFrame = AniGIF1.Frames & " Frames"
End Sub


Private Sub optSequence_Click(Index As Integer)
    AniGIF1.Sequence = Index
End Sub

Private Sub optStretch_Click(Index As Integer)
    AniGIF1.Stretch = Index
End Sub
