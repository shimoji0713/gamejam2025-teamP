#pragma once

#include "SceneBase.h"
#include"Ranking_date.h"

class RankingDispScene : public SceneBase
{
private:

private:
	int background_image;		//�w�i�摜
	//RankingData* ranking;		//�����L���O���

public:
	RankingDispScene();
	virtual ~RankingDispScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};