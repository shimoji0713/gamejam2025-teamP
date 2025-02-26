#include "Help.h"
#include"DxLib.h"
#include"PadInput.h"
#include"Title.h"

Help::Help()
{
	help_image= LoadGraph("Resource/image/help.PNG");
	image = LoadGraph("Resource/image/title.JPG");
	draw_image = LoadGraph("Resource/image/help2.PNG");

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
	DrawRotaGraph(320, 240, 1.5, 0.0, image, TRUE);
	DrawBox(10,10,630,470,0xffffff,TRUE);
	DrawRotaGraph(320, 240, 0.9, 0.0, help_image, TRUE);
	DrawRotaGraph(450, 450, 0.2, 0.0, draw_image, TRUE);
}
