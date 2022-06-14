#pragma once

#include "CBaseStd.h"

class Note;

class NotePair
{
public:
	NotePair(Note* note, float nextDelay)
		: m_Note(note)
		, m_NextDelay(nextDelay)
	{

	}
	~NotePair()
	{
		if (m_Note != NULL)
		{
			delete m_Note;
		}
	}

	Note* m_Note;
	float m_NextDelay;
};


