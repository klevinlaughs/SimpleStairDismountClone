#pragma once
#include "SFML/Window.hpp"

class Application
{
private:
	sf::Window window;
	void gameLoop();
	int exitStatus;
	void render();
public:
	Application();
	~Application();
	void init();
	int run();
	int getExitStatus();
};

