#include "DxLib.h"
#include <math.h>
#include "GameMain.h"
#include "PadInput.h"


GameMain::GameMain()
{
	angle = new Angle;

	timingpress = new TimingPress;

	progress = 0;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	switch (progress)
	{
	//開始合図
	case(0):
		
		break;

	//連打
	case(1):

		break;

	//角度
	case(2):
		angle->Update();
		break;

	//目押し
	case(3):
		timingpress->Update();
		break;

	default:
		break;
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		progress++;
	}

	return this;
}

void GameMain::Draw() const
{
	/*if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		DrawBox(-1, -1, 1280, 720, 0xffffff, TRUE);
	}*/
	
	switch (progress)
	{
		//開始合図
	case(0):
		DrawFormatString(0, 0, 0xffffff, "kaisi");
		break;

		//連打
	case(1):
		DrawFormatString(0, 0, 0xffffff, "rennda");
		break;

		//角度
	case(2):
		DrawFormatString(0, 0, 0xffffff, "kakudo");

		angle->Draw();
		break;

		//目押し
	case(3):
		DrawFormatString(0, 0, 0xffffff, "meosi");

		timingpress->Draw();
		break;
	default:
		break;
	}
}
