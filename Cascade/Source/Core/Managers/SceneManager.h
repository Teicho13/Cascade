#pragma once
#include <memory>
#include <vector>

class Scene;
class SceneManager
{
public:
	void Init();
	void Update(const float dt);
	void Shutdown();
	void Render();

	void MouseButtonUp(bool leftMouse) const;

	void ChangeScene(std::unique_ptr<Scene> newScene);
	void RemoveScene();

	std::vector<std::unique_ptr<Scene>> m_Scenes;
};

