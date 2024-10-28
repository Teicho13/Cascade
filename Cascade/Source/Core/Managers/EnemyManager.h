#pragma once
#include <array>
class Enemy;

class EnemyManager
{
public:
	void SpawnEnemies();
	void RemoveEnemies() const;

	void Draw() const;

	void Update(float dt);
	
	std::array<Enemy*,75>& GetEnemies();

private:
	std::array<Enemy*,75> m_EnemyContainer;
	//15x15

	float m_OffsetX = 200.f;
	float m_OffsetY = 200.f;

	float m_MoveSpeed = 100.f;

	int m_Direction = 1;
};

