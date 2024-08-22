#pragma once
#include <SDL_render.h>
#include <string>

class Sprite
{
public:
	Sprite(const std::string& texturePath);
	Sprite(const std::string& texturePath, int width, int height);

	SDL_Texture* GetTexture() const;
	SDL_Point GetSize() const;

	void SetWidth(int width);
	void SetHeight(int height);

private:
	SDL_Texture* m_Texture = nullptr;
	SDL_Point m_Size = SDL_Point{ 0,0 };
};

