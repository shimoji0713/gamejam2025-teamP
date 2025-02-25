#include "RankingDispScene.h"
#include "PadInput.h"
#include "DxLib.h"
#include "FontManager.h"
#include "SoundManager.h"

RankingDispScene::RankingDispScene() : background_image(NULL)
{

}

RankingDispScene::~RankingDispScene()
{

}
//����������
void RankingDispScene::Initialize()
{
    //�摜�̓ǂݍ���
    background_image = LoadGraph("Resource/images/background.jpg");

    //�G���[�`�F�b�N
    if (background_image == -1)
    {
        throw("Resource/images/Ranking.bmp������܂���\n");
    }

    //�����L���O�����擾
    /*ranking = new RankingData;
    ranking->Initialize();*/
}

eSceneType RankingDispScene::Update()
{
    //B�{�^���������ꂽ��A�^�C�g���ɖ߂�
    if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
    {
        PlaySoundMem(SoundManager::GetSE(7), DX_PLAYTYPE_BACK, TRUE);
        return eSceneType::E_TITLE;
    }

    return GetNowScene();
}

void RankingDispScene::Draw() const
{
    //�w�i�摜�̕`��
    DrawGraph(0, 0, background_image, FALSE);

    //�擾���������L���O�f�[�^��`�悷��
    for (int i = 0; i < 5; i++)
    {
        /* DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-15s %6d",
             ranking->GetRank(i), ranking->GetName(i), ranking->GetScore(i));*/
             //DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-15s %6d",RankingData::GetRank(i), RankingData::GetName(i), RankingData::GetScore(i));


        DrawFormatStringToHandle(300, 300 + i * 70, GetColor(0, 0, 0), FontManager::GetFont(3), "%2d %-15s", RankingData::GetRank(i), RankingData::GetName(i));
        DrawFormatStringToHandle(303, 303 + i * 70, GetColor(255, 255, 255), FontManager::GetFont(3), "%2d %-15s", RankingData::GetRank(i), RankingData::GetName(i));

        DrawFormatStringToHandle(800, 300 + i * 70, GetColor(0, 0, 0), FontManager::GetFont(3), "%6d", RankingData::GetScore(i));
        DrawFormatStringToHandle(803, 303 + i * 70, GetColor(255, 255, 255), FontManager::GetFont(3), "%6d", RankingData::GetScore(i));
    }
    DrawStringToHandle(300, 100, "RANKING", 0x0000aa, FontManager::GetFont(4));

    DrawStringToHandle(500, 680, "B�{�^���Ń^�C�g����", 0x000000, FontManager::GetFont(8));

}

void RankingDispScene::Finalize()
{
    //�ǂݍ��񂾉摜�̍폜
    DeleteGraph(background_image);

    //���I�������̉��
    //ranking->Finalize();

    //delete ranking;
}

eSceneType RankingDispScene::GetNowScene() const
{
    return eSceneType::E_RANKING_DISP;
}
