//---------------------------------------------------------------------------
#include <vcl.h>
#include <time.h>
#pragma hdrstop
#include <windef.h>
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "FereastraJoc.h"
#pragma link "AniGIFCtrl_OCX"
     TfJoc *fJoc;

//---------------------------------------------------------------------------
//----------Main-------------------------------------------------------------
//---------------------------------------------------------------------------
 __fastcall TfJoc::TfJoc(TComponent* Owner): TForm(Owner)
 {
        srand(time(NULL));
        valZar=0;
        m_valZar=0;
        numarJucatori=0;
        mNrPlayeri=0;
        tura=1;
        m_tura = tura;
        clickGalben=clickVerde=clickRosu=clickAlbastru=false;
        tura_G=tura_V=tura_R=tura_A=0;//pentru a stii in cate mutari ai castigat
        zar=false;                         //pentru a nu putea da click pe zar
        trimiteZar=false;
        sare=false;
        btnZar->Enabled=false;
        sariPeste=0;                       //pentru a nu mai face anumite operatii
        tVerificari->Enabled=false;        //pentru a opri timmer-ul
        puneCercuri();                     //punem adresele cercurilor in vectorul TShape local
        Gif1->Stop();
        Gif2->Stop();
        Gif3->Stop();
        Gif4->Stop();
        Gif5->Stop();
        Gif6->Stop();
        g_1=v_1=r_1=a_1=NULL;
        mPlayer1=mPlayer2=mPlayer3=mPlayer4=NULL;
        Jucator_1=Jucator_2=Jucator_3=Jucator_4=false;
        CasaG_1=CasaG_2=CasaG_3=CasaG_4=false;
        CasaV_1=CasaV_2=CasaV_3=CasaV_4=false;
        CasaR_1=CasaR_2=CasaR_3=CasaR_4=false;
        CasaA_1=CasaA_2=CasaA_3=CasaA_4=false;
        lGalben->Caption=" ";
        lVerde->Caption=" ";
        lRosu->Caption=" ";
        lAlbastru->Caption=" ";
        btnConnect->Left=283;
        btnConnect->Top=288;
 }
//------Buton-Jucator-Galben------------------------------------------------

 void __fastcall TfJoc::btnAlegeGalbenClick(TObject *Sender)
 {
         g_1 = new Galben(pBaza,BazaG[0]);
         g_2 = new Galben(pBaza,BazaG[1]);
         g_3 = new Galben(pBaza,BazaG[2]);
         g_4 = new Galben(pBaza,BazaG[3]);
         g_4->iesCasa(Loc[0],&zar);        //incepem jocul cu o piesa pe tabla
         g_1->setIdentitate("Galben", 1);
         g_2->setIdentitate("Galben", 2);
         g_3->setIdentitate("Galben", 3);
         g_4->setIdentitate("Galben", 4);
         btnAlegeGalben->Hide();
         seteazaJucator("Galben");
                                           //asignam event-uri si parametrii obiectelor
         PuneEvent_Parametrii(g_1,g_2,g_3,g_4,"Galben");
         zar=true;                         //putem da cu zarul
         btnZar->Enabled=true;
 }
//-------Buton-Jucator-Verde------------------------------------------------

 void __fastcall TfJoc::btnAlegeVerdeClick(TObject *Sender)
{
         v_1 = new Verde(pBaza,BazaV[0]);
         v_2 = new Verde(pBaza,BazaV[1]);
         v_3 = new Verde(pBaza,BazaV[2]);
         v_4 = new Verde(pBaza,BazaV[3]);
         v_4->iesCasa(Loc[10],&zar);        //incepem jocul cu o piesa pe tabla
         v_1->setIdentitate("Verde", 1);
         v_2->setIdentitate("Verde", 2);
         v_3->setIdentitate("Verde", 3);
         v_4->setIdentitate("Verde", 4);
         seteazaJucator("Verde");
         btnAlegeVerde->Hide();
                                            //asignam event-uri si parametrii obiectelor
         PuneEvent_Parametrii(v_1,v_2,v_3,v_4, "Verde");
         zar=true;                          //putem da cu zarul
         btnZar->Enabled=true;
}
//-------Buton-Jucator-Rosu-------------------------------------------------

void __fastcall TfJoc::btnAlegeRosuClick(TObject *Sender)
{
         r_1 = new Rosu(pBaza,BazaR[0]);
         r_2 = new Rosu(pBaza,BazaR[1]);
         r_3 = new Rosu(pBaza,BazaR[2]);
         r_4 = new Rosu(pBaza,BazaR[3]);
         r_4->iesCasa(Loc[20],&zar);        //incepem jocul cu o piesa pe tabla
         r_1->setIdentitate("Rosu", 1);
         r_2->setIdentitate("Rosu", 2);
         r_3->setIdentitate("Rosu", 3);
         r_4->setIdentitate("Rosu", 4);
         seteazaJucator("Rosu");
         btnAlegeRosu->Hide();
                                            //asignam event-uri si parametrii obiectelor
         PuneEvent_Parametrii(r_1,r_2,r_3,r_4, "Rosu");
         zar=true;                          //putem da cu zarul
         btnZar->Enabled=true;
}
//-------Buton-Jucator-Albastru---------------------------------------------

void __fastcall TfJoc::btnAlegeAlbastruClick(TObject *Sender)
{
         a_1 = new Albastru(pBaza,BazaA[0]);
         a_2 = new Albastru(pBaza,BazaA[1]);
         a_3 = new Albastru(pBaza,BazaA[2]);
         a_4 = new Albastru(pBaza,BazaA[3]);
         a_4->iesCasa(Loc[30],&zar);         //incepem jocul cu o piesa pe tabla
         a_1->setIdentitate("Albastru", 1);
         a_2->setIdentitate("Albastru", 2);
         a_3->setIdentitate("Albastru", 3);
         a_4->setIdentitate("Albastru", 4);
         seteazaJucator("Albastru");
         btnAlegeAlbastru->Hide();
                                             //asignam event-uri si parametrii obiectelor
         PuneEvent_Parametrii(a_1,a_2,a_3,a_4, "Albastru");
         zar=true;                           //putem da cu zarul
         btnZar->Enabled=true;
}
//-------Incepe-jocul-pe-retea----------------------------------------------
//-------Buton-Zar----------------------------------------------------------

 void __fastcall TfJoc::btnZarClick(TObject *Sender)
 {
    if(!sare){                         //se face doar o data
        String aux = numarJucatori;          //salvam in string numarul de jucatori
        aux+=" jucatori conectati";          //concaternam cu alt string
        mTest->Lines->Add(aux);              //afisam numarul de jucatori conectati
        mTest->Lines->Add("Jocul a inceput, Bafta!");//afisam ca am inceput jocul
        btnAlegeGalben->Hide();              //ascundem butoanele, jocul a inceput
        btnAlegeVerde->Hide();
        btnAlegeRosu->Hide();
        btnAlegeAlbastru->Hide();
        verificaCase();
        sare=true;
    }
    if(zar){                                 //daca trebuie sa dau cu zarul
        zar=false;                           //am dat deja cu zarul
        btnZar->Enabled=false;
        DaCuZarul(m_valZar);
        //DebugChatPozitii(g_1,g_2,g_3,g_4, "Galben");
        //DebugChatPozitii(v_1,v_2,v_3,v_4, "Verde");
        //DebugChatPozitii(r_1,r_2,r_3,r_4, "Rosu");
        //DebugChatPozitii(a_1,a_2,a_3,a_4, "Albastru");
        PuneParametruCercuri(g_1,g_2,g_3,g_4,"Galben");
        PuneParametruCercuri(v_1,v_2,v_3,v_4,"Verde");
        PuneParametruCercuri(r_1,r_2,r_3,r_4,"Rosu");
        PuneParametruCercuri(a_1,a_2,a_3,a_4,"Albastru");
        verificaTura();
        verificaDisponibilitate();
        if(!tVerificari->Enabled){
                tVerificari->Enabled=true;     //dupa inceperea meciului deblocam timerul
        }
    }
 }
//-------Timer--------------------------------------------------------------

void __fastcall TfJoc::tVerificariTimer(TObject *Sender)
{                                              //apelam functia de mai jos la fiecare 100ms (0.1s)
        VerificaAnimatii();                    //scoate click-ul si GIF-ul daca nu ruleaza
                                               //scrie pe piese daca sunt in aceeasi zona
        verificaPozitii_Scrie(g_1,g_2,g_3,g_4, "Galben");
        verificaPozitii_Scrie(v_1,v_2,v_3,v_4, "Verde");
        verificaPozitii_Scrie(r_1,r_2,r_3,r_4, "Rosu");
        verificaPozitii_Scrie(a_1,a_2,a_3,a_4, "Albastru");
                                               //adauga click-ul dupa rularea animatiei
        permiteMutare_RefaceCercuri(g_1,g_2,g_3,g_4, " ");
        permiteMutare_RefaceCercuri(v_1,v_2,v_3,v_4, " ");
        permiteMutare_RefaceCercuri(r_1,r_2,r_3,r_4, " ");
        permiteMutare_RefaceCercuri(a_1,a_2,a_3,a_4, " ");

        blocheazaZar();
        verificaDisponibilitate();
}

//---------------------------------------------------------------------------

