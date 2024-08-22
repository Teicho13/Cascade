#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const std::string& texturePath);
	Player(const std::string& texturePath, float posX, float posY);

	void Update(float dt) override;
	void HandleInput(float dt);

private:
	float m_MovementSpeed = 500.f;
};

