#include"DxLib.h"

#include "Counter.h"
#include "PadInput.h"

Counter::Counter() :
	 animation_count()
	,anim()
	,image()

{
	b_count = 0;

	value_decrease_count = 0;

	counter_time = 0;
}

Counter::~Counter()
{

}

//初期化処理
void Counter::Initialize()
{
	LoadDivGraph("C:\\PG\\gamejam2025-teamP\\GameJam2025-teamP\\Resource\\image\\power_battar-.png", 4, 4, 1, 347, 362, anim);

	image = anim[0];
}

//更新処理
void Counter::Update()
{
	//制限時間処理
	if (counter_time <= 3000) {

		PushButton();

		counter_time++;

		Counter_Animation();

		Draw();
	}
}

//描画処理
void Counter::Draw() const
{
	DrawRotaGraph(500, 300, 1.0, 0.0, image, true);

	DrawFormatString(0, 110, 0xffffff, "%d", b_count);
	DrawFormatString(0, 130, 0xffffff, "%d", counter_time);
	DrawFormatString(0, 150, 0xffffff, "%d", value_decrease_count);

	//DrawBox(300, 200, 600, 240, 0x0000ff, true);
	//ゲージ枠組み
	DrawBox(300, 200, 600, 240, 0xffffff, false);
	//ゲージ本体
	DrawBox(300, 200, 300 + b_count, 240, 0xffff00, true);

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
		b_count++;
	
	}
}

//ボタンを押した回数によってアニメーションを変える
void Counter::Counter_Animation()
{
	if (b_count >= 200)
	{
		animation_count += animation_count;
	}

	if (b_count >= 250)
	{
		animation_count += animation_count;
	}

	if (b_count >= 270)
	{
		animation_count += animation_count;
	}


	image = anim[animation_count];
}