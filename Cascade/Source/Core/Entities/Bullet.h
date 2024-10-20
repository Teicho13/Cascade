#pragma once
#include <SDL_rect.h>

class Bullet
{
public:
	Bullet(const float posX, const float posY, const int sizeX, const int sizeY);

	void SetPosition(float newX, float newY);

	SDL_FPoint GetPosition() const;
	SDL_Point GetSize() const;
	SDL_Color GetColor() const;
	bool GetShouldDestroy() const;

	void Tick(float dt);
	void Draw() const;

	void CheckBounds();
	

private:
	SDL_FPoint m_Position = SDL_FPoint{ 0.f,0.f };
	SDL_Point m_Size = SDL_Point{ 0,0 };
	SDL_Color m_Color = SDL_Color{ 255,0,0,255 };

	float m_Speed = 500.f;

	bool m_ShouldDestroy = false;
};

