#pragma once
#include "CScene.h"
#include "NoteController.h"

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

	NoteController* m_pNoteController;
};

