#include "DxLib.h"
#include "Angle.h"

#include"PadInput.h"

Angle::Angle()
{
    angle = 0;

    change_angle = 0;

    inversion_flg = false;

}

Angle::~Angle()
{
}

void Angle::Update()
{
    if (angle == 0) {

        //change_angleを0から90まで変化した後、また0まで変化させる
        if (inversion_flg == true) {
            change_angle--;
        }
        else {
            change_angle++;
        }
        if (change_angle >= 900) { inversion_flg = true; }
        if (change_angle <= 0) { inversion_flg = false; }

    }

    if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
        angle = change_angle;
    }



}

void Angle::Draw() const
{

    DrawFormatString(0, 110, 0xffffff, "%d", change_angle);

    DrawFormatString(0, 130, 0xffffff, "%d", angle);
    
}
