//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <vector>

TSettings *Settings;
//---------------------------------------------------------------------------
__fastcall TSettings::TSettings(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TSettings::Button1Click(TObject *Sender)
{
        // Get X,Y
        AnsiString SE = Edit1->Text;
        char *se = SE.c_str();

        int X, Y=0;
        int tempX=0;
        Coordinates *center;
        for (int i=0; i<strlen(se); i++) {
                if (se[i] == '.') {
                        center = new Coordinates(tempX-1, Y);
                        tempX--;
                }
                tempX++;
                if (se[i] == ';') {
                        Y++;
                        X = tempX-1;
                        tempX=0;
                }
        }
        StructuringElement *cur = new StructuringElement(X, Y, center);

        // Fill structuring element
        int x=0, y=0;
        for (int i=0; i<strlen(se); i++) {
                if (se[i] == '.') continue;
                switch(se[i]) {
                case '0':
                        cur->array[x][y] = NOT_SET;
                        break;
                case '1':
                        cur->array[x][y] = SET;
                        break;
                case '*':
                        cur->array[x][y] = DONT_CARE;
                        break;
                default:
                        break;
                }
                x++;
                if (se[i] == ';') {
                        y++;
                        x=0;
                }
        }

        Form1->curSE = cur;
        cur->print();

}
//---------------------------------------------------------------------------


void __fastcall TSettings::Button2Click(TObject *Sender)
{
        ImageInfo *cur = Form1->getCurrentImage();
        Edit2->Text = cur->CL();
        delete cur;        
}
//---------------------------------------------------------------------------

