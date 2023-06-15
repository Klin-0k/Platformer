TPngImage *PNG = new TPngImage();
TPngImage *PNG1= new TPngImage();



int tPRight(TPngImage *img)
{
for(int i = img->Width;i>=0;i--)
for(int j=0;j<=img->Height;j++)
if(img->Pixels[i][j]!=img->TransparentColor)
{
return (i);
}
return -1;
}
int tPLeft(TPngImage *img)
{
for(int i = 0;i<=img->Width;i++)
for(int j=0;j<=img->Height;j++)
if(img->Pixels[i][j]!=img->TransparentColor)
{
return (i);
}
return -1;
}
int tPTop(TPngImage *img)
{
for(int i = 0;i<=img->Height;i++)
for(int j=0;j<=img->Width;j++)
if(img->Pixels[j][i]!=img->TransparentColor)
{
return (i);
}
return -1;
}
int tPBottom(TPngImage *img)
{
for(int i = img->Height;i>=0;i--)
for(int j=0;j<=img->Width;j++)
if(img->Pixels[j][i]!=img->TransparentColor)
{
return (i);
}
return -1;
}

int tPRight(TImage *img)
{
PNG->Assign(img->Picture);
return tPRight(PNG);
}
int tPLeft(TImage *img)
{
PNG->Assign(img->Picture);
return tPLeft(PNG);
}
int tPTop(TImage *img)
{
PNG->Assign(img->Picture);
return tPTop(PNG);
}
int tPBottom(TImage *img)
{
PNG->Assign(img->Picture);
return tPBottom(PNG);
}

void Mirror(TPngImage *img)
{
for(int i =0;i<img->Width/2;i++)
for(int j =0;j<=img->Height;j++)
{
TColor a,b;
a=img->Pixels[i][j];
b=img->Pixels[img->Width-i][j];
img->Pixels[i][j]=b;
img->Pixels[img->Width-i][j]=a;
}
}
void Mirror(TImage *img)
{
PNG->Assign(img->Picture);
for(int i =0;i<img->Width/2;i++)
for(int j =0;j<=img->Height;j++)
{
TColor a,b;
a=PNG->Pixels[i][j];
b=PNG->Pixels[img->Width-i][j];
PNG->Pixels[i][j]=b;
PNG->Pixels[img->Width-i][j]=a;
}
img->Picture->Assign(PNG);
}


void __fastcall TGame::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key=='A')
{
if(!CP['A'])
{
TP['A']=mtime;
P['A']=1;
CP['A']=1;
}
}
if(Key=='W')
{
if(!CP['W'])
{
TP['W']=mtime;
P['W']=1;
CP['W']=1;
}
}
if(Key=='D')
{
if(!CP['D'])
{
TP['D']=mtime;
P['D']=1;
CP['D']=1;
}
}
if(Key=='S')
{
if(!CP['S'])
{
TP['S']=mtime;
P['S']=1;
CP['S']=1;
}
}
if(Key=='E')
{
if(!CP['E'])
{
TP['E']=mtime;
P['E']=1;
CP['E']=1;
}
}
if(Key=='F')
{
if(!CP['F'])
{
TP['F']=mtime;
P['F']=1;
CP['F']=1;
}
}
if(Key==char(32))
{
if(!CP['W'])
{
TP['W']=mtime;
P['W']=1;
CP['W']=1;
}
}
if(Key==char(27))
{
if(!CP[char(27)])
{
TP[char(27)]=mtime;
P[char(27)]=1;
CP[char(27)]=1;
}
}
}
void __fastcall TGame::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key=='A')
{
P['A']=0;
CP['A']=0;
}
if(Key=='W')
{
P['W']=0;
CP['W']=0;
}
if(Key=='D')
{
P['D']=0;
CP['D']=0;
}
if(Key=='S')
{
P['S']=0;
CP['S']=0;
}
if(Key=='E')
{
P['E']=0;
CP['E']=0;
}
if(Key=='F')
{
P['F']=0;
CP['F']=0;
}
if(Key==char(32))
{
P['W']=0;
CP['W']=0;
}
}