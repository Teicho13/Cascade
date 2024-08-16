#include "SceneManager.h"

#include <iostream>

#include "Core/Scenes/Scene.h"

void SceneManager::Init()
{
	m_Scenes.back()->Init();
}

void SceneManager::Update(const float dt)
{
	if(!m_Scenes.empty())
	{
		m_Scenes.back()->Tick(dt);
	}
}

void SceneManager::Shutdown()
{
	if (!m_Scenes.empty())
	{
		m_Scenes.back()->Destroy();
	}
}

void SceneManager::Render()
{
	if (!m_Scenes.empty())
	{
		m_Scenes.back()->Render();
	}
}

void SceneManager::ChangeScene(std::unique_ptr<Scene> newScene)
{
	if(newScene != nullptr)
	{
		//Remove current state
		if (!m_Scenes.empty())
		{
			//call Shutdown for current state before removal to clean up.
			m_Scenes.back()->Destroy();
			m_Scenes.pop_back();
		}
		m_Scenes.push_back(std::move(newScene));
		m_Scenes.back()->Init();
	}
	else
	{
		std::cout << "Invalid scene passed";
		return;
	}
}

//Removes last scene (LIFO)
void SceneManager::RemoveScene()
{
	//Remove current state
	if (!m_Scenes.empty())
	{
		//call Shutdown for current state before removal to clean up.
		m_Scenes.back()->Destroy();
		m_Scenes.pop_back();
	}
}
