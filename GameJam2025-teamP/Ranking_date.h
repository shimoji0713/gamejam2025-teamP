#pragma once
#include <string>
class RankingData
{
public:
	static void Initialize(); //��������
	static void Finalize(); //�I������

public:
	//�����L���O�f�[�^�̍쐬
	static void SetRankingData(int s, const char* n);
	//�X�R�A�擾����
	static int GetScore(int value);
	//�X�R�A�擾����
	static int GetRank(int value);
	//���O�擾����
	static const char* GetName(int value);

private:
	static int score[6];
	static int rank[6];
	static std::string name[6];

private:
	//�f�[�^����ւ�����
	static void SortData();

};
//#pragma once
//#include <string>
//class RankingData
//{
//public:
//	�����L���O�\����
//	struct RANKING
//	{
//		int no;					//����
//		std::string name;		//���O
//		int score;				//�X�R�A
//	};
//
//private:
//	static RANKING rankingData[5];		//�����L���O�f�[�^�i�[�p
//
//public:
//	�����L���O�̓Ǎ�
//	static void ReadRanking();
//	�����L���O�̏������ݗp
//	�����Fn ���O�@s �X�R�A
//	static void WriteRanking(std::string n, int s);
//
//	�����L���O�f�[�^�̎擾
//	�����Fnum�@�擾�������f�[�^�̔ԍ�
//	�߂�l�Fnum�Ŏw�肳�ꂽ�ԍ���rankingData��ԋp
//	static RANKING GetRankingData(int num)
//	{
//		return rankingData[num];
//	}
//};

