#pragma once
#include "PadInput.h"

//// ボタン入力をカウントするクラス
class Counter
{
private:
	int b_count;			// ボタンが押された回数
	int b_lastcount;        //最後に鳴らしたカウント

	int value_decrease_count;		//連打値の減少

	int counter_time;		//時間制限
	int max_counter_time;


private:
	int anim[4];  //プレイヤーのアニメーション
	int image;  //画像
	int ball_image;
	int limit_image;
	int chage_se;  //チャージ音
	int animation_count;  //カウント
	int fontHandle;  //フォント

	int wait_count;

	bool end_flg;       //終了フラグ

public:
	// コンストラクタ
	Counter();

	//デストラクタ
	~Counter();

	//初期化処理
	void Initialize();

	//シーンの更新処理を行う
	void Update();  

	//シーンの描画処理を行う
	void Draw() const;

	int GetCount();  

	void PushButton(); 

	//ボタンを押した回数によってアニメーションを変える
	void Counter_Animation();

	//終了確認
	bool GetEndFlg();
};

