#pragma once
#include "CBaseStd.h"
#include "NoteController.h"
#include "CInput.h"

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
	NoteController* m_pNoteController;
	CInput m_InputObject;
	TInputState		m_InputState;
};

