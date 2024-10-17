#pragma once
#include <array>
class Enemy;

class EnemyManager
{
public:
	void SpawnEnemies();
	void RemoveEnemies();

	void Draw();

	void Update(float dt);

private:
	std::array<Enemy*,75> m_EnemyContainer;
	//15x15

	float m_OffsetX = 0.f;
	float m_OffsetY = 0.f;

	float m_MoveSpeed = 100.f;

	int m_Direction = 1;
};

