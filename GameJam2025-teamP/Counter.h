#pragma once
#include "PadInput.h"

//�{�^���A�ŃN���X
class Counter
{
	int b_count;  //�A�ł����{�^���̉�

	Counter();
	void Update();
	void Draw();

	int GetCount();
	void ResetCount();
	void PushButton();
};