void __fastcall TfJoc::cSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        String socketRequest = Socket->ReceiveText();
        if(socketRequest==1){
                m_valZar=1;
                btnZarClick(Sender);
                return;
        }
        if(socketRequest==2){
                m_valZar=2;
                btnZarClick(Sender);
                return;
        }
        if(socketRequest==3){
                m_valZar=3;
                btnZarClick(Sender);
                return;
        }
        if(socketRequest==4){
                m_valZar=4;
                btnZarClick(Sender);
                return;
        }
        if(socketRequest==5){
                m_valZar=5;
                btnZarClick(Sender);
                return;
        }
        if(socketRequest==6){
                m_valZar=6;
                btnZarClick(Sender);
                return;
        }
        String decGalben = socketRequest.SubString(1,6);
        if(decGalben=="Galben"){
        //culoare_pozitie
                String decID = socketRequest.SubString(7,1);
                if(socketRequest.Length()>7){
                        String decSF = socketRequest.SubString(8,3);
                        if(decSF=="Ies"){
                                if(decID == "1"){
                                        g_1->iesCasa(Loc[0],&zar);
                                        return;
                                }
                                if(decID == "2"){
                                        g_2->iesCasa(Loc[0],&zar);
                                        return;
                                }
                                if(decID == "3"){
                                        g_3->iesCasa(Loc[0],&zar);
                                        return;
                                }
                                if(decID == "4"){
                                        g_4->iesCasa(Loc[0],&zar);
                                        return;
                                }
                        }
                }
                if(decGalben=="Galben"){
                        if(decID == "1"){
                                g_1->faCeva();
                                return;
                        }
                        if(decID == "2"){
                                g_2->faCeva();
                                return;
                        }
                        if(decID == "3"){
                                g_3->faCeva();
                                return;
                        }
                        if(decID == "4"){
                                g_4->faCeva();
                                return;
                        }
                }
        }
        String decVerde = socketRequest.SubString(1,5);
        if(decVerde=="Verde"){
        //culoare_pozitie
                String decID = socketRequest.SubString(6,1);
                if(socketRequest.Length()>6){
                        String decSF = socketRequest.SubString(7,3);
                        if(decSF=="Ies"){
                                if(decID == "1"){
                                        v_1->iesCasa(Loc[10],&zar);
                                        return;
                                }
                                if(decID == "2"){
                                        v_2->iesCasa(Loc[10],&zar);
                                        return;
                                }
                                if(decID == "3"){
                                        v_3->iesCasa(Loc[10],&zar);
                                        return;
                                }
                                if(decID == "4"){
                                        v_4->iesCasa(Loc[10],&zar);
                                        return;
                                }

                        }
                }
                if(decVerde=="Verde"){
                        if(decID == "1"){
                                v_1->faCeva();
                                return;
                        }
                        if(decID == "2"){
                                v_2->faCeva();
                                return;
                        }
                        if(decID == "3"){
                                v_3->faCeva();
                                return;
                        }
                        if(decID == "4"){
                                v_4->faCeva();
                                return;
                        }
                }
        }
        String decRosu = socketRequest.SubString(1,4);
        if(decRosu=="Rosu"){
        //culoare_pozitie
                String decID = socketRequest.SubString(5,1);
                if(socketRequest.Length()>5){
                        String decSF = socketRequest.SubString(6,3);
                        if(decSF=="Ies"){
                                if(decID == "1"){
                                        r_1->iesCasa(Loc[20],&zar);
                                        return;
                                }
                                if(decID == "2"){
                                        r_2->iesCasa(Loc[20],&zar);
                                        return;
                                }
                                if(decID == "3"){
                                        r_3->iesCasa(Loc[20],&zar);
                                        return;
                                }
                                if(decID == "4"){
                                        r_4->iesCasa(Loc[20],&zar);
                                        return;
                                }
                        }
                }
                if(decRosu=="Rosu"){
                        if(decID == "1"){
                                r_1->faCeva();
                                return;
                        }
                        if(decID == "2"){
                                r_2->faCeva();
                                return;
                        }
                        if(decID == "3"){
                                r_3->faCeva();
                                return;
                        }
                        if(decID == "4"){
                                r_4->faCeva(); 
                                return;
                        }
                }
        }
        String decAlbastru = socketRequest.SubString(1,8);
        if(decAlbastru=="Albastru"){
        //culoare_pozitie
                String decID = socketRequest.SubString(9,1);
                if(socketRequest.Length()>9){
                        String decSF = socketRequest.SubString(10,3);
                        if(decSF=="Ies"){
                                if(decID == "1"){
                                        a_1->iesCasa(Loc[30],&zar);
                                        return;
                                }
                                if(decID == "2"){
                                        a_2->iesCasa(Loc[30],&zar);
                                        return;
                                }
                                if(decID == "3"){
                                        a_3->iesCasa(Loc[30],&zar);
                                        return;
                                }
                                if(decID == "4"){
                                        a_4->iesCasa(Loc[30],&zar);
                                        return;
                                }
                        }
                }
                if(decAlbastru=="Albastru"){
                        if(decID == "1"){
                                a_1->faCeva();
                                return;
                        }
                        if(decID == "2"){
                                a_2->faCeva();
                                return;
                        }
                        if(decID == "3"){
                                a_3->faCeva();
                                return;
                        }
                        if(decID == "4"){
                                a_4->faCeva(); 
                                return;
                        }
                }
        }
                                                     //pentru loby primesc toti clientii
        String decN = socketRequest.SubString(1,2);
        //Nr_NrPlayeri || Nr_Nume
        if(decN=="Nr"){
                String decI = socketRequest.SubString(3,1);
                String decNume = socketRequest.SubString(3, socketRequest.Length()-2);
                if(decI==1){
                        mNrPlayeri=1;
                        return;
                }
                if(decI==2){
                        mNrPlayeri=2;
                        return;
                }
                if(decI==3){
                        mNrPlayeri=3;
                        return;
                }
                if(decI==4){
                        mNrPlayeri=4;
                        return;
                }
                if(mPlayer1==NULL && mPlayer1!=decNume){
                        mPlayer1=decNume;
                        return;
                }
                if(mPlayer2==NULL && mPlayer2!=decNume){
                        mPlayer2=decNume;
                        return;
                }
                if(mPlayer3==NULL && mPlayer3!=decNume){
                        mPlayer3=decNume;
                        return;
                }
                if(mPlayer4==NULL && mPlayer4!=decNume){
                        mPlayer4=decNume;
                        return;
                }
                }
        if(decN=="CL"){
        //CL_Culoare_NrPlayer
                String decCL=socketRequest.SubString(3,1);
                String decID=socketRequest.SubString(4,1);
                if(decCL=="G"){
                        if(decID==1){
                                fLobby->rbGalben1->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==2){
                                fLobby->rbGalben2->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==3){
                                fLobby->rbGalben3->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==4){
                                fLobby->rbGalben4->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                }
                if(decCL=="V"){
                        if(decID==1){
                                fLobby->rbVerde1->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==2){
                                fLobby->rbVerde2->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==3){
                                fLobby->rbVerde3->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==4){
                                fLobby->rbVerde4->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                }
                if(decCL=="R"){
                        if(decID==1){
                                fLobby->rbRosu1->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==2){
                                fLobby->rbRosu2->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==3){
                                fLobby->rbRosu3->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==4){
                                fLobby->rbRosu4->Checked=true; 
                                fLobby->verificaCulori();
                                return;
                        }
                }
                if(decCL=="A"){
                        if(decID==1){
                                fLobby->rbAlbastru1->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==2){
                                fLobby->rbAlbastru2->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==3){
                                fLobby->rbAlbastru3->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                        if(decID==4){
                                fLobby->rbAlbastru4->Checked=true;
                                fLobby->verificaCulori();
                                return;
                        }
                }
        }
        if(decN=="CB"){                         //checkBox
        //CB_NrPlayer_Stare
                String decID=socketRequest.SubString(3,1);
                String decCH=socketRequest.SubString(4,1);
                if(decID==1){
                        if(decCH=="A"){
                                fLobby->cb1->Checked=true;
                                return;
                        }
                        fLobby->cb1->Checked=false;
                }
                if(decID==2){
                        if(decCH=="A"){
                                fLobby->cb2->Checked=true;
                                return;
                        }
                        fLobby->cb2->Checked=false;
                }
                if(decID==3){
                        if(decCH=="A"){
                                fLobby->cb3->Checked=true;
                                return;
                        }
                        fLobby->cb3->Checked=false;
                }
                if(decID==4){
                        if(decCH=="A"){
                                fLobby->cb4->Checked=true;
                                return;
                        }
                        fLobby->cb4->Checked=false;
                }
        }
}

//---------------------------------------------------------------------------

void __fastcall TfJoc::cSocketConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        mTest->Lines->Add(cSocket->Socket->RemoteAddress);
}

//--------Da-cu-zarul-si-pune-GIF--------------------------------------------

 void __fastcall TfJoc:: DaCuZarul(int a){
        if(a!=0){
                valZar=a;
        }
        else{
                valZar=rand()%6+1;;
        }

        if(!trimiteZar){
                cSocket->Socket->SendText(valZar);
                trimiteZar=true;
        }
       //valZar=6; tura++ ;                       //pentru teste
                                                  //ascundem GIF-urile
       Gif1->Visible=false;
       Gif2->Visible=false;
       Gif3->Visible=false;
       Gif4->Visible=false;
       Gif5->Visible=false;
       Gif6->Visible=false;
       if(tura%(numarJucatori+1)==0){
       tura++;
       }                                          //pentru fiecare caz, pornim GIF-ul
       if(valZar==1){                             //portivit impreuna cu un sunet de zar
       Gif1->Play();
       Gif1->Visible=true;
       sndPlaySoundA("SunetZar.wav", SND_ASYNC | SND_FILENAME);
      }
      if(valZar==2){
       Gif2->Play();
       Gif2->Visible=true;
       sndPlaySoundA("SunetZar.wav", SND_ASYNC | SND_FILENAME);
      }
      if(valZar==3){
       Gif3->Play();
       Gif3->Visible=true;
       sndPlaySoundA("SunetZar.wav", SND_ASYNC | SND_FILENAME);
      }
      if(valZar==4){
       Gif4->Play();
       Gif4->Visible=true;
       sndPlaySoundA("SunetZar.wav", SND_ASYNC | SND_FILENAME);
      }
      if(valZar==5){
       Gif5->Play();
       Gif5->Visible=true;
       sndPlaySoundA("SunetZar.wav", SND_ASYNC | SND_FILENAME);
      }
      if(valZar==6){
       Gif6->Play();
       Gif6->Visible=true;
       sndPlaySoundA("SunetZar.wav", SND_ASYNC | SND_FILENAME);
      }
       btnZar->Caption = valZar;                   //notam valoarea zarului pe buton
       pozitie += valZar;                          //adaugam apoi la pozitia initiala
      VerificaAnimatii();                          //scoate click-ul si GIF-ul daca nu ruleaza
 }

//-----------Verifica-daca-ruleaza-GIF---------------------------------------

 void __fastcall TfJoc :: VerificaAnimatii(){
        scoateEventClick(g_1,g_2,g_3,g_4);        //scoate click-ul
        scoateEventClick(v_1,v_2,v_3,v_4);
        scoateEventClick(r_1,r_2,r_3,r_4);
        scoateEventClick(a_1,a_2,a_3,a_4);

        if(!Gif1->Playing){                       //scoate GIF-ul daca nu ruleaza
           Gif1->Visible=false;
        }
        if(!Gif2->Playing){
           Gif2->Visible=false;
        }
        if(!Gif3->Playing){
           Gif3->Visible=false;
        }
        if(!Gif4->Playing){
           Gif4->Visible=false;
        }
        if(!Gif5->Playing){
           Gif5->Visible=false;
        }
        if(!Gif6->Playing){
           Gif6->Visible=false;
        }
}

//---------Scoate-click-------------------------------------------------------

 void __fastcall TfJoc :: scoateEventClick(Pozitie *a, Pozitie *b, Pozitie *c, Pozitie *d)
 {
        if(a!=NULL){                                 //daca jucatorul exista si cel putin un GIF ruleaza
         if(Gif1->Playing || Gif2->Playing || Gif3->Playing ||
 Gif4->Playing || Gif5->Playing || Gif6->Playing){
           a->Piesa->OnClick=NULL;                   //scoate click-ul de la acel jucator
           b->Piesa->OnClick=NULL;
           c->Piesa->OnClick=NULL;
           d->Piesa->OnClick=NULL;
         }
        }
 }

//--------Adauga-click-si-redeseneaza----------------------------------------

 void __fastcall TfJoc :: permiteMutare_RefaceCercuri(Pozitie *a, Pozitie *b, Pozitie *c, Pozitie *d, String s){

    if(a != NULL && !Gif1->Playing && !Gif2->Playing && !Gif3->Playing && !Gif4->Playing && !Gif5->Playing && !Gif6->Playing){
        a->Piesa->OnClick = a->EventMutaPiesa;       //daca jucatorul exista si nu ruleaza nici-un GIF
        b->Piesa->OnClick = b->EventMutaPiesa;       //atribuie click-ul jucatorului
        c->Piesa->OnClick = c->EventMutaPiesa;
        d->Piesa->OnClick = d->EventMutaPiesa;
    }
    if(s=="Reface"){                                 //daca vrem sa refacem piesele cu highlight
    if(a != NULL){  a->Reface();
    }
    if(b != NULL){  b->Reface();
    }
    if(c != NULL){  c->Reface();
    }
    if(d != NULL){  d->Reface();
    }
    }
 }

//----------Pentru-teste----------------------------------------------------

void __fastcall TfJoc::Panel1Click(TObject *Sender)
{
        btnZar->Enabled=true;                       //pentru teste
        zar=true;
}

//------Buton-Exit----------------------------------------------------------

 void __fastcall TfJoc::BitBtn1Click(TObject *Sender)
 {
        exit(0);                                   //iesi din aplicatie
 }

//----------Pentru-a-arata-pozitia-pieselor-unui-jucator---------------------

 void __fastcall TfJoc :: DebugChatPozitii(Pozitie *a, Pozitie *b, Pozitie *c,
 Pozitie *d, String s){
     String aux;                                  //------pentru "debugging"
     if(a!=NULL){
       aux="1 ";
       aux+=s;
       aux+=": ";
       aux+=a->iaPoz();
       mTest->Lines->Add(aux);
       mTest->Lines->Add(" ");
       aux="2 ";
       aux+=s;
       aux+=": ";
       aux+=b->iaPoz();
       mTest->Lines->Add(aux);
       mTest->Lines->Add(" ");
       aux="3 ";
       aux+=s;
       aux+=": ";
       aux+=c->iaPoz();
       mTest->Lines->Add(aux);
       mTest->Lines->Add(" ");
       aux="4 ";
       aux+=s;
       aux+=": ";
       aux+=d->iaPoz();
       mTest->Lines->Add(aux);
       mTest->Lines->Add(" ");

       String s;
                if(tVerificari->Enabled==true){    s="pornit";  }
                 else/*---------------------*/{    s="oprit";   }
       mTest->Lines->Add(s);                       //-----sf "debugging"
       }
}

//----------Verifica-daca-jucatorul-poate-muta-----------------------------

void __fastcall TfJoc :: verificaDisponibilitate(){
        if(g_1!=NULL){
          if(tura_inceput_G==tura%(numarJucatori+1) && valZar!=6){
                if(g_1->iaCasa() && g_2->iaCasa() && g_3->iaCasa() && g_4->iaCasa() ||
finalGalben==1 && g_1->iaCasa() && g_2->iaCasa() && g_3->iaCasa() ||
finalGalben==1 && g_1->iaCasa() && g_2->iaCasa() && g_4->iaCasa() ||
finalGalben==1 && g_1->iaCasa() && g_3->iaCasa() && g_4->iaCasa() ||
finalGalben==1 && g_2->iaCasa() && g_3->iaCasa() && g_4->iaCasa() ||
finalGalben==2 && g_1->iaCasa() && g_2->iaCasa()  ||
finalGalben==2 && g_1->iaCasa() && g_3->iaCasa()  ||
finalGalben==2 && g_1->iaCasa() && g_4->iaCasa()  ||
finalGalben==2 && g_2->iaCasa() && g_3->iaCasa()  ||
finalGalben==2 && g_2->iaCasa() && g_4->iaCasa()  ||
finalGalben==2 && g_3->iaCasa() && g_4->iaCasa()  ||
finalGalben==3 && g_1->iaCasa() ||
finalGalben==3 && g_2->iaCasa() ||
finalGalben==3 && g_3->iaCasa() ||
finalGalben==3 && g_4->iaCasa()){
                        String aux=valZar;
                        aux+=", urmatorul";
                        btnZar->Caption=aux;
                        zar=true;
                        btnZar->Enabled=true;
                        tura++;
                        m_tura++;
                        return;
                }
          }
        }
        if(v_1!=NULL){
          if(tura_inceput_V==tura%(numarJucatori+1) && valZar!=6){
                if(v_1->iaCasa() && v_2->iaCasa() && v_3->iaCasa() && v_4->iaCasa() ||
finalGalben==1 && v_1->iaCasa() && v_2->iaCasa() && v_3->iaCasa() ||
finalGalben==1 && v_1->iaCasa() && v_2->iaCasa() && v_4->iaCasa() ||
finalGalben==1 && v_1->iaCasa() && v_3->iaCasa() && v_4->iaCasa() ||
finalGalben==1 && v_2->iaCasa() && v_3->iaCasa() && v_4->iaCasa() ||
finalGalben==2 && v_1->iaCasa() && v_2->iaCasa()  ||
finalGalben==2 && v_1->iaCasa() && v_3->iaCasa()  ||
finalGalben==2 && v_1->iaCasa() && v_4->iaCasa()  ||
finalGalben==2 && v_2->iaCasa() && v_3->iaCasa()  ||
finalGalben==2 && v_2->iaCasa() && v_4->iaCasa()  ||
finalGalben==2 && v_3->iaCasa() && v_4->iaCasa()  ||
finalGalben==3 && v_1->iaCasa() ||
finalGalben==3 && v_2->iaCasa() ||
finalGalben==3 && v_3->iaCasa() ||
finalGalben==3 && v_4->iaCasa()){
                        String aux=valZar;
                        aux+=", urmatorul";
                        btnZar->Caption=aux;
                        zar=true;
                        btnZar->Enabled=true;
                        tura++;
                        m_tura++;
                        return;
                }
          }
        }
        if(r_1!=NULL){
          if(tura_inceput_R==tura%(numarJucatori+1) && valZar!=6){
                if(r_1->iaCasa() && r_2->iaCasa() && r_3->iaCasa() && r_4->iaCasa() ||
finalGalben==1 && r_1->iaCasa() && r_2->iaCasa() && r_3->iaCasa() ||
finalGalben==1 && r_1->iaCasa() && r_2->iaCasa() && r_4->iaCasa() ||
finalGalben==1 && r_1->iaCasa() && r_3->iaCasa() && r_4->iaCasa() ||
finalGalben==1 && r_2->iaCasa() && r_3->iaCasa() && r_4->iaCasa() ||
finalGalben==2 && r_1->iaCasa() && r_2->iaCasa()  ||
finalGalben==2 && r_1->iaCasa() && r_3->iaCasa()  ||
finalGalben==2 && r_1->iaCasa() && r_4->iaCasa()  ||
finalGalben==2 && r_2->iaCasa() && r_3->iaCasa()  ||
finalGalben==2 && r_2->iaCasa() && r_4->iaCasa()  ||
finalGalben==2 && r_3->iaCasa() && r_4->iaCasa()  ||
finalGalben==3 && r_1->iaCasa() ||
finalGalben==3 && r_2->iaCasa() ||
finalGalben==3 && r_3->iaCasa() ||
finalGalben==3 && r_4->iaCasa()){
                        String aux=valZar;
                        aux+=", urmatorul";
                        btnZar->Caption=aux;
                        zar=true;
                        btnZar->Enabled=true;
                        tura++;  
                        m_tura++;
                        return;
                }
          }
        }
        if(a_1!=NULL){
        if(tura_inceput_A==tura%(numarJucatori+1) && valZar!=6){
                if(a_1->iaCasa() && a_2->iaCasa() && a_3->iaCasa() && a_4->iaCasa() ||
finalGalben==1 && a_1->iaCasa() && a_2->iaCasa() && a_3->iaCasa() ||
finalGalben==1 && a_1->iaCasa() && a_2->iaCasa() && a_4->iaCasa() ||
finalGalben==1 && a_1->iaCasa() && a_3->iaCasa() && a_4->iaCasa() ||
finalGalben==1 && a_2->iaCasa() && a_3->iaCasa() && a_4->iaCasa() ||
finalGalben==2 && a_1->iaCasa() && a_2->iaCasa()  ||
finalGalben==2 && a_1->iaCasa() && a_3->iaCasa()  ||
finalGalben==2 && a_1->iaCasa() && a_4->iaCasa()  ||
finalGalben==2 && a_2->iaCasa() && a_3->iaCasa()  ||
finalGalben==2 && a_2->iaCasa() && a_4->iaCasa()  ||
finalGalben==2 && a_3->iaCasa() && a_4->iaCasa()  ||
finalGalben==3 && a_1->iaCasa() ||
finalGalben==3 && a_2->iaCasa() ||
finalGalben==3 && a_3->iaCasa() ||
finalGalben==3 && a_4->iaCasa()){
                        String aux=valZar;
                        aux+=", urmatorul";
                        btnZar->Caption=aux;
                        zar=true;
                        btnZar->Enabled=true;
                        tura++;   
                        m_tura++;
                        return;
                }
          }
        }
}
//----------Atribuie-Jucatori---------------------------------------------

 void __fastcall TfJoc :: seteazaJucator(String s){
  numarJucatori++;
   if(!Jucator_1 && !Jucator_2 && !Jucator_3 && !Jucator_4){
                Jucator_1=true;
                mTest->Lines->Add("Jucator 1 conectat");
                seteazaText(s, "Jucator 1", 1);
   }
         else{
           if(!Jucator_2 && !Jucator_3 && !Jucator_4){
                Jucator_2=true;
                mTest->Lines->Add("Jucator 2 conectat");
                seteazaText(s, "Jucator 2", 2);
           }
                else{
                  if(!Jucator_3 && !Jucator_4){
                        Jucator_3=true;
                        mTest->Lines->Add("Jucator 3 conectat");
                        seteazaText(s, "Jucator 3", 3);
                  }
                        else{
                          if(!Jucator_4){
                                Jucator_4=true;
                                mTest->Lines->Add("Jucator 4 conectat");
                                seteazaText(s, "Jucator 4", 4);
                          }
                        }
                }
         }
 }

//----------Seteaza-Text-Jucatori-------------------------------------------

 void __fastcall TfJoc :: seteazaText (String s0, String s1, int a){
        String aux;
         if(s0 == "Galben") {
                lGalben->Caption=s1;
                tura_inceput_G=a;
                aux+=a;
                mTest->Lines->Add(aux);
         }
         if(s0 == "Verde"){
                lVerde->Caption=s1;
                tura_inceput_V=a;
                aux+=a;
                mTest->Lines->Add(aux);
         }
         if(s0 == "Rosu"){
                lRosu->Caption=s1;
                tura_inceput_R=a;
                aux+=a;
                mTest->Lines->Add(aux);
         }
         if(s0 == "Albastru"){
                lAlbastru->Caption=s1;
                tura_inceput_A=a;
                aux+=a;
                mTest->Lines->Add(aux);
         }
 }

//----------Verifica-tura-initiala----------------------------------------

 void __fastcall TfJoc :: verificaTuraInceput(){
        if(g_1!=NULL){
            g_1->setJucatorInitial(&tura_inceput_G);
            g_2->setJucatorInitial(&tura_inceput_G);
            g_3->setJucatorInitial(&tura_inceput_G);
            g_4->setJucatorInitial(&tura_inceput_G);
        }
        if(v_1!=NULL){
            v_1->setJucatorInitial(&tura_inceput_V);
            v_2->setJucatorInitial(&tura_inceput_V);
            v_3->setJucatorInitial(&tura_inceput_V);
            v_4->setJucatorInitial(&tura_inceput_V);
        }
        if(r_1!=NULL){
            r_1->setJucatorInitial(&tura_inceput_R);
            r_2->setJucatorInitial(&tura_inceput_R);
            r_3->setJucatorInitial(&tura_inceput_R);
            r_4->setJucatorInitial(&tura_inceput_R);
        }
        if(a_1!=NULL){
            a_1->setJucatorInitial(&tura_inceput_A);
            a_2->setJucatorInitial(&tura_inceput_A);
            a_3->setJucatorInitial(&tura_inceput_A);
            a_4->setJucatorInitial(&tura_inceput_A);
        }
 }

//----------Verifica-a-cui-este-tura----------------------------------------

 void __fastcall TfJoc :: verificaTura(){
            if(g_1!=NULL){
            g_1->setTura(&tura);
            g_2->setTura(&tura);
            g_3->setTura(&tura);
            g_4->setTura(&tura);
           }
            if(v_1!=NULL){
            v_1->setTura(&tura);
            v_2->setTura(&tura);
            v_3->setTura(&tura);
            v_4->setTura(&tura);
            }
            if(r_1!=NULL){
            r_1->setTura(&tura);
            r_2->setTura(&tura);
            r_3->setTura(&tura);
            r_4->setTura(&tura);
            }
            if(a_1!=NULL){
            a_1->setTura(&tura);
            a_2->setTura(&tura);
            a_3->setTura(&tura);
            a_4->setTura(&tura);
            }
 }

//----------Setare-inamici-------------------------------------------------

 void __fastcall TfJoc :: verificaInamici(String s){
       if(s=="Galben"){
                if(g_1->iaPoz()!=-1){
                        cine_scoate(g_1, s);
                }
                if(g_2->iaPoz()!=-1){
                        cine_scoate(g_2, s);
                }
                if(g_3->iaPoz()!=-1){
                        cine_scoate(g_3, s);
                }
                if(g_4->iaPoz()!=-1){
                        cine_scoate(g_4, s);
                }
       }
       if(s=="Verde"){
                if(v_1->iaPoz()!=-1){
                        cine_scoate(v_1, s);
                }
                if(v_2->iaPoz()!=-1){
                        cine_scoate(v_2, s);
                }
                if(v_3->iaPoz()!=-1){
                        cine_scoate(v_3, s);
                }
                if(v_4->iaPoz()!=-1){
                        cine_scoate(v_4, s);
                }
       }
        if(s=="Rosu"){
                if(r_1->iaPoz()!=-1){
                        cine_scoate(r_1, s);
                }
                if(r_2->iaPoz()!=-1){
                        cine_scoate(r_2, s);
                }
                if(r_3->iaPoz()!=-1){
                        cine_scoate(r_3, s);
                }
                if(r_4->iaPoz()!=-1){
                        cine_scoate(r_4, s);
                }
        }

       if(s=="Albastru"){
                if(a_1->iaPoz()!=-1){
                        cine_scoate(a_1, s);
                }
                if(a_2->iaPoz()!=-1){
                        cine_scoate(a_2, s);
                }
                if(a_3->iaPoz()!=-1){
                        cine_scoate(a_3, s);
                }
                if(a_4->iaPoz()!=-1){
                        cine_scoate(a_4, s);
                }
       }
 }

 //----------Piesa-X-scoate-piesa-Y-----------------------------------------

  void __fastcall TfJoc :: cine_scoate(Pozitie *cineScoate, String s_cineScoate){
        if(s_cineScoate=="Galben"){
                if(v_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, v_1, v_2, v_3, v_4, s_cineScoate, "Verde");
                }
                if(r_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, r_1, r_2, r_3, r_4, s_cineScoate, "Rosu");
                }
                if(a_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, a_1, a_2, a_3, a_4, s_cineScoate, "Albastru");
                }
        }
        if(s_cineScoate=="Verde"){
                if(g_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, g_1, g_2, g_3, g_4, s_cineScoate, "Galben");
                }
                if(r_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, r_1, r_2, r_3, r_4, s_cineScoate, "Rosu");
                }
                if(a_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, a_1, a_2, a_3, a_4, s_cineScoate, "Albastru");
                }
        }
        if(s_cineScoate=="Rosu"){
                if(g_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, g_1, g_2, g_3, g_4, s_cineScoate, "Galben");
                }
                if(v_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, v_1, v_2, v_3, v_4, s_cineScoate, "Verde");
                }
                if(a_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, a_1, a_2, a_3, a_4, s_cineScoate, "Albastru");
                }
        }
        if(s_cineScoate=="Albastru"){
                if(g_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, g_1, g_2, g_3, g_4, s_cineScoate, "Galben");
                }
                if(v_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, v_1, v_2, v_3, v_4, s_cineScoate, "Verde");
                }
                if(r_1!=NULL){
                        verifica_si_scoate_pe(cineScoate, r_1, r_2, r_3, r_4, s_cineScoate, "Rosu");
                }
        }

  }

