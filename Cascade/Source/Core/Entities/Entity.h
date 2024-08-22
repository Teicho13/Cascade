#pragma once
#include <SDL_render.h>
#include <string>

class Entity
{
public:
	Entity(const std::string& texturePath);
	Entity(const std::string& texturePath,float posX, float posY);

	SDL_Texture* GetTexture() const;
	SDL_FPoint GetPosition() const;

	void Draw();
private:
	SDL_Texture* m_Texture = nullptr;
	SDL_FPoint m_Position = SDL_FPoint{ 0.f,0.f };
};

