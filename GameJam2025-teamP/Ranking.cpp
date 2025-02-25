#include "DxLib.h"
#include "Ranking.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define RANKING_FILE_NAME "Ranking.txt" // ランキングデータのファイル名

/// <summary>
/// ランキングデータをファイルから読み込む
/// </summary>
void Ranking::ReadRanking() {
	std::ifstream ifs(RANKING_FILE_NAME); // ファイルを開く

	std::string line;
	for (int i = 0; std::getline(ifs, line); i++) { // 1行ずつ読み込む
		std::istringstream stream(line);
		std::string str;
		for (int j = 0; std::getline(stream, str, ','); j++) { // カンマ区切りで分割
			if (j == 0) {
				rankingData[i].no = std::stoi(str); // 順位を格納
			}
			else if (j == 1) {
				rankingData[i].name = str; // 名前を格納
			}
			else {
				rankingData[i].score = std::stol(str); // スコアを格納
			}
		}
	}
}

/// <summary>
/// ランキングデータを書き込み、並び替えを行う
/// </summary>
/// <param name="_name">プレイヤー名</param>
/// <param name="stage">スコア（ステージ数）</param>
void Ranking::WriteRanking(std::string _name, long int stage) {
	std::ofstream ofs(RANKING_FILE_NAME); // ファイルを開く（上書きモード）

	// 新しいスコアを最後の要素に追加
	rankingData[4].name = _name;
	rankingData[4].score = stage;

	// スコアを降順に並び替え（バブルソート）
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (rankingData[i].score < rankingData[j].score) {
				// データを交換
				RANKING_DATA temp = rankingData[i];
				rankingData[i] = rankingData[j];
				rankingData[j] = temp;
			}
		}
	}

	// 順位を設定
	rankingData[0].no = 1;
	for (int i = 1; i < 5; i++) {
		if (rankingData[i - 1].score == rankingData[i].score) {
			rankingData[i].no = rankingData[i - 1].no; // スコアが同じなら同順位
		}
		else {
			rankingData[i].no = i + 1; // 順位を付与
		}
	}

	// ファイルへ書き込み
	for (int i = 0; i < 5; i++) {
		ofs << rankingData[i].no << "," << rankingData[i].name.c_str() << "," << rankingData[i].score << std::endl;
	}
}
