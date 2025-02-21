#pragma once
#include "PadInput.h"

//ボタン連打クラス
class Counter
{
	int b_count;  //連打したボタンの回数

	Counter();
	void Update();
	void Draw();

	int GetCount();
	void ResetCount();
	void PushButton();
};

