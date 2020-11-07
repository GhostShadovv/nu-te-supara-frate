//---------------------------------------------------------------------------

#ifndef FereastraJocH
#define FereastraJocH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include "Pozitie.h"
#include "Galben.h"
#include "Albastru.h"
#include "Rosu.h"
#include "Verde.h"
#include <ScktComp.hpp>
#include <mmsystem.h>
#include "AniGIFCtrl_OCX.h"
#include <DBOleCtl.hpp>
#include <OleCtrls.hpp>
#include "Lobby.h"
//-------------------------------------------------------------------------
class TfJoc : public TForm
{
__published:	// IDE-managed Components
        TPanel *pBaza;
        TBitBtn *BitBtn1;
        TButton *btnAlegeAlbastru;
        TButton *btnAlegeGalben;
        TButton *btnAlegeRosu;
        TButton *btnAlegeVerde;
        TButton *btnZar;
        TShape *cercA1;
        TShape *cercA2;
        TShape *cercA3;
        TShape *cercA4;
        TShape *cercA5;
        TShape *cercA6;
        TShape *cercA7;
        TShape *cercA8;
        TShape *cercA9;
        TShape *cercB1;
        TShape *cercB2;
        TShape *cercB3;
        TShape *cercB4;
        TShape *cercB5;
        TShape *cercB6;
        TShape *cercB7;
        TShape *cercB8;
        TShape *cercB9;
        TShape *cercA;
        TShape *cerc_CasaA1;
        TShape *cerc_CasaA2;
        TShape *cerc_CasaA3;
        TShape *cerc_CasaA4;
        TShape *cercB;
        TShape *cerc_CasaB1;
        TShape *cerc_CasaB2;
        TShape *cerc_CasaB3;
        TShape *cerc_CasaB4;
        TShape *cercC;
        TShape *cerc_CasaC1;
        TShape *cerc_CasaC2;
        TShape *cerc_CasaC3;
        TShape *cerc_CasaC4;
        TShape *cercD;
        TShape *cerc_CasaD1;
        TShape *cerc_CasaD2;
        TShape *cerc_CasaD3;
        TShape *cerc_CasaD4;
        TShape *cercC1;
        TShape *cercC2;
        TShape *cercC3;
        TShape *cercC4;
        TShape *cercC5;
        TShape *cercC6;
        TShape *cercC7;
        TShape *cercC8;
        TShape *cercC9;
        TShape *cercD1;
        TShape *cercD2;
        TShape *cercD3;
        TShape *cercD4;
        TShape *cercD5;
        TShape *cercD6;
        TShape *cercD7;
        TShape *cercD8;
        TShape *cercD9;
        TShape *cercFinalA1;
        TShape *cercFinalA2;
        TShape *cercFinalA3;
        TShape *cercFinalA4;
        TShape *cercFinalB1;
        TShape *cercFinalB2;
        TShape *cercFinalB3;
        TShape *cercFinalB4;
        TShape *cercFinalC1;
        TShape *cercFinalC2;
        TShape *cercFinalC3;
        TShape *cercFinalC4;
        TShape *cercFinalD1;
        TShape *cercFinalD2;
        TShape *cercFinalD3;
        TShape *cercFinalD4;
        TLabel *lTextA;
        TLabel *lTextB;
        TLabel *lTextC;
        TLabel *lTextD;
        TPanel *Panel1;
        TTimer *tVerificari;
        TMemo *mTest;
        TClientSocket *cSocket;
        TAniGIF *Gif1;
        TAniGIF *Gif2;
        TAniGIF *Gif3;
        TAniGIF *Gif4;
        TAniGIF *Gif5;
        TAniGIF *Gif6;
        TLabel *lGalben;
        TLabel *lVerde;
        TLabel *lRosu;
        TLabel *lAlbastru;
        TTimer *tClient;
        TButton *btnConnect;
        TTimer *tMultiplayer;
                                                       //butoane
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall btnAlegeGalbenClick(TObject *Sender);
        void __fastcall btnAlegeRosuClick(TObject *Sender);
        void __fastcall btnAlegeAlbastruClick(TObject *Sender);
        void __fastcall btnAlegeVerdeClick(TObject *Sender);
        void __fastcall btnZarClick(TObject *Sender);
                                                      //utilitare
        void __fastcall tVerificariTimer(TObject *Sender);
        void __fastcall cSocketRead(TObject *Sender,
TCustomWinSocket *Socket);
        void __fastcall cSocketConnect(TObject *Sender,
TCustomWinSocket *Socket);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall pBazaMouseMove(TObject *Sender, TShiftState Shift,
int X, int Y);
                                                    //metode personalizate simple
        void __fastcall puneCercuri();
        void __fastcall DaCuZarul(int a);
        void __fastcall VerificaAnimatii();
        void __fastcall verificaTura();
        void __fastcall verificaTuraInceput();
        void __fastcall seteazaJucator(String s);
        void __fastcall trimiteJucatoriInceput(String cine, int tura);
        void __fastcall verificaDisponibilitate();
        void __fastcall blocheazaZar();

                                                   //metode ce modifica clasele
        void __fastcall verificaInamici(String s);
        void __fastcall cine_scoate(Pozitie *cineScoate, String s_cineScoate);
        void __fastcall verifica_si_scoate_pe(Pozitie *cineScoate, Pozitie *a,
Pozitie *b, Pozitie *c, Pozitie *d, String s_cineScoate, String s_peCine);
        void __fastcall seteazaText(String s0, String s1, int a);
        void __fastcall verificaCase();
        void __fastcall verificaFiecare_Casa(String s);
        void __fastcall verificaPentru_Fiecare_Membru(String s);
        void __fastcall verificaPe_Baza(Pozitie *cineSet, Pozitie *a, Pozitie *b, Pozitie *c,
Pozitie *d, TPoint Baza, int id);
        void __fastcall verificaID_Casa(Pozitie *cineVerifica, int id, bool a);

