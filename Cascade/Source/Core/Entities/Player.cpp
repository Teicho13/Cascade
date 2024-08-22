#include "Player.h"
#include "Core/Utility/KeyStates.h"

Player::Player(const std::string& texturePath)
	:Entity(texturePath)
{

}

Player::Player(const std::string& texturePath, float posX, float posY)
	:Entity(texturePath,posX,posY)
{

}

void Player::Update(float dt)
{
	HandleInput(dt);
}

void Player::HandleInput(float dt)
{
	if(g_KeyStates[SDL_SCANCODE_A])
	{
		SetPosX(GetPosition().x + -m_MovementSpeed * dt);
	}

	if (g_KeyStates[SDL_SCANCODE_D])
	{
		SetPosX(GetPosition().x + m_MovementSpeed * dt);
	}
}
