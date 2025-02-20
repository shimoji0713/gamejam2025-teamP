#include"DxLib.h"
#include"SceneManager.h"

// シーンの更新処理を行う
AbstractScene* SceneManager::Update()
{
	AbstractScene* NextScene;
	try
	{
		// 現在のシーンを更新し、次のシーンを取得
		NextScene = mScene->Update();
	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);

		//エラーログファイルを開く（追記モード）
		fopen_s(&fp, "ErrLog.txt", "a");
		//エラー情報をログに記録
		fprintf_s(fp, "%02d�N %02d�� %02d�� %02d�� %02d�� %02d�b : %s������܂���B\n", data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);

		// シーンの更新に失敗した場合、nullptr を返す
		return nullptr;
	}

	// シーンが変更された場合、古いシーンを削除して新しいシーンに切り替える
	if (NextScene != mScene)
	{
		delete mScene;		// 現在のシーンを解放
		mScene = NextScene;	// 新しいシーンに切り替え
	}

	return mScene;		// 現在のシーン（または新しいシーン）を返す
}

// 現在のシーンを描画する
void SceneManager::Draw() const {
	//現在のシーンの描画処理を実行
	mScene->Draw();
}

