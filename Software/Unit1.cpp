//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include <vector>
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ImagXpr7_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;

void TForm1::reset() {
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        ProgressBar1->Position=0;
        ProgressBar2->Position=0;
}

void TForm1::updateImages() {
        ImagXpress7_1->ScrollBars=3;
        ImagXpress7_1->ZoomToFit(2);
        ImagXpress7_2->ScrollBars=3;
        ImagXpress7_2->ZoomToFit(2);
        ImagXpress7_3->ScrollBars=3;
        ImagXpress7_3->ZoomToFit(2);
        ImagXpress7_4->ScrollBars=3;
        ImagXpress7_4->ZoomToFit(2);
}

void TForm1::loadImage(ImageInfo *image) {
        ImagXpress7_1->LoadBuffer((long)image->IMAGE);
}

ImageInfo* TForm1::getCurrentImage() {
        ImagXpress7_1->ColorDepth(8,1,0);
        ImagXpress7_1->SaveToBuffer = true;
        ImagXpress7_1->SaveFileType =  FT_TIFF;
        ImagXpress7_1->SaveFile ();
        return new ImageInfo(Ix, Iy, (HANDLE)ImagXpress7_1->SaveBufferHandle);
}

ImageInfo* TForm1::getInitialImage() {
        ImagXpress7_2->ColorDepth(8,1,0);
        ImagXpress7_2->SaveToBuffer = true;
        ImagXpress7_2->SaveFileType =  FT_TIFF;
        ImagXpress7_2->SaveFile ();
        return new ImageInfo(Ix, Iy, (HANDLE)ImagXpress7_2->SaveBufferHandle);
}

ImageInfo* TForm1::getPattern() {
        ImagXpress7_3->ColorDepth(8,1,0);
        ImagXpress7_3->SaveToBuffer = true;
        ImagXpress7_3->SaveFileType =  FT_TIFF;
        ImagXpress7_3->SaveFile ();
        return new ImageInfo(Ix, Iy, (HANDLE)ImagXpress7_3->SaveBufferHandle);
}

ImageInfo* TForm1::getInitWithPattern() {
        ImagXpress7_4->ColorDepth(8,1,0);
        ImagXpress7_4->SaveToBuffer = true;
        ImagXpress7_4->SaveFileType =  FT_TIFF;
        ImagXpress7_4->SaveFile ();
        return new ImageInfo(Ix, Iy, (HANDLE)ImagXpress7_4->SaveBufferHandle);
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Ix = 500;
        Iy = 500;

        this->updateImages();

        srand(time(NULL));
}
//---------------------------------------------------------------------------

void printInt(AnsiString name, int value) {
      AnsiString s = value;
      AnsiString out = name + ": " + s;
      ShowMessage(out);
}

void printFloat(AnsiString name, float value) {
      AnsiString s = value;
      AnsiString out = name + ": " + s;
      ShowMessage(out);
}

int generateInt(int min, int max) {
        return (rand()%(max-min+1) + min);
}

