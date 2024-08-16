#include "PlayScene.h"

#include "Core/Managers/TextureManager.h"
#include "Core/Utility/Logger.h"

void PlayScene::Init()
{
	Log::Info("Initialize Play Scene");
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
}
