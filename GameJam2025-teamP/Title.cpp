#include "Title.h"
#include"DxLib.h"
#include"PadInput.h"

#include"GameMain.h"
#include"Ranking.h"
#include"Help.h"
#include"End.h"

#include<math.h>

int title_image;
int select_number;
int cursor_image;
int cursor_y;

Title::Title()
{
	select_number = 0;
	cursor_y = 0;
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

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		switch (select_number)
		{
		case 0:
			return new GameMain;
		case 1:
			return new Ranking;
		case 2:
			return new Help;
		default:
			return new End;
		}
	}
	return nullptr;
}

void Title::Draw() const
{

}
