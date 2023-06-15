__fastcall MExit::MExit(System::Classes::TComponent* AOwner,bool &CanClose) : Answer(CanClose), TForm(AOwner, 1)
	{
	Answer=0;
	Fon=new TImage(this);
	Label=new TLabel(this);
	Yes = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Да","Amatic SC Bold",0.28,clYellow);
	No = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Нет","Amatic SC Bold",0.28,clYellow);
	ClientHeight=Game->ClientHeight/2;
	//ClientWidth=Game->ClientWidth/2;
	ClientWidth=ClientHeight*1.5;
	Left=Game->Left+(Game->ClientWidth-ClientWidth)/2;
	Top=Game->Top+Game->ClientHeight/4;
	DoubleBuffered=true;
	Caption="Выход из игры";
	BorderStyle=bsNone;
	//BorderIcons>>biMaximize>>biMinimize;
	Color=clCream;
	OnClose=FormClose;
	Label->Parent=this;
	Label->Font->Height=Height/10;
	Label->Font->Name="Amatic SC Bold";
	Label->Caption="Вы уверены, что хотите выйти?";
	Label->AutoSize=true;
	Label->Top=(Label->Height)/2;
	Label->Left=(ClientWidth-Label->Width)/2;
	Yes->ObjectPicture->Width=ClientWidth*0.3;
	Yes->ObjectPicture->Height=ClientHeight*0.15;
	Yes->ObjectPicture->Left=(ClientWidth-Yes->ObjectPicture->Width*2)/3;
	Yes->ObjectPicture->Top=ClientHeight-Yes->ObjectPicture->Height*3/2;
	Yes->ObjectPicture->OnClick=YesClick;
	No->ObjectPicture->Width=ClientWidth*0.3;
	No->ObjectPicture->Height=ClientHeight*0.15;
	No->ObjectPicture->Left=(ClientWidth-No->ObjectPicture->Width*2)*2/3+Yes->ObjectPicture->Width;
	No->ObjectPicture->Top=ClientHeight-No->ObjectPicture->Height*3/2;
	No->ObjectPicture->OnClick=NoClick;
	Fon->Parent=this;
	Fon->Stretch=true;
	Fon->Picture->LoadFromFile("../../img/fon/ExitFon/1.png");
	Fon->SendToBack();
	Fon->Width=ClientWidth;
	Fon->Height=ClientHeight-(Yes->ObjectPicture->Height+Label->Height)*2;
	Fon->Left=0;
	Fon->Top=Label->Height*2;
	}
	__fastcall MExit::~MExit()
	{
		 delete Fon;
		 delete Label;
		 delete Yes;
		 delete No;
	}
