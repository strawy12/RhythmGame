#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_ReservedScene = (nullptr);
	m_CurrentScene= (nullptr);
}

SceneManager::~SceneManager()
{
	for (auto it = m_SceneMap.begin(); it != m_SceneMap.end(); it++)
	{
		it->second->Release();
		delete it->second;
	}
}

void SceneManager::RegisterScene(const std::string& sceneName, CScene* scene)
{
	if (scene == nullptr || sceneName.compare("") == 0)
	{
		return;
	}

	//scene->Init();

	m_SceneMap.insert(m_SceneMap.end(), pair<string, CScene*>(sceneName, scene));
}

void SceneManager::ReserveChangeScene(const std::string& sceneName)
{
	auto it = m_SceneMap.find(sceneName);
	if (it != m_SceneMap.end())
	{
		m_ReservedScene = it->second;
	}

	else
		m_ReservedScene = nullptr;
}

void SceneManager::Init()
{
}

void SceneManager::Update(float dt)
{
	if (m_ReservedScene)
	{
		if (m_CurrentScene)
		{
			m_CurrentScene->Release();
			if (m_CurrentScene->IsPaused == false)
			{
				m_CurrentScene->IsPaused = true;
			}
		}

		if (m_ReservedScene->IsPaused == true)
		{
			m_ReservedScene->IsPaused = false;
		}
		else
		{
			m_ReservedScene->Init();
		}

		m_CurrentScene = m_ReservedScene;
		m_ReservedScene = nullptr;
	}

	if (m_CurrentScene)
		m_CurrentScene->Update(dt);

	if (m_CurrentScene->IsPaused)
	{
		ReserveChangeScene(m_CurrentScene->ReservedSceneName);
	}
}

void SceneManager::Release()
{
}
