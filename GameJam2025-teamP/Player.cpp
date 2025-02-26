#include "Player.h"
#include"DxLib.h"

//�R���X�g���N�^
Player::Player() :move_animation(),animation_time(),anim(),animation_cont()
{
	image = 0;

	animation_endflg = false;
}

//�f�X�g���N�^
Player::~Player()
{

}

//����������
void Player::Initialize()
{
	LoadDivGraph("Resource/image/batta-1.png", 7, 7, 1, 114, 179, anim);
	
	image = anim[0];
	animation_time = 0;
}
void Player::Update(int progress)
{

	int game_progress = progress;
	if (progress > 3) {
		AnimationControl();
	}
	
}
void Player::Draw()
{
	DrawRotaGraph(240, 260, 1.0, 0.0, image, true);
}
void Player::Finalize()
{
	
}

void Player::AnimationControl()
{
	animation_time++;

	if (animation_time >= 25.0&& animation_cont < 6)
	{
		animation_time = 0.0f;
		animation_cont++;
		if (animation_cont >= 6)
		{
			animation_endflg = true;
		}
	}

	image = anim[animation_cont];
}

bool Player::GetAnimationEndflg()
{
	return animation_endflg;
}
