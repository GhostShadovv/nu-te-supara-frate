//---------------------------------------------------------------------------

#ifndef LobbyH
#define LobbyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FereastraJoc.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfLobby : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grupConectare;
        TLabel *lAdresaIP;
        TLabel *lPort;
        TEdit *eAdresa;
        TEdit *ePort;
        TButton *btnConnect;
        TGroupBox *grupLoby;
        TGroupBox *grPlayer1;
        TLabel *lNumePlayer1;
        TRadioButton *rbGalben1;
        TRadioButton *rbVerde1;
        TRadioButton *rbRosu1;
        TRadioButton *rbAlbastru1;
        TGroupBox *grPlayer2;
        TLabel *lNumePlayer2;
        TRadioButton *rbGalben2;
        TRadioButton *rbVerde2;
        TRadioButton *rbRosu2;
        TRadioButton *rbAlbastru2;
        TGroupBox *grPlayer3;
        TLabel *lNumePlayer3;
        TRadioButton *rbGalben3;
        TRadioButton *rbVerde3;
        TRadioButton *rbRosu3;
        TRadioButton *rbAlbastru3;
        TGroupBox *grPlayer4;
        TLabel *lNumePlayer4;
        TRadioButton *rbGalben4;
        TRadioButton *rbVerde4;
        TRadioButton *rbRosu4;
        TRadioButton *rbAlbastru4;
        TCheckBox *cb1;
        TCheckBox *cb2;
        TCheckBox *cb3;
        TCheckBox *cb4;
        TLabel *lGata;
        TLabel *lNumeJucatori;
        TLabel *lCuloare;
        TLabel *l1;
        TLabel *l2;
        TLabel *l3;
        TLabel *l4;
        TButton *btnSinglePlayer;
        TTimer *mVerifica;
        TLabel *lHost;
        TEdit *eNume;
        TTimer *tNumaratoare;
        TLabel *lNumaratoareInversa;
        TTimer *tTrimiteNume;
        TLabel *lAfisareNume;
        
        void __fastcall eAdresaClick(TObject *Sender);
        void __fastcall eNumeClick(TObject *Sender);
        void __fastcall ePortClick(TObject *Sender);
        void __fastcall btnConnectClick(TObject *Sender);
        void __fastcall btnSinglePlayerClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall mVerificaTimer(TObject *Sender);
        void __fastcall tNumaratoareTimer(TObject *Sender);
        void __fastcall tTrimiteNumeTimer(TObject *Sender);
        void __fastcall rbGalben1Click(TObject *Sender);
        void __fastcall rbVerde1Click(TObject *Sender);
        void __fastcall rbRosu1Click(TObject *Sender);
        void __fastcall rbAlbastru1Click(TObject *Sender);
        void __fastcall rbGalben2Click(TObject *Sender);
        void __fastcall rbGalben3Click(TObject *Sender);
        void __fastcall rbGalben4Click(TObject *Sender);
        void __fastcall rbVerde2Click(TObject *Sender);
        void __fastcall rbVerde3Click(TObject *Sender);
        void __fastcall rbVerde4Click(TObject *Sender);
        void __fastcall rbRosu2Click(TObject *Sender);
        void __fastcall rbRosu3Click(TObject *Sender);
        void __fastcall rbRosu4Click(TObject *Sender);
        void __fastcall rbAlbastru2Click(TObject *Sender);
        void __fastcall rbAlbastru3Click(TObject *Sender);
        void __fastcall rbAlbastru4Click(TObject *Sender);
        void __fastcall cb1Click(TObject *Sender);
        void __fastcall cb2Click(TObject *Sender);
        void __fastcall cb3Click(TObject *Sender);
        void __fastcall cb4Click(TObject *Sender);
        
        void __fastcall disableCeilalti();
        void __fastcall afiseazaPlayeri();
        void __fastcall pornesteNumaratoare();
        void __fastcall verificaCulori();
        void __fastcall maresteFereastra();
        void __fastcall micsoreazaFereastra();

private:	// User declarations
public:		// User declarations
        __fastcall TfLobby(TComponent* Owner);
        int timp_ramas;
        int playeri;

        bool sariPeste;

        AnsiString nume;

};
//---------------------------------------------------------------------------
extern PACKAGE TfLobby *fLobby;
//---------------------------------------------------------------------------
#endif
