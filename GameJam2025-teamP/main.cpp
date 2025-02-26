#include"DxLib.h"
//#include"Define.h"
#include"SceneManager.h"
//#include"FpsController.h"
#include"Title.h"
#include"PadInput.h"
#include"GameMain.h"

#define FRAMERATE 60.0		//フレームレート（1秒間の描画回数）
#define SCREEN_HEIGHT 480	// 画面の高さ
#define SCREEN_WIDTH 640	// 画面の幅
#define REFRESHRATE 32		// リフレッシュレート
int bgm;

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("GameJam2025-teamP");		// ウィンドウのタイトルを設定

	ChangeWindowMode(TRUE);		//ウィンドウモードで実行

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, REFRESHRATE);	//画面サイズとリフレッシュレートを設定

	if (DxLib_Init() == -1) return -1;	//DxLib の初期化（失敗した場合はエラーコード -1 を返して終了）

	SetDrawScreen(DX_SCREEN_BACK);	//描画先を裏画面に設定（ダブルバッファリング）

	SceneManager* sceneMng;		// シーンマネージャーのポインタ

	try
	{
		// 初期シーンとして GameMain を設定
		sceneMng = new SceneManager((AbstractScene*)new Title());

	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);
		//エラーログファイルを開く
		fopen_s(&fp, "ErrLog.txt", "a");
		//エラーメッセージを書き込む
		fprintf_s(fp, "%02d�N %02d�� %02d�� %02d�� %02d�� %02d�b : %s������܂���B\n", data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);

		return 0;
	}
	//FpsController FPSC(FRAMERATE, 800);

	bgm = LoadSoundMem("Resource/sound/bgm/small-yakyuu-no-veteran.mp3");
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);

	/***********************************************
	 * メインループ（ゲームが動作する間ループを繰り返す）
	 ***********************************************/
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr)) {

		ClearDrawScreen();		//画面をクリア
		PAD_INPUT::UpdateKey();	// 入力情報の更新（キーやボタンの状態を取得）
		sceneMng->Draw();		// シーンの描画処理
		/*	FPSC.All();
			FPSC.Disp();*/
			//�����I��

		// ゲーム終了処理（コントローラーのBACKボタンが押されたらループを抜ける）
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		ScreenFlip();			// 裏画面を表画面に反映（ダブルバッファリング）
	}
	return 0;
}