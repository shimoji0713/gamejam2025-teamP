#include "DxLib.h"
#include "TimingPress.h"

#include"PadInput.h"


TimingPress::TimingPress()
{
	timing_score = 0;

	change_timing = 0;

	timing_speed = 0;

	speed_count = 0;

	end_flg = false;

	wait_count = 0;

}

TimingPress::~TimingPress()
{

}

void TimingPress::Update()
{
	if (timing_score == 0) {

		//タイミング変化の速さ調整
		if (timing_speed<=speed_count) {

			//change_timingを0から120まで変化、変化後0に戻す
			if (change_timing >= 120) {
				change_timing = 0;
			}
			else {
				change_timing++;
			}

			speed_count = 0;

		}
		else {
			speed_count++;
		}
	}
	else
	{

		wait_count++;

		if (wait_count > 30) {
			end_flg = true;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		timing_score = change_timing;
	}

}

void TimingPress::Draw() const
{
	//デバック用表示
	DrawFormatString(0, 110, 0xffffff, "%d", change_timing);
	DrawFormatString(0, 130, 0xffffff, "%d", timing_score);

	float a = (float)560 * ((float)change_timing / (float)120);

	DrawBox(40,400,40+a,450,0x00FFFF,TRUE);
	DrawBox(40, 400, 600, 450, 0xffffff, false);

}

int TimingPress::GetTimingScore()
{
	return timing_score;
}

bool TimingPress::GetEndFlg()
{
	return end_flg;
}
