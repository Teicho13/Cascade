#include "PlayScene.h"

#include "Core/Managers/TextureManager.h"
#include "Core/Utility/Logger.h"

#include "Core/Entities/Entity.h"
#include "Core/Entities/Player.h"

#include "Config/AppConfig.h"


void PlayScene::Init()
{
	Log::Info("Initialize Play Scene");

	m_Player = new Player(std::string("Assets/Player.png"),(AppConfig::Width / 2) - 20,(AppConfig::Height - 65));
}

void PlayScene::Tick(float dt)
{
	m_Player->Update(dt);
}

void PlayScene::Destroy()
{
	delete m_Player;
}

void PlayScene::Render()
{
	TextureManager::RenderBox(m_Player->GetPosition().x, m_Player->GetPosition().y,static_cast<float>(m_Player->GetSize().x),static_cast<float>(m_Player->GetSize().y));
	m_Player->Draw();
}
