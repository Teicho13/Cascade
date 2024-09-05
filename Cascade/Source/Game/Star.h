#pragma once
#include <cstdlib>
#include <SDL_rect.h>
#include "Core/Utility/Logger.h"
#include "Core/Managers/TextureManager.h"

struct Star
{
	Star()
	{
		float posX = 1 + (rand() % 1079);
		float posY = 1 + (rand() % 719);

		m_Position = SDL_FPoint{ posX,posY };
	}

	void Tick(float dt)
	{
		m_Position.y = m_Position.y + m_Speed * dt;
		if(m_Position.y >= 720)
		{
			m_Position.y = 0;
		}
	}

	void Draw() const
	{
		TextureManager::Plot(m_Position.x, m_Position.y, m_Color);
	}

	float m_Speed = 300;
	SDL_FPoint m_Position = SDL_FPoint{ 0.f,0.f };
	SDL_Color m_Color = SDL_Color{ 255,255,255,255 };
};
