#pragma once
#include "AbstractScene.h"

#include"Counter.h"
#include"Angle.h"
#include"TimingPress.h"
#include"Result.h"
#include"Player.h"

class GameMain: public AbstractScene
{
private:
    Counter* counter;

    Angle* angle;

    TimingPress* timingpress;

    Result* result;

    int progress;       //ゲームの進行度

    Player* player;

    int background_image;   //背景画像

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

