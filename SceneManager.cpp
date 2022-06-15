#include "SceneManager.h"

SceneManager* SceneManager::m_Instance = nullptr;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::RegisterScene(const std::string& sceneName, CScene* scene)
{
}

void SceneManager::ReserveChangeScene(const std::string& sceneName)
{
}

void SceneManager::Init()
{
}

void SceneManager::Update(float dt)
{
}

void SceneManager::Release()
{
}
