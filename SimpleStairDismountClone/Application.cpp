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
			isRunning = false;
		}

		//drawing and rendering
		render();

		window.display();
	}

	window.close();
}

void Application::render()
{

	// clear the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1, 1, 1, 0);

	glMatrixMode(GL_MODELVIEW);

	// Matrix Load Identity
	glLoadIdentity();

	gluLookAt(5, 5, 1, 5, 5, 0, 0, 1, 0);

	// draw...		 
	//red
	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0);
	glVertex3f(8, 8, 0);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//gluPerspective(75, window.getSize().x / (float)window.getSize().y, 1, 10);

	gluOrtho2D(-24, 24, -18, 18);

	glFlush();
}
