#pragma once
#include "AbstractScene.h"

class Result :public AbstractScene
{
private:
	double counter_score;	//連打のスコア

	double angle_score;	//角度のスコア

	double timing_score;	//目押しのスコア

	int final_score;	//最終スコア

	int number_images[10];

	int anime_images[10];

	int result_se;

	int animation_cont;

	int fram;

	bool anime_endFlg;

public:
	// コンストラクタ
	Result();

	//デストラクタ
	~Result();

	//シーンの更新処理を行う
	AbstractScene* Update() override;

	//シーンの描画処理を行う
	void Draw() const;

	//連打スコアの値設定
	void SetCounterScore(int count_s);

	//角度スコアの値設定
	void SetAngleScore(int angle_s);

	//目押しスコアの値設定
	void SetTimingScore(int timing_s);

	//角度スコアの計算
	void AngleScoreCalculation();

	//目押しスコアの計算
	void TimingScoreCalculation();

	bool GetAnime_endFlg();

	int GetScore();
};

