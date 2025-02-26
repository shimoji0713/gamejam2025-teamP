#pragma once
#include "AbstractScene.h"

class End :public AbstractScene
{
public:

private:
    int end;
    int endimage;
    int count;
public:
    // コンストラクタ
    End();

    //デストラクタ
    ~End();

    //シーンの更新処理を行う
    AbstractScene* Update() override;

    //シーンの描画処理を行う
    void Draw() const override;
};

