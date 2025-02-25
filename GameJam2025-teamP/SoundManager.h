#pragma once
class SoundManager
{
private:
	static int BGM[];
	static int SE[];

public:
	SoundManager();
	~SoundManager();

	static void Initialize();
	static void Finalize();

	static int GetBGM(int n) { return BGM[n]; }
	static int GetSE(int n) { return SE[n]; }
};