void __fastcall TForm1::N2Click(TObject *Sender)
{
  if (OpenDialog1->Execute())
  {
    filename = OpenDialog1->FileName;

    if (FileExists(filename)) {
        this->reset();

        ImagXpress7_1->FileName = filename;
        Ix = ImagXpress7_1->IWidth;
        Iy = ImagXpress7_1->IHeight;
        this->updateImages();
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImagXpress7_1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{

  if (!FileExists(filename)) return;

  int x = ImagXpress7_1->DIBXPos;
  int y = ImagXpress7_1->DIBYPos;
  int c = ImagXpress7_1->DIBGetPixel(x,y);

  AnsiString S = "["; S=S+x;S=S+",";S=S+y;
  S=S+"] c:";S=S+c;

  Label1->Caption=S;
}
//---------------------------------------------------------------------------

// Binary Conversion
void __fastcall TForm1::N7Click(TObject *Sender)
{
        ImagXpress7_1->ColorDepth(1,0,0);
        ImagXpress7_1->Update();

        ImageInfo *initial = this->getCurrentImage();
        ImagXpress7_2->LoadBuffer((long)initial->IMAGE);
        this->updateImages();
        delete initial;
}
//---------------------------------------------------------------------------

/*
* --------------------------EROSION-------------------------------
*/
bool checkErosionMask(ImageInfo *image, StructuringElement *se, int x, int y) {
        Coordinates *center = se->center;

        for (int i=0; i<se->X; i++)
        for (int j=0; j<se->Y; j++) {
                if ((se->array[i][j] == DONT_CARE) || (i == center->x && j == center->y))
                        continue;
                int xx = x + i - center->x;
                int yy = y + j - center->y;
                if (se->array[i][j] == image->getPixelAt(xx, yy))
                        return true;
        }
        return false;
}

ImageInfo* TForm1::erode(ImageInfo *image) {
        std::vector<Coordinates> toChange;

        //Erode
        int yMin = 0 + curSE->center->y;
        int yMax = Iy - (curSE->Y - curSE->center->y - 1);
        int xMin = 0 + curSE->center->x;
        int xMax = Ix - (curSE->X - curSE->center->x - 1);

        // Iterate image
        for (int x=xMin; x<xMax; x++)
        for (int y=yMin; y<yMax; y++)
                if ((image->getPixelAt(x, y) == true) && checkErosionMask(image, curSE, x, y))
                        toChange.push_back(Coordinates(x,y));

        image->clear();

        // Fill selected pixels
        for (int i=0; i<toChange.size(); i++)
                image->setPixelAt(toChange[i].x, toChange[i].y, 0);

        return image;
}

ImageInfo* TForm1::erode2(ImageInfo *image) {
        std::vector<Coordinates> toChange;

        //Erode
        int yMin = 0 + curSE->center->y;
        int yMax = Iy - (curSE->Y - curSE->center->y - 1);
        int xMin = 0 + curSE->center->x;
        int xMax = Ix - (curSE->X - curSE->center->x - 1);

        // Iterate image
        for (int x=xMin; x<xMax; x++)
        for (int y=yMin; y<yMax; y++)
                if ((image->getPixelAt(x, y) == true) && !checkErosionMask(image, curSE, x, y))
                        toChange.push_back(Coordinates(x,y));

        // Remove selected pixels
        for (int i=0; i<toChange.size(); i++)
                image->setPixelAt(toChange[i].x, toChange[i].y, 255);

        return image;
}

/*
* --------------------------DILATION-------------------------------
*/
bool checkDilationMask(ImageInfo *image, StructuringElement *se, int x, int y) {
        Coordinates *center = se->center;

        for (int i=0; i<se->X; i++)
        for (int j=0; j<se->Y; j++) {
                if ((se->array[i][j] == DONT_CARE) || (i == center->x && j == center->y))
                        continue;
                int xx = x + i - center->x;
                int yy = y + j - center->y;
                if (se->array[i][j] == image->getPixelAt(xx, yy))
                        return true;
        }
        return false;
}

ImageInfo* TForm1::dilate(ImageInfo *image) {
        std::vector<Coordinates> toChange;
        
        //Dilate
        int yMin = 0 + curSE->center->y;
        int yMax = Iy - (curSE->Y - curSE->center->y - 1);
        int xMin = 0 + curSE->center->x;
        int xMax = Ix - (curSE->X - curSE->center->x - 1);

        // Iterate image
        for (int x=xMin; x<xMax; x++)
        for (int y=yMin; y<yMax; y++)
                if ((image->getPixelAt(x, y) == false) && checkDilationMask(image, curSE, x, y))
                        toChange.push_back(Coordinates(x,y));


        // Fill selected pixels
        for (int i=0; i<toChange.size(); i++)
                image->setPixelAt(toChange[i].x, toChange[i].y, 0);

        return image;
}
/*
* --------------------------OPENING-------------------------------
*/
ImageInfo* TForm1::open(ImageInfo *image) {
        return this->dilate(this->erode(image));
}
/*
* --------------------------CLOSING-------------------------------
*/
ImageInfo* TForm1::close(ImageInfo *image) {
        return this->erode(this->dilate(image));
}


/*
* --------------------------PDH-------------------------------
*/
StructuringElement* TForm1::getBi(int i) {
        StructuringElement *ret = new StructuringElement(i, 1, new Coordinates(0,0));
        ret->array[0][0] = SET;
        ret->array[i-1][0] = SET;
        return ret;
}

void TForm1::getPDH() {
        T1 = new StructuringElement(2, 1, new Coordinates(1, 0));
        T1->array[0][0] = NOT_SET;
        T1->array[1][0] = SET;

        ImageInfo *image = this->getCurrentImage();

        Screen->Cursor = crHourGlass;
        ProgressBar1->Max =Ix - 1;
        int PDH;
        int maxPixels = 0;
        for (int i=2; i<Ix; i++) {
                ProgressBar1->Position = i;

                this->curSE = T1;
                image = this->erode(image);
                this->curSE = this->getBi(i);
                image = this->erode(image);
                delete this->curSE;

                long pixels = image->CL();
                if (pixels > maxPixels) {
                        maxPixels = pixels;
                        PDH = i;
                }

                delete image;
                image = this->getInitWithPattern();
        }
        delete image;

        this->PDH = PDH - 1;
        Edit1->Text = this->PDH;
        Edit1->Update();

        Screen->Cursor = crDefault;

        delete this->T1;
}

/*
* --------------------------PDV-------------------------------
*/
StructuringElement* TForm1::getBj(int j) {
        StructuringElement *ret = new StructuringElement(1, j, new Coordinates(0,0));
        ret->array[0][0] = SET;
        ret->array[0][j-1] = SET;
        return ret;
}

void TForm1::getPDV() {
        T2 = new StructuringElement(1, 2, new Coordinates(0, 1));
        T2->array[0][0] = NOT_SET;
        T2->array[0][1] = SET;

        ImageInfo *image = this->getCurrentImage();

        Screen->Cursor = crHourGlass;
        ProgressBar2->Max = Iy - 1;
        int PDV;
        int maxPixels = 0;
        for (int j=2; j<Iy; j++) {
                ProgressBar2->Position = j;

                this->curSE = T2;
                image = this->erode(image);
                this->curSE = this->getBj(j);
                image = this->erode(image);
                delete this->curSE;

                long pixels = image->CL();
                if (pixels > maxPixels) {
                        maxPixels = pixels;
                        PDV = j;
                }

                delete image;
                image = this->getInitWithPattern();
        }
        delete image;

        this->PDV = PDV - 1;
        Edit2->Text = this->PDV;
        Edit2->Update();

        Screen->Cursor = crDefault;
        
        delete this->T2;
}

/*
* --------------------------PATTERN REMOVAL-------------------------------
*/

ImageInfo* TForm1::uniteImages(ImageInfo *image1, ImageInfo *image2) {
        ImageInfo *image = this->getCurrentImage();
        image->clear();

        for (int i=0; i<Ix; i++)
        for (int j=0; j<Iy; j++)
                if (image1->getPixelAt(i, j) || image2->getPixelAt(i, j))
                        image->setPixelAt(i, j, 0);

        delete image1;
        delete image2;

        return image;
}

ImageInfo* TForm1::intersectImages(ImageInfo *image1, ImageInfo *image2) {
        ImageInfo *image = this->getCurrentImage();
        image->clear();

        for (int i=0; i<Ix; i++)
        for (int j=0; j<Iy; j++)
                if (image1->getPixelAt(i, j) && image2->getPixelAt(i, j))
                        image->setPixelAt(i, j, 0);

        delete image1;
        delete image2;

        return image;
}

ImageInfo* TForm1::xorImages(ImageInfo *image1, ImageInfo *image2) {
        ImageInfo *image = this->getCurrentImage();
        image->clear();

        for (int i=0; i<Ix; i++)
        for (int j=0; j<Iy; j++)
                if (image1->getPixelAt(i, j) != image2->getPixelAt(i, j))
                        image->setPixelAt(i, j, 0);

        delete image1;
        delete image2;

        return image;
}

void TForm1::findPattern() {
        // Initialize structuring elements
        this->S1 = new StructuringElement(PDH+1, 1, new Coordinates(0,0));
        this->S1->array[0][0] = SET;
        this->S1->array[PDH-2][0] = SET;
        this->S1->array[PDH-1][0] = SET;
        this->S1->array[PDH][0] = SET;

        this->S2 = new StructuringElement(PDH+1, 1, new Coordinates(PDH,0));
        this->S2->array[PDH][0] = SET;
        this->S2->array[0][0] = SET;
        this->S2->array[1][0] = SET;
        this->S2->array[2][0] = SET;

        this->S3 = new StructuringElement(1, PDV+1, new Coordinates(0,0));
        this->S3->array[0][0] = SET;
        this->S3->array[0][PDV-2] = SET;
        this->S3->array[0][PDV-1] = SET;
        this->S3->array[0][PDV] = SET;

        this->S4 = new StructuringElement(1, PDV+1, new Coordinates(0,PDV));
        this->S4->array[0][0] = SET;
        this->S4->array[0][1] = SET;
        this->S4->array[0][2] = SET;
        this->S4->array[0][PDV] = SET;

        ImageInfo *image = this->getCurrentImage();

        int pixelCount = image->CL();

        this->curSE = this->S1;
        image = this->erode2(image);
        this->curSE = this->S2;
        image = this->erode2(image);
        this->curSE = this->S3;
        image = this->erode2(image);
        this->curSE = this->S4;
        image = this->erode2(image);

        this->loadImage(image);
        ShowMessage("Iteration");

        int newPixelCount = image->CL();

        int lastDiff = pixelCount - newPixelCount;

        // Repeat erosions until we reach fixpoint
        while ((pixelCount - newPixelCount) > (lastDiff/4) ) {
                lastDiff = pixelCount - newPixelCount;

                this->curSE = this->S1;
                image = this->erode2(image);
                this->curSE = this->S2;
                image = this->erode2(image);
                this->curSE = this->S3;
                image = this->erode2(image);
                this->curSE = this->S4;
                image = this->erode2(image);

                this->loadImage(image);
                ShowMessage("Iteration");

                pixelCount = newPixelCount;
                newPixelCount = image->CL();
        }

        ImagXpress7_3->LoadBuffer((long)image->IMAGE);
        this->updateImages();

        delete image;
        delete this->S1;
        delete this->S2;
        delete this->S3;
        delete this->S4;
}

void TForm1::removePattern() {
        ImageInfo *background = this->getPattern();
        ImageInfo *initialImage = this->getInitWithPattern();
        ImageInfo *final = this->xorImages(initialImage, background);
        this->loadImage(final);
        delete final;
}


/*
* --------------------------GENERATION-------------------------------
*/

StructuringElement* TForm1::generateShape() {
        int X = generateInt(2, ceil(Ix/15));
        int Y = generateInt(2, ceil(Iy/15));

        StructuringElement *ret = new StructuringElement(X, Y, new Coordinates(0,0));
        ret->randomize();

        return ret;
}
StructuringElement* TForm1::generateSquares() {
        int X = generateInt(2, ceil(Ix/15));
        int Y = generateInt(2, ceil(Iy/15));

        StructuringElement *ret = new StructuringElement(X, Y, new Coordinates(0,0));
        ret->fill();

        return ret;
}
StructuringElement* TForm1::generateCrosses() {
        int X = generateInt(2, ceil(Ix/15));
        int Y = generateInt(2, ceil(Iy/15));

        StructuringElement *ret = new StructuringElement(X, Y, new Coordinates(0,0));
        ret->clear();
        int fixX = ret->X/2;
        int fixY = ret->Y/2;
        for (int i=0; i<ret->X; i++) ret->array[i][fixY] = SET;
        for (int j=0; j<ret->Y; j++) ret->array[fixX][j] = SET;
        return ret;
}
StructuringElement* TForm1::generateDots() {
        int X = generateInt(2, floor(Ix/60));
        int Y = generateInt(2, floor(Iy/60));

        StructuringElement *ret = new StructuringElement(X, Y, new Coordinates(0,0));
        ret->fill();

        return ret;
}


void TForm1::insertPattern(ImageInfo *image, StructuringElement *se, Coordinates *coords) {
        for (int i=0; i<se->X; i++)
        for (int j=0; j<se->Y; j++)
        if (se->array[i][j] == SET)
                image->setPixelAt(coords->x + i, coords->y + j, 0);
}

void TForm1::addPattern(AnsiString type) {
        ImageInfo *image = this->getCurrentImage();
        StructuringElement *se;
        if (type == "RANDOM")
                se = this->generateShape();
        else if (type == "SQUARES")
                se = this->generateSquares();
        else if (type == "CROSSES")
                se = this->generateCrosses();
        else if (type == "DOTS")
                se = this->generateDots();

        int PDH = generateInt(se->X, 3*se->X);
        int PDV = generateInt(se->Y, 3*se->Y);

        Coordinates *insertionPoint = new Coordinates(0,0);
        while (insertionPoint->y < Iy-se->Y) {
                while (insertionPoint->x < Ix-se->X) {
                        this->insertPattern(image, se, insertionPoint);
                        insertionPoint->x += PDH;
                }
                insertionPoint->x = 0;
                insertionPoint->y += PDV;
        }

        this->loadImage(image);
        ImagXpress7_4->LoadBuffer((long)image->IMAGE);
        this->updateImages();


        delete image;
        delete insertionPoint;
        delete se;
}

void TForm1::addLines() {
        ImageInfo *image = this->getCurrentImage();

        int PDH = generateInt(3, this->Ix/20);
        int PDV = generateInt(3, this->Iy/20);


        for (int i=0; i<Ix; i++)
        for (int j=0; j<Iy; j++) {
                if (i % PDH == 0) image->setPixelAt(i, j, 0);
                if (j % PDV == 0) image->setPixelAt(i, j, 0);
        }

        this->loadImage(image);
        ImagXpress7_4->LoadBuffer((long)image->IMAGE);
        this->updateImages();


        delete image;
}


/*
* --------------------------OPTIMIZE-------------------------------
*/

void TForm1::improveQuality() {
        Edit3->Text = this->evaluate();
        double score = Edit3->Text.ToDouble();
        this->final = this->getCurrentImage();

        StructuringElement *B = new StructuringElement(3, 3, new Coordinates(1, 1));
        B->fill();
        this->curSE = B;

        ImageInfo *image = this->getCurrentImage();
        ImageInfo *toDilate = this->getCurrentImage();

        toDilate = this->dilate(toDilate);
        this->loadImage(toDilate);
        Edit3->Text = this->evaluate();
        if (Edit3->Text.ToDouble() > score) {
                score = Edit3->Text.ToDouble();
                delete this->final;
                this->final = this->getCurrentImage();
        }
        delete toDilate;
        ShowMessage("Dilated");



        ImageInfo *background = this->getPattern();
        ImageInfo *current = this->getCurrentImage();
        current = this->intersectImages(background, current);
        this->loadImage(current);
        Edit3->Text = this->evaluate();
        ShowMessage("Intersected");



        image = this->uniteImages(image, current);
        this->loadImage(image);
        delete current;
        Edit3->Text = this->evaluate();
        if (Edit3->Text.ToDouble() > score) {
                score = Edit3->Text.ToDouble();
                delete this->final;
                this->final = this->getCurrentImage();
        }
        ShowMessage("United");


        image = this->close(image);
        this->loadImage(image);
        Edit3->Text = this->evaluate();
        if (Edit3->Text.ToDouble() > score) {
                score = Edit3->Text.ToDouble();
                delete this->final;
                this->final = this->getCurrentImage();
        }
        ShowMessage("Closed");

        this->loadImage(final);
        Edit3->Text = this->evaluate();

        delete image;
        delete B;
}

/*
* --------------------------EVALUATION-------------------------------
*/

double TForm1::evaluate() {
        ImageInfo *initial = this->getInitialImage();
        ImageInfo *final = this->getCurrentImage();

        double tp = 0.0, fp = 0.0, fn = 0.0;

        // Count TP, FP, FN pixels
        for (int i=0; i<Ix; i++) 
        for (int j=0; j<Iy; j++) {
                bool init = initial->getPixelAt(i,j);
                bool fin = final->getPixelAt(i,j);
                if (init && fin) tp++;
                else if (fin) fp++;
                else if (init) fn++;
        }
        delete initial;
        delete final;

        // Calculate Recall
        float recall = tp/(fn+tp);
        // Calculate Precision
        float precision = tp/(fp+tp);
        // Calculate F-Measure
        float score = ((2*recall*precision)/(recall+precision));

        return score*100;
}

/*
* --------------------------EVENTS-------------------------------
*/

void __fastcall TForm1::Erode1Click(TObject *Sender)
{
        ImageInfo *eroded = this->erode(this->getCurrentImage());
        this->loadImage(eroded);
        delete eroded;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Dilate1Click(TObject *Sender)
{
        ImageInfo *dilated = this->erode(this->getCurrentImage());
        this->loadImage(dilated);
        delete dilated;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Opening1Click(TObject *Sender)
{
        ImageInfo *opened = this->erode(this->getCurrentImage());
        this->loadImage(opened);
        delete opened;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Closing1Click(TObject *Sender)
{
        ImageInfo *closed = this->erode(this->getCurrentImage());
        this->loadImage(closed);
        delete closed;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Find1Click(TObject *Sender)
{
        // Reset visuals
        Edit1->Clear();
        ProgressBar1->Position=0;
        Edit2->Clear();
        ProgressBar2->Position=0;

        this->getPDH();
        this->getPDV();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Addrandompattern1Click(TObject *Sender)
{
        this->addPattern("RANDOM");
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Findpattern1Click(TObject *Sender)
{
        this->findPattern();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Removepattern1Click(TObject *Sender)
{
        this->removePattern();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if (Settings->Visible == true)
                Settings->Close();
        else
                Settings->Show();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Optimize1Click(TObject *Sender)
{
        this->improveQuality();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GetScore1Click(TObject *Sender)
{
        Edit3->Text = "";
        Edit3->Text = this->evaluate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveImage1Click(TObject *Sender)
{
        ImagXpress7_1->SaveToBuffer = false;
        AnsiString filename = "D:\\";
        filename += Edit4->Text;
        filename += ".tiff";
        ImagXpress7_1->SaveFileName = filename;
        ShowMessage(ImagXpress7_1->SaveFileName);
        ImagXpress7_1->SaveFileType = FT_TIFF;
        ImagXpress7_1->SaveFile();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Addlines1Click(TObject *Sender)
{
        this->addLines();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AddSquares1Click(TObject *Sender)
{
        this->addPattern("SQUARES");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Addcrosses1Click(TObject *Sender)
{
        this->addPattern("CROSSES");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Adddots1Click(TObject *Sender)
{
        this->addPattern("DOTS");        
}
//---------------------------------------------------------------------------

