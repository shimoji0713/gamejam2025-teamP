#include "SoundManager.h"
#include "DxLib.h"


SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::Initialize()
{
	

}

void SoundManager::Finalize()
{
	for (int i = 0; i < 8; i++)
	{
		DeleteSoundMem(BGM[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		DeleteSoundMem(SE[i]);
	}
}
