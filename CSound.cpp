#include "CSound.h"

CSound::CSound()
	: m_pFMODSystem(nullptr)
	, m_pChannel{}
	, m_pSound{}
{
}

CSound::~CSound()
{
}

void CSound::Init()
{
	System_Create(&m_pFMODSystem);

	if (m_pFMODSystem)
	{
		m_pFMODSystem->init(4, FMOD_INIT_NORMAL, nullptr);
	}

	Load();
}

void CSound::Load()
{
	m_pFMODSystem->createSound("Data/Coin.wav", FMOD_LOOP_NORMAL | FMOD_DEFAULT, nullptr, &m_pSound[ST_COINMUSIC]);

	m_pFMODSystem->createSound("Data/Effect.wav", FMOD_DEFAULT, nullptr, &m_pSound[ST_EFFECTSOUND]);
}

void CSound::Play(int _Type)
{
	if (_Type < 0 || _Type >= ST_MAXSOUND)return;
	//m_pFMODSystem->update();
	m_pFMODSystem->playSound(m_pSound[_Type], 0, false, &m_pChannel[_Type]);

}



void CSound::Stop(int _Type)
{
	if (_Type < 0 || _Type >= ST_MAXSOUND) return;
	m_pFMODSystem->playSound(m_pSound[_Type], 0, true, &m_pChannel[_Type]);
	//m_pChannel[_Type]->stop();
}

void CSound::Paused(int _Type, bool bPaused)
{
	if (_Type < 0 || _Type >= ST_MAXSOUND) return;
	m_pChannel[_Type]->setPaused(bPaused);
}

void CSound::Release()
{
	m_pFMODSystem->release();
	m_pFMODSystem->close();
}

void CSound::SetVolume(int _Type,float volume)
{
	m_pChannel[_Type]->setVolume(volume);
}
