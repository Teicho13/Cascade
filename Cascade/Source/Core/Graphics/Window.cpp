#include "Window.h"

#include <iostream>

#include "Config/AppConfig.h"
#include "Core/Utility/Logger.h"

bool Window::Create()
{
	Log::Info("Creating Window");

	auto windowFlag = (AppConfig::Fullscreen) ? SDL_WINDOW_FULLSCREEN : (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	m_Window = SDL_CreateWindow("Cascade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, AppConfig::Width, AppConfig::Height, windowFlag);

	if(m_Window == nullptr)
	{
		Log::Error("Failed to create window");
		return false;
	}

	return true;
}

void Window::Destroy()
{
	SDL_DestroyWindow(m_Window);
}

SDL_Window* Window::GetWindow()
{
	return m_Window;
}
