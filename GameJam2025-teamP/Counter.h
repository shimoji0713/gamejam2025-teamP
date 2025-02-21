#pragma once
#include "PadInput.h"

//�{�^���A�ŃN���X
class Counter
{
private:
	int b_count;  //�A�ł����{�^���̉�

private:
	//���N���X�̃|�C���^�i���̂��A�h���X�̐�ŕۗL�j
	static Counter* instance;

	Counter();  //�C���X�g���N�^
	void Update();  //�X�V����
	void Draw();  //�`�揈��

	int GetCount();  //�J�E���g�̉񐔂��擾
	void ResetCount();  //�J�E���g�̃��Z�b�g
	void PushButton();  //B�{�^������������A�J�E���g��+1�ɂ���

};

