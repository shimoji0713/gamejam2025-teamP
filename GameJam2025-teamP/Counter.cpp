#include"DxLib.h"

#include "Counter.h"
#include "PadInput.h"

Counter::Counter() :
	 animation_count()
	,anim()
	,image()
	,ball_image()
	,limit_image()
	,chage_se()

{
	b_count = 0;
	b_lastcount = -1;
	fontHandle = 

	value_decrease_count = 0;

	counter_time = 0;
	max_counter_time = 3000;

	end_flg = false;

	wait_count = 0;
}

Counter::~Counter()
{

}

//初期化処理
void Counter::Initialize()
{
	LoadDivGraph("Resource/image/power_battar-image.png", 4, 4, 1, 114, 130, anim);
	ball_image = LoadGraph("Resource/image/baseball.png");
	limit_image = LoadGraph("Resource/image/limit.png");
	chage_se = LoadSoundMem("Resource/Resource/sound/se/Chage_SE.mp3");

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
	else
	{

		wait_count++;

		if (wait_count > 500) {
			end_flg = true;
		}
	}
}

//描画処理
void Counter::Draw() const
{
	DrawRotaGraph(500, 130, 2, 0.0, image, true);
	DrawRotaGraph(500, 380, 0.5, 0, ball_image, TRUE);

	DrawFormatString(470, 360, 0x000000, "%d", b_count);

	//残り時間のゲージ
	DrawRotaGraph(220, 25, 0.5, 0, limit_image, TRUE);
	DrawBox(300, 10, 600, 40, 0xffffff, false);
	DrawBox(300, 10, 600-counter_time/10, 40, 0x80eeff, true);



	//DrawFormatString(250, 0, 0xffffff, "%d", counter_time);
	//DrawFormatString(0, 150, 0xffffff, "%d", value_decrease_count);

	//DrawBox(300, 200, 600, 240, 0x0000ff, true);
	//ゲージ枠組み
	DrawBox(380, 260, 620, 300, 0xffffff, false);
	//ゲージ本体
	DrawBox(380, 260, 380 + b_count, 300, 0xffff00, true);

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
	if (b_count >= 50)
	{
		image = anim[2];
	}

	if (b_count >= 100)
	{
		image = anim[3];
	}

	if (b_count >= 150)
	{
		image = anim[1];
	}
}

bool Counter::GetEndFlg()
{
	return end_flg;
}
