#include"DxLib.h"
#include "Result.h"

#include"PadInput.h"

Result::Result()
{
	counter_score = 0.0f;	

	angle_score = 0.0f;	

	timing_score = 0.0f;

	final_score = 0;
}

Result::~Result()
{
}

void Result::Update()
{
	counter_score = counter_score * 10;

	AngleScoreCalculation();

	TimingScoreCalculation();

	final_score = (int)counter_score + (int)angle_score + (int)timing_score;
	
}

void Result::Draw() const
{
	DrawFormatString(0, 110, 0xffffff, "%f", counter_score);
	DrawFormatString(0, 130, 0xffffff, "%f", angle_score);
	DrawFormatString(0, 150, 0xffffff, "%f", timing_score);
	DrawFormatString(0, 170, 0xffffff, "%d", final_score);
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
		timing_score = - 1000 * var;
	}
	else
	{
		var = timing_score / 100;
		timing_score = 1000 * var;
	}

}
