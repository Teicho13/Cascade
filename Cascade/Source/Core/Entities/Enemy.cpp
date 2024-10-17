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

void Enemy::Move(float dt)
{
}

bool Enemy::CheckBounds() const
{
	if((GetPosition().x + static_cast<float>(GetSize().x)) >= AppConfig::Width || GetPosition().x <= 0)
	{
		return false;
	}

	return true;
}
