#include"DxLib.h"
#include "Result.h"
#include"Title.h"

#include"PadInput.h"

Result::Result()
{
	counter_score = 0.0f;	

	angle_score = 0.0f;	

	timing_score = 0.0f;

	final_score = 0;

	LoadDivGraph("Resource/image/NUMBER.png", 10, 5, 2, 160, 160, number_images);
	LoadDivGraph("Resource/image/NUMBER.png", 10, 5, 2, 160, 160, anime_images);

	result_se = LoadSoundMem("Resource/sound/se/maou_se_system49.mp3");

	animation_cont = 0;

	fram = 0;

	anime_endFlg = false;
}

Result::~Result()
{
}

AbstractScene* Result::Update()
{
	counter_score = counter_score * 10;

	AngleScoreCalculation();

	TimingScoreCalculation();

	final_score = (int)counter_score + (int)angle_score + (int)timing_score;

	fram++;
	animation_cont++;
	if (animation_cont>10)
	{
		animation_cont = 0;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		anime_endFlg = true;
	}
	return this;
}

void Result::Draw() const
{
	DrawFormatString(0, 110, 0xffffff, "%f", counter_score);
	DrawFormatString(0, 130, 0xffffff, "%f", angle_score);
	DrawFormatString(0, 150, 0xffffff, "%f", timing_score);
	DrawFormatString(0, 170, 0xffffff, "%d", final_score);

	int dt[5] = {
		final_score / 10000 % 10,
		final_score / 1000 % 10,
		final_score / 100 % 100 % 10,
		final_score / 10 % 1000 % 100 % 10,
		final_score / 1 % 10000 % 1000 % 100 % 10
	};

	if (fram<180)
	{
		DrawRotaGraph(250, 240, 2.0, 0.0, anime_images[animation_cont], TRUE);
	}

	if (fram > 180)
	{
		for (int i = 0; i < 5; i++)
		{
			DrawRotaGraph((i * 50) + 200, 240, 0.5, 0.0, number_images[dt[i]], TRUE);
		}
	}
	
}

void Result::SetCounterScore(int counter_s)
{
	counter_score = counter_s;
}

void Result::SetAngleScore(int angle_s)
{
	angle_score = angle_s;
}

void Result::SetTimingScore(int timing_s)
{
	timing_score = timing_s;
}

//角度スコアの計算
void Result::AngleScoreCalculation()
{
	double var;
	var = angle_score / 45.0f;
	if (var > 1) {
		var = var - 1;
	}

	angle_score = 1000 * var;

}

void Result::TimingScoreCalculation()
{
	double var;

	if (timing_score > 100) {
		var = (timing_score - 100) / 100;
		timing_score = - 500 * var;
	}
	else
	{
		var = timing_score / 100;
		timing_score = 1000 * var;
	}

}

bool Result::GetAnime_endFlg()
{
	return anime_endFlg;
}

int Result::GetScore()
{
	return final_score;
}
