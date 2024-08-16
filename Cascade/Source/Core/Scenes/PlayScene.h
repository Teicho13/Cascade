#pragma once
#include "Scene.h"
class PlayScene : public Scene
{
public:
	void Init() override;
	void Tick(float dt) override;
	void Destroy() override;
	void Render() override;
};

