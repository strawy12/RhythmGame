#pragma once
#include "CScene.h"
#include "NoteController.h"

enum KEYTYPE
{
	KT_D = 0,
	KT_F,
	KT_J,
	KT_K,
};
enum KEY_HIT_STATE
{
	KTS_NONE,
	KTS_SUCCESS,
	KTS_FAILED
};

class GameScene : public CScene
{
public:
	GameScene();
	virtual ~GameScene();

public:
	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Release() override;
	virtual void PrintScreen(float dt) override;

public:
	void CheckNoteKey();
	void ClearNote(int PosX, int keyNum, bool keyDown);
	void PrintUI();

	void CalcScore(float error);

private:
	int m_HitSuccess[4];
	float m_SuccessTimer[4];
	float m_SuccessDelayTime;

	float m_PlayTime;
	int m_Score;
	NoteController* m_pNoteController;
};

