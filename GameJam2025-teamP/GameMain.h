#pragma once
#include "AbstractScene.h"

#include"Angle.h"

class GameMain: public AbstractScene
{
private:
    Angle* angle;


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

