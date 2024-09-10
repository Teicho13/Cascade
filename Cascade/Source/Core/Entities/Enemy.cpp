#include "Enemy.h"

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
