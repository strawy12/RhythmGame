#pragma once
#include "CScene.h"

class SceneManager
{

private:
	static SceneManager* m_Instance;

public:
	static SceneManager* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new SceneManager;
		}

		return m_Instance;
	}
public:
	SceneManager();
	~SceneManager();

public:
	void RegisterScene(const std::string& sceneName, CScene* scene);
	void ReserveChangeScene(const std::string& sceneName);

public:
	void Init();
	void Update(float dt);
	void Release();

private:
	std::map<std::string, CScene*>	m_SceneMap;

	CScene* m_ReservedScene;
	CScene* m_CurrentScene;
};

