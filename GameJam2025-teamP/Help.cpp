#include "Help.h"
#include"DxLib.h"
#include"PadInput.h"
#include"Title.h"

int help_se;

Help::Help()
{
	help_se = LoadSoundMem("Resource/sound/se/maou_se_system49.mp3");
}

Help::~Help()
{
}

AbstractScene* Help::Update()
{
	return nullptr;

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		PlaySoundMem(help_se, DX_PLAYTYPE_NORMAL);

		return new Title;
	}
	return this;
}

void Help::Draw() const
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Bボタンを押してタイトルに戻る");
	DrawFormatString(320, 100, GetColor(255, 255, 255), "Bボタンのみ使用");
	DrawFormatString(320, 200, GetColor(255, 255, 255), "とにかく連打");
	DrawFormatString(320, 300, GetColor(255, 255, 255), "赤いところで止める");
	DrawFormatString(320, 400, GetColor(255, 255, 255), "行き過ぎないように止める");
}