//----------Verifica-cine-scoate-pe-cine----------------------------------------------

 void __fastcall TfJoc :: verifica_si_scoate_pe(Pozitie *cineScoate, Pozitie *a, Pozitie *b,
Pozitie *c, Pozitie *d, String s_cineScoate, String s_peCine){
        if(s_cineScoate=="Galben"){
                if(s_peCine=="Verde"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+10)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+10)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+10)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+10)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Rosu"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+20)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+20)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+20)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+20)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Albastru"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+30)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+30)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+30)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+30)%40){
                                        d->puneInCasa();
                                }
                        }
                }
        }
        if(s_cineScoate=="Verde"){
                if(s_peCine=="Galben"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+30)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+30)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+30)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+30)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Rosu"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+10)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+10)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+10)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+10)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Albastru"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+20)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+20)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+20)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+20)%40){
                                        d->puneInCasa();
                                }
                        }
                }
        }
        if(s_cineScoate=="Rosu"){
                if(s_peCine=="Galben"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+20)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+20)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+20)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+20)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Verde"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+30)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+30)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+30)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+30)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Albastru"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+10)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+10)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+10)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+10)%40){
                                        d->puneInCasa();
                                }
                        }
                }
        }
        if(s_cineScoate=="Albastru"){
                if(s_peCine=="Galben"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+10)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+10)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+10)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+10)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Verde"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+20)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+20)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+20)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+20)%40){
                                        d->puneInCasa();
                                }
                        }
                }
                if(s_peCine=="Rosu"){
                        if(a->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(a->iaPoz()+30)%40){
                                        a->puneInCasa();
                                }
                        }
                        if(b->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(b->iaPoz()+30)%40){
                                        b->puneInCasa();
                                }
                        }
                        if(c->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(c->iaPoz()+30)%40){
                                        c->puneInCasa();
                                }
                        }
                        if(d->iaPoz()!=-1){
                                if(cineScoate->iaPoz()==(d->iaPoz()+30)%40){
                                        d->puneInCasa();
                                }
                        }
                }
        }
 }

