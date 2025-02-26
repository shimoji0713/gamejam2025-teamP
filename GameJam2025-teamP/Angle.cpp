#include "DxLib.h"
#include "Angle.h"

#include"PadInput.h"

#define PI 3.1415f

Angle::Angle()
{
    //画像の読み込み
    angle_image = LoadGraph("Resource/image/AngleImage/ougi.png");
    target_image= LoadGraph("Resource/image/AngleImage/target.png");

    angle = 0;

    change_angle = 0;

    angle_speed =0;     //ここで速さを変更する

    speed_count = 0;

    Image_angle = 0.0;

    inversion_flg = false;

    time_count = 0;


    end_flg = false;

    wait_count = 0;
}

Angle::~Angle()
{
}

void Angle::Update()
{
    if (angle == 0) {

        //角度変化の速さ調整
        if (angle_speed <= speed_count) {

            //change_angleを0から90まで変化した後、また0まで変化させる
            if (inversion_flg == true) {
                change_angle--;
            }
            else {
                change_angle++;
            }

            Image_angle = (change_angle + 270) * PI / 180;

            if (change_angle >= 90) { inversion_flg = true; }
            if (change_angle <= 0) { inversion_flg = false; }

            speed_count = 0;
        }
        else {
            speed_count++;
        }

    }
    else
    {
        
        wait_count++;

        if (wait_count > 30) {
            end_flg = true;
        }
    }

    if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
        angle = 90-change_angle;
    }



}

void Angle::Draw() const
{

    //デバック用表示
    DrawFormatString(0, 110, 0xffffff, "%d", change_angle);
    DrawFormatString(0, 130, 0xffffff, "%d", angle);
    DrawFormatString(0, 150, 0xffffff, "%d", time_count);

    DrawRotaGraph(370, 190 , 1, 0, angle_image, TRUE);

    DrawRotaGraph2(370-120, 190+120, 0, 12, 1, Image_angle, target_image, TRUE);
    
}

int Angle::GetAngle()
{
    return angle;
}

bool Angle::GetEndFlg()
{
    return end_flg;
}
