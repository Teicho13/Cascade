#pragma once
class Application
{
public:

	void Run();
	bool Init();
	void Shutdown();

	void HandleEvents();

	void Render();

	bool m_ShouldRun = true;
};