//----------Redesenare-cercuri----------------------------------------------

 void __fastcall TfJoc :: pBazaMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
 {                                   //adauga click-ul si redeseneaza cercurile care au avut highlight
    permiteMutare_RefaceCercuri(g_1,g_2,g_3,g_4, "Reface");
    permiteMutare_RefaceCercuri(v_1,v_2,v_3,v_4, "Reface");
    permiteMutare_RefaceCercuri(r_1,r_2,r_3,r_4, "Reface");
    permiteMutare_RefaceCercuri(a_1,a_2,a_3,a_4, "Reface");
                                     //redesenam cercurie de inceput sau final daca au fost modificate
    if(cercA->Brush->Color!=clYellow){
         cercA->Brush->Color=clYellow;
    }
    if(cercB->Brush->Color!=clGreen){
         cercB->Brush->Color=clGreen;
    }
    if(cercC->Brush->Color!=clRed){
         cercC->Brush->Color=clRed;
    }
    if(cercD->Brush->Color!=clBlue){
         cercD->Brush->Color=clBlue;
    }
    if(cercFinalA1->Brush->Color!=clYellow || cercFinalA2->Brush->Color!=clYellow || cercFinalA3->Brush->Color!=clYellow || cercFinalA4->Brush->Color!=clYellow)
    {
         cercFinalA1->Brush->Color=clYellow;
         cercFinalA2->Brush->Color=clYellow;
         cercFinalA3->Brush->Color=clYellow;
         cercFinalA4->Brush->Color=clYellow;
    }
    if(cercFinalB1->Brush->Color!=clGreen || cercFinalB2->Brush->Color!=clGreen || cercFinalB3->Brush->Color!=clGreen || cercFinalB4->Brush->Color!=clGreen)
    {
         cercFinalB1->Brush->Color=clGreen;
         cercFinalB2->Brush->Color=clGreen;
         cercFinalB3->Brush->Color=clGreen;
         cercFinalB4->Brush->Color=clGreen;
    }
    if(cercFinalC1->Brush->Color!=clRed || cercFinalC2->Brush->Color!=clRed || cercFinalC3->Brush->Color!=clRed || cercFinalC4->Brush->Color!=clRed)
    {
         cercFinalC1->Brush->Color=clRed;
         cercFinalC2->Brush->Color=clRed;
         cercFinalC3->Brush->Color=clRed;
         cercFinalC4->Brush->Color=clRed;
    }
    if(cercFinalD1->Brush->Color!=clBlue || cercFinalD2->Brush->Color!=clBlue || cercFinalD3->Brush->Color!=clBlue || cercFinalD4->Brush->Color!=clBlue)
    {
         cercFinalD1->Brush->Color=clBlue;
         cercFinalD2->Brush->Color=clBlue;
         cercFinalD3->Brush->Color=clBlue;
         cercFinalD4->Brush->Color=clBlue;
    }
 }

