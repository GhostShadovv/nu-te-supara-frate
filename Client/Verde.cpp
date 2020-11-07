//---------------------------------------------------------------------------


#pragma hdrstop

#include "Verde.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
//---------Metode clasa derivata Verde--------------------------------------
//---------------------------------------------------------------------------

 Verde :: Verde (TPanel *panel,  TPoint point):Pozitie(panel){
         Piesa->Color=clGreen;                            //punem culoare specifica
         puneLoc();                                       //copiem pozitiile din vectorul global
         Aseaza(point, "Casa");                             //asezam piesele in pozitie
         Initializeaza_prima_piesa(point);                  //marcam prima piesa ca fiind in afara casei
 }

 //---------------------------------------------------------------------------

 TPoint Verde :: iaLocatie(){
        return Locatie[1];
 }

//---------------------------------------------------------------------------

 void Verde :: puneLoc(){
        for(int i=0;i<30;i++){
        //pune in primele 30 pozitii din vectorul local ultimele 30 din vectorul global
                Locatie[i]=Loc[i+10];
        }
        for(int i=30;i<40;i++){
        //pune in urmatoarele 10 pozitii din vectorul local primele 10 din vectorul global
                Locatie[i]=Loc[i-30];
        }
 }

 //---------------------------------------------------------------------------

 void Verde :: modificaCase(bool *a, bool *b, bool *c, bool *d){
        casa_1=a;
        casa_2=b;
        casa_3=c;
        casa_4=d;
 }

//---------------------------------------------------------------------------

 void Verde :: modificaCasa(POINT& poz){
        if(poz.x==BazaV[0].x && poz.y==BazaV[0].y){
                pozitieCasa=BazaV[0];
        }else{
                if(poz.x==BazaV[1].x && poz.y==BazaV[1].y){
                        pozitieCasa=BazaV[1];
                }else{
                        if(poz.x==BazaV[2].x && poz.y==BazaV[2].y){
                                pozitieCasa=BazaV[2];
                        }else{
                                if(poz.x==BazaV[3].x && poz.y==BazaV[3].y){
                                        pozitieCasa=BazaV[3];
                                }
                        }
                }
        }
 }

//---------------------------------------------------------------------------

 void Verde::Aseaza(POINT& poz, String s){
        Piesa->Left=poz.x;
        Piesa->Top=poz.y;
        if(s=="Casa"){
                modificaCasa(poz);
        }else{
                pozitieCasa=TPoint(NULL,NULL);
        }
 }

//---------------------------------------------------------------------------

void Verde :: Initializeaza_prima_piesa(TPoint aux0){
      if (aux0.x==Locatie[1].x && aux0.y == Locatie[1].y){// daca am mutat pe prima pozitie
                Pozitie::setCasa(false);                  // marcam ca am iesit din clasa
                poz=1;                                    // marcam ca suntem pe pozitia 1 ;
         }
 }
//---------------------------------------------------------------------------

  void Verde :: puneCercuri(TShape *cercuri0, TShape *cercuriFinal0,
TShape *cercIesireCasa0){                                 //pointam cercurile pentru highlight
        cercuri=cercuri0;
        cercuriFinal=cercuriFinal0;
        cercIesireCasa = cercIesireCasa0;
}

//---------------------------------------------------------------------------

 void Verde :: setJucatorInitial(int *a){
        tura_initiala=a;
 }

//---------------------------------------------------------------------------

void Verde :: setTura(int *a){
        tura_mea=a;
}

//---------------------------------------------------------------------------

 void Verde :: scoateDin_Casa(TPoint aux, bool *marcheazaZar, TButton *aux0, int identificator){
         iesCasa(aux, marcheazaZar);
         fJoc->tura_G++;
         sndPlaySound("IesireCasa.wav", SND_ASYNC | SND_FILENAME);
         aux0->Enabled=true;                            //deblocam zarul
         fJoc->verificaCase();
         fJoc->verificaInamici("Verde");
         String text = ceSunt + cineSunt + "Ies";
         fJoc->cSocket->Socket->SendText(text);
}

