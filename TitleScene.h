#pragma once

#include "CScene.h"
#include "console.h"

enum SCREENTYPE
{
	SCT_TITLE,
	SCT_SETTING
};

class TitleScene : public CScene
{
public:

	TitleScene();
	virtual ~TitleScene();

	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Release() override;
	virtual void PrintScreen() override;

	void CheckVK(float dt);

private:
	const char m_DefaultScreen[100][100] =
	{
		"��������������������������������������������������������������������",
		"��                                ��",
		"��       1�� Game Start ��        ��",
		"��       2��  Setting   ��        ��",
		"��       3��    Quit    ��        ��",
		"��                                ��",
		"��������������������������������������������������������������������",
		"&"
	};

	const char m_SettingScreen[100][100] =
	{
		"��������������������������������������������������������������������",
		"��                                ��",
		"��    1�� Volume: @@@@@ ��    ��",
		"��    2��        Back       ��    ��",
		"��                                ��",
		"��������������������������������������������������������������������",
		"&"
	};

	const static float KeyInputDelayTime;

	char *m_CurrentScreen;
	float m_KeyInputTimer;

	int m_SoundVolume;

	int m_SelectedNum;
	int m_SceneType;

};

