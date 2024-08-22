#include "Sprite.h"

#include "Core/Managers/ResourceManager.h"

Sprite::Sprite(const std::string& texturePath)
	:m_Texture(ResourceManager::GetResourceManager()->GetTexture(texturePath))
{
	auto surface = ResourceManager::GetResourceManager()->GetSurface(texturePath);
	m_Size.x = surface->w;
	m_Size.y = surface->h;
}

Sprite::Sprite(const std::string& texturePath, int width, int height)
	:m_Texture(ResourceManager::GetResourceManager()->GetTexture(texturePath)),
	m_Size(SDL_Point{width,height})
{
}

SDL_Texture* Sprite::GetTexture() const
{
	return m_Texture;
}

SDL_Point Sprite::GetSize() const
{
	return m_Size;
}

void Sprite::SetWidth(int width)
{
	m_Size.x = width;
}

void Sprite::SetHeight(int height)
{
	m_Size.y = height;
}
