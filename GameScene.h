#pragma once
#include "CScene.h"
#include "NoteController.h"
#include "CInput.h"
#include "CSound.h"

class GameScene : public CScene
{
public:
	GameScene();
	virtual ~GameScene();

public:
	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Release() override;
	virtual void PrintScreen() override;

public:
	void CheckNoteKey();
	void PrintUI();

private:
	bool _isPaused;
	CSound m_soundManager;
	NoteController* m_pNoteController;
	CInput m_InputObject;
	TInputState		m_InputState;


};

