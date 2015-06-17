//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "ImagXpr7_OCX.h"
#include <OleCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <ActnMan.hpp>
#include <ActnCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------

class ImageInfo {
private:
        int Ix;
        int Iy;
        long offset;
public:
        unsigned char *IMAGE;

        ImageInfo(ImageInfo *copy) {
                this->Ix = copy->Ix;
                this->Iy = copy->Iy;
                this->offset = copy->offset;
        }

        ImageInfo(int Ix, int Iy, HANDLE handle) {
                this->Ix = Ix;
                this->Iy = Iy;
                this->IMAGE = (unsigned char *)GlobalLock(handle);
                long ln = GlobalSize(handle);
                this->offset=ln-(long)Ix*Iy;
                GlobalUnlock(handle);
        }

        // true: black, false: white
        bool getPixelAt(int x, int y) {
                return ((*(this->IMAGE+y*Ix+x+this->offset)) == 0);
        }

        void setPixelAt(int x, int y, int set) {
                *(this->IMAGE+y*Ix+x+this->offset) = set;
        }

        void clear() {
                for (int i=0; i<this->Ix; i++)
                for (int j=0; j<this->Iy; j++)
                        this->setPixelAt(i, j, 255);
        }

        long CL() {
                int ret = 0;
                for (int i=0; i<this->Ix; i++)
                for (int j=0; j<this->Iy; j++)
                        if (this->getPixelAt(i, j))
                                ret++;
                return ret;
        }

        void print() {
                AnsiString out = "";
                for (int i=0; i<this->Iy; i++) {
                        for (int j=0; j<this->Ix; j++)
                                if (this->getPixelAt(j, i) == true)
                                        out += "1";
                                else
                                        out += "0";
                        out += "\n";
                }
                ShowMessage(out);
        }

        ~ImageInfo() {
                GlobalFree(this->IMAGE);
        }
};

class Coordinates {
public:
        int x;
        int y;
        Coordinates(int x, int y) {
                this->x = x;
                this->y = y;
        }

        void print() {
                AnsiString out = "[";
                out += x;
                out += ", ";
                out += y;
                out += "]";
                ShowMessage(out);
        }
};

enum MaskBool {
        NOT_SET = 0,
        SET,
        DONT_CARE
};
class StructuringElement {
public:
        int X;
        int Y;
        MaskBool **array;
        Coordinates *center;

        StructuringElement(int X, int Y, Coordinates *center) {
                this->X = X;
                this->Y = Y;
                this->array = (MaskBool**)malloc(sizeof(MaskBool*)*X);
                for (int i=0; i<X; i++) {
                        this->array[i] = (MaskBool*)malloc(sizeof(MaskBool)*Y);
                        for (int j=0; j<Y; j++)
                                this->array[i][j] = DONT_CARE;
                }
                this->center = center;
        }

        ~StructuringElement() {
                for (int i=0; i<this->X; i++)
                        free(this->array[i]);
                free(this->array);
        }

        void clear() {
                for (int i=0; i<X; i++)
                for (int j=0; j<Y; j++)
                        this->array[i][j] = NOT_SET;
        }

        void fill() {
                for (int i=0; i<X; i++)
                for (int j=0; j<Y; j++)
                        this->array[i][j] = SET;
        }

        void randomize() {
                for (int i=0; i<X; i++)
                for (int j=0; j<Y; j++) {
                        bool gen = rand() % 2;
                        this->array[i][j] = gen? SET:NOT_SET;
                }
        }

