#pragma once

class AbstractScene
{
public:
	//デストラクタ
	virtual ~AbstractScene() {};

	//シーンの更新処理
	virtual AbstractScene* Update() = 0;

	//シーンの描画処理
	virtual void Draw() const = 0;

};
