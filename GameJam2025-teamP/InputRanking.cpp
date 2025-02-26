#include "InputRanking.h"
#include "DrawRanking.h"
#include "PadInput.h"

InputRanking::InputRanking(int final_score) {
	//score = round;
	cursorPoint = { 0, 0 };
	ranking.ReadRanking();
	for (int i = 0; i < 5; i++) {
		rankingData[i] = ranking.GetRankingData(i);
	}

	score = final_score;

	//SelectSE = LoadSoundMem("Resources/sounds/cursorsound.mp3");
	//DesideSE = LoadSoundMem("Resources/sounds/kettei.mp3");
	//BackSE = LoadSoundMem("Resources/sounds/cancel.mp3");

}

AbstractScene* InputRanking::Update() {

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) == 1) {
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
		if (--cursorPoint.y < 0) {
			//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
			if (cursorPoint.x > 10) {
				cursorPoint.y = 3;
			}
			else {
				cursorPoint.y = 4;
			}
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) == 1) {
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
		if (++cursorPoint.y > 3 && cursorPoint.x > 10 || cursorPoint.y > 4) {
			cursorPoint.y = 0;
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) == 1) {
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
		if (++cursorPoint.x > 10 && cursorPoint.y > 3 || cursorPoint.x > 12) {
			cursorPoint.x = 0;
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT) == 1) {
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
		if (--cursorPoint.x < 0) {
			if (cursorPoint.y > 3) {
				cursorPoint.x = 10;
			}
			else {
				cursorPoint.x = 12;
			}
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B) == 1 && (name.size() < 5 || keyboard[cursorPoint.y][cursorPoint.x] == '<')) {
		//PlaySoundMem(BackSE, DX_PLAYTYPE_BACK);
		if (keyboard[cursorPoint.y][cursorPoint.x] == '<') {
			if (name.size() > 0) {
				name.erase(name.begin() + (name.size() - 1));
			}
		}
		else {
			name += keyboard[cursorPoint.y][cursorPoint.x];
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == 1) {

		//PlaySoundMem(DesideSE, DX_PLAYTYPE_BACK);
		ranking.WriteRanking(name, score);		//ファイル書き込みscoreを取得する方法

		return new DrawRanking(/*score*/);

	}
	return this;
}

void InputRanking::Draw() const {
	//DrawGraph(0, 0, image, TRUE);
	SetFontSize(40);
	DrawString(180, 55, "INPUT RANKING", 0xffffff);

	SetFontSize(40);
	DrawBox(100, 100, 540, 140, 0xffffff, TRUE);
	DrawFormatString(100, 100, 0xFF00FF, "%s", name.c_str());

	// カーソルの描画
	DrawBox(75+ 40 * cursorPoint.x, 175 + 40 * cursorPoint.y,
		110 + 40 * cursorPoint.x, 220 + 40 * cursorPoint.y, 0x808080, TRUE);

	// 仮想キーボードの描画
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 14; j++) {
			DrawFormatString(j * 40 + 80, i * 40 + 180, 0xffffff, "%c", keyboard[i][j]);
		}
	}

	SetFontSize(32);
	DrawString(190, 410, "A BUTTON PUSH", 0xffffff);
}