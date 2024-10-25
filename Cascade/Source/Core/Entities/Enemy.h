#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(const std::string& texturePath);
	Enemy(const std::string& texturePath, float posX, float posY);

	void Update(float dt) override;

	void SetIsActive(bool isActive);

	void Move(float dt);
	bool CheckBounds();
	bool GetIsActive() const;

private:
	bool m_IsActive = true;
};

