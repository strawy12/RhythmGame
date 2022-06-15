#pragma once

#include "CBaseStd.h"
#include "console.h"

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
		GoToXY(x, y);
		cout << " ________  ___  ___      ___    ___ _________  ___  ___  _____ ______       "; GoToXY(x, y + 1);
		cout << "|\   __  \|\  \|\  \    |\  \  /  /|\___   ___\\  \|\  \|\   _ \  _   \     "; GoToXY(x, y + 2);
		cout << "\ \  \|\  \ \  \\\  \   \ \  \/  / ||___ \  \_\ \  \\\  \ \  \\\__\ \  \    "; GoToXY(x, y + 3);
		cout << " \ \   _  _\ \   __  \   \ \    / /     \ \  \ \ \   __  \ \  \\|__| \  \   "; GoToXY(x, y + 4);
		cout << "  \ \  \\  \\ \  \ \  \   \/  /  /       \ \  \ \ \  \ \  \ \  \    \ \  \  "; GoToXY(x, y + 5);
		cout << "   \ \__\\ _\\ \__\ \__\__/  / /          \ \__\ \ \__\ \__\ \__\    \ \__\ "; GoToXY(x, y + 6);
		cout << "    \|__|\|__|\|__|\|__|\___/ /            \|__|  \|__|\|__|\|__|     \|__| "; GoToXY(x, y + 7);
		cout << "                       \|___|/                                              "; GoToXY(x, y + 8);
	}

};

