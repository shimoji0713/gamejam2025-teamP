#include "RankingInputScene.h"
#include "PadInput.h"
#include "DxLib.h"
#include "FontManager.h"
#include "SoundManager.h"

RankingInputScene::RankingInputScene() : background_image(NULL),
score(0), name_num(0), cursor_x(0), cursor_y(0)
{
	memset(name, NULL, (sizeof(char) * 15));
}

RankingInputScene::~RankingInputScene()
{
}

// ������
void RankingInputScene::Initialize()
{
	// �摜�̓ǂݍ���
	//background_image = LoadGraph("Resource/images/background.jpg");

	// �G���[�`�F�b�N
	/*if (background_image == -1) {
		throw("Resource/images/Ranking.bmp������܂���\n");
	}*/

	// �������̓��I�m��
	/*ranking = new RankingData;
	ranking->Initialize();*/

	// ���U���g�f�[�^���擾����
	FILE* fp = nullptr;
	// �t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/image/result_data.csv", "r");

	// �G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/result_data.csv���ǂݍ��߂܂���\n");
	}

	// ���ʂ�ǂݍ���
	fscanf_s(fp, "%6d,\n", &score);

	// �t�@�C���N���[�Y
	fclose(fp);
}

// �X�V
eSceneType RankingInputScene::Update()
{
	bool is_change = false;

	// ���O����
	is_change = InputName();

	// �V�[���ύX�͉\��
	if (is_change)
	{
		// �����L���O�\���ɑJ��
		return eSceneType::E_RANKING_DISP;
	}
	else
	{
		return GetNowScene();
	}
}

// �`��
void RankingInputScene::Draw() const
{
	// �w�i�̕`��
	DrawGraph(0, 0, background_image, TRUE);

	//DrawString(150, 100, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
	DrawStringToHandle(150, 100, "�����L���O�ɓo�^���܂�", GetColor(255, 255, 255), FontManager::GetFont(6));
	//DrawFormatString(100, 220, GetColor(255, 255, 255), ">%s", name);
	DrawFormatStringToHandle(100, 220, GetColor(255, 255, 255), FontManager::GetFont(1), ">%s", name);
	DrawLine(100, 260, 800, 260, 0xffffff);

	// �I��p������`��
	const int font_size = 95;
	for (int i = 0; i < 26; i++)
	{
		int x = (i % 13) * font_size + 15;
		int y = (i / 13) * font_size + 300;
		//DrawFormatString(x, y, GetColor(255, 255, 255), "%-3c", 'a' + i);
		DrawFormatStringToHandle(x, y, GetColor(0, 0, 0), FontManager::GetFont(1), "%-3c", 'a' + i);
		DrawFormatStringToHandle(x + 3, y + 3, GetColor(255, 255, 255), FontManager::GetFont(1), "%-3c", 'a' + i);
		y = ((i / 13) + 2) * font_size + 300;
		//DrawFormatString(x, y, GetColor(255, 255, 255), "%-3c", 'A' + i);
		DrawFormatStringToHandle(x, y, GetColor(0, 0, 0), FontManager::GetFont(1), "%-3c", 'A' + i);
		DrawFormatStringToHandle(x + 3, y + 3, GetColor(255, 255, 255), FontManager::GetFont(1), "%-3c", 'A' + i);
	}
	//DrawString(40, 680, "����", GetColor(255, 255, 255));
	//DrawString(40 + font_size * 2, 680, "����", GetColor(255, 255, 255));
	DrawStringToHandle(40, 680, "PASS", GetColor(0, 0, 0), FontManager::GetFont(1));
	DrawStringToHandle(40 + 3, 680 + 3, "PASS", GetColor(255, 255, 255), FontManager::GetFont(1));
	DrawStringToHandle(40 + font_size * 2, 680, "DELETE", GetColor(0, 0, 0), FontManager::GetFont(1));
	DrawStringToHandle(40 + font_size * 2 + 3, 680 + 3, "DELETE", GetColor(255, 255, 255), FontManager::GetFont(1));

	// �I�����t�H�[�J�X
	if (cursor_y < 4)
	{
		int x = cursor_x * font_size + 10;
		int y = cursor_y * font_size + 295;
		DrawBox(x, y, x + font_size, y + font_size, GetColor(255, 0, 0), FALSE);
	}
	else
	{
		if (cursor_x == 0)
		{
			DrawBox(40, 650, 40 + font_size * 2, 650 + font_size, GetColor(255, 0, 0), FALSE);
		}
		else
		{
			DrawBox(40 + font_size * 2, 650, 40 + font_size * 2 + (40 + font_size * 2), 650 + font_size, GetColor(255, 0, 0), FALSE);
		}
	}
}

// �I��������
void RankingInputScene::Finalize()
{
	// �����L���O�Ƀf�[�^���i�[
	//ranking->SetRankingData(score, name);
	RankingData::SetRankingData(score, name);

	// �ǂݍ��񂾉摜���폜
	DeleteGraph(background_image);

	// ���I�������̊J��
	//delete ranking;
}

eSceneType RankingInputScene::GetNowScene() const
{
	return eSceneType::E_RANKING_INPUT;
}

// ���O����
bool RankingInputScene::InputName()
{
	// �J�[�\�����쏈��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		PlaySoundMem(SoundManager::GetSE(6), DX_PLAYTYPE_BACK, TRUE);
		if (cursor_x > 0)
		{
			cursor_x--;
		}
		else
		{
			cursor_x = 12;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		PlaySoundMem(SoundManager::GetSE(6), DX_PLAYTYPE_BACK, TRUE);
		if (cursor_x < 12)
		{
			cursor_x++;
		}
		else
		{
			cursor_x = 0;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		PlaySoundMem(SoundManager::GetSE(6), DX_PLAYTYPE_BACK, TRUE);
		if (cursor_y > 0)
		{
			cursor_y--;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		PlaySoundMem(SoundManager::GetSE(6), DX_PLAYTYPE_BACK, TRUE);
		if (cursor_y < 4)
		{
			cursor_y++;
			if (cursor_y == 4)
			{
				cursor_x = 0;
			}
		}
	}

	// �J�[�\���ʒu�̕��������肷��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		PlaySoundMem(SoundManager::GetSE(7), DX_PLAYTYPE_BACK, TRUE);
		if (name_num < 15) {
			if (cursor_y < 2)
			{
				name[name_num++] = 'a' + cursor_x + (cursor_y * 13);
				if (name_num == 14)
				{
					cursor_x = 0;
					cursor_y = 4;
				}
			}
			else if (cursor_y < 4)
			{
				name[name_num++] = 'A' + cursor_x + ((cursor_y - 2) * 13);
				if (name_num == 14)
				{
					cursor_x = 0;
					cursor_y = 4;
				}
			}
			else
			{
				if (cursor_x == 0)
				{
					name[name_num] = '\0';
					return true;
				}
				else
				{
					if (name_num > 0) {
						name[name_num - 1] = NULL;
						name_num--;
					}
				}
			}
		}
	}
	return false;
}
