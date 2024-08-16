#include <iostream>

#include "Core/Application.h"
#include "Core/Utility/Logger.h"

int main(int argc, char** argv)
{
	std::cout << "Starting Cascade... \n";
	Log::Init();
	Log::Info("Initialized Logger");
	Application app;
	app.Run();

	return 0;
}