//------------------------------------
	void __fastcall MGameOver::FormClose(TObject *Sender, TCloseAction &Action)
	{
	ModalResult=1;
	Release();
	}
	void __fastcall MGameOver::PlayAgainClick(TObject *Sender)
	{
	delete Hero;
	delete Map;
	CreateCurrentLevel();
	Stage=1;
	Close();
	}
	void __fastcall MGameOver::BackToMMClick(TObject *Sender)
	{
	delete Hero;
	delete Map;
	Stage=-1;
	CreateMainMenu();
	Close();
	}
	__fastcall MGameOver::MGameOver(System::Classes::TComponent* AOwner) : TForm(AOwner, 1)
	{
	Fon=new TImage(this);
	Pict=new TImage(this);
	Label=new TLabel(this);
	PlayAgain = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Заново","Amatic SC Bold",0.28,clYellow);
	BackToMM = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Главное меню","Amatic SC Bold",0.28,clYellow);
	ClientHeight=Game->ClientHeight/2;
	ClientWidth=ClientHeight*1.5;
	Left=Game->Left+(Game->ClientWidth-ClientWidth)/2;
	Top=Game->Top+Game->ClientHeight/4;
	DoubleBuffered=true;
	Caption="Игра окончена";
	BorderStyle=bsNone;
	//BorderIcons>>biMaximize>>biMinimize;
	Color=clCream;
	OnClose=FormClose;
	Label->Parent=this;
	Label->Font->Height=Height/10;
	Label->Font->Name="Amatic SC Bold";
	Label->Caption="Вы умерли";
	Label->AutoSize=true;
	Label->Top=(Label->Height)/2;
	Label->Left=(ClientWidth-Label->Width)/2;
	PlayAgain->ObjectPicture->Width=ClientWidth*0.3;
	PlayAgain->ObjectPicture->Height=ClientHeight*0.15;
	PlayAgain->ObjectPicture->Left=(ClientWidth-PlayAgain->ObjectPicture->Width*2)/3;
	PlayAgain->ObjectPicture->Top=ClientHeight-PlayAgain->ObjectPicture->Height*3/2;
	PlayAgain->ObjectPicture->OnClick=PlayAgainClick;
	BackToMM->ObjectPicture->Width=ClientWidth*0.3;
	BackToMM->ObjectPicture->Height=ClientHeight*0.15;
	BackToMM->ObjectPicture->Left=(ClientWidth-BackToMM->ObjectPicture->Width*2)*2/3+PlayAgain->ObjectPicture->Width;
	BackToMM->ObjectPicture->Top=ClientHeight-BackToMM->ObjectPicture->Height*3/2;
	BackToMM->ObjectPicture->OnClick=BackToMMClick;
	Fon->Parent=this;
	Fon->Stretch=true;
	Fon->Picture->LoadFromFile("../../img/fon/MenuFon/1.png");
	Fon->SendToBack();
	Fon->Width=ClientWidth;
	Fon->Height=ClientHeight;
	Fon->Left=0;
	Fon->Top=0;
	Pict->Parent=this;
	Pict->Stretch=true;
	Pict->Picture->LoadFromFile("../../img/characters/adventure_girl/Dead (10).png");
	Pict->Height=ClientHeight/2.5;
	Pict->Width=ClientWidth/2.5;
	Pict->Left=(ClientWidth-Pict->Width)/2;
	Pict->Top=(ClientHeight-Pict->Height)/2;
	}
	__fastcall MGameOver::~MGameOver()
	{
		 delete Fon;
		 delete Pict;
		 delete PlayAgain;
		 delete BackToMM;
		 delete Label;
	}
//---------------------------
		void __fastcall MLevelMenu::FormClose(TObject *Sender, TCloseAction &Action)
	{
	ModalResult=1;
	Release();
	}
		void __fastcall MLevelMenu::ContinueClick(TObject *Sender)
	{
	Stage=1;
	Close();
	}
	void __fastcall MLevelMenu::PlayAgainClick(TObject *Sender)
	{
	delete Hero;
	delete Map;
	CreateCurrentLevel();
	Stage=1;
	Close();
	}
	void __fastcall MLevelMenu::BackToMMClick(TObject *Sender)
	{
	Stage=-1;
	delete Hero;
	delete Map;
	CreateMainMenu();
	Close();
	}
	void __fastcall MLevelMenu::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
	{
		if(Key==char(27))
		{
		Stage=1;
		Close();
		}
	}
	__fastcall MLevelMenu::MLevelMenu(System::Classes::TComponent* AOwner) : TForm(AOwner, 1)
	{
	Fon=new TImage(this);
    Continue = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Продолжить","Amatic SC Bold",0.28,clYellow);
	PlayAgain = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Заново","Amatic SC Bold",0.28,clYellow);
	BackToMM = new MButton(this,"../../img/buttons/Button2.png","../../img/buttons/Button1.png","../../img/buttons/Button2.png","Главное меню","Amatic SC Bold",0.28,clYellow);
	ClientHeight=Game->ClientHeight/2;
	ClientWidth=ClientHeight*1.5;
	Left=Game->Left+(Game->ClientWidth-ClientWidth)/2;
	Top=Game->Top+Game->ClientHeight/4;
	DoubleBuffered=true;
	Caption="Пауза";
	BorderStyle=bsNone;
	//BorderIcons>>biMaximize>>biMinimize;
	Color=clCream;
	OnClose=FormClose;
	OnKeyDown=FormKeyDown;
	Continue->ObjectPicture->Width=ClientWidth*0.4;
	Continue->ObjectPicture->Height=ClientHeight*0.2;
	Continue->ObjectPicture->Left=(ClientWidth-Continue->ObjectPicture->Width)/2;
	Continue->ObjectPicture->Top=(ClientHeight-Continue->ObjectPicture->Height*3)/4;
	Continue->ObjectPicture->OnClick=ContinueClick;
	PlayAgain->ObjectPicture->Width=ClientWidth*0.4;
	PlayAgain->ObjectPicture->Height=ClientHeight*0.2;
	PlayAgain->ObjectPicture->Left=(ClientWidth-PlayAgain->ObjectPicture->Width)/2;
	PlayAgain->ObjectPicture->Top=(ClientHeight-PlayAgain->ObjectPicture->Height*3)/4*2+Continue->ObjectPicture->Height;
	PlayAgain->ObjectPicture->OnClick=PlayAgainClick;
	BackToMM->ObjectPicture->Width=ClientWidth*0.4;
	BackToMM->ObjectPicture->Height=ClientHeight*0.2;
	BackToMM->ObjectPicture->Left=(ClientWidth-BackToMM->ObjectPicture->Width)/2;
	BackToMM->ObjectPicture->Top=(ClientHeight-BackToMM->ObjectPicture->Height*3)/4*3+Continue->ObjectPicture->Height+PlayAgain->ObjectPicture->Height;
	BackToMM->ObjectPicture->OnClick=BackToMMClick;
	Fon->Parent=this;
	Fon->Stretch=true;
	Fon->Picture->LoadFromFile("../../img/fon/MenuFon/1.png");
	Fon->SendToBack();
	Fon->Width=ClientWidth;
	Fon->Height=ClientHeight;
	Fon->Left=0;
	Fon->Top=0;
	}
	__fastcall MLevelMenu::~MLevelMenu()
	{
		 delete Fon;
		 delete PlayAgain;
		 delete BackToMM;
		 delete Continue;
	}

