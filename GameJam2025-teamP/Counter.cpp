#include"DxLib.h"

#include "Counter.h"
#include "PadInput.h"

Counter::Counter()
{
	b_count = 0;

	value_decrease_count = 0;

	counter_time = 0;

}


Counter::~Counter()
{
}


void Counter::Update()
{
	//制限時間処理
	if (counter_time <= 3000) {

		PushButton();

		counter_time++;
	}

	////一定時間経過で値を減少させる
	//if (value_decrease_count >= 50) {
	//
	//	if (b_count != 0) {
	//		b_count -= 2;
	//	}
	//	value_decrease_count = 0;
	//}
	//else {
	//	value_decrease_count++;
	//}

}


void Counter::Draw() const 
{
	DrawFormatString(0, 110, 0xffffff, "%d", b_count);
	DrawFormatString(0, 130, 0xffffff, "%d", counter_time);
	DrawFormatString(0, 150, 0xffffff, "%d", value_decrease_count);

	//DrawBox(300, 200, 600, 240, 0x0000ff, true);
	DrawBox(300,200,600,240,0xffffff,false);

}

// 現在のカウント値を取得
int Counter::GetCount()
{
	return b_count;
}

// Bボタンが押されたらカウントを増加
void Counter::PushButton()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		b_count+=4;
	}
}
