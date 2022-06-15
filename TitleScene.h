#pragma once

#include "CScene.h"
#include "CInput.h"
#include "console.h"

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
	const char m_UIScreen[100][100] =
	{
		"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
		"弛                                弛",
		"弛       1□ Game Start ■        弛",
		"弛       2□  Setting   ■        弛",
		"弛       3□    Quit    ■        弛",
		"弛                                弛",
		"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
		"/"
	};

	const static float KeyInputDelayTime;
	float m_KeyInputTimer;

	int m_SelectedNum;
	CInput m_InputObject;
	TInputState m_InputState;

};

