#pragma once
#include "SFML/Window.hpp"
#include "StateManager.h"

namespace SSDC
{
	class Application
	{
	private:
		sf::Window window;
		StateManager stateManager;
		void gameLoop();
		int exitStatus;
		void draw();
		void update();
	public:
		Application();
		~Application();
		void init();
		int run();
		int getExitStatus();
	};
}

