#include "DxLib.h"
#include <math.h>
#include "GameMain.h"
#include "PadInput.h"

#include"DrawRanking.h"
#include"InputRanking.h"



GameMain::GameMain()
{
	ranking.ReadRanking();

	// 読み込んだランキングデータをメンバ変数にコピー
	for (int i = 0; i < 5; i++) {
		rankingData[i] = ranking.GetRankingData(i);
	}

	counter = new Counter;
	counter->Initialize();

	angle = new Angle;

	timingpress = new TimingPress;

	result = new Result;

	progress = 2;

	player = new Player();
	player->Initialize();

	background_image= LoadGraph("Resource/image/haikei.png");

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

	player->Update(progress);

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

		if (angle->GetEndFlg() == true) {
			progress = progress + 1;
		}
		break;

	//目押し
	case(3):
		timingpress->Update();

		if (timingpress->GetEndFlg() == true) {
			progress = progress + 1;
		}
		break;

	case(4):
		

		if (player->GetAnimationEndflg() == true) {
			result->SetCounterScore(counter->GetCount());
			result->SetAngleScore(angle->GetAngle());
			result->SetTimingScore(timingpress->GetTimingScore());
			result->Update();
			
		}
		


		if(result->GetAnime_endFlg())
		 {
			if(result->GetScore()>rankingData[4].score) {
				return new InputRanking(result->GetScore());
			}else{
				return new DrawRanking();
			}
		 }
		
		


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
	DrawGraph(0,0,background_image,true);
	
	player->Draw();

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
		if (player->GetAnimationEndflg() == true) {
			result->Draw();
		}
		break;
	default:
		break;
	}

}
