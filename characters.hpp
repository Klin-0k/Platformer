MCharacter::MCharacter()
{
Life=100000;
direction="Right";
}
MCharacter::~MCharacter()
{
	for(int i =0;i<pictures.size();i++)
	for(int j =0;j<pictures[i].size();j++)
	delete pictures[i][j];
}
string MCharacter::statetostr(int n)
{
switch(n)
{
case 0:
{
	return "Idle";
}
case 1:
{
	return "Run";
}
case 2:
{
	return "Jump";
}
case 3:
{
	return "Fall";
}
case 4:
{
	return "Slide";
}
case 5:
{
	return "Melee";
}
case 6:
{
	return "Shoot";
}
case 7:
{
	return "Dead";
}
}
return "";
}
int MCharacter::tLeft()
{
if(direction=="Right")
return ObjectPicture->Left+tpicturesLeft[state];
else return ObjectPicture->Left+ObjectPicture->Width-tpicturesRight[state];
}
int MCharacter::tTop()
{
return ObjectPicture->Top+tpicturesTop[state];
}
int MCharacter::tRight()
{
if(direction=="Right")
return ObjectPicture->Left+tpicturesRight[state];
else return ObjectPicture->Left+ObjectPicture->Width-tpicturesLeft[state];
}
int MCharacter::tBottom()
{
return ObjectPicture->Top+tpicturesBottom[state];
}
string MCharacter::statetostr()
{
	return statetostr(state);
}
void MCharacter::AssignS(int st,int sn)
{
if(direction=="Left")
{
Mirror(pictures[st][sn]);
//Map->QuickMove(0,-tPBottom(ObjectPicture)+tPBottom(pictures[st][sn]));
AssignP(pictures[st][sn]);
Mirror(pictures[st][sn]);
}
else
{
AssignP(pictures[st][sn]);
//Map->QuickMove(0,-tPBottom(ObjectPicture)+tPBottom(pictures[st][sn]));
}
}

//---------------------------------------------------------------------------

