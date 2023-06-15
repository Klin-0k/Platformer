MButton::MButton(Vcl::Controls::TWinControl* Owner, String s1, String s2, String s3):MObject(Owner)
{
ObjectPicture->Stretch=true;
pressed = 0;
p1=new TPngImage();
p2=new TPngImage();
p3=new TPngImage();
p1->LoadFromFile(s1);
p2->LoadFromFile(s2);
p3->LoadFromFile(s3);
AssignP(p1);
ObjectPicture->OnMouseEnter=ButtonPictureMouseEnter;
ObjectPicture->OnMouseLeave=ButtonPictureMouseLeave;
ObjectPicture->OnMouseDown=ButtonPictureMouseDown;
ObjectPicture->OnMouseUp=ButtonPictureMouseUp;
ObjectPicture->OnMouseMove=ButtonPictureMouseMove;
}
MButton::MButton(Vcl::Controls::TWinControl* Owner,String s1, String s2, String s3,String name,String fname,double fsize, TColor fcolor):MButton(Owner,s1,s2,s3)
{
print(name,fname,fsize,fcolor);
AssignP(p1);
}
void MButton::print(String s, String fname, double fsize, TColor fcolor)
{
	p1->Canvas->Font->Name=fname;
	p1->Canvas->Font->Size=p1->Height*fsize;
	p1->Canvas->Font->Color=fcolor;
	p1->Canvas->Brush->Style=bsClear;
	p1->Canvas->TextOut((p1->Width-p1->Canvas->TextWidth(s))/2,(p1->Height-p1->Canvas->TextHeight(s))/2,s);
	p2->Canvas->Font->Name=fname;
	p2->Canvas->Font->Size=p2->Height*fsize;
	p2->Canvas->Font->Color=fcolor;
	p2->Canvas->Brush->Style=bsClear;
	p2->Canvas->TextOut((p2->Width-p2->Canvas->TextWidth(s))/2,(p2->Height-p2->Canvas->TextHeight(s))/2,s);
	p3->Canvas->Font->Name=fname;
	p3->Canvas->Font->Size=p3->Height*fsize;
	p3->Canvas->Font->Color=fcolor;
	p3->Canvas->Brush->Style=bsClear;
	p3->Canvas->TextOut((p3->Width-p3->Canvas->TextWidth(s))/2,(p3->Height-p3->Canvas->TextHeight(s))/2,s);
}
MButton::~MButton()
{
ObjectPicture->OnMouseEnter=NULL;
ObjectPicture->OnMouseLeave=NULL;
ObjectPicture->OnMouseDown=NULL;
ObjectPicture->OnMouseUp=NULL;
ObjectPicture->OnMouseMove=NULL;
ObjectPicture->OnClick=NULL;
delete p1;
delete p2;
delete p3;
}
void __fastcall MButton::ButtonPictureMouseEnter(TObject *Sender)
{
	   AssignP(p2);
}
void __fastcall MButton::ButtonPictureMouseLeave(TObject *Sender)
{
	   AssignP(p1);
}
void __fastcall MButton::ButtonPictureMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	   AssignP(p3);
	   pressed=1;
}
void __fastcall MButton::ButtonPictureMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	   AssignP(p1);
	   pressed=0;
}
void __fastcall MButton::ButtonPictureMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{      if(pressed)
	   {
	   AssignP(p3);
	   }
	   else
	   {
	   AssignP(p2);
	   }
}