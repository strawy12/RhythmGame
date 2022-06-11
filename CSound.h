#pragma once

#include "CBaseStd.h"
#include "fmod.hpp"
#include"fmod_errors.h"

using namespace FMOD;

enum ESoundType
{
	ST_BACKGROUNDSOUND = 0,
	ST_EFFECTSOUND,
	ST_MAXSOUND
};

class CSound
{
public:
	CSound();
	~CSound();

public:
	void Init();
	void Load();
	void Play(int _Type);
	void Stop(int _Type);
	void Paused(int _type, bool bpaused);
	void Release();

private:
	System* m_pFMODSystem;
	Channel* m_pChannel[ST_MAXSOUND];
	Sound* m_pSound[ST_MAXSOUND];


};

