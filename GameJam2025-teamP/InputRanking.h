#pragma once
#include "AbstractScene.h"
#include "Ranking.h"
#include "DxLib.h"

/// <summary>
/// ランキングの名前入力シーン
/// </summary>
class InputRanking : public AbstractScene
{
private:
    Ranking ranking;  // ランキングデータ管理用
    Ranking::RANKING_DATA rankingData[5];  // ランキングのデータ

    int score;  // プレイヤーのスコア
    std::string name;  // プレイヤーの入力した名前

    POINT cursorPoint;  // キーボード入力用のカーソル位置
    // 仮想キーボードのキー配置
    const char keyboard[5][14] = {
        "ABCDEFGHIJKLM",
        "NOPQRSTUVWXYZ",
        "abcdefghijklm",
        "nopqrstuvwxyz",
        "0123456789<"
    };

public:
    /// <summary>
    /// コンストラクタ (名前入力の初期化)
    /// </summary>
    InputRanking();

    /// <summary>
    /// 描画処理 (ランキングの名前入力画面を描画)
    /// </summary>
    virtual void Draw() const override;

    /// <summary>
    /// 更新処理 (入力を処理して次のシーンに移行するか判断)
    /// </summary>
    virtual AbstractScene* Update() override;
};
