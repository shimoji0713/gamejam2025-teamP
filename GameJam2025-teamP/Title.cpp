#include "Title.h"
#include"DxLib.h"
#include"PadInput.h"

#include"GameMain.h"

#include"DrawRanking.h"
#include"InputRanking.h"

#include"Help.h"
#include"End.h"

#include<math.h>

Title::Title()
{
	title_image = LoadGraph("Resource/image/title.JPG");
	title_name = LoadGraph("Resource/image/title_name.PNG");
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

	cursor_y = 220 + (select_number * 60);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		PlaySoundMem(title_se,DX_PLAYTYPE_NORMAL);

		switch (select_number)
		{
		case 0:
			return new GameMain;
		case 1:
			return new DrawRanking;
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
	DrawRotaGraph(320, 100, 1.0, 0.0, title_name, TRUE);

	SetFontSize(40);
	DrawFormatString(320, 200, GetColor(255, 255, 255), "START");
	DrawFormatString(320, 260, GetColor(255, 255, 255), "RANKING");
	DrawFormatString(320, 320, GetColor(255, 255, 255), "HELP");
	DrawFormatString(320, 380, GetColor(255, 255, 255), "END");
}
