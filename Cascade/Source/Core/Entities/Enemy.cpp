#include "Enemy.h"
#include "Config/AppConfig.h"

Enemy::Enemy(const std::string& texturePath)
	:Entity(texturePath)
{

}

Enemy::Enemy(const std::string& texturePath, float posX, float posY)
	:Entity(texturePath, posX, posY)
{

}

void Enemy::Update(float dt)
{
	Move(dt);
	CheckBounds();
}

void Enemy::Move(float dt)
{
	SetPosX(GetPosition().x + m_MovementSpeed * dt * m_Direction);
}

void Enemy::CheckBounds()
{
	if((GetPosition().x + static_cast<float>(GetSize().x)) + m_Offset >= AppConfig::Width || GetPosition().x + m_Offset <= 0)
	{
		m_Direction *= -1;
	}
}
