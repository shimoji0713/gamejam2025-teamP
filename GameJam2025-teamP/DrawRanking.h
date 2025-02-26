#pragma once
#include "AbstractScene.h"
#include "Ranking.h"

/// <summary>
/// ランキング表示シーン
/// </summary>
class DrawRanking : public AbstractScene
{
private:
    Ranking ranking;  // ランキングデータ管理用
    Ranking::RANKING_DATA rankingData[5];  // 5つのランキングデータ

    int image;      // 背景画像
    int bgm;        // BGM
    int TitleSE2;   // タイトル遷移時のSE
    int DesideSE;   // 決定音SE

public:
    /// <summary>
    /// コンストラクタ (ランキングデータの読み込み)
    /// </summary>
    DrawRanking();

    /// <summary>
    /// ランキング画面を描画
    /// </summary>
    virtual void Draw() const override;

    /// <summary>
    /// 入力処理を受け付け、次のシーンに遷移するか判定
    /// </summary>
    virtual AbstractScene* Update() override;
};
