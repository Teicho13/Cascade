#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(const std::string& texturePath);
	Enemy(const std::string& texturePath, float posX, float posY);

	void Update(float dt) override;

	void Move(float dt);
	void CheckBounds();

private:
	float m_MovementSpeed = 100.f;
	float m_Offset = 0.f;
	int m_Direction = 1;
};

