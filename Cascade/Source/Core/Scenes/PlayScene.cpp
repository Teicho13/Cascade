#include "PlayScene.h"

#include "Core/Managers/TextureManager.h"
#include "Core/Utility/Logger.h"

#include "Core/Entities/Entity.h"
#include "Core/Entities/Player.h"

#include "Config/AppConfig.h"
#include "Core/Entities/Bullet.h"
#include "Core/Entities/Enemy.h"
#include "Core/Managers/BulletManager.h"
#include "Core/Managers/CollisionManager.h"
#include "Core/Managers/EnemyManager.h"
#include "Game/Star.h"

Star stars[30];

EnemyManager enemyManager;
BulletManager bulletManager;
CollisionManager collisionManager;

void PlayScene::Init()
{
	Log::Info("Initialize Play Scene");

	m_Player = new Player(std::string("Assets/Player.png"),(AppConfig::Width / 2) - 20,(AppConfig::Height - 65));
	
	enemyManager.SpawnEnemies();
	bulletManager.SetPlayer(m_Player);

	collisionManager.SetEnemyManager(&enemyManager);
	collisionManager.SetBulletManager(&bulletManager);
	
}

void PlayScene::Tick(float dt)
{
	m_Player->Update(dt);
	enemyManager.Update(dt);
	bulletManager.Update(dt);
	for (auto& star : stars)
	{
		star.Tick(dt);
	}
	collisionManager.Update(dt);
}

void PlayScene::Destroy()
{
	delete m_Player;
}

void PlayScene::Render()
{
	for (auto& star : stars)
	{
		star.Draw();
	}

	
	m_Player->Draw();
	enemyManager.Draw();
	bulletManager.Draw();

	TextureManager::RenderBox(m_Player->GetPosition().x, m_Player->GetPosition().y, static_cast<float>(m_Player->GetSize().x), static_cast<float>(m_Player->GetSize().y));
}

void PlayScene::OnMouseButtonUp(bool leftMouse)
{
	if(leftMouse)
	{
		bulletManager.SpawnBullet();
	}
}
