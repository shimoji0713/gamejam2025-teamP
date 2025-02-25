
#pragma once
class Player
{
private:
	int anim[7];
	int image;
	int animation_cont;
	float animation_time;

public:
	Player();
	~Player();

	void Initialize(); //初期化処理
	void Update(); //更新処理
	void Draw();//描画処理
	void Finalize();//終了処理

	/// <summary>

private:
	
	int move_animation;  //アニメーション画像
	// 移動アニメーションの順番
	const int animation_num[7] = { 0, 1, 2, 3, 4, 5, 6,};
	int background_image;		//背景画像

	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void AnimationControl();

	
};

