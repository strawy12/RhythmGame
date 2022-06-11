#pragma once

#include "CBaseStd.h"
#include "console.h"

class Note
{
public:
	Note();
	Note(POS pos, float speed);
	Note(int color, POS pos, float speed);
	~Note();

public:
	void Init();
	void Update(float dt);
	void Release();

public:
	void SetPos(float x, float y);
	void PrintNote();
	void SetColor(int color);
	POS GetPos();

private:
	POS m_Pos;
	int m_Color;
	float m_fSpeed;
};

