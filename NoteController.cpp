#include "NoteController.h"
NoteController* NoteController::instance = nullptr;

NoteController::NoteController()
	: m_timer(0.0f)
	, m_delayTime(1.0f)
	, m_noteDefaultSpeed(15.0f)
{
}

NoteController::~NoteController()
{
}

void NoteController::Init()
{
	//for (int i = 0; i < 16; i++)
	//{


	//}

}

void NoteController::Update(float dt)
{
	m_timer += dt;

	if (m_timer >= m_delayTime)
	{
		m_timer = 0;

		float posX = 2.0f + (8 * (rand() % 4));

		Note* note = new Note(rand() % 15 + 1, POS{ posX,0.0f }, m_noteDefaultSpeed);
		m_pNotes.push_back(note);
	}

	for (int i = 0; i < m_pNotes.size(); i++)
	{
		m_pNotes[i]->Update(dt);
	}
}

void NoteController::Release()
{
}

void NoteController::AddNote(Note* note)
{
}

void NoteController::RemoveNote(Note* note)
{
	for (UINT i = 0; i < m_pNotes.size(); i++)
	{
		if (m_pNotes[i] == note)
		{
			m_pNotes[i]->Release();
			delete m_pNotes[i];
			m_pNotes.erase(m_pNotes.begin() + i);
		}
	}
}
bool NoteController::JudgmentOffset(float fValue1, int iValue2)
{
	if ((int)fValue1  == iValue2 ||
		(int)(fValue1 + m_judgmentOffset) == iValue2 ||
		(int)(fValue1 - m_judgmentOffset) == iValue2)
	{
		return true;
	}

	return false;
}
Note* NoteController::EqualNotePos(int x, int y, bool useOffset)
{
	for (int i = 0; i < m_pNotes.size(); i++)
	{
		if (useOffset)
		{
			if (JudgmentOffset(m_pNotes[i]->GetPos().x, x) &&
				JudgmentOffset(m_pNotes[i]->GetPos().y, y))
			{
				return m_pNotes[i];
			}
		}

		else
		{
			if ((int)m_pNotes[i]->GetPos().x == x &&
				(int)m_pNotes[i]->GetPos().y == y)
			{
				return m_pNotes[i];
			}
		}
		
	}

	return nullptr;
}
