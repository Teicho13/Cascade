#include "Application.h"
#include <iostream>
#include <SDL.h>

#include "Graphics/Renderer.h"
#include "Graphics/Window.h"
#include "Managers/SceneManager.h"
#include "Scenes/PlayScene.h"

#include "Utility/KeyStates.h"
#include "Utility/DeltaTime.h"

DeltaTime dt;
SceneManager sceneManager;

void Application::Run()
{

	//Initialize Project

	if(!Init())
	{
		return;
	}

	//Create default scene
	sceneManager.ChangeScene(std::make_unique<PlayScene>());

	//Update / loop project
	while(m_ShouldRun)
	{
		dt.Update();
		HandleEvents();
		if(!m_ShouldRun)
			break;
		sceneManager.Update(dt.GetSeconds());
		Render();
	}

	Shutdown();
}

bool Application::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set current time
	dt.GetTime();

	if(!Window::Create())
	{
		return false;
	}

	if(!Renderer::Create())
	{
		return false;
	}

	//Pointer to keyboard button states
	g_KeyStates = SDL_GetKeyboardState(nullptr);

	return true;
}

void Application::Shutdown()
{
	Renderer::Destroy();
	Window::Destroy();
	SDL_Quit();
}

void Application::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//Window "X" is clicked
		case SDL_QUIT:
			m_ShouldRun = false;
			break;

			//key is pressed
		case SDL_KEYDOWN:
			//If Escape is clicked exit out
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				m_ShouldRun = false;
				return;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				sceneManager.MouseButtonUp(true);
			}
			if(event.button.button == SDL_BUTTON_RIGHT)
			{
				sceneManager.MouseButtonUp(false);
			}
			break;
		}
	}
}

void Application::Render()
{
	if (!m_ShouldRun) return;

	Renderer::Clear();

	//Render game objects
	sceneManager.Render();

	Renderer::Present();

}

