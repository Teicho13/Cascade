#include "Entity.h"
#include "Core/Managers/ResourceManager.h"
#include "Core/Managers/TextureManager.h"

Entity::Entity(const std::string& texturePath)
	:m_Sprite(std::make_unique<Sprite>("Assets/Player.png"))
{
}


Entity::Entity(const std::string& texturePath, float posX, float posY)
	:m_Sprite(std::make_unique<Sprite>("Assets/Player.png")),
	m_Position(SDL_FPoint{ posX,posY })
{
}

SDL_FPoint Entity::GetPosition() const
{
	return m_Position;
}

SDL_Point Entity::GetSize() const
{
	return m_Sprite->GetSize();
}

void Entity::SetPosX(float posX)
{
	m_Position.x = posX;
}

void Entity::SetPosY(float posY)
{
	m_Position.y = posY;
}

void Entity::Draw() const
{
	if(m_Sprite != nullptr)
	{
		//Create Variable for the position of the sprite
		const SDL_FRect tempRec{ m_Position.x, m_Position.y, static_cast<float>(m_Sprite->GetSize().x), static_cast<float>(m_Sprite->GetSize().y) };

		TextureManager::RenderTexture(m_Sprite->GetTexture(), &tempRec);
	}
}
