#pragma once

#include "CBaseStd.h"
#include "console.h"

enum class Note_Type
{
	Single,
	Long
};

class Note
{
public:
	Note();
	Note(POS pos, float speed, Note_Type type, int height);
	Note(int color, POS pos, float speed, Note_Type type, int height = 0);
	~Note();

public:
	void Init();
	void Update(float dt);
	void Release();

public:
	void SetPos(float x, float y);
	void NoteDown();
	void PrintNote(int bgColor = C_BLACK);
	void SetColor(int color);
	bool GetKeyDown() { return m_keyPush; }
	POS GetPos();
	Note_Type GetType() { return m_Type; }
	int GetHeight() { return m_Height; }

private:
	POS m_Pos;
	bool m_keyPush;
	int m_Color;
	float m_fSpeed;
	Note_Type m_Type;
	int m_Height;
};

