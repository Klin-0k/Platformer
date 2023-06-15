MObject::MObject(Vcl::Controls::TWinControl* Owner)
{
ObjectPicture = new TImage(Owner);
ObjectPicture->Parent=Owner;
}
MObject::MObject():MObject(Game)
{
}
MObject::~MObject()
{
delete ObjectPicture;
}
void MObject::Move(int X,int Y)
{
Ox=X+ObjectPicture->Width/2;
Oy=Y+ObjectPicture->Height/2;
ObjectPicture->Left=X;
ObjectPicture->Top=Y;
}
void MObject::MoveByCenter(int X,int Y)
{
Ox=X;
Oy=Y;
ObjectPicture->Left=Ox-ObjectPicture->Width/2;
ObjectPicture->Top=Oy-ObjectPicture->Height/2;
}
void MObject::LoadFromFile(String s)
{
	ObjectPicture->Picture->LoadFromFile(s);
}
void MObject::AssignP(System::Classes::TPersistent* Img)
{
ObjectPicture->Picture->Assign(Img);
}
void MObject::SetPixels(int x,int y, TColor c)
{
PNG->Assign(ObjectPicture->Picture);
if(PNG->Pixels[x][y]!=clBlack)
PNG->Pixels[x][y]=c;
ObjectPicture->Picture->Assign(PNG);
}
void MObject::SetRectOfPixels(int x1,int y1, int x2,int y2, TColor c)
{
PNG->Assign(ObjectPicture->Picture);
for(int i=x1;i<x2;i++)
for(int j=y1;j<y2;j++)
if(PNG->Pixels[i][j]!=PNG->TransparentColor)
PNG->Pixels[i][j]=c;
ObjectPicture->Picture->Assign(PNG);
}
TColor MObject::GetPixels(int x, int y)
{
PNG->Assign(ObjectPicture->Picture);
return PNG->Pixels[x][y];
}
int MObject::tRight()
{
PNG->Assign(ObjectPicture->Picture);
for(int i = PNG->Width;i>=0;i--)
for(int j=0;j<=PNG->Height;j++)
if(PNG->Pixels[i][j]!=PNG->TransparentColor)
{
return (ObjectPicture->Left+i);
}
return -1;
}
int MObject::tLeft()
{
PNG->Assign(ObjectPicture->Picture);
for(int i = 0;i<=PNG->Width;i++)
for(int j=0;j<=PNG->Height;j++)
if(PNG->Pixels[i][j]!=PNG->TransparentColor)
{
return (ObjectPicture->Left+i);
}
return -1;
}
int MObject::tTop()
{
PNG->Assign(ObjectPicture->Picture);
for(int i = 0;i<=PNG->Height;i++)
for(int j=0;j<=PNG->Width;j++)
if(PNG->Pixels[j][i]!=PNG->TransparentColor)
{
return (ObjectPicture->Top+i);
}
return -1;
}
int MObject::tBottom()
{
PNG->Assign(ObjectPicture->Picture);
for(int i = PNG->Height;i>=0;i--)
for(int j=0;j<=PNG->Width;j++)
if(PNG->Pixels[j][i]!=PNG->TransparentColor)
{
return (ObjectPicture->Top+i);
}
return -1;
}