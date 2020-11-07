//---------------------------------------------------------------------------

#ifndef GalbenH
#define GalbenH
#include "Pozitie.h"
#include "FereastraJoc.h"

//---------------------------------------------------------------------------
//---------Clasa derivata Galben---------------------------------------------
//---------------------------------------------------------------------------
class Galben : public Pozitie
{
        TPoint Locatie[41];
        TShape *cercIesireCasa;
        int *tura_mea;
        int *tura_initiala;
public:
        Galben ();
        Galben (TPanel *aux0,  TPoint aux);
        ~Galben(){};

        TPoint iaLocatie();

        void puneLoc();
        void modificaCasa(POINT& poz);
        virtual void modificaCase(bool *a, bool *b, bool *c, bool *d);
        void scoateDin_Casa(TPoint point, bool *marcheazaZar,TButton *aux0, int identificator);
        virtual void puneInCasa();
        void Initializeaza_prima_piesa(TPoint point);
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
