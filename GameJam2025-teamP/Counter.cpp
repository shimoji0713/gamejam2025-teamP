#include "Counter.h"
#include "PadInput.h"

//
Counter* Counter::instance = nullptr;

//�R���X�g���N�^
Counter::Counter() : 
	b_count(0)
{

}

//�X�V����
void Counter::Update()
{
	PushButton();
}

//�`�揈��
void Counter::Draw()
{
	printf("%d", b_count);
}

//�J�E���^�����Z�b�g
void Counter::ResetCount()
{
	b_count = 0;
}

//�񐔂��擾
int Counter::GetCount()
{
	return b_count;
}

//B�{�^������������J�E���g��+1�ɂ���
void Counter::PushButton()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		b_count++;
	}
}