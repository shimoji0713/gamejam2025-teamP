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
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		PlaySoundMem(help_se, DX_PLAYTYPE_NORMAL);

		return new Title;
	}
	return this;
}

void Help::Draw() const
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "B�{�^��������ă^�C�g���ɖ߂�");
	DrawFormatString(320, 100, GetColor(255, 255, 255), "B�{�^���̂ݎg�p");
	DrawFormatString(320, 200, GetColor(255, 255, 255), "�Ƃɂ����A��");
	DrawFormatString(320, 300, GetColor(255, 255, 255), "�Ԃ��Ƃ���Ŏ~�߂�");
	DrawFormatString(320, 400, GetColor(255, 255, 255), "�s���߂��Ȃ��悤�Ɏ~�߂�");
}
