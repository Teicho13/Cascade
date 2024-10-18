#pragma once
#include "Scene.h"

class Entity;
class PlayScene : public Scene
{
public:
	void Init() override;
	void Tick(float dt) override;
	void Destroy() override;
	void Render() override;

	void OnMouseButtonUp(bool leftMouse) override;

	Entity* m_Player = nullptr;
};

