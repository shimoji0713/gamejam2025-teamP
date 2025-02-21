#include "Counter.h"
#include "PadInput.h"

//
Counter* Counter::instance = nullptr;

//コンストラクタ
Counter::Counter() : 
	b_count(0)
{

}

//更新処理
void Counter::Update()
{
	PushButton();
}

//描画処理
void Counter::Draw()
{
	printf("%d", b_count);
}

//カウンタをリセット
void Counter::ResetCount()
{
	b_count = 0;
}

//回数を取得
int Counter::GetCount()
{
	return b_count;
}

//Bボタンを押したらカウントを+1にする
void Counter::PushButton()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		b_count++;
	}
}