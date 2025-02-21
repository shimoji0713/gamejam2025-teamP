#pragma once
#include "PadInput.h"

//ボタン連打クラス
class Counter
{
private:
	int b_count;  //連打したボタンの回数

private:
	//自クラスのポインタ（実体をアドレスの先で保有）
	static Counter* instance;

	Counter();  //インストラクタ
	void Update();  //更新処理
	void Draw();  //描画処理

	int GetCount();  //カウントの回数を取得
	void ResetCount();  //カウントのリセット
	void PushButton();  //Bボタンを押したら、カウントを+1にする

};

