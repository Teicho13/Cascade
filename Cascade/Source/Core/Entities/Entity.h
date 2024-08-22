#pragma once
#include <memory>
#include <string>
#include <SDL_render.h>

#include "Core/Graphics/Sprite.h"

class Entity
{
public:
	Entity(const std::string& texturePath);
	Entity(const std::string& texturePath,float posX, float posY);
	virtual ~Entity() = default;

	SDL_FPoint GetPosition() const;
	SDL_Point GetSize() const;

	void SetPosX(float posX);
	void SetPosY(float posY);

	virtual void Update(float dt) = 0;

	void Draw() const;
private:
	std::unique_ptr<Sprite> m_Sprite = nullptr;
	SDL_FPoint m_Position = SDL_FPoint{ 0.f,0.f };
};

