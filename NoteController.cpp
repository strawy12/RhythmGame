#include "NoteController.h"
NoteController* NoteController::m_Instance = nullptr;

NoteController::NoteController()
	: m_timer(0.0f)
	, m_delayTime(2.5f)
	, m_noteDefaultSpeed(8.0f)
	, m_judgmentOffset(1.0f)
{
	if(m_Instance == nullptr)
	m_Instance = this;
}

NoteController::~NoteController()
{
}

void NoteController::Init()
{
	PushNotePair(POS{ KEY_F, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.064f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.064f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.064f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.064f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.128f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 1.7f, Note_Type::Single);

	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 1.2f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 1.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 1.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 1.2f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Long, 20);
	PushNotePair(POS{ KEY_D, 0 }, 1.0f, Note_Type::Long, 20);
	PushNotePair(POS{ KEY_F, 0 }, 0.5f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.5f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.3f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.15f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.5f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.55f, Note_Type::Single);

	PushNotePair(POS{ KEY_K, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.5f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.5f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.5f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.7f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_J, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 1.35f, Note_Type::Single);

	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_F, 0 }, 1.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_K, 0 }, 1.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_F, 0 }, 1.0f, Note_Type::Long, 6);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_J, 0 }, 1.0f, Note_Type::Long, 6);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 1.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_K, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.25f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 2.2f, Note_Type::Single);

	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_F, 0 }, 1.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_K, 0 }, 1.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_F, 0 }, 1.0f, Note_Type::Long, 6);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Long, 6);
	PushNotePair(POS{ KEY_J, 0 }, 1.0f, Note_Type::Long, 6);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 4.0f, Note_Type::Single);

	for (int i = 0; i < 5; i++)
	{
		PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
		PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
		PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
		PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);
	}

	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Long, 12);
	PushNotePair(POS{ KEY_K, 0 }, 2.0f, Note_Type::Long, 12);

	for (int i = 0; i < 5; i++)
	{
		PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
		PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
		PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
		PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);
	}


	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.5f, Note_Type::Single);

	float delay = 0.16f;
	PushNotePair(POS{ KEY_D, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, delay, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, delay+0.1f, Note_Type::Single);
	PushNotePair(POS{ KEY_D, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_F, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_J, 0 }, 0.0f, Note_Type::Single);
	PushNotePair(POS{ KEY_K, 0 }, 4.0f, Note_Type::Single);

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
			
			if (m_notePairs.size() != 0)
			{
				while (pair->m_NextDelay <= 0)
				{
					pair = m_notePairs.front();
					m_notePairs.pop();
					m_pNotes.push_back(pair->m_Note);
				}
			}

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
			delete m_pNotes[i];
			m_pNotes.erase(m_pNotes.begin() + i);
		}
	}
}
void NoteController::PushNotePair(POS pos, float delay, Note_Type type, int height)
{
	int color = 0;
	if (pos.x == KEY_D || pos.x == KEY_K)
	{
		color = C_LIGHTYELLOW;
	}

	else
	{
		color = C_LIGHTBLUE;
	}

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
