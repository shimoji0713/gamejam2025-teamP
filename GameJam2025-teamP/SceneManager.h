#pragma once
#include"AbstractScene.h"

class SceneManager :
    public AbstractScene
{
private:
    AbstractScene* mScene;  // 現在のシーン
public:

    //コンストラクタ
    SceneManager(AbstractScene* scene) :mScene(scene) {};

    //デストラクタ
    ~SceneManager()
    {
        delete mScene;
    }

    //シーンの更新処理
    AbstractScene* Update() override;

    //シーンの描画処理
    void Draw() const override;
};