//----------------------
	void __fastcall MGameEnd::FormClose(TObject *Sender, TCloseAction &Action)
	{
	ModalResult=1;
	Release();
	}
	void __fastcall MGameEnd::ContinueClick(TObject *Sender)
	{
	delete Hero;
	delete Map;
	CurrentLevel=CurrentLevel%NL+1;
	CreateCurrentLevel();
	Stage=1;
	Close();
	}
	void __fastcall MGameEnd::PlayAgainClick(TObject *Sender)
	{
	delete Hero;
	delete Map;
	CreateCurrentLevel();
	Stage=1;
	Close();
    }
	void __fastcall MGameEnd::BackToMMClick(TObject *Sender)
	{
	delete Hero;
	delete Map;
	CreateMainMenu();
	Stage=-1;
	Close();
	}
	__fastcall MGameEnd::MGameEnd(System::Classes::TComponent* AOwner): TForm(AOwner, 1)
	{
	if(CurrentLevel>Level)
	Level=CurrentLevel;
	Fon=new TImage(this);
	Pict=new TImage(this);
	Continue = new MButton(this,"../../img/buttons/next.png","../../img/buttons/next.png","../../img/buttons/next.png");
	PlayAgain = new MButton(this,"../../img/buttons/again.png","../../img/buttons/again.png","../../img/buttons/again.png");
	BackToMM = new MButton(this,"../../img/buttons/home.png","../../img/buttons/home.png","../../img/buttons/home.png");
	Label=new TLabel(this);
	ClientHeight=Game->ClientHeight/2;
	ClientWidth=ClientHeight*1.5;
	Left=Game->Left+(Game->ClientWidth-ClientWidth)/2;
	Top=Game->Top+Game->ClientHeight/4;
	DoubleBuffered=true;
	Caption="Конец уровня";
	BorderStyle=bsNone;
	//BorderIcons>>biMaximize>>biMinimize;
	Color=clCream;
	OnClose=FormClose;
	Label->Parent=this;
	Label->Font->Height=Height/10;
	Label->Font->Name="Amatic SC Bold";
	Label->Caption="Уровень пройден!";
	Label->AutoSize=true;
	Label->Top=(Label->Height)/2;
	Label->Left=(ClientWidth-Label->Width)/2;
	Continue->ObjectPicture->Height=ClientHeight*0.2;
	Continue->ObjectPicture->Width=Continue->ObjectPicture->Height;
	Continue->ObjectPicture->Left=(ClientWidth-Continue->ObjectPicture->Width*3)/4;
	Continue->ObjectPicture->Top=ClientHeight-Continue->ObjectPicture->Height*2;
	Continue->ObjectPicture->OnClick=ContinueClick;
	PlayAgain->ObjectPicture->Height=ClientHeight*0.2;
	PlayAgain->ObjectPicture->Width=PlayAgain->ObjectPicture->Height;
	PlayAgain->ObjectPicture->Left=(ClientWidth-PlayAgain->ObjectPicture->Width*3)/4*2+Continue->ObjectPicture->Width;
	PlayAgain->ObjectPicture->Top=ClientHeight-PlayAgain->ObjectPicture->Height*2;
	PlayAgain->ObjectPicture->OnClick=PlayAgainClick;
	BackToMM->ObjectPicture->Height=ClientHeight*0.2;
	BackToMM->ObjectPicture->Width=BackToMM->ObjectPicture->Height;
	BackToMM->ObjectPicture->Left=(ClientWidth-BackToMM->ObjectPicture->Width*3)/4*3+Continue->ObjectPicture->Width+PlayAgain->ObjectPicture->Width;
	BackToMM->ObjectPicture->Top=ClientHeight-BackToMM->ObjectPicture->Height*2;
	BackToMM->ObjectPicture->OnClick=BackToMMClick;
	Fon->Parent=this;
	Fon->Stretch=true;
	Fon->Picture->LoadFromFile("../../img/fon/MenuFon/1.png");
	Fon->SendToBack();
	Fon->Width=ClientWidth;
	Fon->Height=ClientHeight;
	Fon->Left=0;
	Fon->Top=0;
    Pict->Parent=this;
	Pict->Stretch=true;
	Pict->Picture->LoadFromFile("../../img/characters/adventure_girl/Idle (1).png");
	Pict->Height=ClientHeight/2.5;
	Pict->Width=ClientWidth/2.5;
	Pict->Left=(ClientWidth-Pict->Width)/2;
	Pict->Top=(ClientHeight-Pict->Height)/2;
	}
	__fastcall MGameEnd::~MGameEnd()
	{
		 delete Fon;
		 delete Pict;
		 delete PlayAgain;
		 delete BackToMM;
		 delete Continue;
		 delete Label;
	}
