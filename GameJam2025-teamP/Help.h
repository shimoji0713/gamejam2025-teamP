#pragma once
#include "AbstractScene.h"

class Help :public AbstractScene
{
public:
    int help_image;

    int draw_image;

    int image;

    int help_bgm;

    int help_se;
    
private:

public:
    // コンストラクタ
    Help();

    //デストラクタ
    ~Help();

    //シーンの更新処理を行う
    AbstractScene* Update() override;

    //シーンの描画処理を行う
    void Draw() const override;
};