//---------Salveaza-parametrii-jucator---------------------------------------

 void _fastcall TfJoc::PuneEvent_Parametrii(Pozitie *a, Pozitie *b, Pozitie *c,
Pozitie *d, String s){
        a->Piesa->OnClick = a->EventMutaPiesa;     //atribuim piesele
        b->Piesa->OnClick = b->EventMutaPiesa;
        c->Piesa->OnClick = c->EventMutaPiesa;
        d->Piesa->OnClick = d->EventMutaPiesa;    //initializam contoarele de final cu 0
        finalGalben=finalVerde=finalRosu=finalAlbastru=0;
        if(a!=NULL && s=="Galben"){               //daca-i galben luam parametrii pentru galben
        a->iaParametrii(&valZar, &zar, &finalGalben, btnZar, b->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_G);
        b->iaParametrii(&valZar, &zar, &finalGalben, btnZar, a->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_G);
        c->iaParametrii(&valZar, &zar, &finalGalben, btnZar, a->iaPoz(), b->iaPoz(), d->iaPoz(), mTest, &nrCasa_G);
        d->iaParametrii(&valZar, &zar, &finalGalben, btnZar, a->iaPoz(), b->iaPoz(), c->iaPoz(), mTest, &nrCasa_G);
        }
        if(a!=NULL && s=="Verde"){                //daca-i verde luam parametrii pentru verde
        a->iaParametrii(&valZar, &zar, &finalVerde, btnZar, b->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_V);
        b->iaParametrii(&valZar, &zar, &finalVerde, btnZar, a->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_V);
        c->iaParametrii(&valZar, &zar, &finalVerde, btnZar, a->iaPoz(), b->iaPoz(), d->iaPoz(), mTest, &nrCasa_V);
        d->iaParametrii(&valZar, &zar, &finalVerde, btnZar, a->iaPoz(), b->iaPoz(), c->iaPoz(), mTest, &nrCasa_V);
        }
        if(a!=NULL && s=="Rosu"){                  //daca-i rosu luam parametrii pentru rosu
        a->iaParametrii(&valZar, &zar, &finalRosu, btnZar, b->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_R);
        b->iaParametrii(&valZar, &zar, &finalRosu, btnZar, a->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_R);
        c->iaParametrii(&valZar, &zar, &finalRosu, btnZar, a->iaPoz(), b->iaPoz(), d->iaPoz(), mTest, &nrCasa_R);
        d->iaParametrii(&valZar, &zar, &finalRosu, btnZar, a->iaPoz(), b->iaPoz(), c->iaPoz(), mTest, &nrCasa_R);
        }
        if(a!=NULL && s=="Albastru"){              //daca-i albastru luam parametrii pentru albastru
        a->iaParametrii(&valZar, &zar, &finalAlbastru, btnZar, b->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_A);
        b->iaParametrii(&valZar, &zar, &finalAlbastru, btnZar, a->iaPoz(), c->iaPoz(), d->iaPoz(), mTest, &nrCasa_A);
        c->iaParametrii(&valZar, &zar, &finalAlbastru, btnZar, a->iaPoz(), b->iaPoz(), d->iaPoz(), mTest, &nrCasa_A);
        d->iaParametrii(&valZar, &zar, &finalAlbastru, btnZar, a->iaPoz(), b->iaPoz(), c->iaPoz(), mTest, &nrCasa_A);
        }                                         //atribuim event-ul specific atunci cand miscam
        a->Piesa->OnMouseMove = a->EventMouseMove;//mouse-ul deasupra piesei pentru a da highlight
        b->Piesa->OnMouseMove = b->EventMouseMove;
        c->Piesa->OnMouseMove = c->EventMouseMove;
        d->Piesa->OnMouseMove = d->EventMouseMove;
 }

//---------Salveaza-cercurile-pentru-highlight------------------------------

 void __fastcall TfJoc :: PuneParametruCercuri(Pozitie *a, Pozitie *b, Pozitie *c, Pozitie *d, String s){
        if(a!=NULL && s=="Galben"){            //daca exista piesa si e galbena, pune cercurile pentru highlight
                                               //pozitia unde sare sau de final sau de iesire din casa
        a->puneCercuri(cercuriGalben[a->iaPoz()+fJoc->valZar],cercuriFinalGalben[fJoc->finalGalben],cercA);
        b->puneCercuri(cercuriGalben[b->iaPoz()+fJoc->valZar],cercuriFinalGalben[fJoc->finalGalben],cercA);
        c->puneCercuri(cercuriGalben[c->iaPoz()+fJoc->valZar],cercuriFinalGalben[fJoc->finalGalben],cercA);
        d->puneCercuri(cercuriGalben[d->iaPoz()+fJoc->valZar],cercuriFinalGalben[fJoc->finalGalben],cercA);
        }
        if(a!=NULL && s=="Verde"){
        a->puneCercuri(cercuriVerde[a->iaPoz()+fJoc->valZar],cercuriFinalVerde[fJoc->finalVerde],cercB);
        b->puneCercuri(cercuriVerde[b->iaPoz()+fJoc->valZar],cercuriFinalVerde[fJoc->finalVerde],cercB);
        c->puneCercuri(cercuriVerde[c->iaPoz()+fJoc->valZar],cercuriFinalVerde[fJoc->finalVerde],cercB);
        d->puneCercuri(cercuriVerde[d->iaPoz()+fJoc->valZar],cercuriFinalVerde[fJoc->finalVerde],cercB);
        }
        if(a!=NULL && s=="Rosu"){
        a->puneCercuri(cercuriRosu[a->iaPoz()+fJoc->valZar],cercuriFinalRosu[fJoc->finalRosu],cercC);
        b->puneCercuri(cercuriRosu[b->iaPoz()+fJoc->valZar],cercuriFinalRosu[fJoc->finalRosu],cercC);
        c->puneCercuri(cercuriRosu[c->iaPoz()+fJoc->valZar],cercuriFinalRosu[fJoc->finalRosu],cercC);
        d->puneCercuri(cercuriRosu[d->iaPoz()+fJoc->valZar],cercuriFinalRosu[fJoc->finalRosu],cercC);
        }
        if(a!=NULL && s=="Albastru"){
        a->puneCercuri(cercuriAlbastru[a->iaPoz()+fJoc->valZar],cercuriFinalAlbastru[fJoc->finalAlbastru],cercD);
        b->puneCercuri(cercuriAlbastru[b->iaPoz()+fJoc->valZar],cercuriFinalAlbastru[fJoc->finalAlbastru],cercD);
        c->puneCercuri(cercuriAlbastru[c->iaPoz()+fJoc->valZar],cercuriFinalAlbastru[fJoc->finalAlbastru],cercD);
        d->puneCercuri(cercuriAlbastru[d->iaPoz()+fJoc->valZar],cercuriFinalAlbastru[fJoc->finalAlbastru],cercD);
        }
 }

