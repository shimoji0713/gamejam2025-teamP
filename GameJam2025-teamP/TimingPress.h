#pragma once

class TimingPress
{
private:

    int timing_score;       //目押しのタイミング

    int change_timing;      // タイミングの変化

    int timing_speed;       //タイミング変化の速さ

    int speed_count;       

public:
    // コンストラクタ
    TimingPress();

    //デストラクタ
    ~TimingPress();

    //シーンの更新処理を行う
    void Update();

    //シーンの描画処理を行う
    void Draw() const;

    //タイミングのスコアを獲得
    int GetTimingScore();

};

