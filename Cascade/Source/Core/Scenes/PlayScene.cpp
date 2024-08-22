#include "PlayScene.h"

#include "Core/Managers/TextureManager.h"
#include "Core/Utility/Logger.h"

#include "Core/Entities/Entity.h"

Entity* test = nullptr;

void PlayScene::Init()
{
	Log::Info("Initialize Play Scene");

	test = new Entity(std::string("Assets/Player.png"),50.f,60.f);
}

void PlayScene::Tick(float dt)
{
}

void PlayScene::Destroy()
{
}

void PlayScene::Render()
{
	TextureManager::RenderBox(50.f, 100.f, 50.f, 50.f);
	test->Draw();
}
