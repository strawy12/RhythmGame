#include "Note.h"
#include "NoteController.h"

Note::Note()
	: m_Color(C_LIGHTWHITE)
	, m_Pos{ 0.0f,0.0f }
	, m_fSpeed(0.0f)
	, m_Type(Note_Type::Single)
	, m_Height(1)
	, m_keyPush(false)
{

}

Note::Note(POS pos, float speed, Note_Type type, int height)
	: m_Color(C_LIGHTWHITE)
	, m_Pos(pos)
	, m_fSpeed(speed)
	, m_Type(type)
	, m_Height(height)
	, m_keyPush(false)
{

}

Note::Note(int color, POS pos, float speed, Note_Type type, int height)
	: m_Color(color)
	, m_Pos(pos)
	, m_fSpeed(speed)
	, m_Type(type)
	, m_Height(height)	
	, m_keyPush(false)

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

	if (m_Pos.y >= LINE_HEIGHT)
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

void Note::NoteDown()
{
	if (m_Type == Note_Type::Long)
	{
		if (m_keyPush == false)
		{
			m_keyPush = true;
		}

		m_Height--;
		m_Pos.y--;
	}
}

void Note::PrintNote()
{
	if (m_Color == 16)
	{
		m_Color = rand() % 16;
		if (m_Color == C_BLACK)
		{
			m_Color = C_WHITE;
		}
	}

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
