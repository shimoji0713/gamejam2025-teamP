#pragma once
#include"DxLib.h"

#define BUTTONS 16

//�X�e�B�b�N
struct Stick
{
	short ThumbX;	//横軸の入力値
	short ThumbY;	//縦軸の入力値
};

class PAD_INPUT
{
private:
	static char NowKey[BUTTONS]; //現在のキー入力状態
	static char OldKey[BUTTONS]; //1フレーム前のキー入力状態
	static XINPUT_STATE Input; //パッドの入力情報
	static Stick Rstick; //右スティックの状態
	static Stick Lstick; //左スティックの状態
private:
	//コンストラクタ
	PAD_INPUT() = default;
public:
	//パッド入力の状態を更新する
	static void UpdateKey()
	{
		// パッドの入力状態を取得
		GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);

		// 各ボタンの状態を更新
		for (int i = 0; i < BUTTONS; i++)
		{
			OldKey[i] = NowKey[i];
			NowKey[i] = Input.Buttons[i];
		}

		//右スティックの状態を更新
		Rstick.ThumbX = Input.ThumbRX;
		Rstick.ThumbY = Input.ThumbRY;

		//左スティックの状態を更新
		Lstick.ThumbX = Input.ThumbLX;
		Lstick.ThumbY = Input.ThumbLY;
	}

	//指定したボタンが押された瞬間かどうかを判定
	static bool OnButton(int button)
	{
		bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
		return ret;
	}

	//指定したボタンが離された瞬間かどうかを判定
	static bool OnRelease(int button)
	{
		bool ret = (NowKey[button] == 0 && OldKey[button] == 1);
		return ret;
	}

	//右スティックの状態を取得
	static Stick GetRStick()
	{
		return Rstick;
	}

	//左スティックの状態を取得
	static Stick GetLStick()
	{
		return Lstick;
	}
};

