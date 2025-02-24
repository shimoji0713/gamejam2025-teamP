#include "DxLib.h"
#include "TimingPress.h"

#include"PadInput.h"


TimingPress::TimingPress()
{
	timing_score = 0;

	change_timing = 0;

	timing_speed = 1;

	speed_count = 0;

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

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		timing_score = change_timing;
	}

}

void TimingPress::Draw() const
{
	//デバック用表示
	DrawFormatString(0, 110, 0xffffff, "%d", change_timing);
	DrawFormatString(0, 130, 0xffffff, "%d", timing_score);

}
