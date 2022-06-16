#pragma once

#include "CBaseStd.h"
#include "console.h"
#include "CSound.h"
#include "CInput.h"
#include<io.h>
#include<fcntl.h>
class CScene
{

public:
	CScene() = default;
	virtual ~CScene() = default;

public:
	virtual	void Init() = 0;
	virtual	void Update(float dt) = 0;
	virtual	void Release() = 0;
	virtual	void PrintScreen() = 0;


	void PrintTitle(int x, int y)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		/*

		*/
		GoToXY(x, y);

		wcout << L" ___  ________      ________  ___  ___      ___    ___ _________  ___  ___  _____ ______"; GoToXY(x, y + 1);
		wcout << L"|\\  \\|\\  _____\\    |\\   __  \\|\\  \\|\\  \\    |\\  \\  /  /|\\___   ___\\\\  \\|\\  \\|\\   _ \\  _   \\ "; GoToXY(x, y + 2);
		wcout << L"\\ \\  \\ \\  \\__/     \\ \\  \\|\\  \\ \\  \\\\\\  \\   \\ \\  \\/  / ||___ \\  \\_\\ \\  \\\\\\  \\ \\  \\\\\\__\\ \\  \\ "; GoToXY(x, y + 3);
		wcout << L" \\ \\  \\ \\   __\\     \\ \\   _  _\\ \\   __  \\   \\ \\    / /     \\ \\  \\ \\ \\   __  \\ \\  \\\\|__| \\  \\ "; GoToXY(x, y + 4);
		wcout << L"  \\ \\  \\ \\  \\_|      \\ \\  \\\\  \\\\ \\  \\ \\  \\   \\/  /  /       \\ \\  \\ \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ "; GoToXY(x, y + 5);
		wcout << L"   \\ \\__\\ \\__\\        \\ \\__\\\\ _\\\\ \\__\\ \\__\\__/  / /          \\ \\__\\ \\ \\__\\ \\__\\ \\__\\    \\ \\__\\ "; GoToXY(x, y + 6);
		wcout << L"    \\|__|\\|__|         \\|__|\\|__|\\|__|\\|__|\\___/ /            \\|__|  \\|__|\\|__|\\|__|     \\|__|"; GoToXY(x, y + 7);
		wcout << L"				             \\|___|/"; GoToXY(x, y + 8);
		_setmode(_fileno(stdout), _O_TEXT);

	}
public:
	bool IsPaused;
	string ReservedSceneName;
protected:

	CSound m_SoundObject;
	CInput m_InputObject;
	TInputState	m_InputState;
};

