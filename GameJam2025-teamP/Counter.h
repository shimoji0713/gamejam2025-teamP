#pragma once
#include "PadInput.h"

//// ボタン入力をカウントするクラス
class Counter
{
private:
	int b_count;			// ボタンが押された回数

	int value_decrease_count;		//連打値の減少

	int counter_time;		//時間制限

public:
	// コンストラクタ
	Counter();

	//デストラクタ
	~Counter();

	//シーンの更新処理を行う
	void Update();  

	//シーンの描画処理を行う
	void Draw() const;

	int GetCount();  

	void PushButton(); 

};

