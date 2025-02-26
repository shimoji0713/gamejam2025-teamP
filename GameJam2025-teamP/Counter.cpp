#include"DxLib.h"

#include "Counter.h"
#include "PadInput.h"

Counter::Counter() :
	 animation_count()
	,anim()
	,image()
	,chage_se()

{
	b_count = 0;
	b_lastcount = -1;
	fontHandle = 

	value_decrease_count = 0;

	counter_time = 0;
}

Counter::~Counter()
{

}

//初期化処理
void Counter::Initialize()
{
	LoadDivGraph("C:\\PG\\gamejam2025-teamP\\GameJam2025-teamP\\Resource\\image\\power_battar-image.png", 4, 4, 1, 114, 130, anim);
	chage_se = LoadSoundMem("C:\\PG\\gamejam2025-teamP\\GameJam2025-teamP\\Resource\\sound\\se\\Chage_SE.mp3");

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
	}
}

//描画処理
void Counter::Draw() const
{
	DrawRotaGraph(460, 150, 1.5, 0.0, image, true);

	DrawFormatString(250, 110, 0xffffff, "%d", b_count);
	DrawFormatString(0, 130, 0xffffff, "%d", counter_time);
	DrawFormatString(0, 150, 0xffffff, "%d", value_decrease_count);

	//DrawBox(300, 200, 600, 240, 0x0000ff, true);
	//ゲージ枠組み
	DrawBox(300, 350, 600, 390, 0xffffff, false);
	//ゲージ本体
	DrawBox(300, 350, 300 + b_count, 390, 0xffff00, true);

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

	//カウントが5の倍数の時に一回ずつサウンドを鳴らす
	if (b_count % 5 == 0 && b_count != 0 && b_count != b_lastcount)
	{
		PlaySoundMem(chage_se, DX_PLAYTYPE_BACK);
		b_lastcount = b_count;
	}
}

//ボタンを押した回数によってアニメーションを変える
void Counter::Counter_Animation()
{
	if (b_count >= 20)
	{
		image = anim[1];
	}

	if (b_count >= 30)
	{
		image = anim[2];
	}

	if (b_count >= 40)
	{
		image = anim[3];
	}

}
