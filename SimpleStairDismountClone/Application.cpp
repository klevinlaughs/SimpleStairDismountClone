#include "Application.h"
#include <stdio.h>
#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"
#include <GL/GLU.h>


Application::Application()
{
	printf("%s\n", glGetString(GL_VERSION));
	exitStatus = 0;
	window.create(sf::VideoMode(800, 600), "Stair Dismount Clone");
}

Application::~Application()
{
}

int Application::getExitStatus()
{
	return exitStatus;
}

void Application::init() 
{
	//TODO: do something?
}

int Application::run()
{
	gameLoop();
	return exitStatus;
}

void Application::gameLoop() 
{
	bool isRunning = true;
	while (isRunning)
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// end the program
				isRunning = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}

		// Close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			//TODO: do something
			//window.close();
		}

		//drawing and rendering
		render();

		window.display();
	}

	window.close();
}

void Application::render()
{
	glClearColor(1, 1, 1, 0);

	glMatrixMode(GL_PROJECTION);

	// Matrix Load Identity
	glLoadIdentity();

	// clear the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw...		 
	//red
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 10);
	glVertex3f(10, 20, 10);
	glVertex3f(0, 10, 0);
	glEnd();
}
