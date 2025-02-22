#pragma once


class Angle
{
private:

    int angle_image;        //角度ゲージの画像
    int target_image;       //ターゲットの画像


    int angle;  //角度

    int change_angle;   //角度の変化

    int angle_speed;     //角度変化の速さ

    int speed_count;

    float Image_angle;    //画像の回転

    bool inversion_flg;  //反転フラグ


    int time_count;     //制限時間カウント

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

