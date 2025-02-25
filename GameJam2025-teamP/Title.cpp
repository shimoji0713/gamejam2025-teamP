#include "Title.h"
#include"DxLib.h"
#include"PadInput.h"

#include"GameMain.h"
#include"Ranking_date.h"
#include"Help.h"
#include"End.h"

#include<math.h>

int title_image;
int select_number;
int cursor_image;
int cursor_y;
int bgm;
int title_se;

Title::Title()
{
	title_image = LoadGraph("Resource/image/title.JPG");
	cursor_image = LoadGraph("Resource/image/cursor.png");

	//bgm = LoadSoundMem("Resource/sound/bgm/small-yakyuu-no-veteran.mp3");
	title_se= LoadSoundMem("Resource/sound/se/maou_se_system49.mp3");

	select_number = 0;
	cursor_y = 240;
}

Title::~Title()
{
}

AbstractScene* Title::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		select_number--;
		if (select_number < 0)
		{
			select_number = 3;
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		select_number++;
		select_number = select_number % 4;
	}

	cursor_y = 240 + (select_number * 60);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		PlaySoundMem(title_se,DX_PLAYTYPE_NORMAL);

		switch (select_number)
		{
		case 0:
			return new GameMain;
		case 1:
			//return new Ranking;
		case 2:
			return new Help;
		default:
			return new End;
		}
	}
	return this;
}

void Title::Draw() const
{
	DrawRotaGraph(320, 240, 1.5, 0.0, title_image, TRUE);
	DrawRotaGraph(250, cursor_y, 0.1, 0.0, cursor_image, TRUE);

	/*SetFontSize();
	SetFontThickness();
	ChangeFont("");
	ChangeFontType();*/
	DrawFormatString(320, 100, GetColor(255, 0, 0), "チャージバット");

	/*SetFontSize();
	SetFontThickness();
	ChangeFont("");
	ChangeFontType();*/
	DrawFormatString(320, 230, GetColor(255, 255, 255), "スタート");
	DrawFormatString(320, 290, GetColor(255, 255, 255), "ランキング");
	DrawFormatString(320, 350, GetColor(255, 255, 255), "ヘルプ");
	DrawFormatString(320, 410, GetColor(255, 255, 255), "エンド");
}
