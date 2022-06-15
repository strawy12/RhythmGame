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
		"��������������������������������������������������������������������",
		"��                                ��",
		"��       1�� Game Start ��        ��",
		"��       2��  Setting   ��        ��",
		"��       3��    Quit    ��        ��",
		"��                                ��",
		"��������������������������������������������������������������������",
		"/"
	};

	const static float KeyInputDelayTime;
	float m_KeyInputTimer;

	int m_SelectedNum;
	CInput m_InputObject;
	TInputState m_InputState;

};

