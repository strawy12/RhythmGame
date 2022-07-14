#pragma once
#include "CScene.h"


class SceneManager
{

public:
	SceneManager();
	~SceneManager();

public:
	void RegisterScene(const string& sceneName, CScene* scene);
	void ReserveChangeScene(const string& sceneName);

public:
	void Init();
	void Update(float dt);
	void Release();

private:
	map<string, CScene*> m_SceneMap;

	CScene* m_ReservedScene;
	CScene* m_CurrentScene;
};

