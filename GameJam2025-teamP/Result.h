#pragma once
#include"AbstractScene.h"
class Result : public AbstractScene
{
private:



public:
	// コンストラクタ
	Result(int counter,int angle,int timing);

	//デストラクタ
	~Result();

	//シーンの更新処理を行う
	AbstractScene* Update() override;

	//シーンの描画処理を行う
	void Draw() const override;
};

