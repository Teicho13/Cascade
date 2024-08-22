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
	delete test;
}

void PlayScene::Render()
{
	TextureManager::RenderBox(test->GetPosition().x,test->GetPosition().y,static_cast<float>(test->GetSize().x),static_cast<float>(test->GetSize().y));
	test->Draw();
}
