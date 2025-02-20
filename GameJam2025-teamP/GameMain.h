#pragma once
#include "AbstractScene.h"

class GameMain:
	public AbstractScene
{
public:

private:


public:
    // コンストラクタ
    GameMain();

    //デストラクタ
    ~GameMain();

    //シーンの更新処理を行う
    AbstractScene* Update() override;

    //シーンの描画処理を行う
    void Draw() const override;
};