        void print() {
                AnsiString out = "";
                for (int i=0; i<this->Y; i++) {
                        for (int j=0; j<this->X; j++) {
                                if (this->array[j][i] == SET)
                                        out += "1";
                                else if (this->array[j][i] == NOT_SET)
                                        out += "0";
                                else
                                        out += "*";
                                if (i==center->y && j==center->x)
                                        out += ".";
                                else
                                        out += " ";
                        }
                        out += "\n";
                }
                ShowMessage(out);
        }
};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TOpenDialog *OpenDialog1;
        TImagXpress7_ *ImagXpress7_1;
        TPanel *Panel1;
        TLabel *Label1;
        TMenuItem *N7;
        TMenuItem *Morphology1;
        TMenuItem *Dilate1;
        TMenuItem *Erode1;
        TMenuItem *Opening1;
        TMenuItem *Closing1;
        TMenuItem *Generate1;
        TMenuItem *Addrandompattern1;
        TMenuItem *Steps1;
        TMenuItem *Find1;
        TMenuItem *Findpattern1;
        TMenuItem *Removepattern1;
        TMenuItem *Optimize1;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit1;
        TEdit *Edit2;
        TProgressBar *ProgressBar1;
        TProgressBar *ProgressBar2;
        TImagXpress7_ *ImagXpress7_2;
        TButton *Button1;
        TMenuItem *N4;
        TLabel *Label2;
        TLabel *Label5;
        TImagXpress7_ *ImagXpress7_3;
        TLabel *Label6;
        TMenuItem *Evaluation1;
        TMenuItem *GetScore1;
        TLabel *Label7;
        TEdit *Edit3;
        TLabel *Label8;
        TImagXpress7_ *ImagXpress7_4;
        TLabel *Label9;
        TMenuItem *SaveImage1;
        TMenuItem *Addlines1;
        TLabel *Label10;
        TEdit *Edit4;
        TMenuItem *AddSquares1;
        TMenuItem *Addcrosses1;
        TMenuItem *Adddots1;
        void __fastcall N2Click(TObject *Sender);
        void __fastcall ImagXpress7_1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall Erode1Click(TObject *Sender);
        void __fastcall Dilate1Click(TObject *Sender);
        void __fastcall Opening1Click(TObject *Sender);
        void __fastcall Closing1Click(TObject *Sender);
        void __fastcall Find1Click(TObject *Sender);
        void __fastcall Addrandompattern1Click(TObject *Sender);
        void __fastcall Findpattern1Click(TObject *Sender);
        void __fastcall Removepattern1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Optimize1Click(TObject *Sender);
        void __fastcall GetScore1Click(TObject *Sender);
        void __fastcall SaveImage1Click(TObject *Sender);
        void __fastcall Addlines1Click(TObject *Sender);
        void __fastcall AddSquares1Click(TObject *Sender);
        void __fastcall Addcrosses1Click(TObject *Sender);
        void __fastcall Adddots1Click(TObject *Sender);
private:	// User declarations
        /*
        *       FIELDS
        */

        // Image filename
        AnsiString filename;

        // Image Dimentions
        int Ix,Iy;

        // Structuring elements
        StructuringElement *T1,*T2;
        StructuringElement *S1,*S2,*S3,*S4;

        // Pattern Offsets
        int PDH, PDV;


        /*
        *       METHODS
        */

        // Morphological operations
        ImageInfo* erode(ImageInfo *image);
        ImageInfo* erode2(ImageInfo *image);
        ImageInfo* dilate(ImageInfo *image);
        ImageInfo* open(ImageInfo *image);
        ImageInfo* close(ImageInfo *image);

        // Pattern removal
        StructuringElement* getBi(int i);
        StructuringElement* getBj(int j);
        void getPDH();
        void getPDV();
        ImageInfo* uniteImages(ImageInfo *image1, ImageInfo *image2);
        ImageInfo* intersectImages(ImageInfo *image1, ImageInfo *image2);
        void findPattern();
        ImageInfo* xorImages(ImageInfo *image1, ImageInfo *image2);
        void removePattern();

        // Optimization
        void improveQuality();
        void improveQuality2();

        // Generation
        StructuringElement* generateShape();
        StructuringElement* generateSquares();
        StructuringElement* generateCrosses();
        StructuringElement* generateDots();
        void insertPattern(ImageInfo *image, StructuringElement *se, Coordinates *point);
        void addPattern(AnsiString type);
        void addLines();

        // Evaluation
        double evaluate();


public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

        StructuringElement *pattern;
        StructuringElement *curSE;
        ImageInfo *final;

        // Utilities
        void loadImage(ImageInfo *image);
        ImageInfo* getCurrentImage();
        ImageInfo* getInitialImage();
        ImageInfo* getPattern();
        ImageInfo* getInitWithPattern();
        void updateImages();
        void reset();
};


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
