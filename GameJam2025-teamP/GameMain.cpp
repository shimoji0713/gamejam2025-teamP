#include "DxLib.h"
#include <math.h>
#include "GameMain.h"
#include "PadInput.h"


GameMain::GameMain()
{
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{

	return this;
}

void GameMain::Draw() const
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		DrawBox(-1, -1, 1280, 720, 0xffffff, TRUE);
	}
	

	//DrawBox(45,45,45+50,45+50,0x000000,true);
}
