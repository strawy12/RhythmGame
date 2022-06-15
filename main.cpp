#include "console.h"
#include "CScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "main.h"
#include "CBaseStd.h"

LARGE_INTEGER g_liPrevCount;
LARGE_INTEGER g_liCurCount;
LARGE_INTEGER g_liFrequency;

float g_fDT;
float g_fAcc;

CScene* g_pMainScene;
map<string, CScene*> g_pSceneMap;

class GameScene;
void MainLoop();

int main()
{
    g_pSceneMap.insert(g_pSceneMap.end(), pair<string, CScene*>("GameScene", new GameScene()));
    g_pSceneMap.insert(g_pSceneMap.end(), pair<string, CScene*>("TitleScene", new TitleScene()));
    // 현재 카운트
    QueryPerformanceCounter(&g_liPrevCount);

    // 초당 카운트 횟수
    QueryPerformanceFrequency(&g_liFrequency);

    g_pMainScene = g_pSceneMap["TitleScene"];

    CursorView(false);
    system("mode con cols=100 lines=30 | title If Rhythm");
    srand(time(NULL));

    g_pMainScene->Init();

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

    g_pMainScene->Update(g_fDT);
}

