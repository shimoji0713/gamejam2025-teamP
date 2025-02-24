#pragma once
#include "AbstractScene.h"

#include"Angle.h"
#include"TimingPress.h"
#include"Player.h"

class GameMain: public AbstractScene
{
private:
    Angle* angle;

    TimingPress* timingpress;

    int progress;       //ゲームの進行度

    Player* player;

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

