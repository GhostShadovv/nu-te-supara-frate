//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lobby.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfLobby *fLobby;
//---------------------------------------------------------------------------

__fastcall TfLobby::TfLobby(TComponent* Owner)
        : TForm(Owner)
{
        playeri=0;
        timp_ramas=0;
        sariPeste=false;
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::eAdresaClick(TObject *Sender){
        eAdresa->Clear();    
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::eNumeClick(TObject *Sender){
        eNume->Clear();        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::ePortClick(TObject *Sender){
        ePort->Clear();
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::btnConnectClick(TObject *Sender){
        fJoc->cSocket->Active=false;
        fJoc->cSocket->Address=eAdresa->Text;
        lAfisareNume->Caption = nume = eNume->Text;
        fJoc->cSocket->Port=StrToInt(ePort->Text);
        fJoc->cSocket->Active=true;
        maresteFereastra();
        grupLoby->Visible=true;
        tTrimiteNume->Enabled=true;
        lAfisareNume->Visible=true;
        cb1->Enabled=false;
        cb2->Enabled=false;
        cb3->Enabled=false;
        cb4->Enabled=false;

}

//---------------------------------------------------------------------------

void __fastcall TfLobby :: maresteFereastra(){
       grupConectare->Visible=false;
       btnSinglePlayer->Visible=false;
       grupLoby->Left=24;
       for(int i=0;i<20;i++){
                if(fLobby->Left>0){
                        fLobby->Left-=1*8;
                }
                if(fLobby->Top>0){
                        fLobby->Top-=1*5;
                }
           fLobby->Width+=1*15;
           fLobby->Height+=1*2.41;
       }

}

//---------------------------------------------------------------------------

void __fastcall TfLobby :: micsoreazaFereastra(){
       grupConectare->Visible=true;
       fLobby->Left=600;
       fLobby->Top=300;
       fLobby->Width=260;  //770
       fLobby->Height=222; //270
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::btnSinglePlayerClick(TObject *Sender){
        fLobby->Hide();
        fJoc->cSocket->Active=false;
        fJoc->Show();
        fJoc->btnAlegeAlbastru->Visible=true;
        fJoc->btnAlegeVerde->Visible=true;
        fJoc->btnAlegeRosu->Visible=true;
        fJoc->btnAlegeGalben->Visible=true;
        fJoc->btnZar->Visible=true;
        fJoc->btnConnect->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::FormClose(TObject *Sender, TCloseAction &Action){
        exit(0);        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::mVerificaTimer(TObject *Sender){
        disableCeilalti();
        afiseazaPlayeri();
        verificaCulori();
        pornesteNumaratoare();
}

//---------------------------------------------------------------------------


void __fastcall TfLobby::tNumaratoareTimer(TObject *Sender){
        lNumaratoareInversa->Visible=true;
        if(timp_ramas>0){
                lNumaratoareInversa->Caption=timp_ramas;
                timp_ramas--;
                pornesteNumaratoare();
        }else{
                lNumaratoareInversa->Caption="Incepe";
                tNumaratoare->Enabled=false;
                Sleep(500);
                fLobby->Hide();
                fJoc->Show();
                fJoc->btnConnect->Visible=false;
                fJoc->tMultiplayer->Enabled=true;
        }
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::tTrimiteNumeTimer(TObject *Sender)
{
        tTrimiteNume->Enabled=false;
        fJoc->cSocket->Socket->SendText("Nr" + nume);
        
}

//---------------------------------------------------------------------------

 void __fastcall TfLobby :: verificaCulori(){
        if(!sariPeste){
                if(rbGalben1->Checked || rbGalben2->Checked || rbGalben3->Checked || rbGalben4->Checked){
                        rbGalben1->Enabled=false;
                        rbGalben2->Enabled=false;
                        rbGalben3->Enabled=false;
                        rbGalben4->Enabled=false;
                }
                if(rbVerde1->Checked || rbVerde2->Checked || rbVerde3->Checked || rbVerde4->Checked){
                        rbVerde1->Enabled=false;
                        rbVerde2->Enabled=false;
                        rbVerde3->Enabled=false;
                        rbVerde4->Enabled=false;
                }
                if(rbRosu1->Checked || rbRosu2->Checked || rbRosu3->Checked || rbRosu4->Checked){
                        rbRosu1->Enabled=false;
                        rbRosu2->Enabled=false;
                        rbRosu3->Enabled=false;
                        rbRosu4->Enabled=false;
                }
                if(rbAlbastru1->Checked || rbAlbastru2->Checked || rbAlbastru3->Checked || rbAlbastru4->Checked){
                        rbAlbastru1->Enabled=false;
                        rbAlbastru2->Enabled=false;
                        rbAlbastru3->Enabled=false;
                        rbAlbastru4->Enabled=false;
                }
                if(!rbGalben1->Checked && !rbGalben2->Checked && !rbGalben3->Checked && !rbGalben4->Checked){
                        rbGalben1->Enabled=true;
                        rbGalben2->Enabled=true;
                        rbGalben3->Enabled=true;
                        rbGalben4->Enabled=true;
                }
                if(!rbVerde1->Checked && !rbVerde2->Checked && !rbVerde3->Checked && !rbVerde4->Checked){
                        rbVerde1->Enabled=true;
                        rbVerde2->Enabled=true;
                        rbVerde3->Enabled=true;
                        rbVerde4->Enabled=true;
                }
                if(!rbRosu1->Checked && !rbRosu2->Checked && !rbRosu3->Checked && !rbRosu4->Checked){
                        rbRosu1->Enabled=true;
                        rbRosu2->Enabled=true;
                        rbRosu3->Enabled=true;
                        rbRosu4->Enabled=true;
                }
                if(!rbAlbastru1->Checked && !rbAlbastru2->Checked && !rbAlbastru3->Checked && !rbAlbastru4->Checked){
                        rbAlbastru1->Enabled=true;
                        rbAlbastru2->Enabled=true;
                        rbAlbastru3->Enabled=true;
                        rbAlbastru4->Enabled=true;
                }
        }
 }

//---------------------------------------------------------------------------

 void __fastcall TfLobby :: disableCeilalti(){
        if(nume==lNumePlayer1->Caption){
                grPlayer2->Enabled=false;
                grPlayer3->Enabled=false;
                grPlayer4->Enabled=false;
                if(rbGalben1->Checked || rbVerde1->Checked || rbRosu1->Checked || rbAlbastru1->Checked){
                        cb1->Enabled=true;
                }
                return;
        }
        if(nume==lNumePlayer2->Caption){
                grPlayer1->Enabled=false;
                grPlayer3->Enabled=false;
                grPlayer4->Enabled=false;
                if(rbGalben2->Checked || rbVerde2->Checked || rbRosu2->Checked || rbAlbastru2->Checked){
                        cb2->Enabled=true;
                }
                return;
        }
        if(nume==lNumePlayer3->Caption){
                grPlayer1->Enabled=false;
                grPlayer2->Enabled=false;
                grPlayer4->Enabled=false;
                if(rbGalben3->Checked || rbVerde3->Checked || rbRosu3->Checked || rbAlbastru3->Checked){
                        cb3->Enabled=true;
                }
                return;
        }
        if(nume==lNumePlayer4->Caption){
                grPlayer1->Enabled=false;
                grPlayer2->Enabled=false;
                grPlayer3->Enabled=false;
                if(rbGalben4->Checked || rbVerde4->Checked || rbRosu4->Checked || rbAlbastru4->Checked){
                        cb4->Enabled=true;
                }
                return;
        }
 }

//---------------------------------------------------------------------------

 void __fastcall TfLobby :: afiseazaPlayeri(){
        if(fJoc->mPlayer1!=NULL){
                grPlayer1->Visible=true;
                lNumePlayer1->Caption=fJoc->mPlayer1;
        }
        if(fJoc->mPlayer2!=NULL){
                grPlayer2->Visible=true;
                lNumePlayer2->Caption=fJoc->mPlayer2;
        }
        if(fJoc->mPlayer3!=NULL){
                grPlayer3->Visible=true;
                lNumePlayer3->Caption=fJoc->mPlayer3;
        }
        if(fJoc->mPlayer4!=NULL){
                grPlayer4->Visible=true;
                lNumePlayer4->Caption=fJoc->mPlayer4;
        }
 }

//---------------------------------------------------------------------------

 void __fastcall TfLobby :: pornesteNumaratoare(){
        if(tNumaratoare->Enabled==false){
                timp_ramas=5;
        }
        if(fJoc->mNrPlayeri==1 && cb1->Checked){
                if(tNumaratoare->Enabled==false){
                        tNumaratoare->Enabled=true;
                }
        }else{
          if(fJoc->mNrPlayeri==2 && cb1->Checked && cb2->Checked){
                if(tNumaratoare->Enabled==false){
                        tNumaratoare->Enabled=true;
                }
          }else{
             if(fJoc->mNrPlayeri==3 && cb1->Checked && cb2->Checked && cb3->Checked){
                if(tNumaratoare->Enabled==false){
                        tNumaratoare->Enabled=true;
                }
             }else{
                if(fJoc->mNrPlayeri==4 && cb1->Checked && cb2->Checked && cb3->Checked && cb4->Checked){
                        if(tNumaratoare->Enabled==false){
                        tNumaratoare->Enabled=true;
                        }
                }else{
                        lNumaratoareInversa->Visible=false;
                        tNumaratoare->Enabled=false;
                }
             }
          }
        }
 }

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbGalben1Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLG1");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbGalben2Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLG2");        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbGalben3Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLG3");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbGalben4Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLG4");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbVerde1Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLV1");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbVerde2Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLV2");        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbVerde3Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLV3");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbVerde4Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLV4");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbRosu1Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLR1");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbRosu2Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLR2");        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbRosu3Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLR3");        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbRosu4Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLR4");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbAlbastru1Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLA1");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbAlbastru2Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLA2");        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbAlbastru3Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLA3");        
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::rbAlbastru4Click(TObject *Sender){
        fJoc->cSocket->Socket->SendText("CLA4");
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::cb1Click(TObject *Sender){
        if(cb1->Checked==true){
                fJoc->cSocket->Socket->SendText("CB1A");
                rbGalben1->Enabled=false;
                rbVerde1->Enabled=false;
                rbRosu1->Enabled=false;
                rbAlbastru1->Enabled=false;
                sariPeste=true;
        }else{
                fJoc->cSocket->Socket->SendText("CB1F");
                rbGalben1->Enabled=true;
                rbVerde1->Enabled=true;
                rbRosu1->Enabled=true;
                rbAlbastru1->Enabled=true;
                sariPeste=false;
        }
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::cb2Click(TObject *Sender){
        if(cb2->Checked==true){
                fJoc->cSocket->Socket->SendText("CB2A");
                rbGalben2->Enabled=false;
                rbVerde2->Enabled=false;
                rbRosu2->Enabled=false;
                rbAlbastru2->Enabled=false;
                sariPeste=true;
        }else{
                fJoc->cSocket->Socket->SendText("CB2F");
                rbGalben2->Enabled=true;
                rbVerde2->Enabled=true;
                rbRosu2->Enabled=true;
                rbAlbastru2->Enabled=true;
                sariPeste=false;
        }
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::cb3Click(TObject *Sender){
        if(cb3->Checked==true){
                fJoc->cSocket->Socket->SendText("CB3A");
                rbGalben3->Enabled=false;
                rbVerde3->Enabled=false;
                rbRosu3->Enabled=false;
                rbAlbastru3->Enabled=false;
                sariPeste=true;
        }else{
                fJoc->cSocket->Socket->SendText("CB3F");
                rbGalben3->Enabled=true;
                rbVerde3->Enabled=true;
                rbRosu3->Enabled=true;
                rbAlbastru3->Enabled=true;
                sariPeste=false;
        }
}

//---------------------------------------------------------------------------

void __fastcall TfLobby::cb4Click(TObject *Sender){
        if(cb4->Checked==true){
                fJoc->cSocket->Socket->SendText("CB1A");
                rbGalben4->Enabled=false;
                rbVerde4->Enabled=false;
                rbRosu4->Enabled=false;
                rbAlbastru4->Enabled=false;
                sariPeste=true;
        }else{
                fJoc->cSocket->Socket->SendText("CB4F");
                rbGalben4->Enabled=true;
                rbVerde4->Enabled=true;
                rbRosu4->Enabled=true;
                rbAlbastru4->Enabled=true;
                sariPeste=false;
        }
}

//---------------------------------------------------------------------------


