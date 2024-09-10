#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(const std::string& texturePath);
	Enemy(const std::string& texturePath, float posX, float posY);

	void Update(float dt) override;

private:
	float m_MovementSpeed = 500.f;
};

