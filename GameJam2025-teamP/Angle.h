#pragma once


class Angle
{
private:
    int angle;  //角度

    int change_angle;   //角度の変化

    int inversion_flg;  //反転フラグ

public:
    // コンストラクタ
    Angle();

    //デストラクタ
    ~Angle();

    //シーンの更新処理を行う
    void Update();

    //シーンの描画処理を行う
    void Draw() const;
};

