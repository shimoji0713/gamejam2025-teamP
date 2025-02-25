#include "DxLib.h"
#include <math.h>
#include "GameMain.h"
#include "PadInput.h"


GameMain::GameMain()
{
	counter = new Counter;

	angle = new Angle;

	timingpress = new TimingPress;

	result = new Result;

	progress = 4;
}

GameMain::~GameMain()
{
	delete counter;
	delete angle;
	delete timingpress;
	delete result;
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
		counter->Update();
		break;

	//角度
	case(2):
		angle->Update();
		break;

	//目押し
	case(3):
		timingpress->Update();
		break;

	case(4):
		result->SetCounterScore(counter->GetCount());
		result->SetAngleScore(angle->GetAngle());
		result->SetTimingScore(timingpress->GetTimingScore());
		result->Update();
	default:
		break;
	}


	/*if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		progress++;
	}*/

	return this;
}

void GameMain::Draw() const
{
	
	switch (progress)
	{
		//開始合図
	case(0):
		DrawFormatString(0, 0, 0xffffff, "kaisi");
		break;

		//連打
	case(1):
		DrawFormatString(0, 0, 0xffffff, "rennda");

		counter->Draw();
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
	case(4):
		DrawFormatString(0, 0, 0xffffff, "result");

		result->Draw();
		break;
	default:
		break;
	}

}
