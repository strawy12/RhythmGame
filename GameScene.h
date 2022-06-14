#pragma once
#include "CBaseStd.h"
#include "NoteController.h"
#include "CInput.h"
#include "CSound.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

public:
	void Init();
	void Update(float dt);
	void Release();

public:
	void PrintScreen();
	void CheckNoteKey();
	void PrintTitle();
	void PrintUI();

private:
	bool _isPaused;
	CSound m_soundManager;
	NoteController* m_pNoteController;
	CInput m_InputObject;
	TInputState		m_InputState;
};

