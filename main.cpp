#include "console.h"
#include "CScene.h"
#include "CBaseStd.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"


LARGE_INTEGER g_liPrevCount;
LARGE_INTEGER g_liCurCount;
LARGE_INTEGER g_liFrequency;

float g_fDT;
float g_fAcc;

void MainLoop();

SceneManager g_SceneManager;


int main()
{
    // 현재 카운트
    QueryPerformanceCounter(&g_liPrevCount);

    // 초당 카운트 횟수
    QueryPerformanceFrequency(&g_liFrequency);

    g_SceneManager.RegisterScene("GameScene", new GameScene());
    g_SceneManager.RegisterScene("TitleScene", new TitleScene());

    CursorView(false);
    system("mode con cols=100 lines=30 | title If Rhythm");
    srand(time(NULL));
    g_SceneManager.ReserveChangeScene("TitleScene");

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

    g_SceneManager.Update(g_fDT);
}

