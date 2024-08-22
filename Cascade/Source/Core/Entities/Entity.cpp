#include "Entity.h"
#include "Core/Managers/ResourceManager.h"
#include "Core/Managers/TextureManager.h"

Entity::Entity(const std::string& texturePath)
	:m_Texture(ResourceManager::GetResourceManager()->GetTexture(texturePath))
{
}


Entity::Entity(const std::string& texturePath, float posX, float posY)
	:m_Texture(ResourceManager::GetResourceManager()->GetTexture(texturePath)),
	m_Position(SDL_FPoint{ posX,posY })
{
}

SDL_Texture* Entity::GetTexture() const
{
	return m_Texture;
}

SDL_FPoint Entity::GetPosition() const
{
	return m_Position;
}

void Entity::Draw()
{
	if(m_Texture != nullptr)
	{
		//Create Variable for the position of the sprite
		const SDL_FRect tempRec(m_Position.x, m_Position.y, 39.f,60.f);

		TextureManager::RenderTexture(m_Texture, &tempRec);
	}
}
