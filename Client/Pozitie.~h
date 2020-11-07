//---------------------------------------------------------------------------

#ifndef PozitieH
#define PozitieH
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>


//---------------------------------------------------------------------------
//------Clasa de baza--------------------------------------------------------
//---------------------------------------------------------------------------
class Pozitie
{
protected:
        int poz;
        int *nrCasa;
        bool casa;
        int *valZar;
        int *final;
        bool *zar;
        bool sariPeste;
        bool Jucator_1, Jucator_2, Jucator_3, Jucator_4;
        bool casa_1, casa_2, casa_3, casa_4;
        int poz_a,poz_b,poz_c;                          //pozitiile aliatilor
        int cineSunt;
        String ceSunt;

        TButton *aux1;
        TShape *cercuri;
        TShape *cercuriFinal;
        TShape *lastModified;
        TMemo *text;
public:
        Pozitie(TPanel *aux, int pozitieFinal=0);
        Pozitie(){};
        ~Pozitie();

        TPanel *Piesa;
        TPoint pozitieCasa;
        int iaPoz();
        bool iaCasa();

        void setCasa_1(bool a);
        void setCasa_2(bool a);
        void setCasa_3(bool a);
        void setCasa_4(bool a);
        void setCasa(bool a);
        void setPoz(int a);
        void setIdentitate(String ce, int cine);

        virtual void modificaCase(bool *a, bool *b, bool *c, bool *d){};
        virtual void puneInCasa()=0;
        virtual void setTura(int *a){};
        virtual void setJucatorInitial(int *a){};
        
        void iesCasa(TPoint aux, bool *marcheazaZar);
        void verificaDrum(int i, TPoint *aux, int *modificaFinal, TButton *aux0, bool *modificaZar);
        void verifica_Zar6(int *valoareZar,TButton *aux);
        void Muta(TPoint aux, bool *marcheazaZar, int *valoareZar);
        void faCeva();
        void iaParametrii(int *valoareZar, bool *marcheazaZar, int *finalJoc,
TButton *aux0, int a0, int b0, int c0, TMemo *memo, int *modificaNrCasa);

        virtual void Aseaza(POINT& poz, String s=" ")=0;
        virtual void Joaca(int *valoareZar, bool *marcheazaZar,  int *finalJoc,
TButton *aux0){};
        virtual void puneCercuri(TShape *cercuriAux, TShape *cercuriFinalAux, TShape *aux);
        virtual void mouseMove(TShape *cercuri, TShape *cercuriFinal, TShape *aux);

        virtual void __fastcall EventMouseMove(TObject *Sender, TShiftState Shift,
int X, int Y){};

        void __fastcall Reface();
        void __fastcall EventMutaPiesa(TObject *Sender);

};

#endif
