MBlock::MBlock(String s,int W,int H)
{
ObjectPicture->Height=H;
ObjectPicture->Width=W;
PNG->LoadFromFile(s);
delete PNG1;
PNG1=new TPngImage(COLOR_RGB,16,W,H);
PNG1->Canvas->StretchDraw(Rect(0,0,W,H),PNG);
PNG1->Transparent=true;
PNG1->TransparentColor=clBlack;
AssignP(PNG1);
onground=1;
speedx=0;
speedy=0;
}
MBlock::MBlock(string s,int n,int W,int H):MBlock((s.substr(0,s.find('*'))+to_string(n)+s.substr(s.find('*')+1)).c_str(),W,H)
{

}
MBlock::MBlock(String s):MBlock(s,Game->ClientWidth/16,Game->ClientHeight/9)
{

}
MBlock::MBlock(string s,int n):MBlock((s.substr(0,s.find('*'))+to_string(n)+s.substr(s.find('*')+1)).c_str())
{

}
MBlock::MBlock(String s1,String s2,int W,int H)
{
ObjectPicture->Height=H;
ObjectPicture->Width=W;
PNG->LoadFromFile(s1);
delete PNG1;
PNG1=new TPngImage(COLOR_RGB,16,W,H);
PNG1->Canvas->StretchDraw(Rect(0,0,W*9.0/16,H),PNG);
PNG->LoadFromFile(s2);
PNG1->Canvas->StretchDraw(Rect(W*(1-9.0/16),0,W,H),PNG);
PNG1->Transparent=true;
PNG1->TransparentColor=clBlack;
AssignP(PNG1);
onground=1;
speedx=0;
speedy=0;
}
MBlock::MBlock(string s,int n1,int n2,int W,int H):MBlock((s.substr(0,s.find('*'))+to_string(n1)+s.substr(s.find('*')+1)).c_str(),(s.substr(0,s.find('*'))+to_string(n2)+s.substr(s.find('*')+1)).c_str(),W,H)
{

}