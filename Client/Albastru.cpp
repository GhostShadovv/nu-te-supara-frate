//---------------------------------------------------------------------------


#pragma hdrstop

#include "Albastru.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//------------------------------------------------------------------------
//---------Metode clasa derivata Albastru--------------------------------------
//---------------------------------------------------------------------------

 Albastru :: Albastru (TPanel *panel,  TPoint point):Pozitie(panel){
         Piesa->Color=clBlue;                             //pune culoare specifica
         puneLoc();                                       //copiem pozitiile din vectorul global
         Aseaza(point, "Casa");                             //asezam piesele in pozitie
         Initializeaza_prima_piesa(point);                  //marcam prima piesa ca fiind in afara casei
 }

//---------------------------------------------------------------------------

 TPoint Albastru :: iaLocatie(){
        return Locatie[1];
 }

//---------------------------------------------------------------------------

 void Albastru :: puneLoc(){
        for(int i=0;i<10;i++){
        //pune in primele 10 pozitii din vectorul local ultimele 10 din vectorul glboal
                Locatie[i]=Loc[i+30];
        }
        for(int i=10;i<40;i++){
        //pune in urmatoarele 30 pozitii din vectorul local primele 30 din vectorul global
                Locatie[i]=Loc[i-10];
        }
 }
 
 //---------------------------------------------------------------------------

 void Albastru :: modificaCase(bool *a, bool *b, bool *c, bool *d){
        casa_1=a;
        casa_2=b;
        casa_3=c;
        casa_4=d;
 }

//---------------------------------------------------------------------------

 void Albastru :: modificaCasa(POINT& poz){
        if(poz.x==BazaA[0].x && poz.y==BazaA[0].y){
                pozitieCasa=BazaA[0];
        }else{
                if(poz.x==BazaA[1].x && poz.y==BazaA[1].y){
                        pozitieCasa=BazaA[1];
                }else{
                        if(poz.x==BazaA[2].x && poz.y==BazaA[2].y){
                                pozitieCasa=BazaA[2];
                        }else{
                                if(poz.x==BazaA[3].x && poz.y==BazaA[3].y){
                                        pozitieCasa=BazaA[3];
                                }
                        }
                }
        }
 }

//---------------------------------------------------------------------------

 void Albastru::Aseaza(POINT& poz, String s){
        Piesa->Left=poz.x;
        Piesa->Top=poz.y;
        if(s=="Casa"){
                modificaCasa(poz);
        }else{
                pozitieCasa=TPoint(NULL,NULL);
        }
 }

//---------------------------------------------------------------------------

 void Albastru :: Initializeaza_prima_piesa(TPoint aux0){
      if (aux0.x==Locatie[1].x && aux0.y == Locatie[1].y){// daca am mutat pe prima pozitie
                Pozitie::setCasa(false);                  // marcam ca am iesit din clasa
                poz=1;                                    // marcam ca suntem pe pozitia 1 ;
         }
 }
//---------------------------------------------------------------------------

  void Albastru :: puneCercuri(TShape *cercuri0, TShape *cercuriFinal0,
TShape *cercIesireCasa0){                                //pointam cercurile pentru highlight
        cercuri=cercuri0;
        cercuriFinal=cercuriFinal0;
        cercIesireCasa = cercIesireCasa0;
}

//---------------------------------------------------------------------------

 void Albastru :: setJucatorInitial(int *a){
        tura_initiala=a;
 }

//---------------------------------------------------------------------------

void Albastru :: setTura(int *a){
        tura_mea=a;
}

//---------------------------------------------------------------------------

 void Albastru :: scoateDin_Casa(TPoint aux, bool *marcheazaZar, TButton *aux0, int identificator){
         iesCasa(aux, marcheazaZar);
         fJoc->tura_G++;
         sndPlaySound("IesireCasa.wav", SND_ASYNC | SND_FILENAME);
         aux0->Enabled=true;                            //deblocam zarul
         fJoc->verificaCase();
         fJoc->verificaInamici("Albastru");
         String text = ceSunt + cineSunt + "Ies";
         fJoc->cSocket->Socket->SendText(text);
}

//---------------------------------------------------------------------------

 void Albastru :: Joaca(int *valoareZar, bool *marcheazaZar, int *finalJoc,
 TButton *aux0){
   if((*tura_mea)%(fJoc->numarJucatori+1)==*tura_initiala){
        int pozitieInitiala=poz;                        //salvam pozitia initiala
        if (*marcheazaZar){                             //daca am dat cu zarul nu pot da click
                return;
        }
        if(poz>40){                                    //daca dam click pe o piesa din final iesim
                return;
        }
        if(casa && *valoareZar!=6){                      //daca sunt in casa si nu am dat 6
                return;                                 //iesi din functie
        } 
        if (casa==true && *valoareZar==6){               //daca piesa e in casa si dam un 6, o punem pe tabla
               scoateDin_Casa(Locatie[0], marcheazaZar, aux0, cineSunt); 
               String trimite = ceSunt + cineSunt;
               fJoc->cSocket->Socket->SendText(trimite);
               return;                                 //iesim din Joc
        }
      for(int i=pozitieInitiala; i<=pozitieInitiala+*valoareZar;i++){
        if(i>40){                                        //daca am ajuns la sfarsitul tablei intram la final
                verificaDrum(i,FinalA, finalJoc, aux0, marcheazaZar);
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
                fJoc->tura_A++;
        if(*valoareZar!=6){
                fJoc->tura++;
        }
        fJoc->verificaCase();
        fJoc->verificaInamici("Albastru");
        }
      }                                                  //sfarsit for

        verifica_Zar6(valoareZar, aux0);               //verifica daca am dat cu zarul 6
        aux0->Enabled=true;                            //pentru a debloca zarul
        Piesa->OnClick=EventMutaPiesa;                 //atribuie event de click
        fJoc->trimiteZar=false;
        fJoc->m_valZar=0;
   }else{
        text->Lines->Add("Nu e randul tau");
    }
 }

//---------------------------------------------------------------------------

 void __fastcall Albastru :: EventMouseMove(TObject *Sender, TShiftState Shift,
 int X, int Y){
        if(!*zar){
                if((*tura_mea)%(fJoc->numarJucatori+1)==*tura_initiala){
                        mouseMove(cercuri,cercuriFinal,cercIesireCasa);
                }
        }
 }

//---------------------------------------------------------------------------

 void Albastru :: mouseMove(TShape *cercuri0, TShape *cercuriFinal0, TShape *cercIesireCasa0){
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
          return;
   }
}

//---------------------------------------------------------------------------

 void Albastru :: puneInCasa(){
        fJoc->verificaCase();
        if(!casa_1){
                Aseaza(BazaA[0],"Casa");
                casa_1=true;
                poz=-1;
                return;
        }
        if(!casa_2){
                Aseaza(BazaA[1],"Casa");
                casa_2=true;
                poz=-1;
                return;
        }
        if(!casa_3){
                Aseaza(BazaA[2],"Casa");
                casa_3=true;
                poz=-1;
                return;
        }
        if(!casa_4){
                Aseaza(BazaA[3],"Casa");
                casa_4=true;
                poz=-1;
                return;
        }
 }
 
//---------------------------------------------------------------------------