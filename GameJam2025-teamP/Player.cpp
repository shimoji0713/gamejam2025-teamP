#include "Player.h"
#include"DxLib.h"

//コンストラクタ
Player::Player() :move_animation(),animation_time(),anim(),animation_cont()
{
	
}

//デストラクタ
Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	LoadDivGraph("C:\\PG\\gamejam2025-teamP\\GameJam2025-teamP\\Resource\\image\\batta-1.png", 7, 7, 1, 114, 179, anim);
	
	image = anim[0];
	animation_time = 0;
}
void Player::Update()
{

	AnimationControl();
}
void Player::Draw()
{
	DrawRotaGraph(320, 240, 1.0, 0.0, image, true);
}
void Player::Finalize()
{
	
}

void Player::AnimationControl()
{
	animation_time++;

	if (animation_time >= 15.0)
	{
		animation_time = 0.0f;
		animation_cont++;
		if (animation_cont >= 7)
		{
			animation_cont = 0;
		}

		image = anim[animation_cont];
	}
}