//---------------------------------------------------------------------------
 void Verde :: Joaca(int *valoareZar, bool *marcheazaZar, int *finalJoc,
 TButton *aux0){
   if((*tura_mea)%(fJoc->numarJucatori+1)==*tura_initiala){
        int pozitieInitiala=poz;                        //salvam pozitia initiala
        if (*marcheazaZar){                             //daca am dat cu zarul nu pot da click
          return;
        }
        if(poz>40){                                    //daca dam click pe o piesa din final iesim
          return;
        }

        if (casa==true && *valoareZar==6){               //daca piesa e in casa si dam un 6, o punem pe tabla
               scoateDin_Casa(Locatie[0], marcheazaZar, aux0, cineSunt);
               String trimite = ceSunt + cineSunt;
               fJoc->cSocket->Socket->SendText(trimite);
               return;                                 //iesim din Joc
        }
        if(casa && *valoareZar!=6){                      //daca sunt in casa si nu am dat 6
                return;                                 //iesi din functie
        }
      for(int i=pozitieInitiala; i<=pozitieInitiala+*valoareZar;i++){
        if(i>40){                                        //daca am ajuns la sfarsitul tablei intram la final
                verificaDrum(i,FinalV, finalJoc, aux0, marcheazaZar);
                String trimite = ceSunt + cineSunt;
                fJoc->cSocket->Socket->SendText(trimite);
                break;                                  //iesi din for daca ai ajuns la final
        }
        if(i<40){                                      //daca suntem pe tabla
                Muta(Locatie[i], marcheazaZar, valoareZar);
        }
        if(i==pozitieInitiala-1+*valZar || i>40){      //daca pozitia noastra este pozitia finala si inca suntem pe tabla
                *marcheazaZar=true;                            // putem da cu zarul
                poz=pozitieInitiala+*valoareZar;             //incrementam pozitia piesei cu pozitia initiala inaintea mutarii pas cu pas + valoarea zarului
                String trimite = ceSunt + cineSunt;
                fJoc->cSocket->Socket->SendText(trimite);
                fJoc->tura_V++;
                if(*valoareZar!=6){
                        fJoc->tura++;
                }
                fJoc->verificaCase();
                fJoc->verificaInamici("Verde");
        }
      }                                                  //sfarsit for

        verifica_Zar6(valoareZar, aux0);               //verifica daca am dat cu zarul 6
        aux0->Enabled=true;                            //pentru a debloca zarul
        Piesa->OnClick=EventMutaPiesa;                 //atribuie event de click
        fJoc->trimiteZar=false;
        fJoc->m_valZar=0;
   }
   else{
        text->Lines->Add("Nu e randul tau");
    }
 }

//---------------------------------------------------------------------------

 void __fastcall Verde :: EventMouseMove(TObject *Sender, TShiftState Shift,
 int X, int Y){
        if(!*zar){
                if((*tura_mea)%(fJoc->numarJucatori+1)==*tura_initiala){
                        mouseMove(cercuri,cercuriFinal,cercIesireCasa);
                }
        }
 }

//---------------------------------------------------------------------------

 void Verde :: mouseMove(TShape *cercuri0, TShape *cercuriFinal0, TShape *cercIesireCasa0){
    if(cercuri0 != NULL){
      if(poz==-1 && *valZar==6){
      cercIesireCasa0->Brush->Color=clAqua;
      return;                                           //ca sa nu mai coloreze la pozitia -1+6
      }
      if(poz==-1 && *valZar<6){
      return;                                           //ca sa nu mai coloreze
      }
      if(poz>40){return;}                               //ca sa nu mai coloreze daca sunt in final

      if( poz + *valZar >40){
        cercuriFinal0->Brush->Color=clAqua;
        return;
      }
          lastModified = cercuri0;
          cercuri0->Brush->Color=clAqua;
   }
}

//---------------------------------------------------------------------------

 void Verde :: puneInCasa(){
        fJoc->verificaCase();
        if(!casa_1){
                Aseaza(BazaV[0],"Casa");
                casa_1=true;
                poz=-1;
                return;
        }
        if(!casa_2){
                Aseaza(BazaV[1],"Casa");
                casa_2=true;
                poz=-1;
                return;
        }
        if(!casa_3){
                Aseaza(BazaV[2],"Casa");
                casa_3=true;
                poz=-1;
                return;
        }
        if(!casa_4){
                Aseaza(BazaV[3],"Casa");
                casa_4=true;
                poz=-1;
                return;
        }
 }
 
//---------------------------------------------------------------------------
