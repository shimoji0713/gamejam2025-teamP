#include "DrawRanking.h"
#include "PadInput.h"
#include "DxLib.h"
#include "GameMain.h"
#include"Title.h"


/// DrawRanking クラスのコンストラクタ
/// ランキングデータを読み込み、ローカル変数に保存する
/// </summary>
DrawRanking::DrawRanking(/*int score スコアを受け取る場合の引数*/) {
    ranking.ReadRanking();  // ランキングデータをファイルから読み込む

    // 読み込んだランキングデータをメンバ変数にコピー
    for (int i = 0; i < 5; i++) {
        rankingData[i] = ranking.GetRankingData(i);
    }

    // 背景画像と決定音のロード (コメントアウトされているが、必要なら復活させる)
    // image = LoadGraph("Resources/images/Ranking_bg.png");
    // DesideSE = LoadSoundMem("Resources/sounds/kettei.mp3");
}


// 更新処理 (ボタン入力のチェック)
// Aボタンが押されたら次のシーンへ遷移する
/// <returns>次のシーンのポインタ (Aボタンが押されていなければ this を返す)</returns>
AbstractScene* DrawRanking::Update() {
    if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == 1) {
        //PlaySoundMem(DesideSE, DX_PLAYTYPE_BACK);  // 決定音を再生

        return new Title();  
    }

    return this;  // シーン遷移がなければ現在のシーンを維持
}

// ランキング画面の描画

void DrawRanking::Draw() const {
    // 背景画像の描画 (コメントアウトされているが、必要なら復活させる)
    // DrawGraph(0, 0, image, TRUE);

    SetFontSize(50);
    DrawString(190, 70, "RANKING", 0xff0000);  // タイトル表示

    SetFontSize(30);
    for (int i = 0; i < 5; i++) {
        // ランキングの順位・名前・スコアを描画
        DrawFormatString(165, 165 + 50 * i, 0xffffff, "%d %4s ", rankingData[i].no, rankingData[i].name.c_str());
        DrawFormatString(305, 165 + 50 * i, 0xffffff, "%5ld", rankingData[i].score);
    }

    // "A PUSH" の表示
    SetFontSize(30);
    DrawString(200, 400, "A  PUSH", 0xff0000);
}
