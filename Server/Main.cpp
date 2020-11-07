//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm1::sServerClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        String clientRequest = Socket->ReceiveText();
        String decN = clientRequest.SubString(1,2);
        if(decN=="Nr" || decN=="CL" || decN=="CB"){                 //da la toti numele jucatorilor
                for(int i=0;i<sServer->Socket->ActiveConnections;i++){
                        sServer->Socket->Connections[i]->SendText(clientRequest);
                }
        }
        else{                           //da la restul actiunile sender-ului
                for(int i=0;i<sServer->Socket->ActiveConnections;i++){
                        if(Socket!=sServer->Socket->Connections[i]){
                                sServer->Socket->Connections[i]->SendText(clientRequest);
                        }
                }
        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::sServerClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        int Players = sServer->Socket->ActiveConnections;
        for(int i=0;i<sServer->Socket->ActiveConnections;i++){
                sServer->Socket->Connections[i]->SendText("Nr" + IntToStr(Players));
        }
}
//---------------------------------------------------------------------------

