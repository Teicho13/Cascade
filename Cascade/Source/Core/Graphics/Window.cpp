#include "Window.h"

#include <iostream>

#include "Config/AppConfig.h"

bool Window::Create()
{
	std::cout << "Creating window \n";

	auto windowFlag = (AppConfig::Fullscreen) ? SDL_WINDOW_FULLSCREEN : (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	m_Window = SDL_CreateWindow("Cascade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, AppConfig::Width, AppConfig::Height, windowFlag);

	if(m_Window == nullptr)
	{
		std::cout << "failed to create window! \n";
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
