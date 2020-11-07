//---------------------------------------------------------------------------

#ifndef AlbastruH
#define AlbastruH
//---------------------------------------------------------------------------
#include "Pozitie.h"
#include "FereastraJoc.h"
//---------------------------------------------------------------------------
//---------Clasa derivata Albastru---------------------------------------------
//---------------------------------------------------------------------------
class Albastru : public Pozitie
{
        TPoint Locatie[41];
        TShape *cercIesireCasa;
        int *tura_mea;
        int *tura_initiala;
public:
        Albastru ();
        Albastru (TPanel *aux0,  TPoint aux);
        ~Albastru(){};

        TPoint iaLocatie();

        void puneLoc();
        void modificaCasa(POINT& poz);
        virtual void modificaCase(bool *a, bool *b, bool *c, bool *d);
        void scoateDin_Casa(TPoint aux, bool *marcheazaZar,TButton *aux0, int identificator);
        virtual void puneInCasa();
        virtual void Initializeaza_prima_piesa(TPoint aux);
        virtual void setJucatorInitial(int *a);
        virtual void setTura(int *a);
        virtual void Aseaza(POINT& poz, String s=" ");
        virtual void Joaca(int *valoareZar, bool *marcheazaZar, int *finalJoc,
TButton *aux);
        virtual void puneCercuri(TShape *cercuri0, TShape *cercuriFinal0, TShape *cercIesireCasa0);
        virtual void mouseMove(TShape *cercuri0, TShape *cercuriFinal0, TShape *cercIesireCasa0);

        virtual void __fastcall EventMouseMove(TObject *Sender, TShiftState Shift,
int X, int Y);
};

#endif
