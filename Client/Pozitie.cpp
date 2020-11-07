//---------------------------------------------------------------------------


#pragma hdrstop

#include "Pozitie.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


//---------------------------------------------------------------------------
//---------Metode clasa baza-------------------------------------------------
//---------------------------------------------------------------------------

 Pozitie :: Pozitie (TPanel *panel,  int pozitieFinal){
         Piesa = new TPanel(this);
         Piesa->Caption=' ';
         Piesa->Parent=panel;
         Piesa->BevelInner=bvSpace;
         Piesa->BevelOuter=bvRaised;
         Piesa->BevelWidth=2;
         Piesa->Height=33;
         Piesa->Width=33;
         casa=true;
         poz=-1;
         cercuri=NULL;
         cercuriFinal=NULL;
         nrCasa++;
         sariPeste=false;
         
 }

//---------------------------------------------------------------------------

  Pozitie :: ~Pozitie(){
        delete(Piesa);
  }

//---------------------------------------------------------------------------

 void Pozitie :: setCasa(bool a){
        casa=a;
 }

//---------------------------------------------------------------------------

 void Pozitie :: setCasa_1(bool a){
        casa_1=a;
 }

//---------------------------------------------------------------------------

 void Pozitie :: setCasa_2(bool a){
        casa_2=a;
 }

//---------------------------------------------------------------------------

 void Pozitie :: setCasa_3(bool a){
        casa_3=a;
 }

//---------------------------------------------------------------------------

 void Pozitie :: setCasa_4(bool a){
        casa_4=a;
 }

//---------------------------------------------------------------------------

 bool Pozitie :: iaCasa(){
        return casa;
 }


//---------------------------------------------------------------------------

 void Pozitie :: setPoz(int a){
        poz=a;
 }

//---------------------------------------------------------------------------

 int Pozitie :: iaPoz(){
        return poz;
 }

//---------------------------------------------------------------------------

 void Pozitie :: verificaDrum(int i, TPoint *aux,int *modificaFinal,
TButton *aux0, bool *modificaZar){
          Aseaza(aux[*modificaFinal]);                  //Aseaza(PoziieFinal[contorFinal]);
          *modificaFinal+=1;                            //incrementeaza contorul final
          poz=i;                                        //adauga la pozitia inaintea mutarii pas cu pas, pozitiile cate am sarit
          aux0->Enabled=true;                           //deblocam zarul
          *modificaZar=true;                            //marcam ca putem da cu zarul
          sndPlaySound("IntrareFinal.wav", SND_ASYNC | SND_FILENAME);
 }

 //---------------------------------------------------------------------------

 void Pozitie :: iesCasa(TPoint aux, bool *marcheazaZar){
        poz=1;
        Aseaza(aux);
        casa=false;                                     //am iesit din casa
        *marcheazaZar=false;                            //am dat cu zarul 6, mai putem da o data
        nrCasa--;
 }

//---------------------------------------------------------------------------

 void Pozitie :: verifica_Zar6(int *valoareZar, TButton *aux){
        if(*valoareZar==6){                              //daca am dat cu zarul 6,anuntam ca mai dam o data
                aux->Caption="Inca o data";
        }
 }

//---------------------------------------------------------------------------

 void Pozitie :: Muta(TPoint aux, bool *marcheazaZar, int *valoareZar)
 {
       if((*marcheazaZar==false) && (casa==false)){      //daca am dat cu zarul si nu sunt in casa
                Aseaza(aux);
                sndPlaySound("SunetMutare.wav", SND_SYNC | SND_FILENAME);
       }
 }

//---------------------------------------------------------------------------

 void Pozitie :: iaParametrii(int *valoareZar, bool *marcheazaZar, int *finalJoc, TButton *aux0
 , int a0, int b0, int c0, TMemo *memo, int *modificaNrCasa){
        valZar=valoareZar;
        zar=marcheazaZar;
        final=finalJoc;
        aux1=aux0;
        poz_a=a0;
        poz_b=b0;
        poz_c=c0;
        lastModified=NULL;
        text=memo;
        nrCasa=modificaNrCasa;
 }

//---------------------------------------------------------------------------

 void __fastcall Pozitie :: EventMutaPiesa (TObject *Sender){
        faCeva();
 }

//---------------------------------------------------------------------------

 void Pozitie :: faCeva(){
        Joaca(valZar, zar, final, aux1);
 }

//---virtual-----------------------------------------------------------------

 void Pozitie :: puneCercuri(TShape *cercuriAux, TShape *cercuriFinalAux, TShape *aux){
           cercuri=cercuriAux;
           cercuriFinal=cercuriFinalAux;
 }

//---------------------------------------------------------------------------

 void __fastcall Pozitie :: Reface(){
     if(lastModified != NULL){
       lastModified->Brush->Color = clWhite;
       lastModified = NULL;
     }
 }

//---virtual-----------------------------------------------------------------

  void Pozitie :: mouseMove(TShape *cercuri, TShape *cercuriFinal, TShape *aux){
    if(!*zar){
      if(*zar && poz==-1 && *valZar==6){
      cercuri->Brush->Color=clAqua;
      return;                                           //ca sa nu mai coloreze la pozitia -1+6
      }
      if(*zar && poz==-1 && *valZar<6){
      return;                                           //ca sa nu mai coloreze
      }
      if(poz>41){return;}                               //ca sa nu mai coloreze daca sunt in final

      if( poz + *valZar >41){
        cercuriFinal->Brush->Color=clAqua;
      }
      for(int i=1;i<41;i++){
          if ((poz + *valZar)==i){
          //(TColor) culoareOriginala = cercuri[i]->Brush->Color;    E2208 Cannot access an inactive scope
          lastModified = cercuri;
          cercuri->Brush->Color=clAqua;
         }
      }
   }
  }

//---------------------------------------------------------------------------

void Pozitie :: setIdentitate(String ce, int cine){
     ceSunt=ce;
     cineSunt=cine;
}

//---------------------------------------------------------------------------

