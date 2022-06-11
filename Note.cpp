#include "Note.h"
#include "NoteController.h"

Note::Note()
	: m_Color(C_LIGHTWHITE)
	, m_Pos{0.0f,0.0f}
	, m_fSpeed(0.0f)

{

}

Note::Note(POS pos, float speed)
	: m_Color(C_LIGHTWHITE)
	, m_Pos(pos)
	, m_fSpeed(speed)

{

}

Note::Note(int color, POS pos, float speed)
	: m_Color(color)
	, m_Pos(pos)
	, m_fSpeed(speed)

{
}

Note::~Note()
{

}

void Note::Init()
{
}

void Note::Update(float dt)
{
	m_Pos.y += dt * m_fSpeed;

	if (m_Pos.y >= LINE_HEIGHT + TITLE_OFFSET_Y)
	{
		Release();
	}
	//if (m_pPos->y > 10)
	//{
	//	Release();
	//}
}

void Note::Release()
{
	NoteController::GetInstance()->RemoveNote(this);
}

void Note::SetPos(float x, float y)
{
	m_Pos.x = x;
	m_Pos.y = y;
}

void Note::PrintNote()
{
	SetCursorColor(m_Color, C_BLACK);

	cout << "¡á¡á¡á";
}

void Note::SetColor(int color)
{
	m_Color = color;
}

POS Note::GetPos()
{
	return m_Pos;
}
