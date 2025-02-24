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

Title::Title()
{
	title_image = LoadGraph("Resource/image/IMG_2119.JPG");
	cursor_image = LoadGraph("Resource/image/IMG_cursor.png");
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
	DrawRotaGraph(0, 0, 3.0, 0.0, title_image, TRUE);
	DrawRotaGraph(250, cursor_y, 0.1, 0.0, cursor_image, TRUE);

	DrawFormatString(320, 100, GetColor(255, 0, 0), "チャージバット");
	DrawFormatString(320, 230, GetColor(255, 255, 255), "スタート");
	DrawFormatString(320, 290, GetColor(255, 255, 255), "ランキング");
	DrawFormatString(320, 350, GetColor(255, 255, 255), "ヘルプ");
	DrawFormatString(320, 410, GetColor(255, 255, 255), "エンド");
}
