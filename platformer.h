//---------------------------------------------------------------------------

#ifndef platformerH
#define platformerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.TeCanvas.hpp>
#include "Vcl.Imaging.pngimage.hpp"
//---------------------------------------------------------------------------
class TGame : public TForm
{
__published:	// IDE-managed Components
	TImage *Fon;
	TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TGame(TComponent* Owner);
	void __fastcall PlayClick(TObject *Sender);
	void __fastcall SettingsClick(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);

};
//---------------------------------------------------------------------------

extern PACKAGE TGame *Game;
//---------------------------------------------------------------------------
#endif

#include "functions.hpp"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


class MObject ///////////////////////////////////////////////////////////////
{
public:
int Ox, Oy;
TImage *ObjectPicture;
void LoadFromFile(String s);
void AssignP(System::Classes::TPersistent* Img);
void SetPixels(int x,int y, TColor c);
void SetRectOfPixels(int x1,int y1, int x2,int y2, TColor c);
TColor GetPixels(int x, int y);
void Move(int X,int Y);
void MoveByCenter(int X,int Y);
virtual int tRight();
virtual int tLeft();
virtual int tTop();
virtual int tBottom();
MObject(Vcl::Controls::TWinControl* Owner);
MObject();
~MObject();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MButton: public MObject ///////////////////////////////////////////////
{
private:
bool pressed;
TPngImage *p1,*p2,*p3;
void __fastcall ButtonPictureMouseEnter(TObject *Sender);
void __fastcall ButtonPictureMouseLeave(TObject *Sender);
void __fastcall ButtonPictureMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
void __fastcall ButtonPictureMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
void __fastcall ButtonPictureMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
public:
MButton(Vcl::Controls::TWinControl* Owner,String s1, String s2, String s3);
MButton(String s1, String s2, String s3):MButton(Game,s1,s2,s3){}
MButton(Vcl::Controls::TWinControl* Owner,String s1, String s2, String s3,String name,String fname, double fsize, TColor fcolor);
MButton(String s1, String s2, String s3,String name,String fname, double fsize, TColor fcolor):MButton(Game,s1,s2,s3,name,fname,fsize,fcolor){}
void print(String s, String fname, double fsize, TColor fcolor);
~MButton();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MLevelButton: public MButton
{
public:
int LevelNumber;
MLevelButton(String s1, String s2, String s3, int n):MButton(s1,s2,s3,IntToStr(n),"TimesNewRoman", 0.4,clYellow)
{
LevelNumber = n;
ObjectPicture->OnClick=LevelBClick;
}
void __fastcall LevelBClick(TObject *Sender);
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MExit : public TForm //////////////////////////////////////////////////
{
private:
bool &Answer;
public:
	TImage *Fon;
	TLabel *Label;
	MButton *Yes;
	MButton *No;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action){ModalResult=1; Release();}
	void __fastcall YesClick(TObject *Sender){Answer=1; Close();}
	void __fastcall NoClick(TObject *Sender){Close();}
	__fastcall MExit(System::Classes::TComponent* AOwner,bool &CanClose);
	__fastcall ~MExit();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MSettings : public TForm //////////////////////////////////////////////////
{
private:
public:
	TImage *Fon;
	TCheckBox *FScreen;
	TLabeledEdit *FSize;
	TEdit *SCode;
	TButton *Save, *BackToMM,*SCodeButton,*reset;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FScreenClick(TObject *Sender);
	void __fastcall SCodeButtonClick(TObject *Sender);
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall BackToMMClick(TObject *Sender);
	void __fastcall resetClick(TObject *Sender);
	__fastcall MSettings(System::Classes::TComponent* AOwner);
	__fastcall ~MSettings();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MLevelMenu : public TForm //////////////////////////////////////////////////
{
private:
public:
	TImage *Fon;
	MButton *BackToMM, *PlayAgain, *Continue;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ContinueClick(TObject *Sender);
	void __fastcall PlayAgainClick(TObject *Sender);
	void __fastcall BackToMMClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	__fastcall MLevelMenu(System::Classes::TComponent* AOwner);
	__fastcall ~MLevelMenu();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MGameEnd : public TForm //////////////////////////////////////////////////
{
private:
public:
	TImage *Fon, *Pict;
	MButton *BackToMM, *PlayAgain, *Continue;
	TLabel *Label;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ContinueClick(TObject *Sender);
	void __fastcall PlayAgainClick(TObject *Sender);
	void __fastcall BackToMMClick(TObject *Sender);
	__fastcall MGameEnd(System::Classes::TComponent* AOwner);
	__fastcall ~MGameEnd();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MGameOver : public TForm //////////////////////////////////////////////////
{
private:
public:
	TImage *Fon, *Pict;
	MButton *BackToMM, *PlayAgain;
	TLabel *Label;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PlayAgainClick(TObject *Sender);
	void __fastcall BackToMMClick(TObject *Sender);
	__fastcall MGameOver(System::Classes::TComponent* AOwner);
	__fastcall ~MGameOver();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MCharacter: public MObject ////////////////////////////////////////////
{
public:
vector <vector<TPngImage*> > pictures;
vector <int> stinf;
vector <vector<vector<int> > > tsize;
int tLeft();
int tTop();
int tRight();
int tBottom();
int Life;
int state;
vector <int> tpicturesLeft;
vector <int> tpicturesTop;
vector <int> tpicturesRight;
vector <int> tpicturesBottom;
string statetostr(int n);
string statetostr();
virtual void AssignS(int st,int sn);
string direction;
bool onground;
MCharacter();
~MCharacter();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MHero: public MCharacter //////////////////////////////////////////////
{
public:
TPngImage *HealthP,*BreathP,*EBar;
TImage *HealthBar,*BreathBar,*Coinpict;
TLabel *CoinN;
bool inwater;
bool onspikes;
bool nexttolever;
bool nexttodoor;
int Coins;
int timeinwater;
void UpdateInfo();
void mirrorR();
void mirrorL();
void AssignS(int st,int sn);
//int Left,Top,Right,Bottom;
MHero();
~MHero();
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MBlock: public MObject ////////////////////////////////////////////////
{
public:
MBlock(String s,int W,int H);
MBlock(string s, int n,int W,int H);
MBlock(String s);
MBlock(string s, int n);
MBlock(String s1,String s2,int W,int H);
MBlock(string s,int n1,int n2,int W,int H);
bool onground;
int speedx;
int speedy;
char Type;
int SpriteNumber;
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Ground: public MBlock
{
public:
Ground(int n):MBlock("../../img/map/tiles/*.png",n)
{
Type='G';
SpriteNumber=n;
}
Ground(int n,int W,int H):MBlock("../../img/map/tiles/*.png",n,W,H)
{
Type='G';
SpriteNumber=n;
}
Ground(int n1,int n2,int W,int H):MBlock("../../img/map/tiles/*.png",n1,n2,W,H)
{
Type='G';
SpriteNumber=-1;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Water: public MBlock
{
public:
Water(int n):MBlock("../../img/map/tiles/*.png",n)
{
Type='W';
SpriteNumber=n;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Spike: public MBlock
{
public:
Spike():MBlock("../../img/map/Objects/Spike 0.png",Game->ClientWidth/16,Game->ClientHeight/10)
{
Type='s';
SpriteNumber=0;
}
Spike(int n, double i):MBlock("../../img/map/Objects/Spike *.png",n,Game->ClientWidth*i,Game->ClientHeight/20)
{
Type='s';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Rock: public MBlock
{
public:
Rock():MBlock("../../img/map/Objects/Stone.png",Game->ClientWidth/30,Game->ClientHeight/25)
{
Type='r';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Tree: public MBlock
{
public:
Tree(int n):MBlock("../../img/map/Objects/Tree_*.png",n,Game->ClientWidth/8,Game->ClientHeight*(rand()%11+30)/100)
{
Type='t';
SpriteNumber=n;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Box: public MBlock
{
public:
Box():MBlock("../../img/map/Objects/Box (1).png",Game->ClientWidth/32,Game->ClientHeight/18)
{
Type='b';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class BigBox: public MBlock
{
public:
BigBox():MBlock("../../img/map/Objects/BigBox.png",Game->ClientWidth/18,Game->ClientHeight/10)
{
//speedy=1;
Type='C';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Door: public MBlock
{
public:
Door():MBlock("../../img/map/Objects/Door 0.png",Game->ClientWidth/16,Game->ClientHeight/9)
{
Type='E';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Lever: public MBlock
{
public:
Lever():MBlock("../../img/map/Objects/Switch (1).png",Game->ClientWidth/32,Game->ClientHeight/9)
{
Type='L';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Spring: public MBlock
{
public:
Spring():MBlock("../../img/map/Objects/Spring 0.png",Game->ClientWidth/32,Game->ClientHeight/18)
{
Type='Y';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Coin: public MBlock
{
public:
Coin():MBlock("../../img/map/Objects/gold_1.png",Game->ClientWidth/32,Game->ClientHeight/18)
{
Type='c';
SpriteNumber=0;
}
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class MMap //////////////////////////////////////////////////////////////////
{
public:
string LevelName;
vector <string> M;
vector <MBlock*> MB;
map <string,vector<MBlock*> > CB;
int Sx,Sy;
MMap(string Path);
~MMap();
map <string,int>OSN;
map <string,vector <TPngImage*> > objectpictures;
void Move(int dx,int dy);
void QuickMove(int dx,int dy);
void MoveObjects();
void Position();
void Wateranimation();
void Coinanimation();
};

//---------------------------------------------------------------------------

extern MButton *Play,*Settings,*Exit;
extern MHero *Hero;
extern MMap *Map;

#include "mobject.hpp"
#include "mbutton.hpp"
#include "forms.hpp"
#include "characters.hpp"
#include "blocks.hpp"
#include "mmap.hpp"
