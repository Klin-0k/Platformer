//---------------------------------------------------------------------------
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <ctime>
using std::string;
using std::vector;
using std::map;
using std::to_string;
using std::endl;
using std::ifstream;
using std::ofstream;
//---------------------------------------------------------------------------
ifstream fin;
ofstream fout("../../files/Output.txt");
int mtime = 0;
int chtime = 0;
int dtime = 0;
int jumptime = 0;
int FFN=8, TFFN=1;
double FS=0.3;
string FPath="../../img/fon/MainMenuFon/*.png";
map<char,bool> P = {{'A',0},{'W',0},{'D',0},{'S',0},{'F',0},{'E',0}};
map<char,bool> CP = {{'A',0},{'W',0},{'D',0},{'S',0},{'F',0},{'E',0}};
map<char,int> TP = {{'A',0},{'W',0},{'D',0},{'S',0},{'F',0},{'E',0}};
const int idle=0,run=1,jump=2,fall=3,slide=4,melee=5,shoot=6,dead=7;
void CreateMainMenu();
void CreateCurrentLevel();
void Heroanimation();
void HFall();
void HDead();
void HShoot();
void HMelee();
void HSlide();
void HJump();
void HRun();
void HIdle();
double Stage = -1;
int NL=5;
int MMF = 8, LMF = 80, GF = 61;
double MMFS=0.3, LMFS=0.3, GFS = 0.25;
string MMFPath="../../img/fon/MainMenuFon/*.png", LMFPath="../../img/fon/LevelMenuFon/frame (*).png", GFPath="../../img/fon/GameFon/GFon (*).png";
int CurrentLevel=1;
int FullScreen, animation=1;
double FormSize;
int Level;
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "platformer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGame *Game;
MButton *Play;
MButton *Settings;
MButton *Exit;
vector<MLevelButton*>LevelB(NL);
MButton *Back;
MHero *Hero;
MMap* Map;
//---------------------------------------------------------------------------
__fastcall TGame::TGame(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGame::FormCreate(TObject *Sender)
{
fin.open("../../files/Settings.txt");
fin>>FullScreen>>FormSize>>Level;
fin.close();
srand(time(NULL));
//Game->BorderStyle=bsNone;
//Game->BorderStyle=bsSingle;
if(FullScreen)
{
Game->BorderStyle=bsNone;
Game->WindowState=wsMaximized;
Game->Height=Screen->Height;
Game->Width=Screen->Width;
Game->Fon->Left=0;
Game->Fon->Top=0;
Game->Fon->Height=Game->ClientHeight;
Game->Fon->Width=Game->ClientWidth;
}
else
{
Game->WindowState=wsNormal;
Game->BorderStyle=bsSingle;
Game->ClientHeight=Screen->Height*FormSize;
Game->ClientWidth=Game->ClientHeight*16/9;
Game->Left=(Screen->Width-Game->ClientWidth)/2;
Game->Top=(Screen->Height-Game->ClientHeight)/2;
Game->Fon->Left=0;
Game->Fon->Top=0;
Game->Fon->Height=Game->ClientHeight;
Game->Fon->Width=Game->ClientWidth;
}
CreateMainMenu();
}
void CreateMainMenu()
{
Stage=-1;
FPath=MMFPath;
FFN=MMF;
FS=MMFS;
TFFN=1;
Game->Fon->Picture->LoadFromFile((FPath.substr(0,FPath.find('*'))+"1"+FPath.substr(FPath.find('*')+1)).c_str());
Play = new MButton("../../img/buttons/ButtonP1.png","../../img/buttons/ButtonP2.png","../../img/buttons/ButtonP3.png");
Settings = new MButton("../../img/buttons/ButtonS1.png","../../img/buttons/ButtonS2.png","../../img/buttons/ButtonS3.png");
Exit = new MButton("../../img/buttons/ButtonE1.png","../../img/buttons/ButtonE2.png","../../img/buttons/ButtonE3.png");
Play->ObjectPicture->Height=Game->ClientHeight*0.15;
Play->ObjectPicture->Width=Game->ClientWidth*0.25;
Settings->ObjectPicture->Height=Game->ClientHeight*0.15;
Settings->ObjectPicture->Width=Game->ClientWidth*0.25;
Exit->ObjectPicture->Height=Game->ClientHeight*0.15;
Exit->ObjectPicture->Width=Game->ClientWidth*0.25;
int L=(Game->ClientWidth-Play->ObjectPicture->Width)/2;
int H1=(Game->ClientHeight-Play->ObjectPicture->Height*3)/4;
int H2=Play->ObjectPicture->Height;
Play->Move(L,H1);
Settings->Move(L,H1*2+H2);
Exit->Move(L,H1*3+H2*2);
Play->ObjectPicture->OnClick=Game->PlayClick;
Settings->ObjectPicture->OnClick=Game->SettingsClick;
Exit->ObjectPicture->OnClick=Game->ExitClick;
}
//---------------------------------------------------------------------------
void __fastcall TGame::PlayClick(TObject *Sender)
{
Stage=-0.5;
FPath=LMFPath;
FFN=LMF;
FS=LMFS;
TFFN=1;
for(int i=0;i<NL;i++)
{
if(Level>=i)
LevelB[i]=new MLevelButton("../../img/buttons/UIpack/PNG/blue_button11.png","../../img/buttons/UIpack/PNG/green_button11.png","../../img/buttons/UIpack/PNG/yellow_button12.png",i+1);
else
LevelB[i]=new MLevelButton("../../img/buttons/UIpack/PNG/blue_button11.png","../../img/buttons/UIpack/PNG/red_button08.png","../../img/buttons/UIpack/PNG/yellow_button12.png",i+1);
LevelB[i]->ObjectPicture->Height=Game->ClientHeight/8;
LevelB[i]->ObjectPicture->Width=Game->ClientHeight/8;
LevelB[i]->MoveByCenter((i%5+1)*((Game->ClientWidth-5)/6+1),(i/5+1)*((Game->ClientHeight-(NL-1)/5-2)/((NL-1)/5+3)+1));
}
Back = new MButton("../../img/buttons/UIpack/PNG/blue_button04.png","../../img/buttons/UIpack/PNG/green_button04.png","../../img/buttons/UIpack/PNG/yellow_button05.png","Назад","TimesNewRoman",0.4,clYellow);
Back->ObjectPicture->Height=Game->ClientHeight/8;
Back->ObjectPicture->Width=Game->ClientHeight/8*3;
Back->ObjectPicture->OnClick=Game->BackClick;
Back->MoveByCenter(Game->ClientWidth/2,((NL-1)/5+2)*((Game->ClientHeight-(NL-1)/5-2)/((NL-1)/5+3)+1));
}
void __fastcall TGame::SettingsClick(TObject *Sender)
{
MSettings *SettingsMenu=new MSettings(this);
SettingsMenu->ShowModal();
}
void __fastcall TGame::ExitClick(TObject *Sender)
{
Close();
}

void Fonanimation(double speed)
{
Game->Fon->Picture->LoadFromFile((FPath.substr(0,FPath.find('*'))+to_string(int(mtime*speed)%FFN+1)+FPath.substr(FPath.find('*')+1)).c_str());
}

void __fastcall MLevelButton::LevelBClick(TObject *Sender)
{
if(Level+1>=LevelNumber)
{
CurrentLevel=LevelNumber;
Stage=0.5;
}
}

void CreateCurrentLevel()
{
FFN=GF;
FPath=GFPath;
FS=GFS;
Game->Fon->Picture->LoadFromFile((FPath.substr(0,FPath.find('*'))+"1"+FPath.substr(FPath.find('*')+1)).c_str());
for(map<char,bool>::iterator i=P.begin();i!=P.end();i++)
i->second=0;
for(map<char,bool>::iterator i=CP.begin();i!=CP.end();i++)
i->second=0;
Hero= new MHero();
Map=new MMap("../../files/Level "+to_string(CurrentLevel)+".txt");
Hero->state=idle;
Hero->onground=true;
}

void __fastcall TGame::BackClick(TObject *Sender)
{
Stage=-0.75;
}

void __fastcall TGame::Timer1Timer(TObject *Sender)
{
mtime++;
dtime=int(clock())-chtime;
chtime=clock();
if(Stage==-1||Stage==0)
Fonanimation(FS);
else if(Stage==1||Stage==2)
{
Map->MoveObjects();
Heroanimation();
Hero->UpdateInfo();
}
else if(Stage==-0.5)
{
Stage=0;
delete Play;
delete Settings;
delete Exit;
}
else if(Stage==0.5)
{
for(int i=0;i<NL;i++)
delete LevelB[i];
delete Back;
CreateCurrentLevel();
Stage=1;
}
else if(Stage==2.5)
{
Stage=3;
MGameOver *GameOver=new MGameOver(Game);
GameOver->ShowModal();
}
else if(Stage==4)
{
Stage=5;
MGameEnd *GameEnd=new MGameEnd(Game);
GameEnd->ShowModal();
}
else if(Stage==-0.75)
{
for(int i=0;i<NL;i++)
delete LevelB[i];
delete Back;
Stage=-1;
FPath=MMFPath;
FFN=MMF;
FS=MMFS;
TFFN=1;
CreateMainMenu();
}
if(Stage==1||Stage==2||Stage==3||Stage==1.5||Stage==4)
{
if(animation&&!(mtime%10))
{
Map->Wateranimation();
Map->Coinanimation();
}
}
if(Stage ==1&&P[char(27)]==1)
{
P[char(27)]=0;
CP[char(27)]=0;
Stage=1.5;
MLevelMenu *LevelMenu=new MLevelMenu(Game);
LevelMenu->ShowModal();
for(map<char,bool>::iterator i=P.begin();i!=P.end();i++)
i->second=0;
for(map<char,bool>::iterator i=CP.begin();i!=CP.end();i++)
i->second=0;
}
}
//---------------------------------------------------------------------------
void Heroanimation()
{
//Game->BorderStyle=bsSingle;
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HDead();
if(Stage==1)
{
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HShoot();
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HMelee();
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
//HSlide();
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HJump();
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HRun();
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HIdle();
//if(dtime!=0)
//Game->Caption=IntToStr(mtime)+' '+IntToStr(int(1000/dtime))+' '+IntToStr(int(Hero->Life/1000))+' '+Hero->statetostr().c_str()+' '+IntToStr(dtime);
HFall();
Map->Position();
}
//Game->Caption=IntToStr(Hero->state);
}
void HFall()
{
if(Hero->state==fall)
{
Hero->stinf[fall]++;
if(Hero->stinf[fall]<=5)
Hero->AssignS(fall,(Hero->stinf[fall]-1)%Hero->pictures[fall].size());
Map->Move(0,-(2*jumptime+dtime)*Game->ClientHeight*2*dtime/1000000);
jumptime+=dtime;
}
}
void HIdle()
{
if(!(P['A']||P['D']||P['W']||P['S']||P['E']||P['F']||mtime%5)&&Hero->state!=jump&&Hero->state!=fall)
{
Hero->state=idle;
Hero->stinf[idle]=(Hero->stinf[idle]+1)%Hero->pictures[idle].size();
Hero->AssignS(idle,Hero->stinf[idle]);
}
}
void HRun()
{
if(!(Hero->state==shoot||Hero->state==melee||Hero->state==slide))
{
if(P['A'] &&(P['D']==0||TP['A']>=TP['D']))
{
if(Hero->state==idle)
Hero->state=run;
Hero->stinf[run]=(Hero->stinf[run]+1)%Hero->pictures[run].size();
if(Hero->state!=jump&&Hero->state!=fall)
{
Hero->AssignS(run,Hero->stinf[run]);
}
Hero->mirrorL();
//if(mtime%2)
//TFFN=(TFFN)%FFN+1;
//Game->Fon->Picture->LoadFromFile((FPath.substr(0,FPath.find('*'))+to_string(TFFN)+FPath.substr(FPath.find('*')+1)).c_str());
Map->Move(Game->ClientWidth*dtime/5000,0);
//Hero->MoveByCenter(Hero->Ox-10,Hero->Oy);
}
else if(P['D']&&(P['A']==0||TP['D']>TP['A']))
{
if(Hero->state==idle)
Hero->state=run;
Hero->stinf[run]=(Hero->stinf[run]+1)%Hero->pictures[run].size();
if(Hero->state!=jump&&Hero->state!=fall)
{
Hero->AssignS(run,Hero->stinf[run]);
}
Hero->mirrorR();
//if(mtime%2)
//TFFN=(FFN+TFFN-2)%FFN+1;
//Game->Fon->Picture->LoadFromFile((FPath.substr(0,FPath.find('*'))+to_string(TFFN)+FPath.substr(FPath.find('*')+1)).c_str());
Map->Move(-Game->ClientWidth*dtime/5000,0);
//Hero->MoveByCenter(Hero->Ox+10,Hero->Oy);
}
}
}
void HJump()
{
if(P['W']&&Hero->state!=fall&&Hero->onground&&Hero->state!=melee&&Hero->state!=shoot&&Hero->state!=jump)
{
Hero->state=jump;
jumptime=0;
P['W']=0;
}
if(Hero->state==jump)
{
Hero->AssignS(jump,Hero->stinf[jump]);
if(Hero->stinf[jump]<Hero->pictures[jump].size()-1)
{
Hero->stinf[jump]++;
}
Map->Move(0,2*Game->ClientHeight*dtime/2000-(2*jumptime+dtime)*Game->ClientHeight*2*dtime/1000000);
jumptime+=dtime;
if(2*Game->ClientHeight*dtime/2000-(2*jumptime+dtime)*Game->ClientHeight*2*dtime/1000000<=0)
{
Hero->state=fall;
jumptime=0;
Hero->stinf[fall]=0;
Hero->stinf[jump]=0;
}
}
}
void HSlide()
{
if(P['S']&&Hero->state!=jump&&Hero->state!=fall&&Hero->state!=melee&&Hero->state!=shoot)
{
Hero->state=slide;
Hero->stinf[slide]=0;
P['S']=0;
}
if(Hero->state==slide)
{
Hero->AssignS(slide,Hero->stinf[slide]);
if(Hero->stinf[slide]==Hero->pictures[slide].size()-1)
{
Hero->state=idle;
P['S']=0;
}
else Hero->stinf[slide]=(Hero->stinf[slide]+1)%Hero->pictures[slide].size();
}
}
void HMelee()
{

}
void HShoot()
{

}
void HDead()
{
if(Hero->Life<=0)
{
Hero->state=dead;
Hero->AssignS(dead,Hero->stinf[dead]);
Stage = 2;
if(Hero->stinf[dead]==Hero->pictures[dead].size()-1)
{
Stage = 2.5;
}
else Hero->stinf[dead]=(Hero->stinf[dead]+1)%Hero->pictures[dead].size();
}
}
//---------------------------------------------------------------------------



void __fastcall TGame::FormClose(TObject *Sender, TCloseAction &Action)
{
if(Stage==-1)
{
delete Play;
delete Settings;
delete Exit;
}
if(Stage==0)
{
for(int i=0;i<NL;i++)
delete LevelB[i];
delete Back;
}
if(Stage==1)
{
delete Hero;
delete Map;
}
delete PNG;
delete PNG1;
}
//---------------------------------------------------------------------------

void __fastcall TGame::FormCloseQuery(TObject *Sender, bool &CanClose)
{
for(map<char,bool>::iterator i=P.begin();i!=P.end();i++)
i->second=0;
for(map<char,bool>::iterator i=CP.begin();i!=CP.end();i++)
i->second=0;
MExit *ExitForm=new MExit(Game, CanClose);
ExitForm->ShowModal();
}
//---------------------------------------------------------------------------

