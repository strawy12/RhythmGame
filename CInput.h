#pragma once

#include "CBaseStd.h"

enum KEYSTATE
{
	KEY_FREE = 0,
	KEY_PUSH,
	KEY_UP,
	KEY_DOWN,
	KEY_HOLD
};

struct TInputState
{
	DWORD dwKeyUp;
	DWORD dwKeyDown;
	DWORD dwKeyLeft;
	DWORD dwKeyRight;

	DWORD dwKeyD;
	DWORD dwKeyF;
	DWORD dwKeyJ;
	DWORD dwKeyK;

	DWORD dwKeySpace;
};

class CInput
{
public:
	CInput();
	~CInput();

public:

	void Init();
	void Update();
	void Release();

public:
	void KeyCheck(DWORD dwCheckKey, DWORD& dwStateKey);
};

