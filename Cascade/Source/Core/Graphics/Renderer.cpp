#include "Renderer.h"

#include <iostream>

#include "Window.h"

bool Renderer::Create()
{
	std::cout << "Creating Renderer \n";

	//Create renderer for SDL and set default background color
	m_Renderer = SDL_CreateRenderer(Window::GetWindow(), -1, 0);

	if(m_Renderer == nullptr)
	{
		std::cout << "Failed to create Renderer !\n";
		return false;
	}

	SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);

	return true;
}

void Renderer::Destroy()
{
	SDL_DestroyRenderer(m_Renderer);
}

void Renderer::Clear()
{
	//Clear render screen for new frame
	SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);
	SDL_RenderClear(m_Renderer);
}

void Renderer::Present()
{
	//Render everything to the screen
	SDL_RenderPresent(m_Renderer);
}

SDL_Renderer* Renderer::GetRenderer()
{
	return m_Renderer;
}
