#pragma once
#include "Note.h"
#include "NotePair.h"

class NoteController
{
private:
	static NoteController* m_Instance;
public:
	static NoteController* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new NoteController;
			m_Instance->Init();
		}

		return m_Instance;
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

	bool EmptyNote() { return m_notePairs.size() == 0 && m_pNotes.size() == 0; }
	void PushNotePair(POS pos, float delay, Note_Type type, int height = 0);

	bool JudgmentOffset(float fValue1, int iValue2);

	Note* EqualNotePos(int x, int y, bool useOffset = false);

private:
	vector<Note*> m_pNotes;
	queue<NotePair*> m_notePairs;

	float m_timer;
	float m_delayTime;
	float m_noteDefaultSpeed;
	float m_judgmentOffset;
};

