#include "Ranking.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>

int RankingData::score[];
int RankingData::rank[];
std::string RankingData::name[];

//���C���֐�
int main() {
	RankingData::Initialize();
}

//����������
void RankingData::Initialize()
{

	for (int i = 0; i < 6; i++)
	{
		score[i] = NULL;
		rank[i] = NULL;
		for (int j = 0; j < 15; j++)
		{
			name[i] = '\0';
		}
	}

	std::ifstream ifs("Resource/ranking_data.csv");
	std::string line;
	//�����L���O�e�L�X�g�̈�s���擾
	for (int i = 0; std::getline(ifs, line); i++) {
		std::istringstream stream(line);
		std::string str;
		//no name score�ɕ����Ċi�[
		for (int j = 0; std::getline(stream, str, ','); j++) {
			if (j == 0) {
				score[i] = std::stoi(str);
			}
			else if (j == 1) {
				rank[i] = std::stoi(str);
			}
			else {
				name[i] = str;
			}
		}

	}

	ifs.close();

	//�����L���O�`��
	for (int i = 0; i < 5; i++)
	{
		printf("score=%d,rank=%d,name=%s\n", int(score[i]), int(rank[i]), name[i].c_str());
	}

	//�����f�[�^�̐ݒ�
	score[5] = 0;
	rank[5] = 0;
	name[5] = '\0';

}

//�I������
void RankingData::Finalize()
{

}

//�f�[�^�ݒ菈��
void RankingData::SetRankingData(int s, const char* n)
{
	score[5] = s;
	std::string tmp(n);
	name[5] = tmp;

	SortData();
}

//�X�R�A�����擾
int RankingData::GetScore(int value)
{
	return score[value];
}

//�����N�擾����
int RankingData::GetRank(int value)
{
	return rank[value];
}

//���O�擾����
const char* RankingData::GetName(int value)
{
	return name[value].c_str();
}

//�f�[�^����ւ�����
void RankingData::SortData()
{
	//�I��@�\�[�g���g�p���A�~���œ���ւ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (score[i] <= score[j])
			{
				int tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;

				/*char buf[15] = {};
				strcpy_s(buf, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j],buf);*/

				std::string buf1;
				buf1 = name[i];
				name[i] = name[j];
				name[j] = buf1;

			}
		}
	}
	//���ʂ𐮗񂳂���
	for (int i = 0; i < 5; i++)
	{
		rank[i] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (score[i] > score[j])
			{
				rank[j]++;
			}
		}
	}
	//�����L���O�f�[�^�̓ǂݍ���
	FILE* fp = nullptr;

	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/ranking_data.csv", "w");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/ranking_data.csv���J���܂���ł���\n");
	}

	//�Ώۃt�@�C���ɏ�������
	for (int i = 0; i < 5; i++)
	{
		fprintf(fp, "%d,%d,%s,\n", score[i], rank[i], name[i].c_str());
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}
//#include "RankingData.h"
//#include <fstream>
//#include <iostream>
//#include <sstream>
//
//RankingData::RANKING RankingData::rankingData[];
//
//void RankingData::ReadRanking()
//{
//	//�����L���O�e�L�X�g�̓Ǎ�
//	std::ifstream ifs("text/Ranking.txt");
//
//	std::string line;
//	//�����L���O�e�L�X�g�̈�s���擾
//	for (int i = 0; std::getline(ifs, line); i++) {
//		std::istringstream stream(line);
//		std::string str;
//		//no name score�ɕ����Ċi�[
//		for (int j = 0; std::getline(stream, str, ','); j++) {
//			if (j == 0) {
//				rankingData[i].no = std::stoi(str);
//			}
//			else if (j == 1) {
//				rankingData[i].name = str;
//			}
//			else {
//				rankingData[i].score = std::stoi(str);
//			}
//		}
//	}
//}
//
//void RankingData::WriteRanking(std::string n, int s)
//{
//	RANKING tmp;		//����ւ��̎��Ɏg��
//	std::ofstream ofs("text/Ranking.txt");		//�����L���O�e�L�X�g�̓Ǎ�
//
//	//�����L���O�f�[�^�̍ŉ��ʂɈ�������
//	rankingData[4].name = n;
//	rankingData[4].score = s;
//	//���בւ�
//	for (int i = 0; i < 4; i++) {
//		for (int j = i + 1; j < 5; j++) {
//			if (rankingData[i].score < rankingData[j].score) {
//				tmp = rankingData[i];
//				rankingData[i] = rankingData[j];
//				rankingData[j] = tmp;
//			}
//		}
//	}
//
//	//���ʂ̍ĐU�蕪��
//	rankingData[0].no = 1;
//	for (int i = 1; i < 5; i++) {
//		//�����_���������瓯������
//		if (rankingData[i].score == rankingData[i - 1].score) {
//			rankingData[i].no = rankingData[i - 1].no;
//		}
//		//�������ʂ���Ȃ���Έ��������
//		else {
//			rankingData[i].no = i + 1;
//		}
//	}
//
//	//�����L���O�e�L�X�g�ɏ�������
//	for (int i = 0; i < 5; i++) {
//		ofs << rankingData[i].no << "," << rankingData[i].name << "," << rankingData[i].score << std::endl;
//	}
//
//}