//---------------------------------------------------------------------------
//------------Functie-de-verificare-si-afisare-numarul-de-piese--------------
//-------------afisare-numarul-de-piese-suprapuse----------------------------
//--------------(modificata-pentru-adaptare-la-toate-piesele)----------------
//---------------------------------------------------------------------------

 void __fastcall TfJoc :: verificaPozitii_Scrie(Pozitie *a, Pozitie *b,
Pozitie *c, Pozitie *d, String s){
  if(a==NULL){                              //daca nu exista piesa
   return;
  }
  if(sariPeste<numarJucatori)               //daca am facut deja asta
  {                                         //culoare text alba pentru aceste piese
        if(s=="Verde" || s=="Rosu" || s=="Albastru"){ 
                a->Piesa->Font->Color=clWhite;
                b->Piesa->Font->Color=clWhite;
                c->Piesa->Font->Color=clWhite;
                d->Piesa->Font->Color=clWhite;
        }
        if(s=="Galben"){                      //culoare text neagra pentru acesta piesa
                a->Piesa->Font->Color=clBlack;
                b->Piesa->Font->Color=clBlack;
                c->Piesa->Font->Color=clBlack;
                d->Piesa->Font->Color=clBlack;
        }                                      //font personalizat
        a->Piesa->Font->Size=12;
        b->Piesa->Font->Size=12;
        c->Piesa->Font->Size=12;
        d->Piesa->Font->Size=12;
        a->Piesa->Font->Name="MV Boli";
        b->Piesa->Font->Name="MV Boli";
        c->Piesa->Font->Name="MV Boli";
        d->Piesa->Font->Name="MV Boli";
        verificaTuraInceput();
        sariPeste++;                            //bifam ca am facut setarile
  }
  if(a->iaPoz()==b->iaPoz() && a->iaPoz()==c->iaPoz() && a->iaPoz()==d->iaPoz()){//1=2=3=4
   a->Piesa->Caption=4;
   b->Piesa->Caption=4;
   c->Piesa->Caption=4;
   d->Piesa->Caption=4;
  }
  else{
   if (a->iaPoz()==b->iaPoz() && a->iaPoz()==c->iaPoz()){//1=2=3=
     a->Piesa->Caption=3;
     b->Piesa->Caption=3;
     c->Piesa->Caption=3;
     d->Piesa->Caption=" ";
   }
   else{
     if (a->iaPoz()==b->iaPoz() && a->iaPoz()==d->iaPoz()){//1=2=4=
       a->Piesa->Caption=3;
       b->Piesa->Caption=3;
       d->Piesa->Caption=3;
       c->Piesa->Caption=" ";
     }
     else{
       if (a->iaPoz()==c->iaPoz() && a->iaPoz()==d->iaPoz()){//1=3=4=
         a->Piesa->Caption=3;
         c->Piesa->Caption=3;
         d->Piesa->Caption=3;
         b->Piesa->Caption=" ";
       }
       else{
         if (b->iaPoz()==c->iaPoz() && b->iaPoz()==d->iaPoz()){//2=3=4=
           b->Piesa->Caption=3;
           c->Piesa->Caption=3;
           d->Piesa->Caption=3;
           a->Piesa->Caption=" ";
         }
         else{
           if (a->iaPoz()==b->iaPoz()){//1=2 (si daca si celelalte 2)=
             a->Piesa->Caption=2;
             b->Piesa->Caption=2;
             c->Piesa->Caption=" ";
             d->Piesa->Caption=" ";
               if (c->iaPoz()==d->iaPoz()){//3=4
                 c->Piesa->Caption=2;
                 d->Piesa->Caption=2;
               }
           }
           else{
             if (a->iaPoz()==c->iaPoz()){//1=3 si celelalte 2=
               a->Piesa->Caption=2;
               c->Piesa->Caption=2;
               b->Piesa->Caption=" ";
               d->Piesa->Caption=" ";
                 if(b->iaPoz()==d->iaPoz()){//2=4=
                   b->Piesa->Caption=2;
                   d->Piesa->Caption=2;
                 }
             }
             else{
                if(a->iaPoz()==d->iaPoz()){//1=4  si celelalte 2=
                  a->Piesa->Caption=2;
                  d->Piesa->Caption=2;
                  b->Piesa->Caption=" ";
                  c->Piesa->Caption=" ";
                    if (b->iaPoz()==c->iaPoz()){//2=3
                    b->Piesa->Caption=2;
                    c->Piesa->Caption=2;
                    }
                }
                else{
                  if (b->iaPoz()==c->iaPoz()){//2=3 si celelalte 2=
                   b->Piesa->Caption=2;
                   c->Piesa->Caption=2;
                   a->Piesa->Caption=" ";
                   d->Piesa->Caption=" ";
                     if(a->iaPoz()==d->iaPoz()){//1=4
                      a->Piesa->Caption=2;
                      d->Piesa->Caption=2;
                      }
                  }
                  else{
                    if(b->iaPoz()==d->iaPoz()){//2=4 si celelalte 2
                      b->Piesa->Caption=2;
                      d->Piesa->Caption=2;
                      a->Piesa->Caption=" ";
                      c->Piesa->Caption=" ";
                        if (a->iaPoz()==c->iaPoz()){//1=3
                          a->Piesa->Caption=2;
                          c->Piesa->Caption=2;
                          }
                    }
                    else{
                      if (c->iaPoz()==d->iaPoz()){//3=4  si celelalte
                        c->Piesa->Caption=2;
                        d->Piesa->Caption=2;
                        a->Piesa->Caption=" ";
                        b->Piesa->Caption=" ";
                          if (a->iaPoz()==b->iaPoz()){//1=2
                            a->Piesa->Caption=2;
                            b->Piesa->Caption=2;
                          }
                      }
                      else{
                        a->Piesa->Caption=" ";
                        b->Piesa->Caption=" ";
                        c->Piesa->Caption=" ";
                        d->Piesa->Caption=" ";
                      }
                    }
                  }
                }
             }
           }
         }
       }
     }
   }
  }
 }
//------Verifica-casele-----------------------------------------------------

 void __fastcall TfJoc :: verificaCase(){
        if(g_1!=NULL){
                verificaFiecare_Casa("Galben");
        }
        if(v_1!=NULL){
                verificaFiecare_Casa("Verde");
        }
        if(r_1!=NULL){
                verificaFiecare_Casa("Rosu");
        }
        if(a_1!=NULL){
                verificaFiecare_Casa("Albastru");
        }
 }

 //------Verifica-fiecare-casa-a-jucatorilor--------------------------------

 void __fastcall TfJoc :: verificaFiecare_Casa(String s){
        if(s=="Galben"){
                verificaPentru_Fiecare_Membru("Galben");
        }
        if(s=="Verde"){
                verificaPentru_Fiecare_Membru("Verde");
        }
        if(s=="Rosu"){
                verificaPentru_Fiecare_Membru("Rosu");
        }
        if(s=="Albastru"){
                verificaPentru_Fiecare_Membru("Albastru");
        }
 }
 
//------Verifica-Casa-Pentru-Fiecare-Piesa-A-Jucatorului-------------------

 void __fastcall TfJoc :: verificaPentru_Fiecare_Membru(String s)
 {
        if(s=="Galben"){
                verificaPe_Baza(g_1, g_1, g_2, g_3, g_4, BazaG[0], 1);
                verificaPe_Baza(g_1, g_1, g_2, g_3, g_4, BazaG[1], 2);
                verificaPe_Baza(g_1, g_1, g_2, g_3, g_4, BazaG[2], 3);
                verificaPe_Baza(g_1, g_1, g_2, g_3, g_4, BazaG[3], 4);

                verificaPe_Baza(g_2, g_1, g_2, g_3, g_4, BazaG[0], 1);
                verificaPe_Baza(g_2, g_1, g_2, g_3, g_4, BazaG[1], 2);
                verificaPe_Baza(g_2, g_1, g_2, g_3, g_4, BazaG[2], 3);
                verificaPe_Baza(g_2, g_1, g_2, g_3, g_4, BazaG[3], 4);

                verificaPe_Baza(g_3, g_1, g_2, g_3, g_4, BazaG[0], 1);
                verificaPe_Baza(g_3, g_1, g_2, g_3, g_4, BazaG[1], 2);
                verificaPe_Baza(g_3, g_1, g_2, g_3, g_4, BazaG[2], 3);
                verificaPe_Baza(g_3, g_1, g_2, g_3, g_4, BazaG[3], 4);

                verificaPe_Baza(g_4, g_1, g_2, g_3, g_4, BazaG[0], 1);
                verificaPe_Baza(g_4, g_1, g_2, g_3, g_4, BazaG[1], 2);
                verificaPe_Baza(g_4, g_1, g_2, g_3, g_4, BazaG[2], 3);
                verificaPe_Baza(g_4, g_1, g_2, g_3, g_4, BazaG[3], 4);
        }
        if(s=="Verde"){
                verificaPe_Baza(v_1, v_1, v_2, v_3, v_4, BazaV[0], 1);
                verificaPe_Baza(v_1, v_1, v_2, v_3, v_4, BazaV[1], 2);
                verificaPe_Baza(v_1, v_1, v_2, v_3, v_4, BazaV[2], 3);
                verificaPe_Baza(v_1, v_1, v_2, v_3, v_4, BazaV[3], 4);

                verificaPe_Baza(v_2, v_1, v_2, v_3, v_4, BazaV[0], 1);
                verificaPe_Baza(v_2, v_1, v_2, v_3, v_4, BazaV[1], 2);
                verificaPe_Baza(v_2, v_1, v_2, v_3, v_4, BazaV[2], 3);
                verificaPe_Baza(v_2, v_1, v_2, v_3, v_4, BazaV[3], 4);

                verificaPe_Baza(v_3, v_1, v_2, v_3, v_4, BazaV[0], 1);
                verificaPe_Baza(v_3, v_1, v_2, v_3, v_4, BazaV[1], 2);
                verificaPe_Baza(v_3, v_1, v_2, v_3, v_4, BazaV[2], 3);
                verificaPe_Baza(v_3, v_1, v_2, v_3, v_4, BazaV[3], 4);

                verificaPe_Baza(v_4, v_1, v_2, v_3, v_4, BazaV[0], 1);
                verificaPe_Baza(v_4, v_1, v_2, v_3, v_4, BazaV[1], 2);
                verificaPe_Baza(v_4, v_1, v_2, v_3, v_4, BazaV[2], 3);
                verificaPe_Baza(v_4, v_1, v_2, v_3, v_4, BazaV[3], 4);
        }
        if(s=="Rosu"){
                verificaPe_Baza(r_1, r_1, r_2, r_3, r_4, BazaR[0], 1);
                verificaPe_Baza(r_1, r_1, r_2, r_3, r_4, BazaR[1], 2);
                verificaPe_Baza(r_1, r_1, r_2, r_3, r_4, BazaR[2], 3);
                verificaPe_Baza(r_1, r_1, r_2, r_3, r_4, BazaR[3], 4);

                verificaPe_Baza(r_2, r_1, r_2, r_3, r_4, BazaR[0], 1);
                verificaPe_Baza(r_2, r_1, r_2, r_3, r_4, BazaR[1], 2);
                verificaPe_Baza(r_2, r_1, r_2, r_3, r_4, BazaR[2], 3);
                verificaPe_Baza(r_2, r_1, r_2, r_3, r_4, BazaR[3], 4);

                verificaPe_Baza(r_3, r_1, r_2, r_3, r_4, BazaR[0], 1);
                verificaPe_Baza(r_3, r_1, r_2, r_3, r_4, BazaR[1], 2);
                verificaPe_Baza(r_3, r_1, r_2, r_3, r_4, BazaR[2], 3);
                verificaPe_Baza(r_3, r_1, r_2, r_3, r_4, BazaR[3], 4);

                verificaPe_Baza(r_4, r_1, r_2, r_3, r_4, BazaR[0], 1);
                verificaPe_Baza(r_4, r_1, r_2, r_3, r_4, BazaR[1], 2);
                verificaPe_Baza(r_4, r_1, r_2, r_3, r_4, BazaR[2], 3);
                verificaPe_Baza(r_4, r_1, r_2, r_3, r_4, BazaR[3], 4);
        }
        if(s=="Albastru"){
                verificaPe_Baza(a_1, a_1, a_2, a_3, a_4, BazaA[0], 1);
                verificaPe_Baza(a_1, a_1, a_2, a_3, a_4, BazaA[1], 2);
                verificaPe_Baza(a_1, a_1, a_2, a_3, a_4, BazaA[2], 3);
                verificaPe_Baza(a_1, a_1, a_2, a_3, a_4, BazaA[3], 4);

                verificaPe_Baza(a_2, a_1, a_2, a_3, a_4, BazaA[0], 1);
                verificaPe_Baza(a_2, a_1, a_2, a_3, a_4, BazaA[1], 2);
                verificaPe_Baza(a_2, a_1, a_2, a_3, a_4, BazaA[2], 3);
                verificaPe_Baza(a_2, a_1, a_2, a_3, a_4, BazaA[3], 4);

                verificaPe_Baza(a_3, a_1, a_2, a_3, a_4, BazaA[0], 1);
                verificaPe_Baza(a_3, a_1, a_2, a_3, a_4, BazaA[1], 2);
                verificaPe_Baza(a_3, a_1, a_2, a_3, a_4, BazaA[2], 3);
                verificaPe_Baza(a_3, a_1, a_2, a_3, a_4, BazaA[3], 4);

                verificaPe_Baza(a_4, a_1, a_2, a_3, a_4, BazaA[0], 1);
                verificaPe_Baza(a_4, a_1, a_2, a_3, a_4, BazaA[1], 2);
                verificaPe_Baza(a_4, a_1, a_2, a_3, a_4, BazaA[2], 3);
                verificaPe_Baza(a_4, a_1, a_2, a_3, a_4, BazaA[3], 4);
        }
 }


 void __fastcall TfJoc :: verificaPe_Baza(Pozitie *cineSet, Pozitie *a, Pozitie *b, Pozitie *c,
Pozitie *d, TPoint Baza, int id){
        if(a->pozitieCasa.x==Baza.x && a->pozitieCasa.y==Baza.y){
                verificaID_Casa(cineSet, id, true);
        }else{
                if(b->pozitieCasa.x==Baza.x && b->pozitieCasa.y==Baza.y){
                        verificaID_Casa(cineSet, id, true);
                }else{
                        if(c->pozitieCasa.x==Baza.x && c->pozitieCasa.y==Baza.y){
                                verificaID_Casa(cineSet, id, true);
                        }else{
                                if(d->pozitieCasa.x==Baza.x && d->pozitieCasa.y==Baza.y){
                                        verificaID_Casa(cineSet, id, true);
                                }else{
                                        verificaID_Casa(cineSet, id, false);
                                }
                        }
                }
        }
 }

 void __fastcall TfJoc :: verificaID_Casa(Pozitie *cineVerifica, int id, bool a){
        if(id==1){
                cineVerifica->setCasa_1(a);
        }
        if(id==2){
                cineVerifica->setCasa_2(a);
        }
        if(id==3){
                cineVerifica->setCasa_3(a);
        }
        if(id==4){
                cineVerifica->setCasa_4(a);
        }
 }
