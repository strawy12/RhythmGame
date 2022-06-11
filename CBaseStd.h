#pragma once

#include <iostream>
#include<Windows.h>
#include<math.h>
#include<string>
#include<map>
#include<vector>
#include<list>
#include<ctime>

using namespace std;

#define WINSIZEX 800
#define WINSIZEY 600

#define TITLE_OFFSET_Y 8
#define LINE_HEIGHT 14
 
#define VK_D 0x44
#define VK_F 0x46
#define VK_J 0x4A
#define VK_K 0x4B


typedef struct _pos
{
	float x;
	float y;
} POS, * PPOS;

enum COLOR
{
	C_BLACK = 0,
	C_BLUE,
	C_GREEN,
	C_CYAN,
	C_RED,
	C_PURPLE,
	C_YELLOW,
	C_WHITE,
	C_GRAY,
	C_LIGHTBLUE,
	C_LIGHTGREEN,
	C_LIGHTCYAN,
	C_LIGHTRED,
	C_LIGHTPURPLE,
	C_LIGHTYELLOW,
	C_LIGHTWHITE
};

#pragma comment(lib, "winmm.lib")