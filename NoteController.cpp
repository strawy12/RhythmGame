#include "NoteController.h"
NoteController* NoteController::m_Instance = nullptr;

NoteController::NoteController()
	: m_timer(0.0f)
	, m_delayTime(0.9f)
	, m_noteDefaultSpeed(17.0f)
	, m_judgmentOffset(3.0f)
{
}

NoteController::~NoteController()
{
}

void NoteController::Init()
{
		PushNotePair(C_RANDOM, POS{ KEY_D, 0 }, 4.0f, Note_Type::Long, 10);
		PushNotePair(C_RANDOM, POS{ KEY_D, 0 }, 0.4f, Note_Type::Long, 30);
}



void NoteController::Update(float dt)
{
	m_timer += dt;

	if (m_timer >= m_delayTime)
	{
		m_timer = 0;

		if (m_notePairs.size() != 0)
		{
			NotePair* pair = m_notePairs.front();
			m_notePairs.pop();
			m_pNotes.push_back(pair->m_Note);

			m_delayTime = pair->m_NextDelay;
		}
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
void NoteController::PushNotePair(int color, POS pos, float delay, Note_Type type, int height)
{
	m_notePairs.push(new NotePair(new Note(color, pos, m_noteDefaultSpeed, type, height), delay));
}

bool NoteController::JudgmentOffset(float fValue1, int iValue2)
{
	if (
		(fValue1 + m_judgmentOffset) >= iValue2 &&
		(fValue1 - m_judgmentOffset) <= iValue2)
	{
		return true;
	}

	return false;
}
Note* NoteController::EqualNotePos(int x, int y, bool useOffset)
{
	for (int i = 0; i < m_pNotes.size(); i++)
	{
		if (m_pNotes[i]->GetType() == Note_Type::Long)
		{
			for (int j = 0; j < m_pNotes[i]->GetHeight(); j++)
			{
				if (useOffset)
				{
					if ((int)m_pNotes[i]->GetPos().x == x &&
						JudgmentOffset(m_pNotes[i]->GetPos().y - j, y))
					{
						return m_pNotes[i];
					}
				}

				else
				{
					if ((int)m_pNotes[i]->GetPos().x == x &&
						(int)m_pNotes[i]->GetPos().y - j == y)
					{
						return m_pNotes[i];
					}
				}
				
			}

			continue;
		}

		if (useOffset)
		{
			if ((int)m_pNotes[i]->GetPos().x == x &&
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
