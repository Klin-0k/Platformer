MMap::MMap(string Path)
{
fin.open(Path);
getline(fin,LevelName);
int i=0;
int t=0;
objectpictures["water"]=vector <TPngImage*>(2);
for(int i=0;i<objectpictures["water"].size();i++)
{
objectpictures["water"][i]= new TPngImage(COLOR_RGB,16,Game->ClientWidth/16,Game->ClientHeight/9);
if(i==0)
PNG->LoadFromFile("../../img/map/tiles/17.png");
else PNG->LoadFromFile("../../img/map/tiles/21.png");
objectpictures["water"][i]->Canvas->StretchDraw(Rect(0,0,objectpictures["water"][i]->Width,objectpictures["water"][i]->Height),PNG);
objectpictures["water"][i]->Transparent=true;
objectpictures["water"][i]->TransparentColor=clBlack;
}
OSN["water"]=0;

objectpictures["box"]=vector <TPngImage*>(9);
for(int i=0;i<objectpictures["box"].size();i++)
{
objectpictures["box"][i]= new TPngImage(COLOR_RGB,16,Game->ClientWidth/32,Game->ClientHeight/18);
PNG->LoadFromFile("../../img/map/Objects/Box ("+IntToStr(i+1)+").png");
objectpictures["box"][i]->Canvas->StretchDraw(Rect(0,0,objectpictures["box"][i]->Width,objectpictures["box"][i]->Height),PNG);
objectpictures["box"][i]->Transparent=true;
objectpictures["box"][i]->TransparentColor=clBlack;
}

objectpictures["door"]=vector <TPngImage*>(3);
for(int i=0;i<objectpictures["door"].size();i++)
{
objectpictures["door"][i]= new TPngImage(COLOR_RGB,16,Game->ClientWidth/16,Game->ClientHeight/9);
PNG->LoadFromFile("../../img/map/Objects/Door "+IntToStr(i)+".png");
objectpictures["door"][i]->Canvas->StretchDraw(Rect(0,0,objectpictures["door"][i]->Width,objectpictures["door"][i]->Height),PNG);
objectpictures["door"][i]->Transparent=true;
objectpictures["door"][i]->TransparentColor=clBlack;
}

objectpictures["lever"]=vector <TPngImage*>(2);
for(int i=0;i<objectpictures["lever"].size();i++)
{
objectpictures["lever"][i]= new TPngImage(COLOR_RGB,16,Game->ClientWidth/32,Game->ClientHeight/9);
PNG->LoadFromFile("../../img/map/Objects/Switch ("+IntToStr(i+1)+").png");
objectpictures["lever"][i]->Canvas->StretchDraw(Rect(0,0,objectpictures["lever"][i]->Width,objectpictures["lever"][i]->Height),PNG);
objectpictures["lever"][i]->Transparent=true;
objectpictures["lever"][i]->TransparentColor=clBlack;
}

objectpictures["spring"]=vector <TPngImage*>(3);
for(int i=0;i<objectpictures["spring"].size();i++)
{
objectpictures["spring"][i]= new TPngImage(COLOR_RGB,16,Game->ClientWidth/32,Game->ClientHeight/18);
PNG->LoadFromFile("../../img/map/Objects/Spring "+IntToStr(i)+".png");
objectpictures["spring"][i]->Canvas->StretchDraw(Rect(0,0,objectpictures["spring"][i]->Width,objectpictures["spring"][i]->Height),PNG);
objectpictures["spring"][i]->Transparent=true;
objectpictures["spring"][i]->TransparentColor=clBlack;
}

objectpictures["coin"]=vector <TPngImage*>(6);
for(int i=0;i<objectpictures["coin"].size();i++)
{
objectpictures["coin"][i]= new TPngImage(COLOR_RGB,16,Game->ClientWidth/32,Game->ClientHeight/18);
PNG->LoadFromFile("../../img/map/Objects/gold_"+IntToStr(i+1)+".png");
if(i==0)
objectpictures["coin"][i]->Canvas->StretchDraw(Rect(0,0,objectpictures["coin"][i]->Width,objectpictures["coin"][i]->Height),PNG);
if(i==1)
objectpictures["coin"][i]->Canvas->StretchDraw(Rect(objectpictures["coin"][i]->Width*3/28,0,objectpictures["coin"][i]->Width*25/28,objectpictures["coin"][i]->Height),PNG);
if(i==2)
objectpictures["coin"][i]->Canvas->StretchDraw(Rect(objectpictures["coin"][i]->Width*17/84,0,objectpictures["coin"][i]->Width*67/84,objectpictures["coin"][i]->Height),PNG);
if(i==3)
objectpictures["coin"][i]->Canvas->StretchDraw(Rect(objectpictures["coin"][i]->Width*23/56,0,objectpictures["coin"][i]->Width*33/56,objectpictures["coin"][i]->Height),PNG);
if(i==4)
objectpictures["coin"][i]->Canvas->StretchDraw(Rect(objectpictures["coin"][i]->Width*17/84,0,objectpictures["coin"][i]->Width*67/84,objectpictures["coin"][i]->Height),PNG);
if(i==5)
objectpictures["coin"][i]->Canvas->StretchDraw(Rect(objectpictures["coin"][i]->Width*3/28,0,objectpictures["coin"][i]->Width*25/28,objectpictures["coin"][i]->Height),PNG);
objectpictures["coin"][i]->Transparent=true;
objectpictures["coin"][i]->TransparentColor=clBlack;
}
OSN["coin"]=0;
while(!fin.eof())
{
M.resize(M.size()+1);
getline(fin,M[i]);
if(M[i].find('S')!=string::npos)
{
Sx=M[i].find('S');
Sy=i;
M[i][Sx]=' ';
}
i++;
}
for(int y=0;y<M.size();y++)
{
for(int j=0;j<M[y].size();j++)
{
switch(M[y][j])
{
case 'S':
{

	break;
}
case 'G':
{
MB.resize(t+1);
if(y==0||M[y-1][j]!='G')
{
if(y==M.size()-1||M[y+1][j]!='G')
{
if(j==0||M[y][j-1]!='G')
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(13,15,Game->ClientWidth/16,Game->ClientHeight*31/384);      //-
}
else
{
MB[t]=new Ground(13,Game->ClientWidth/16,Game->ClientHeight*31/384);    //R
}
}
else
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(15,Game->ClientWidth/16,Game->ClientHeight*31/384);   //L
}
else
{
MB[t]=new Ground(14,Game->ClientWidth/16,Game->ClientHeight*31/384);   //RL
}
}
}
else
{
if(j==0||M[y][j-1]!='G')
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(2);    //B
}
else
{
MB[t]=new Ground(1);    //RB
}
}
else
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(3);          //LB
}
else
{
MB[t]=new Ground(2);      //RLB
}
}
}
}
else
{
if(y==M.size()-1||M[y+1][j]!='G')
{
if(j==0||M[y][j-1]!='G')
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(9);    //T
}
else
{
MB[t]=new Ground(12);     //RT
}
}
else
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(16);            //TL
}
else
{
MB[t]=new Ground(9);   //RTL
}
}
}
else
{
if(j==0||M[y][j-1]!='G')
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(5);    //TB
}
else
{
MB[t]=new Ground(4);    //RTB
}
}
else
{
if(j==M[y].size()-1||M[y][j+1]!='G')
{
MB[t]=new Ground(6);     //TLB
}
else
{
	//RTLB
if(M[y+1][j+1]!='G')
MB[t]=new Ground(19);
else if(M[y+1][j-1]!='G')
MB[t]=new Ground(20);
else if(M[y-1][j+1]!='G')
MB[t]=new Ground(10);
else if(M[y-1][j-1]!='G')
MB[t]=new Ground(8);
else MB[t]=new Ground(5);
}
}
}
}
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->BringToFront();
CB["G"].push_back(MB[t]);
t++;
	break;
}
case 'g':
{
MB.resize(t+1);
if(j==M[y].size()-1||M[y][j+1]!='g')
{
if(j==0||M[y][j-1]!='g')
{
MB[t]=new Ground(13,15,Game->ClientWidth/16,Game->ClientHeight*31/384);    //-
}
else MB[t]=new Ground(15,Game->ClientWidth/16,Game->ClientHeight*31/384);  //L
}
else
{
if(j==0||M[y][j-1]!='g')
{
MB[t]=new Ground(13,Game->ClientWidth/16,Game->ClientHeight*31/384); //R
}
else MB[t]=new Ground(14,Game->ClientWidth/16,Game->ClientHeight*31/384); //RL
}
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->BringToFront();
CB["G"].push_back(MB[t]);
t++;
	break;
}
case 'W':
{
MB.resize(t+1);
if(y==0||M[y-1][j]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
if(j!=0&&M[y][j-1]=='G')
{
MB.resize(t+1);
if(y==0||M[y-1][j-1]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-1-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
}
if(j!=M[y].size()-1&&M[y][j+1]=='G')
{
MB.resize(t+1);
if(y==0||M[y-1][j-1]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j+1-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
}
	break;
}
case 's':
{
MB.resize(t+1);
MB[t]=new Spike();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["s"].push_back(MB[t]);
t++;
	break;
}
case 'p':
{
MB.resize(t+1);
MB[t]=new Spike(3,1./32);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["s"].push_back(MB[t]);
t++;
	break;
}
case 'P':
{
MB.resize(t+1);
MB[t]=new Spike(3,1./32);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["s"].push_back(MB[t]);
t++;
MB.resize(t+1);
if(y==0||M[y-1][j]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
if(j!=0&&M[y][j-1]=='G')
{
MB.resize(t+1);
if(y==0||M[y-1][j-1]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-1-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
}
if(j!=M[y].size()-1&&M[y][j+1]=='G')
{
MB.resize(t+1);
if(y==0||M[y-1][j-1]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j+1-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
}
	break;
}
case 'r':
{
MB.resize(t+1);
MB[t]=new Rock();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["r"].push_back(MB[t]);
t++;
	break;
}
case 't':
{
MB.resize(t+1);
MB[t]=new Tree(CB["t"].size()%2+2);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->SendToBack();
CB["t"].push_back(MB[t]);
t++;
	break;
}
case 'b':
{
MB.resize(t+1);
MB[t]=new Box();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["b"].push_back(MB[t]);
t++;
	break;
}
case 'B':
{
MB.resize(t+1);
MB[t]=new Box();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["b"].push_back(MB[t]);
t++;
MB.resize(t+1);
MB[t]=new Box();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->BringToFront();
CB["b"].push_back(MB[t]);
t++;
	break;
}
case 'C':
{
MB.resize(t+1);
MB[t]=new BigBox();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["C"].push_back(MB[t]);
t++;
	break;
}
case 'c':
{
MB.resize(t+1);
MB[t]=new Coin();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height)/2;
MB[t]->ObjectPicture->BringToFront();
CB["c"].push_back(MB[t]);
t++;
	break;
}
case 'w':
{
MB.resize(t+1);
MB[t]=new Coin();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height)/2;
MB[t]->ObjectPicture->BringToFront();
CB["c"].push_back(MB[t]);
t++;
MB.resize(t+1);
if(y==0||M[y-1][j]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
if(j!=0&&M[y][j-1]=='G')
{
MB.resize(t+1);
if(y==0||M[y-1][j-1]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-1-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
}
if(j!=M[y].size()-1&&M[y][j+1]=='G')
{
MB.resize(t+1);
if(y==0||M[y-1][j-1]!='W')
MB[t]=new Water(17);
else MB[t]=new Water(18);
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j+1-Sx);
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy);
MB[t]->ObjectPicture->SendToBack();
CB["W"].push_back(MB[t]);
if(MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
t++;
}
	break;
}
case 'Y':
{
MB.resize(t+1);
MB[t]=new Spring();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["Y"].push_back(MB[t]);
t++;
	break;
}
case 'E':
{
MB.resize(t+1);
MB[t]=new Door();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["E"].push_back(MB[t]);
t++;
	break;
}
case 'L':
{
MB.resize(t+1);
MB[t]=new Lever();
MB[t]->ObjectPicture->Left=Game->ClientWidth/16*(7.5+j-Sx)+(Game->ClientWidth/16-MB[t]->ObjectPicture->Width)/2;;
MB[t]->ObjectPicture->Top=Game->ClientHeight/9*(4+y-Sy)+(Game->ClientHeight/9-MB[t]->ObjectPicture->Height);
MB[t]->ObjectPicture->BringToFront();
CB["L"].push_back(MB[t]);
t++;
	break;
}
}
}
}
fin.close();
for(int i=0; i<CB["C"].size();i++)
{
CB["C"][i]->ObjectPicture->SendToBack();
}
for(int i=0; i<CB["W"].size();i++)
{
CB["W"][i]->ObjectPicture->SendToBack();
}
for(int i=0; i<CB["TW"].size();i++)
{
CB["TW"][i]->ObjectPicture->SendToBack();
}
for(int i=0; i<CB["s"].size();i++)
{
CB["s"][i]->ObjectPicture->SendToBack();
}
for(int i=0; i<CB["c"].size();i++)
{
CB["c"][i]->ObjectPicture->SendToBack();
}
Hero->ObjectPicture->SendToBack();
for(int i=0; i<CB["t"].size();i++)
{
CB["t"][i]->ObjectPicture->SendToBack();
}
for(int z=0;z<CB["L"].size();z++)
{
CB["L"][z]->ObjectPicture->SendToBack();
}
CB["E"][0]->ObjectPicture->SendToBack();
Game->Fon->SendToBack();
Hero->HealthBar->BringToFront();
Hero->BreathBar->BringToFront();
Hero->Coinpict->BringToFront();
Hero->CoinN->BringToFront();
}





MMap::~MMap()
{
for(int i=0;i<MB.size();i++)
delete MB[i];
for(map<string,vector<TPngImage*> >::iterator i=objectpictures.begin();i!=objectpictures.end();i++)
for (int j=0; j < i->second.size(); j++)
{
delete i->second[j];
}
}










void MMap::Move(int dx,int dy)
{
Hero->onground=0;
Hero->inwater=0;
Hero->onspikes=0;
if(dx>0)
for(int i=0;i<CB["G"].size();i++)
{
if(CB["G"][i]->tLeft()<=Hero->tRight()&&CB["G"][i]->tRight()+dx>=Hero->tLeft()&& CB["G"][i]->tTop()<=Hero->tBottom()&&CB["G"][i]->tBottom()>=Hero->tTop())
dx=Hero->tLeft()-CB["G"][i]->tRight()-1;
}
else if(dx<0)
for(int i=0;i<CB["G"].size();i++)
{
if(CB["G"][i]->tLeft()+dx<=Hero->tRight()&&CB["G"][i]->tRight()>=Hero->tLeft()&& CB["G"][i]->tTop()<=Hero->tBottom()&&CB["G"][i]->tBottom()>=Hero->tTop())
dx=Hero->tRight()-CB["G"][i]->tLeft()+1;
}
if(dy>0)
for(int i=0;i<CB["G"].size();i++)
{
if(CB["G"][i]->tLeft()<=Hero->tRight()&&CB["G"][i]->tRight()>=Hero->tLeft()&& CB["G"][i]->tTop()<=Hero->tBottom()&&CB["G"][i]->tBottom()+dy>=Hero->tTop()){
dy=Hero->tTop()-CB["G"][i]->tBottom()-1;
Hero->state=fall;
jumptime=0;
P['W']=0;
Hero->stinf[jump]=0;
}
}
else if(dy<0)
for(int i=0;i<CB["G"].size();i++)
{
if(CB["G"][i]->tLeft()<=Hero->tRight()&&CB["G"][i]->tRight()>=Hero->tLeft()&& CB["G"][i]->tTop()+dy<=Hero->tBottom()&&CB["G"][i]->tBottom()>=Hero->tTop()){
dy=Hero->tBottom()-CB["G"][i]->tTop()+1;
Hero->onground=1;
Hero->state=idle;
Hero->stinf[fall]=0;
}
}
if(dy==0)
for(int i=0;i<CB["G"].size();i++)
{
//fout <<to_string(Hero->tBottom()+1-CB["G"][i]->tTop())<<()<<endl;
if(CB["G"][i]->tLeft()<=Hero->tRight() && CB["G"][i]->tRight()>=Hero->tLeft())
{
//fout <<to_string(Hero->tBottom()+1-CB["G"][i]->tTop())<<endl;
if(Hero->tBottom()+1==CB["G"][i]->tTop())
Hero->onground=1;
}
}
if(Hero->onground==0&&Hero->state!=jump&&Hero->state!=fall)
{
Hero->stinf[fall]=0;
Hero->state=fall;
jumptime=0;
}
for(map <string,vector<MBlock*> >::iterator i=CB.begin();i!=CB.end();i++)
if(i->first!="L"&&i->first!="E")
i->second.clear();
for(int t=0;t<MB.size();t++)
{
MB[t]->ObjectPicture->Left+=dx;
MB[t]->ObjectPicture->Top+=dy;
if(MB[t]->ObjectPicture->Left+MB[t]->ObjectPicture->Width>=0&&
MB[t]->ObjectPicture->Left <=Game->ClientWidth&&
MB[t]->ObjectPicture->Top+MB[t]->ObjectPicture->Height>=0&&
MB[t]->ObjectPicture->Top <=Game->ClientHeight)
{
if(MB[t]->ObjectPicture->Left+MB[t]->ObjectPicture->Width>=Game->ClientWidth*5.5/16&&
MB[t]->ObjectPicture->Left <=Game->ClientWidth*10.5/16&&
MB[t]->ObjectPicture->Top+MB[t]->ObjectPicture->Height>=Game->ClientHeight*2/9&&
MB[t]->ObjectPicture->Top <=Game->ClientHeight*7/9)
{
if(MB[t]->Type=='G')
CB["G"].push_back(MB[t]);
else if(MB[t]->Type=='W'&&MB[t]->SpriteNumber==18)
CB["W"].push_back(MB[t]);
else if (MB[t]->Type=='s')
CB["s"].push_back(MB[t]);
else if (MB[t]->Type=='r')
CB["r"].push_back(MB[t]);
else if (MB[t]->Type=='t')
CB["t"].push_back(MB[t]);
else if (MB[t]->Type=='Y')
{
CB["Y"].push_back(MB[t]);
CB["G"].push_back(MB[t]);
}
else if(MB[t]->Type=='b')
{
CB["b"].push_back(MB[t]);
CB["G"].push_back(MB[t]);
}
else if(MB[t]->Type=='C')
{
CB["C"].push_back(MB[t]);
CB["G"].push_back(MB[t]);
if(MB[t]->tTop()<Hero->tBottom() && MB[t]->tBottom()>Hero->tTop()&&MB[t]->tLeft()-1==Hero->tRight())
{
MB[t]->speedx=Game->ClientWidth*dtime/10000;
}
else if(MB[t]->tTop()<Hero->tBottom() && MB[t]->tBottom()>Hero->tTop()&&MB[t]->tRight()+1==Hero->tLeft())
{
MB[t]->speedx-=Game->ClientWidth*dtime/10000;
}
}
else if(MB[t]->Type=='c')
{
if(MB[t]->tTop()<Hero->tBottom() && MB[t]->tBottom()>Hero->tTop()&&MB[t]->tLeft()<Hero->tRight() && MB[t]->tRight()>Hero->tLeft())
{
Hero->Coins++;
Hero->CoinN->Caption=IntToStr(Hero->Coins);
delete MB[t];
MB.erase(MB.begin()+t);
t--;
continue;
}
}
else if(MB[t]->Type=='L')
{
if(MB[t]->tTop()<Hero->tBottom() && MB[t]->tBottom()>Hero->tTop()&&MB[t]->tLeft()<Hero->tRight() && MB[t]->tRight()>Hero->tLeft())
Hero->nexttolever=1;
else Hero->nexttolever=0;
}
else if(MB[t]->Type=='E')
{
if(MB[t]->SpriteNumber==1&&MB[t]->tTop()<Hero->tBottom() && MB[t]->tBottom()>Hero->tTop()&&MB[t]->tLeft()<Hero->tRight() && MB[t]->tRight()>Hero->tLeft())
Hero->nexttodoor=1;
else Hero->nexttodoor=0;
}
}
if(MB[t]->Type=='W'&&MB[t]->SpriteNumber==17)
CB["TW"].push_back(MB[t]);
if(MB[t]->Type=='c')
CB["c"].push_back(MB[t]);
}
}
for(int i=0;i<CB["W"].size();i++)
{
if(CB["W"][i]->tTop()<Hero->tBottom() && CB["W"][i]->tBottom()>Hero->tTop()&&CB["W"][i]->tLeft()<Hero->tRight() && CB["W"][i]->tRight()>Hero->tLeft())
Hero->inwater=1;
}
for(int i=0;i<CB["s"].size();i++)
{
if(CB["s"][i]->tTop()<Hero->tBottom() && CB["s"][i]->tBottom()>Hero->tTop()&&CB["s"][i]->tLeft()<Hero->tRight() && CB["s"][i]->tRight()>Hero->tLeft())
Hero->onspikes=1;
}
for(int i=0;i<CB["s"].size();i++)
{
if(CB["s"][i]->tTop()<Hero->tBottom() && CB["s"][i]->tBottom()>Hero->tTop()&&CB["s"][i]->tLeft()<Hero->tRight() && CB["s"][i]->tRight()>Hero->tLeft())
Hero->onspikes=1;
}
}


void MMap::MoveObjects()
{
for(int i=0;i<CB["C"].size();i++)
{
if(CB["C"][i]->onground==0||CB["C"][i]->speedx)
{
CB["C"][i]->onground=0;
if(CB["C"][i]->speedx>0)
for(int j=0;j<CB["G"].size();j++)
{
if(CB["G"][j]==CB["C"][i])
continue;
if(CB["G"][j]->tLeft()<=CB["C"][i]->tRight()+CB["C"][i]->speedx&&CB["G"][j]->tRight()>=CB["C"][i]->tLeft()&& CB["G"][j]->tTop()<=CB["C"][i]->tBottom()&&CB["G"][j]->tBottom()>=CB["C"][i]->tTop())
CB["C"][i]->speedx=CB["G"][j]->tLeft()-CB["C"][i]->tRight()-1;
}
else if(CB["C"][i]->speedx<0)
for(int j=0;j<CB["G"].size();j++)
{
if(CB["G"][j]==CB["C"][i])
continue;
if(CB["G"][j]->tLeft()<=CB["C"][i]->tRight()&&CB["G"][j]->tRight()>=CB["C"][i]->tLeft()+CB["C"][i]->speedx&& CB["G"][j]->tTop()<=CB["C"][i]->tBottom()&&CB["G"][j]->tBottom()>=CB["C"][i]->tTop())
CB["C"][i]->speedx=CB["G"][j]->tRight()-CB["C"][i]->tLeft()+1;
}
if(CB["C"][i]->speedy>0)
for(int j=0;j<CB["G"].size();j++)
{
if(CB["G"][j]==CB["C"][i])
continue;
if(CB["G"][j]->tLeft()<=CB["C"][i]->tRight()&&CB["G"][j]->tRight()>=CB["C"][i]->tLeft()&& CB["G"][j]->tTop()<=CB["C"][i]->tBottom()+CB["C"][i]->speedy&&CB["G"][j]->tBottom()>=CB["C"][i]->tTop())
{
CB["C"][i]->speedy=CB["G"][j]->tTop()-CB["C"][i]->tBottom()-1;
CB["C"][i]->onground=1;
}
}
if(CB["C"][i]->speedy==0)
for(int j=0;j<CB["G"].size();j++)
{
if(CB["G"][j]==CB["C"][i])
continue;
if(CB["G"][j]->tLeft()<=CB["C"][i]->tRight() && CB["G"][j]->tRight()>=CB["C"][i]->tLeft())
{
if(CB["C"][i]->tBottom()+1==CB["G"][j]->tTop())
CB["C"][i]->onground=1;
}
}
CB["C"][i]->ObjectPicture->Left+=CB["C"][i]->speedx;
CB["C"][i]->ObjectPicture->Top+=CB["C"][i]->speedy;
CB["C"][i]->speedx=0;
if(CB["C"][i]->onground)
CB["C"][i]->speedy=0;
else
CB["C"][i]->speedy=(Game->ClientHeight*4*dtime/10000);
//CB["C"][i]->ObjectPicture->Left+=CB["C"][i]->speedx;
//CB["C"][i]->speedx=0;
}
}
}


void MMap::Position()
{
if(Hero->Life>0)
{
if(Hero->inwater)
{
if(Hero->timeinwater>=5000)
{
Hero->Life-=20*dtime;
}
else Hero->timeinwater+=dtime;
}
else if(Hero->timeinwater>0)
{
Hero->timeinwater-=dtime;
if(Hero->timeinwater<0)
Hero->timeinwater=0;
}
}
if(Hero->onspikes)
{
Hero->Life-=100*dtime;
Hero->SetRectOfPixels(0,0,Hero->ObjectPicture->Width,Hero->ObjectPicture->Height,clRed);
}
if(Hero->nexttolever&&P['E'])
{
CB["E"][0]->SpriteNumber=1;
for(int i = 0;i<CB["L"].size();i++)
{
if(CB["L"][i]->tTop()<Hero->tBottom() && CB["L"][i]->tBottom()>Hero->tTop()&&CB["L"][i]->tLeft()<Hero->tRight() && CB["L"][i]->tRight()>Hero->tLeft())
{
if(CB["L"][i]->SpriteNumber==0)
{
CB["L"][i]->SpriteNumber=1;
CB["L"][i]->AssignP(objectpictures["lever"][1]);
}
else
{
CB["L"][i]->SpriteNumber=0;
CB["L"][i]->AssignP(objectpictures["lever"][0]);
}
}
if(CB["L"][i]->SpriteNumber==0)
CB["E"][0]->SpriteNumber=0;
}
CB["E"][0]->AssignP(objectpictures["door"][CB["E"][0]->SpriteNumber]);
P['E']=0;
}
if(Hero->nexttodoor&&P['E'])
{
CB["E"][0]->SpriteNumber=2;
CB["E"][0]->AssignP(objectpictures["door"][CB["E"][0]->SpriteNumber]);
P['E']=0;
Stage=4;
}
}

void MMap::Wateranimation()
{
OSN["water"]=(OSN["water"]+1)%2;
for (int i = 0;i < CB["TW"].size();i++)
{
CB["TW"][i]->AssignP(objectpictures["water"][OSN["water"]]);
}
}
void MMap::Coinanimation()
{
OSN["coin"]=(OSN["coin"]+1)%4;
for (int i = 0;i < CB["c"].size();i++)
{
CB["c"][i]->AssignP(objectpictures["coin"][OSN["coin"]]);
}
Hero->Coinpict->Picture->Assign(objectpictures["coin"][OSN["coin"]]);
}

void MMap::QuickMove(int dx,int dy)
{
for(int t=0;t<MB.size();t++)
{
MB[t]->ObjectPicture->Left+=dx;
MB[t]->ObjectPicture->Top+=dy;
}
}