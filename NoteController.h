#pragma once
#include "Note.h"

class NoteController
{
private:
	static NoteController* instance;
public:
	static NoteController* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new NoteController;
		}

		return instance;
	}

public:
	NoteController();
	~NoteController();

public:
	void Init();
	void Update(float dt);
	void Release();
	void AddNote(Note* note);
	void RemoveNote(Note* note);

	bool JudgmentOffset(float fValue1, int iValue2);

	Note* EqualNotePos(int x, int y, bool useOffset = false);  

private:
	vector<Note*> m_pNotes;

	float m_timer;
	float m_delayTime;
	float m_noteDefaultSpeed;
	float m_judgmentOffset;
};
