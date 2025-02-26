#pragma once
#include "AbstractScene.h"

class Title :public AbstractScene
{
public:

    int title_image;

    int title_name;

    int select_number;

    int cursor_image;

    int cursor_y;

    int bgm;

    int title_se;

private:

public:
    // コンストラクタ
    Title();

    //デストラクタ
    ~Title();

    //シーンの更新処理を行う
    AbstractScene* Update() override;

    //シーンの描画処理を行う
    void Draw() const override;
};

