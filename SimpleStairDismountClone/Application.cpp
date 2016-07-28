#include "Application.h"
#include <stdio.h>
#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"
#include <GL/GLU.h>

#define _USE_MATH_DEFINES
#include <math.h>

Application::Application()
{
	printf("%s\n", glGetString(GL_VERSION));
	exitStatus = 0;
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
	//TODO: do something?	set up gl

	window.create(sf::VideoMode(800, 600), "Stair Dismount Clone");

	// white clear colour
	glClearColor(1, 1, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(5, 6, 1, 5, 5, 0, 0, 1, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-24, 24, -18, 18, -10, 10);
	//gluOrtho2D(-24, 24, -18, 18);
	//glViewport(0, 0, window.getSize().x, window.getSize().y);

	/*
	#glDepthFunc(GL_LESS)
	#glEnable(GL_DEPTH_TEST)
	#glEnable(GL_LIGHTING)
	#glEnable(GL_LIGHT0)
	#glEnable(GL_COLOR_MATERIAL)
	*/



}

void Application::render()
{

	// clear the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW);

	// matrix Load Identity
	glLoadIdentity();

	//gluLookAt(5, 5, 1, 5, 5, 0, 0, 1, 0);

	// draw...		 
	//red
	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 2);
	glVertex3f(3, 10, 0);
	glEnd();

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	//gluPerspective(75, window.getSize().x / (float)window.getSize().y, 1, 10);

	/*
	int nearClip = 1;
	int farClip = 10;
	int fov = M_PI;
	double aspect = window.getSize().x / (float)window.getSize().y;
	GLdouble left = -1 * nearClip*tan((aspect*fov) / 2);
	GLdouble right = farClip*tan((aspect*fov) / 2);
	GLdouble bottom = -1 * nearClip*tan(fov / 2);
	GLdouble top = farClip*tan(fov / 2);

	glFrustum(left, right, bottom, top, nearClip, farClip);
	*/

	//gluOrtho2D(-24, 24, -18, 18);
	//glOrtho(-24, 24, -18, 18, -1, 1);

	glFlush();
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
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

