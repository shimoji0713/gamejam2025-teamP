#pragma once
#include "AbstractScene.h"

#include"Counter.h"
#include"Angle.h"
#include"TimingPress.h"
#include"Result.h"
#include"Player.h"

#include "Ranking.h"

class GameMain: public AbstractScene
{
private:

    Ranking ranking;  // ランキングデータ管理用
    Ranking::RANKING_DATA rankingData[5];  // 5つのランキングデータ

    Counter* counter;

    Angle* angle;

    TimingPress* timingpress;

    Result* result;

    int progress;       //ゲームの進行度

    Player* player;

    int countdown_time;  //3カウント用

    int background_image;   //背景画像
    int kaisi_image;  //連打開始時の画像
    int count[10];  //カウント用
    int countdown;
    int countdown_image;  //カウント画像用
    int Go_image;

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

