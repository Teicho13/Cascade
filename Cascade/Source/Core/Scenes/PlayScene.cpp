#include "PlayScene.h"

#include "Core/Managers/TextureManager.h"
#include "Core/Utility/Logger.h"

#include "Core/Entities/Entity.h"
#include "Core/Entities/Player.h"

#include "Config/AppConfig.h"
#include "Core/Entities/Bullet.h"
#include "Core/Entities/Enemy.h"
#include "Game/Star.h"

Bullet bullet(540.f,720.f,3,12);
Star stars[30];
Enemy* enemy = nullptr;

void PlayScene::Init()
{
	Log::Info("Initialize Play Scene");

	m_Player = new Player(std::string("Assets/Player.png"),(AppConfig::Width / 2) - 20,(AppConfig::Height - 65));
	enemy = new Enemy(std::string("Assets/Enemy1.png"), (AppConfig::Width / 2) - 33, 200);
}

void PlayScene::Tick(float dt)
{
	m_Player->Update(dt);
	bullet.Tick(dt);
	enemy->Update(dt);
	for (auto& star : stars)
	{
		star.Tick(dt);
	}
}

void PlayScene::Destroy()
{
	delete m_Player;
}

void PlayScene::Render()
{
	TextureManager::RenderBox(m_Player->GetPosition().x, m_Player->GetPosition().y,static_cast<float>(m_Player->GetSize().x),static_cast<float>(m_Player->GetSize().y));
	m_Player->Draw();
	bullet.Draw();
	enemy->Draw();
	for (auto& star : stars)
	{
		star.Draw();
	}
}
