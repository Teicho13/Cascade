#include "EnemyManager.h"

#include <iostream>

#include "../Entities/Enemy.h"
#include "Config/AppConfig.h"

void EnemyManager::SpawnEnemies()
{
	int row = 0;
	int col = 0;
	float offsetX = 200.f;
	float offsetY = 200.f;
	for (int i = 0; i < m_EnemyContainer.max_size(); ++i)
	{
		m_EnemyContainer[i] = new Enemy(std::string("Assets/Enemy1.png"), offsetX + (col * 40), offsetY + row * 30);
		col++;
		if(col % 15 == 0)
		{
			row++;
			col = 0;
		}
	}
}

void EnemyManager::RemoveEnemies()
{
	for (auto enemy : m_EnemyContainer)
	{
		delete enemy;
	}
}

void EnemyManager::Draw()
{
	for (auto enemy : m_EnemyContainer)
	{
		enemy->Draw();
	}
}

void EnemyManager::Update(float dt)
{
	bool shouldChange = false;

	for (auto enemy : m_EnemyContainer)
	{
		enemy->SetPosX(enemy->GetPosition().x + m_MoveSpeed * dt * m_Direction);
		enemy->SetPosY(enemy->GetPosition().y + m_OffsetY);

		if(!enemy->CheckBounds())
		{
			shouldChange = true;
		}
	}

	if(shouldChange)
	{
			m_Direction *= -1;
	}
}
