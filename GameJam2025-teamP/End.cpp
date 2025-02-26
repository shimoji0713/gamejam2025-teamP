#include "End.h"
#include "DxLib.h"


End::End()
{
	end = LoadSoundMem("Resource/sound/se/maou_se_system49.mp3");
	endimage = LoadGraph("Resource/image/end.jpg");

	PlaySoundMem(end, DX_PLAYTYPE_BACK);

	count = 0;
}

End::~End()
{
}

AbstractScene* End::Update()
{
	count++;

	if (count >= 500)
	{
		return nullptr;
	}
	return this;
	
}

void End::Draw() const
{
	DrawRotaGraph(350, 240, 0.6, 0.0, endimage, TRUE);
	
}
