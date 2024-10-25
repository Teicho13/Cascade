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
}

void Enemy::SetIsActive(bool isActive)
{
	m_IsActive = isActive;
}

void Enemy::Move(float dt)
{
}

bool Enemy::CheckBounds()
{
	if((GetPosition().x + static_cast<float>(GetSize().x)) >= AppConfig::Width)
	{
		SetPosX(static_cast<float>(AppConfig::Width - GetSize().x));
		return false;
	}

	if(GetPosition().x <= 0)
	{
		SetPosX(1.f);
		return false;
	}

	return true;
}

bool Enemy::GetIsActive() const
{
	return m_IsActive;
}
