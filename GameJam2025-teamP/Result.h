#pragma once

class Result
{
private:
	double counter_score;	//連打のスコア

	double angle_score;	//角度のスコア

	double timing_score;	//目押しのスコア

	int final_score;	//最終スコア

public:
	// コンストラクタ
	Result();

	//デストラクタ
	~Result();

	//シーンの更新処理を行う
	void Update();

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

};