//------Pozitii-cercuri-hardcode---------------------------------------------

 void __fastcall TfJoc :: puneCercuri(){     //pozitiile hardcode ale cercurilor pentru highlight
  cercuriGalben[1]=cercA;cercuriGalben[2]=cercA1;cercuriGalben[3]=cercA2;cercuriGalben[4]=cercA3;cercuriGalben[5]=cercA4;
  cercuriGalben[6]=cercA5;cercuriGalben[7]=cercA6;cercuriGalben[8]=cercA7;cercuriGalben[9]=cercA8;cercuriGalben[10]=cercA9;
  cercuriGalben[11]=cercB;cercuriGalben[12]=cercB1;cercuriGalben[13]=cercB2;cercuriGalben[14]=cercB3;cercuriGalben[15]=cercB4;
  cercuriGalben[16]=cercB5;cercuriGalben[17]=cercB6;cercuriGalben[18]=cercB7;cercuriGalben[19]=cercB8;cercuriGalben[20]=cercB9;
  cercuriGalben[21]=cercC;cercuriGalben[22]=cercC1;cercuriGalben[23]=cercC2;cercuriGalben[24]=cercC3;cercuriGalben[25]=cercC4;
  cercuriGalben[26]=cercC5;cercuriGalben[27]=cercC6;cercuriGalben[28]=cercC7;cercuriGalben[29]=cercC8;cercuriGalben[30]=cercC9;
  cercuriGalben[31]=cercD;cercuriGalben[32]=cercD1;cercuriGalben[33]=cercD2;cercuriGalben[34]=cercD3;cercuriGalben[35]=cercD4;
  cercuriGalben[36]=cercD5;cercuriGalben[37]=cercD6;cercuriGalben[38]=cercD7;cercuriGalben[39]=cercD8;cercuriGalben[40]=cercD9;

  cercuriVerde[1]=cercB;cercuriVerde[2]=cercB1;cercuriVerde[3]=cercB2;cercuriVerde[4]=cercB3;cercuriVerde[5]=cercB4;
  cercuriVerde[6]=cercB5;cercuriVerde[7]=cercB6;cercuriVerde[8]=cercB7;cercuriVerde[9]=cercB8;cercuriVerde[10]=cercB9;
  cercuriVerde[11]=cercC;cercuriVerde[12]=cercC1;cercuriVerde[13]=cercC2;cercuriVerde[14]=cercC3;cercuriVerde[15]=cercC4;
  cercuriVerde[16]=cercC5;cercuriVerde[17]=cercC6;cercuriVerde[18]=cercC7;cercuriVerde[19]=cercC8;cercuriVerde[20]=cercC9;
  cercuriVerde[21]=cercD;cercuriVerde[22]=cercD1;cercuriVerde[23]=cercD2;cercuriVerde[24]=cercD3;cercuriVerde[25]=cercD4;
  cercuriVerde[26]=cercD5;cercuriVerde[27]=cercD6;cercuriVerde[28]=cercD7;cercuriVerde[29]=cercD8;cercuriVerde[30]=cercD9;
  cercuriVerde[31]=cercA;cercuriVerde[32]=cercA1;cercuriVerde[33]=cercA2;cercuriVerde[34]=cercA3;cercuriVerde[35]=cercA4;
  cercuriVerde[36]=cercA5;cercuriVerde[37]=cercA6;cercuriVerde[38]=cercA7;cercuriVerde[39]=cercA8;cercuriVerde[40]=cercA9;

  cercuriRosu[1]=cercC;cercuriRosu[2]=cercC1;cercuriRosu[3]=cercC2;cercuriRosu[4]=cercC3;cercuriRosu[5]=cercC4;
  cercuriRosu[6]=cercC5;cercuriRosu[7]=cercC6;cercuriRosu[8]=cercC7;cercuriRosu[9]=cercC8;cercuriRosu[10]=cercC9;
  cercuriRosu[11]=cercD;cercuriRosu[12]=cercD1;cercuriRosu[13]=cercD2;cercuriRosu[14]=cercD3;cercuriRosu[15]=cercD4;
  cercuriRosu[16]=cercD5;cercuriRosu[17]=cercD6;cercuriRosu[18]=cercD7;cercuriRosu[19]=cercD8;cercuriRosu[20]=cercD9;
  cercuriRosu[21]=cercA;cercuriRosu[22]=cercA1;cercuriRosu[23]=cercA2;cercuriRosu[24]=cercA3;cercuriRosu[25]=cercA4;
  cercuriRosu[26]=cercA5;cercuriRosu[27]=cercA6;cercuriRosu[28]=cercA7;cercuriRosu[29]=cercA8;cercuriRosu[30]=cercA9;
  cercuriRosu[31]=cercB;cercuriRosu[32]=cercB1;cercuriRosu[33]=cercB2;cercuriRosu[34]=cercB3;cercuriRosu[35]=cercB4;
  cercuriRosu[36]=cercB5;cercuriRosu[37]=cercB6;cercuriRosu[38]=cercB7;cercuriRosu[39]=cercB8;cercuriRosu[40]=cercB9;

  cercuriAlbastru[1]=cercD;cercuriAlbastru[2]=cercD1;cercuriAlbastru[3]=cercD2;cercuriAlbastru[4]=cercD3;cercuriAlbastru[5]=cercD4;
  cercuriAlbastru[6]=cercD5;cercuriAlbastru[7]=cercD6;cercuriAlbastru[8]=cercD7;cercuriAlbastru[9]=cercD8;cercuriAlbastru[10]=cercD9;
  cercuriAlbastru[11]=cercA;cercuriAlbastru[12]=cercA1;cercuriAlbastru[13]=cercA2;cercuriAlbastru[14]=cercA3;cercuriAlbastru[15]=cercA4;
  cercuriAlbastru[16]=cercA5;cercuriAlbastru[17]=cercA6;cercuriAlbastru[18]=cercA7;cercuriAlbastru[19]=cercA8;cercuriAlbastru[20]=cercA9;
  cercuriAlbastru[21]=cercB;cercuriAlbastru[22]=cercB1;cercuriAlbastru[23]=cercB2;cercuriAlbastru[24]=cercB3;cercuriAlbastru[25]=cercB4;
  cercuriAlbastru[26]=cercB5;cercuriAlbastru[27]=cercB6;cercuriAlbastru[28]=cercB7;cercuriAlbastru[29]=cercB8;cercuriAlbastru[30]=cercB9;
  cercuriAlbastru[31]=cercC;cercuriAlbastru[32]=cercC1;cercuriAlbastru[33]=cercC2;cercuriAlbastru[34]=cercC3;cercuriAlbastru[35]=cercC4;
  cercuriAlbastru[36]=cercC5;cercuriAlbastru[37]=cercC6;cercuriAlbastru[38]=cercC7;cercuriAlbastru[39]=cercC8;cercuriAlbastru[40]=cercC9;

  cercuriFinalGalben[0]=cercFinalA1;cercuriFinalGalben[1]=cercFinalA2;
  cercuriFinalGalben[2]=cercFinalA3;cercuriFinalGalben[3]=cercFinalA4;

  cercuriFinalVerde[0]=cercFinalB1;cercuriFinalVerde[1]=cercFinalB2;
  cercuriFinalVerde[2]=cercFinalB3;cercuriFinalVerde[3]=cercFinalB4;

  cercuriFinalRosu[0]=cercFinalC1;cercuriFinalRosu[1]=cercFinalC2;
  cercuriFinalRosu[2]=cercFinalC3;cercuriFinalRosu[3]=cercFinalC4;

  cercuriFinalAlbastru[0]=cercFinalD1;cercuriFinalAlbastru[1]=cercFinalD2;
  cercuriFinalAlbastru[2]=cercFinalD3;cercuriFinalAlbastru[3]=cercFinalD4;
 }

