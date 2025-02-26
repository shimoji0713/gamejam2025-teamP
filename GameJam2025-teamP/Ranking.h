#pragma once
#include <string>

class Ranking
{
public:
	// ランキングデータを格納する構造体
	struct RANKING_DATA {
		int  no;// 順位
		std::string name;    // プレイヤー名
		long int score;      // スコア
	};
private:
	RANKING_DATA rankingData[5];	// 上位5名のランキングデータ

public:
	// ランキングデータをファイルから読み込む
	void ReadRanking();
	// 新しいスコアをランキングに登録し、並び替えた結果をファイルへ書き込む
	void WriteRanking(std::string _name, long int stage);

	// 指定したインデックスのランキングデータを取得
	/// </summary>
	/// <param name="index">取得するランキングのインデックス (0～4)</param>
	/// <returns>指定インデックスのランキングデータ</returns>
	RANKING_DATA GetRankingData(int index) { return rankingData[index]; }
};