#include "EnemyManager.h"

#include <iostream>

#include "../Entities/Enemy.h"
#include "Config/AppConfig.h"
#include "TextureManager.h"

void EnemyManager::SpawnEnemies()
{
	int row = 0;
	int col = 0;
	for (int i = 0; i < m_EnemyContainer.max_size(); ++i)
	{
		float offsetX = 200.f;
		m_EnemyContainer[i] = new Enemy(std::string("Assets/Enemy1.png"), offsetX + (col * 40), m_OffsetY + row * 30);
		m_EnemyContainer[i]->SetRow(row);
		col++;
		if(col % 15 == 0)
		{
			row++;
			col = 0;
		}
	}
}

void EnemyManager::RemoveEnemies() const
{
	for (auto enemy : m_EnemyContainer)
	{
		delete enemy;
	}
}

void EnemyManager::Draw() const
{
	for (auto enemy : m_EnemyContainer)
	{
		if(!enemy->GetIsActive())
			continue;
		enemy->Draw();
	}
}

void EnemyManager::Update(float dt)
{
	bool shouldChange = false;
	
	for (auto enemy : m_EnemyContainer)
	{
		if(!enemy->GetIsActive())
			continue;
		
		enemy->SetPosX(enemy->GetPosition().x + m_MoveSpeed * dt * m_Direction);
		enemy->SetPosY(m_OffsetY + static_cast<float>(enemy->GetRow() * 30));

		if(!enemy->CheckBounds())
		{
			shouldChange = true;
			m_OffsetY += 5.f;
		}
	}

	if(shouldChange)
	{
			m_Direction *= -1;
	}
}

std::array<Enemy*, 75>& EnemyManager::GetEnemies()
{
	return m_EnemyContainer;
}