//---------------------------------------------------------------------------


void __fastcall TfJoc::btnConnectClick(TObject *Sender)
{
        fJoc->Hide();
        fLobby->Width=260;
        fLobby->Height=222;
        fLobby->Left=600;
        fLobby->Top=300;
        fLobby->Show();
}
//---------------------------------------------------------------------------



void __fastcall TfJoc::tMultiplayerTimer(TObject *Sender)
{
        String text;
        String player;
        //player1
         if(fLobby->rbGalben1->Checked){
                btnAlegeGalbenClick(Sender);
                trimiteJucatoriInceput("Galben",1);
                text = "Jucator 1:\n";
                player = fLobby->lNumePlayer1->Caption;
                text+=player;
                lGalben->Caption=text;
         }
         if(fLobby->rbVerde1->Checked){
                btnAlegeVerdeClick(Sender);
                trimiteJucatoriInceput("Verde",1); 
                text = "Jucator 1:\n";
                player = fLobby->lNumePlayer1->Caption;
                text+=player;
                lVerde->Caption=text;
         }
         if(fLobby->rbRosu1->Checked){
                btnAlegeRosuClick(Sender);
                trimiteJucatoriInceput("Rosu",1);
                text = "Jucator 1:\n";
                player = fLobby->lNumePlayer1->Caption;
                text+=player;
                lRosu->Caption=text;
         }
         if(fLobby->rbAlbastru1->Checked){
                btnAlegeAlbastruClick(Sender);
                trimiteJucatoriInceput("Albastru",1);
                text = "Jucator 1:\n";
                player = fLobby->lNumePlayer1->Caption;
                text+=player;
                lAlbastru->Caption=text;
         }
         //player2
         if(fLobby->rbGalben2->Checked){
                btnAlegeGalbenClick(Sender);
                trimiteJucatoriInceput("Galben",2);
                text = "Jucator 2:\n";
                player = fLobby->lNumePlayer2->Caption;
                text+=player;
                lGalben->Caption=text;
         }
         if(fLobby->rbVerde2->Checked){
                btnAlegeVerdeClick(Sender);
                trimiteJucatoriInceput("Verde",2);
                text = "Jucator 2:\n";
                player = fLobby->lNumePlayer2->Caption;
                text+=player;
                lVerde->Caption=text;
         }
         if(fLobby->rbRosu2->Checked){
                btnAlegeRosuClick(Sender); 
                trimiteJucatoriInceput("Rosu",2);
                text = "Jucator 2:\n";
                player = fLobby->lNumePlayer2->Caption;
                text+=player;
                lRosu->Caption=text;
         }
         if(fLobby->rbAlbastru2->Checked){
                btnAlegeAlbastruClick(Sender);
                trimiteJucatoriInceput("Albastru",2);
                text = "Jucator 2:\n";
                player = fLobby->lNumePlayer2->Caption;
                text+=player;
                lAlbastru->Caption=text;
         }
         //player3
         if(fLobby->rbGalben3->Checked){
                btnAlegeGalbenClick(Sender);
                trimiteJucatoriInceput("Galben",3);
                text = "Jucator 3:\n";
                player = fLobby->lNumePlayer3->Caption;
                text+=player;
                lGalben->Caption=text;
         }
         if(fLobby->rbVerde3->Checked){
                btnAlegeVerdeClick(Sender); 
                trimiteJucatoriInceput("Verde",3);
                text = "Jucator 3:\n";
                player = fLobby->lNumePlayer3->Caption;
                text+=player;
                lVerde->Caption=text;
         }
         if(fLobby->rbRosu3->Checked){
                btnAlegeRosuClick(Sender);  
                trimiteJucatoriInceput("Rosu",3);
                text = "Jucator 3:\n";
                player = fLobby->lNumePlayer3->Caption;
                text+=player;
                lRosu->Caption=text;
         }
         if(fLobby->rbAlbastru3->Checked){
                btnAlegeAlbastruClick(Sender);
                trimiteJucatoriInceput("Albastru",3);
                text = "Jucator 3:\n";
                player = fLobby->lNumePlayer3->Caption;
                text+=player;
                lAlbastru->Caption=text;
         }
         //player4
         if(fLobby->rbGalben4->Checked){
                btnAlegeGalbenClick(Sender);
                trimiteJucatoriInceput("Galben",4);
                text = "Jucator 4:\n";
                player = fLobby->lNumePlayer4->Caption;
                text+=player;
                lGalben->Caption=text;
         }
         if(fLobby->rbVerde4->Checked){
                btnAlegeVerdeClick(Sender);  
                trimiteJucatoriInceput("Verde",4);
                text = "Jucator 4:\n";
                player = fLobby->lNumePlayer4->Caption;
                text+=player;
                lVerde->Caption=text;
         }
         if(fLobby->rbRosu4->Checked){
                btnAlegeRosuClick(Sender);   
                trimiteJucatoriInceput("Rosu",4);
                text = "Jucator 4:\n";
                player = fLobby->lNumePlayer4->Caption;
                text+=player;
                lRosu->Caption=text;
         }
         if(fLobby->rbAlbastru4->Checked){
                btnAlegeAlbastruClick(Sender);  
                trimiteJucatoriInceput("Albastru",4);
                text = "Jucator 4:\n";
                player = fLobby->lNumePlayer4->Caption;
                text+=player;
                lAlbastru->Caption=text;
         }
         tMultiplayer->Enabled=false;
         fLobby->mVerifica->Enabled=false;
         fLobby->tNumaratoare->Enabled=false;
         fLobby->tTrimiteNume->Enabled=false;
         blocheazaZar();
}
//---------------------------------------------------------------------------

 void __fastcall TfJoc :: trimiteJucatoriInceput(String cine, int tura){
        if(cine=="Albastru"){
                a_1->setJucatorInitial(&tura);
                a_2->setJucatorInitial(&tura);
                a_3->setJucatorInitial(&tura);
                a_4->setJucatorInitial(&tura);
                tura_A=tura;
        }
        if(cine=="Rosu"){
                r_1->setJucatorInitial(&tura);
                r_2->setJucatorInitial(&tura);
                r_3->setJucatorInitial(&tura);
                r_4->setJucatorInitial(&tura);
                tura_R=tura;
        }
        if(cine=="Verde"){
                v_1->setJucatorInitial(&tura);
                v_2->setJucatorInitial(&tura);
                v_3->setJucatorInitial(&tura);
                v_4->setJucatorInitial(&tura);
                tura_V=tura;
        }
        if(cine=="Galben"){
                g_1->setJucatorInitial(&tura);
                g_2->setJucatorInitial(&tura);
                g_3->setJucatorInitial(&tura);
                g_4->setJucatorInitial(&tura);
                tura_G=tura;
        }
 }

//---------------------------------------------------------------------------

 void __fastcall TfJoc :: blocheazaZar(){
        String numeLobby = fLobby->lAfisareNume->Caption;
        String numeG=lGalben->Caption;
        String ceva=numeG.SubString(12,numeLobby.Length());
        m_tura = tura;
        if(m_tura % (mNrPlayeri+1)==0 && valZar!=6) {
                m_tura++;
        }
        if(fLobby->lAfisareNume->Caption==ceva){
                lGalben->Color=clSilver;
                if(g_1!=NULL && m_tura % (mNrPlayeri+1) == tura_inceput_G && zar){
                        btnZar->Enabled=true;
                        return;
                }
                else{
                        btnZar->Enabled=false;
                }
        }
        String numeV=lVerde->Caption;
        ceva=numeV.SubString(12,numeLobby.Length());
        if(fLobby->lAfisareNume->Caption==ceva){
                lVerde->Color=clSilver;
                if(v_1!=NULL && m_tura % (mNrPlayeri+1) == tura_inceput_V && zar){
                        btnZar->Enabled=true;
                        return;
                }
                else{
                        btnZar->Enabled=false;
                }
        }
        String numeR=lRosu->Caption;
        ceva=numeR.SubString(12,numeLobby.Length());
        if(fLobby->lAfisareNume->Caption==ceva){
                lRosu->Color=clSilver;
                if(r_1!=NULL && m_tura % (mNrPlayeri+1) == tura_inceput_R && zar){
                        btnZar->Enabled=true;
                return;
                }
                else{
                        btnZar->Enabled=false;
                }
        }
        String numeA=lAlbastru->Caption;
        ceva=numeA.SubString(12,numeLobby.Length());
        if(fLobby->lAfisareNume->Caption==ceva){
                lAlbastru->Color=clSilver;
                if(a_1!=NULL && m_tura % (mNrPlayeri+1) == tura_inceput_A && zar){
                    btnZar->Enabled=true;
                    return;
                }
                else{
                    btnZar->Enabled=false;
                }
        }
 }

//---------------------------------------------------------------------------

