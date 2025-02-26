
#pragma once
class Player
{
private:
	int anim[7];
	int image;
	int animation_cont;
	float animation_time;

public:
	Player();
	~Player();

	void Initialize(); //����������
	void Update(); //�X�V����
	void Draw();//�`�揈��
	void Finalize();//�I������

	/// <summary>

private:
	
	int move_animation;  //�A�j���[�V�����摜
	// �ړ��A�j���[�V�����̏���
	const int animation_num[7] = { 0, 1, 2, 3, 4, 5, 6,};
	//int background_image;		//�w�i�摜

	/// �A�j���[�V��������
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void AnimationControl();

	
};
