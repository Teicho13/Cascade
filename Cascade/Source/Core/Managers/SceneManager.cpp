#include "SceneManager.h"

#include "Core/Scenes/Scene.h"
#include "Core/Utility/Logger.h"

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

void SceneManager::MouseButtonUp(bool leftMouse) const
{
	if (!m_Scenes.empty())
	{
		if(leftMouse)
		{
		m_Scenes.back()->OnMouseButtonUp(true);
		}
		else
		{
			m_Scenes.back()->OnMouseButtonUp(false);
		}
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
		Log::Warning("Invalid scene passed");
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