MHero::MHero()
{
ObjectPicture->Height=Game->ClientHeight/9;
ObjectPicture->Width=Game->ClientWidth/16;
pictures=vector <vector<TPngImage*>>(8,vector<TPngImage*>());
stinf=vector <int>(8,0);
tsize = vector <vector<vector<int> > >(4,vector<vector<int> >(8));
for(int i=0;i<4;i++)
tsize[i]=vector <vector<int> >(8,vector<int>());
string path="../../img/characters/adventure_girl/.png";
pictures[run].resize(8);
pictures[dead].resize(10);
pictures[jump].resize(5);
pictures[fall].resize(5);
pictures[idle].resize(10);
pictures[melee].resize(7);
pictures[shoot].resize(3);
pictures[slide].resize(5);
tpicturesLeft=vector <int>(8,0);
tpicturesTop=vector <int>(8,0);
tpicturesRight=vector <int>(8,ObjectPicture->Width);
tpicturesBottom=vector <int>(8,ObjectPicture->Height);

for(int j=0;j<8;j++)
for (int i=1; i<=pictures[j].size();i++)
{
PNG->LoadFromFile((path.substr(0,path.size()-4)+statetostr(j)+" (" +to_string(i)+")"+path.substr(path.size()-4,4)).c_str());
delete PNG1;
if(statetostr(j)!="Jump"&&statetostr(j)!="Fall")
{
PNG1=new TPngImage(COLOR_RGB,16,PNG->Width,tPBottom(PNG)-1);
PNG1->Canvas->CopyRect(Bounds(0,0,PNG1->Width,PNG1->Height),PNG->Canvas,Bounds(0,0,PNG1->Width,PNG1->Height));
}
else
{
PNG1=new TPngImage(COLOR_RGB,16,PNG->Width,tPBottom(PNG)-tPTop(PNG)-1);
PNG1->Canvas->CopyRect(Bounds(0,0,PNG1->Width,PNG1->Height),PNG->Canvas,Bounds(0,tPTop(PNG),PNG1->Width,PNG1->Height));
}
//PNG1=new TPngImage(COLOR_RGB,16,tPRight(PNG)-tPLeft(PNG)+1,tPBottom(PNG)-tPTop(PNG)+1);
//PNG1->Canvas->CopyRect(Rect(0,0,PNG1->Width,PNG1->Height),PNG->Canvas,Rect(tPLeft(PNG),tPTop(PNG),PNG1->Width,PNG1->Height));
 /*
if(statetostr(j)!="Jump")
{
PNG1=new TPngImage(COLOR_RGB,16,PNG->Width,PNG->Height);
PNG1->Canvas->CopyRect(Rect(PNG->Width-tPRight(PNG),PNG->Height-tPBottom(PNG),PNG1->Width,PNG1->Height),PNG->Canvas,Rect(0,0,tPRight(PNG),tPBottom(PNG)));
}
else
{
PNG1=new TPngImage(COLOR_RGB,16,PNG->Width,PNG->Height);
PNG1->Canvas->CopyRect(Rect(PNG->Width-tPRight(PNG),0,PNG1->Width,PNG1->Height-tPTop(PNG)),PNG->Canvas,Rect(tPTop(PNG),tPTop(PNG),tPRight(PNG),PNG1->Height));
}    */
//PNG1=new TPngImage(COLOR_RGB,16,PNG->Width,PNG->Height);
//PNG1->Canvas->CopyRect(Rect(0,0,PNG1->Width,PNG1->Height),PNG->Canvas,Rect(0,0,PNG1->Width,PNG1->Height));
pictures[j][i-1]= new TPngImage(COLOR_RGB,16,ObjectPicture->Width,ObjectPicture->Height);
pictures[j][i-1]->Canvas->StretchDraw(Bounds(0,0,pictures[j][i-1]->Width,pictures[j][i-1]->Height),PNG1);
//pictures[j][i-1]->SaveToFile("../../files/img"+IntToStr(j)+IntToStr(i)+".png");
pictures[j][i-1]->Transparent=true;
pictures[j][i-1]->TransparentColor=clBlack;
for(int z=0;z<4;z++)
tsize[z][j].resize(tsize[z][j].size()+1);
tsize[0][j][i-1]=tPLeft(pictures[j][i-1]);
tsize[1][j][i-1]=tPTop(pictures[j][i-1]);
tsize[2][j][i-1]=tPRight(pictures[j][i-1]);
tsize[3][j][i-1]=tPBottom(pictures[j][i-1]);
//fout << tPBottom(pictures[j][i-1])<<endl ;
if(tPBottom(pictures[j][i-1])<tpicturesBottom[j])
tpicturesBottom[j]=tPBottom(pictures[j][i-1]);
if(tPTop(pictures[j][i-1])>tpicturesTop[j])
tpicturesTop[j]=tPTop(pictures[j][i-1]);
if(tPLeft(pictures[j][i-1])>tpicturesLeft[j])
tpicturesLeft[j]=tPLeft(pictures[j][i-1]);
if(tPRight(pictures[j][i-1])<tpicturesRight[j])
tpicturesRight[j]=tPRight(pictures[j][i-1]);
}
state=idle;
jumptime=0;
timeinwater=0;
inwater=0;
onspikes=0;
nexttolever=0;
nexttodoor=0;
Coins=0;
EBar=new TPngImage();
HealthP=new TPngImage(COLOR_RGB,16,300,100);
BreathP=new TPngImage(COLOR_RGB,16,300,100);
EBar->LoadFromFile("../../img/map/Bars/EmptyBar.png");
HealthP->Canvas->CopyRect(Rect(0,0,300,100),EBar->Canvas,Rect(0,0,300,100));
BreathP->Canvas->CopyRect(Rect(0,0,300,100),EBar->Canvas,Rect(0,0,300,100));
HealthP->TransparentColor=clWhite;
HealthP->Canvas->Brush->Color=clRed;
BreathP->TransparentColor=clWhite;
BreathP->Canvas->Brush->Color=clBlue;
HealthP->Canvas->FillRect(Rect(32,34,270,68));
BreathP->Canvas->FillRect(Rect(32,34,270,68));
HealthBar=new TImage(Game);
HealthBar->Stretch=true;
HealthBar->Parent=Game;
HealthBar->Width=Game->ClientWidth*0.1;
HealthBar->Height=Game->ClientHeight*0.1;
HealthBar->Left=Game->ClientWidth*0.02;
HealthBar->Top=Game->ClientHeight*0.02;
HealthBar->Picture->Assign(HealthP);
BreathBar=new TImage(Game);
BreathBar->Stretch=true;
BreathBar->Parent=Game;
BreathBar->Width=Game->ClientWidth*0.1;
BreathBar->Height=Game->ClientHeight*0.1;
BreathBar->Left=Game->ClientWidth*0.02;
BreathBar->Top=Game->ClientHeight*0.1;
BreathBar->Picture->Assign(BreathP);
Coinpict=new TImage(Game);
Coinpict->Height=Game->ClientHeight*0.05;
Coinpict->Width=Coinpict->Height;
Coinpict->Left=Game->ClientWidth*0.02;
Coinpict->Top=Game->ClientHeight*0.17;
Coinpict->Stretch=true;
Coinpict->Parent=Game;
Coinpict->Picture->LoadFromFile("../../img/map/Objects/gold_1.png");
CoinN=new TLabel(Game);
CoinN->Parent=Game;
CoinN->Font->Height=Coinpict->Height;
CoinN->Caption=IntToStr(Coins);
CoinN->Height=Coinpict->Height;
CoinN->Left=Game->ClientWidth*0.04+Coinpict->Height;
CoinN->Top=Coinpict->Top;
AssignP(pictures[idle][0]);
Game->OnKeyDown=Game->FormKeyDown;
Game->OnKeyUp=Game->FormKeyUp;
Move(Game->ClientWidth/16*7.5,Game->ClientHeight/9*4);
//ObjectPicture->Left=Game->ClientWidth*7.5/16;
//ObjectPicture->Top=Game->ClientHeight*4/9;
}
MHero::~MHero()
{
delete HealthBar;
delete BreathBar;
delete Coinpict;
delete CoinN;
delete HealthP;
delete BreathP;
delete EBar;
Game->OnKeyDown=NULL;
Game->OnKeyUp=NULL;
}
void MHero::UpdateInfo()
{
HealthP->Canvas->CopyRect(Rect(0,0,300,100),EBar->Canvas,Rect(0,0,300,100));
BreathP->Canvas->CopyRect(Rect(0,0,300,100),EBar->Canvas,Rect(0,0,300,100));
if(Life>0)
HealthP->Canvas->FillRect(Rect(32,34,32+238*Life/100000,68));
if(timeinwater<5000)
BreathP->Canvas->FillRect(Rect(32,34,32+238*(1-timeinwater/5000.0),68));
HealthBar->Picture->Assign(HealthP);
BreathBar->Picture->Assign(BreathP);
}
void MHero::AssignS(int st,int sn)
{
if(direction=="Left")
{
Mirror(pictures[st][sn]);
AssignP(pictures[st][sn]);
Mirror(pictures[st][sn]);
}
else
{
AssignP(pictures[st][sn]);
}

}
void MHero::mirrorR()
{
if(direction=="Left")
{
direction="Right";
Map->QuickMove(-Game->ClientWidth*0.01,0);
}
}
void MHero::mirrorL()
{
if(direction=="Right")
{
direction="Left";
Map->QuickMove(Game->ClientWidth*0.01,0);
}
}