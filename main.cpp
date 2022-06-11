#include "CSound.h"
#include "console.h"
#include "GameScene.h"
#include "main.h"

LARGE_INTEGER g_liPrevCount;
LARGE_INTEGER g_liCurCount;
LARGE_INTEGER g_liFrequency;

float g_fDT;
float g_fAcc;

GameScene* mainScene;
void MainLoop();
int main()
{
	mainScene = new GameScene;
    // 현재 카운트
    QueryPerformanceCounter(&g_liPrevCount);

    // 초당 카운트 횟수
    QueryPerformanceFrequency(&g_liFrequency);

    CursorView(false);
    srand(time(NULL));

    mainScene->Init();

    while (true)
    {
        MainLoop();
    }
}




void MainLoop()
{
	QueryPerformanceCounter(&g_liCurCount);
	g_fDT = (float)(g_liCurCount.QuadPart - g_liPrevCount.QuadPart) /
		(float)(g_liFrequency.QuadPart);

	g_liPrevCount = g_liCurCount;

	g_fAcc += g_fDT;

	if (g_fAcc >= 1.0f)
	{
		g_fAcc = 0.0f;
	}

	mainScene->Update(g_fDT);
}

