#include"console.h"
#include "CBaseStd.h"

void GoToXY(int x, int y)
{
	HANDLE handle;
	COORD cursor;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(handle, cursor);
}

void SetCursorColor(int color, int bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgcolor << 4 | color);
}

void CursorView(bool isActive)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = isActive ? TRUE : FALSE; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void FullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}