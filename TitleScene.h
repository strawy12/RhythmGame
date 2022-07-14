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
	virtual void PrintScreen(float dt) override;

	void CheckVK(float dt);

private:
	const char m_DefaultScreen[100][100] =
	{
		"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
		"弛                                弛",
		"弛       1□  Game Start  ■      弛",
		"弛       2□ Song Select  ■      弛",
		"弛       3□     Quit     ■      弛",
		"弛                                弛",
		"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
		"&"
	};

	const char m_SettingScreen[100][100] =
	{
		"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
		"弛                                弛",
		"弛   1□   Song: @@@@@   ■   弛",
		"弛    □  Song Name : $$$$$  ■   弛",
		"弛   2□         Quit        ■   弛",
		"弛                                弛",
		"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
		"&"
	};

	const static float KeyInputDelayTime;

	char *m_CurrentScreen;
	float m_KeyInputTimer;

	int m_SongNum;

	int m_SelectedNum;
	int m_SceneType;

};