                                                   //configurabile pentru toti jucatorii
        void __fastcall DebugChatPozitii(Pozitie *a, Pozitie *b, Pozitie *c,
Pozitie *d, String s);
        void __fastcall scoateEventClick(Pozitie *a, Pozitie *b, Pozitie *c,
Pozitie *d);
        void __fastcall verificaPozitii_Scrie(Pozitie *a, Pozitie *b,
Pozitie *c, Pozitie *d, String s);
        void __fastcall PuneEvent_Parametrii(Pozitie *a, Pozitie *b,
Pozitie *c, Pozitie *d, String s);
        void __fastcall PuneParametruCercuri(Pozitie *a, Pozitie *b,
Pozitie *c, Pozitie *d, String s);
        void __fastcall permiteMutare_RefaceCercuri(Pozitie *a, Pozitie *b,
Pozitie *c, Pozitie *d, String s);
        void __fastcall btnConnectClick(TObject *Sender);
        void __fastcall tMultiplayerTimer(TObject *Sender);

        
private:	// User declarations
        bool clickGalben, clickVerde, clickRosu, clickAlbastru;
        bool zar;
        int sariPeste;
        int alegeri;
        int pozitieInamic[12];
        int nrCasa_G, nrCasa_V, nrCasa_R, nrCasa_A;
        int tura_inceput_G, tura_inceput_V, tura_inceput_R, tura_inceput_A;

        bool sare;
        bool Jucator_1, Jucator_2, Jucator_3, Jucator_4;
        bool Jucator_G, Jucator_V, Jucator_R, Jucator_A;
        bool Jucator;
        bool CasaG_1, CasaG_2, CasaG_3, CasaG_4;
        bool CasaV_1, CasaV_2, CasaV_3, CasaV_4;
        bool CasaR_1, CasaR_2, CasaR_3, CasaR_4;
        bool CasaA_1, CasaA_2, CasaA_3, CasaA_4;
                                        //pozitiile hardcode a cercurilor pentru colorare
        TShape *cercuriGalben[40];
        TShape *cercuriVerde[40];
        TShape *cercuriRosu[40];
        TShape *cercuriAlbastru[40];
        TShape *cercuriFinalGalben[4];
        TShape *cercuriFinalVerde[4];
        TShape *cercuriFinalRosu[4];
        TShape *cercuriFinalAlbastru[4];

public:		// User declarations
        __fastcall TfJoc(TComponent* Owner);

        bool trimiteZar;
        
        int tura_G, tura_V, tura_R, tura_A;
        int numarJucatori;
        int tura;
        int m_tura;
        int valZar;
        int pozitie;
        int finalGalben, finalVerde, finalRosu, finalAlbastru;
        int mNrPlayeri;
        int m_valZar;

        String mPlayer1, mPlayer2, mPlayer3, mPlayer4;


        Pozitie *g_1, *g_2, *g_3, *g_4; //galben
        Pozitie *v_1, *v_2, *v_3, *v_4; //verde
        Pozitie *r_1, *r_2, *r_3, *r_4; //rosu
        Pozitie *a_1, *a_2, *a_3, *a_4; //albastru


};
//---------------------------------------------------------------------------
extern PACKAGE TfJoc *fJoc;
//---------------------------------------------------------------------------


TPoint BazaG[4] = {TPoint(30,26),   TPoint(103,26),  TPoint(30,99),   TPoint(103,99)};
TPoint BazaV[4] = {TPoint(510,26),  TPoint(583,26),  TPoint(510,99),  TPoint(583,99)};
TPoint BazaR[4] = {TPoint(510,514), TPoint(583,516), TPoint(510,587), TPoint(583,587)};
TPoint BazaA[4] = {TPoint(30,514),  TPoint(103,514), TPoint(30,586),  TPoint(103,586)};

TPoint Loc[40] = {TPoint(20,250),  TPoint(80,250),  TPoint(140,250), TPoint(200,250),
TPoint(260,250),  TPoint(260,190), TPoint(260,130), TPoint(260,70),  TPoint(260,10),
TPoint(320,10),   TPoint(380,10),  TPoint(380,70),  TPoint(380,130), TPoint(380,190), TPoint(380,250),
TPoint(440,250),  TPoint(500,250), TPoint(560,250), TPoint(620,250), TPoint(620,310),
TPoint(620,370),  TPoint(560,370), TPoint(500,370), TPoint(440,370), TPoint(380,370), TPoint(380,430),
TPoint(380,490),  TPoint(380,550), TPoint(380,610), TPoint(320,610), TPoint(260,610),
TPoint(260,550),  TPoint(260,490), TPoint(260,430), TPoint(260,370), TPoint(200,370), TPoint(140,370),
TPoint(80,370),   TPoint(20,370),  TPoint(20,310)};

TPoint FinalG[4] = {TPoint(253,306), TPoint(193,306), TPoint(133,306), TPoint(73,306)};
TPoint FinalV[4] = {TPoint(321,252), TPoint(321,192), TPoint(321,132), TPoint(321,72)};
TPoint FinalR[4] = {TPoint(387,306), TPoint(447,306), TPoint(507,306), TPoint(567,306)};
TPoint FinalA[4] = {TPoint(321,362), TPoint(321,422), TPoint(321,482), TPoint(321,542)};


#endif


