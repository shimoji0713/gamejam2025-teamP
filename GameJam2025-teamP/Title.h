#pragma once
#include "AbstractScene.h"

class Title :public AbstractScene
{
public:

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

