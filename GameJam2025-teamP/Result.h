#pragma once

class Result
{
private:



public:
	// コンストラクタ
	Result(int counter,int angle,int timing);

	//デストラクタ
	~Result();

	//シーンの更新処理を行う
	void Update();

	//シーンの描画処理を行う
	void Draw() const;
};