//---------------------------------------------------------------------------
	void __fastcall MSettings::FormClose(TObject *Sender, TCloseAction &Action){ModalResult=1; Release();}
	void __fastcall MSettings::FScreenClick(TObject *Sender)
	{
	if(FScreen->Checked)
	{
	FSize->Enabled=false;
    }
	else
	{
	FSize->Enabled=true;
    }
	}
	void __fastcall MSettings::SCodeButtonClick(TObject *Sender)
	{
	if(SCode->Text=="NGGYU")
    Level=NL;
	}
	void __fastcall MSettings::SaveClick(TObject *Sender)
	{
	if(FScreen->Checked)
	FullScreen=1;
	else FullScreen=0;
	std::wstring ws=FSize->Text.c_str();
	string s(ws.begin(),ws.end());
	if(s.find_first_not_of("0123456789,")==string::npos&&s.find(",")==s.rfind(",")&&StrToFloat(FSize->Text)>=0.3&&StrToFloat(FSize->Text)<=1)
	FormSize=StrToFloat(FSize->Text);
	else
	{
	FSize->Text=FloatToStr(FormSize);
	ShowMessage("Поле \"Размер формы\" может принимать только действительные значения от 0,3 до 1");
    }
	fout.close();
	fout.open("../../files/Settings.txt");
	fout <<FullScreen<<endl<<FormSize<<endl<<Level;
	fout.close();
	fout.open("../../files/Output.txt");
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
	}
	void __fastcall MSettings::BackToMMClick(TObject *Sender)
	{
	Close();
	}
	void __fastcall MSettings::resetClick(TObject *Sender)
	{
	Level=0;
    }
	__fastcall MSettings::MSettings(System::Classes::TComponent* AOwner) : TForm(AOwner, 1)
	{
	Fon=new TImage(this);
	FScreen=new TCheckBox(this);
	FSize=new TLabeledEdit(this);
	SCode=new TEdit(this);
	SCodeButton=new TButton(this);
	reset=new TButton(this);
	Save=new TButton(this);
	BackToMM=new TButton(this);
	ClientHeight=1080*0.7/2;
	//ClientWidth=Game->ClientWidth/2;
	ClientWidth=ClientHeight*1.5;
	Left=(Screen->Width-ClientWidth)/2;
	Top=(Screen->Height-ClientHeight)/2;
	DoubleBuffered=true;
	Caption="Настройки";
	BorderStyle=bsNone;
	//BorderIcons>>biMaximize>>biMinimize;
	//Color=clCream;
	OnClose=FormClose;
	FScreen->Parent=this;
	FSize->Parent=this;
	SCode->Parent=this;
	reset->Parent=this;
	SCodeButton->Parent=this;
	Save->Parent=this;
	BackToMM->Parent=this;
	FScreen->Caption="Полноэкранный режим";
	FScreen->Checked=FullScreen;
	FScreen->Width=Width/2;
	FScreen->Left=(Width-FScreen->Width)/2;
	FScreen->Height=Height/15;
	FScreen->Top=FScreen->Height*2;
	FScreen->OnClick=FScreenClick;
	if(FullScreen)
	FSize->Enabled=false;
	FSize->EditLabel->Caption="Размер формы";
	FSize->Text=FloatToStr(FormSize);
	FSize->Width=Width/2;
	FSize->Left=(Width-FSize->Width)/2;
	FSize->Height=Height/9;
	FSize->Top=FScreen->Height*2+FSize->Height*2;
	//FSize->OnClick=FSizeClick;
	SCodeButton->Caption="Ввести код";
	SCodeButton->Width=Width/4;
	SCodeButton->Left=(SCodeButton->Width*2)*2/3+SCodeButton->Width;
	SCodeButton->Height=Height/9;
	SCodeButton->Top=FScreen->Height*2+FSize->Height*2+SCodeButton->Height;
	SCodeButton->OnClick=SCodeButtonClick;
	SCode->Text="";
	SCode->Width=Width/4;
	SCode->Left=(SCodeButton->Width*2)/3;
	SCode->Top=SCodeButton->Top+(SCodeButton->Height-SCode->Height)/2;
	reset->Caption="Сброс";
	reset->Width=Width/5;
	reset->Left=(Width-reset->Width)/2;;
	reset->Height=Height/9;
	reset->Top=FScreen->Height*2+FSize->Height*2+SCodeButton->Height*2.5;
	reset->OnClick=resetClick;
	Save->Caption="Сохранить";
	Save->Width=ClientWidth*0.3;
	Save->Height=ClientHeight*0.15;
	Save->Left=(ClientWidth-Save->Width*2)/3;
	Save->Top=ClientHeight-Save->Height*3/2;
	Save->OnClick=SaveClick;
	BackToMM->Caption="Назад";
	BackToMM->Width=ClientWidth*0.3;
	BackToMM->Height=ClientHeight*0.15;
	BackToMM->Left=(ClientWidth-BackToMM->Width*2)*2/3+Save->Width;
	BackToMM->Top=ClientHeight-BackToMM->Height*3/2;
	BackToMM->OnClick=BackToMMClick;
	Fon->Parent=this;
	Fon->Stretch=true;
	Fon->Picture->LoadFromFile("../../img/fon/MenuFon/1.png");
	Fon->SendToBack();
	Fon->Width=ClientWidth;
	Fon->Left=0;
	Fon->Height=ClientHeight;
	Fon->Top=0;
	}
	__fastcall MSettings::~MSettings()
	{
		 delete Fon;
		 delete FScreen;
		 delete FSize;
		 delete SCode;
		 delete SCodeButton;
		 delete Save;
		 delete BackToMM;
		 delete reset;
	}
//----------------------------------------