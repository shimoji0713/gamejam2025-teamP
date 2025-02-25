#pragma once
#include "AbstractScene.h"
class Ranking: public AbstractScene
{
public:
	Ranking();
	~Ranking();
	int RankingScene_Initialize(void);
	AbstractScene* Update(void) override;

    void Draw (void) const override ;

	void Set_RankingMode(int mode);
	void Set_RankingScore(int score);
private:
	

};

Ranking::Ranking()
{
}

Ranking::~Ranking()
{
}
/*************************
*マクロ定義
*************************/
#define RANKING_INPUT_MODE (1)
#define RANKING_DISP_MODE  (2)

/*************************
*型定義
*************************/

/*************************
*プロトタイプ宣言
*************************/
;