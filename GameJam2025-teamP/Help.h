#pragma once
#include "AbstractScene.h"

class Help :public AbstractScene
{
public:

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

