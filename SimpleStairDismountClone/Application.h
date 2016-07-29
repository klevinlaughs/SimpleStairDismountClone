#pragma once
#include "SFML/Window.hpp"

namespace SSDC
{
	class Application
	{
	private:
		sf::Window window;
		void gameLoop();
		int exitStatus;
		void draw();
	public:
		Application();
		~Application();
		void init();
		int run();
		int getExitStatus();
	};
}
