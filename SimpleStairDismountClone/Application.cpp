#include "Application.h"
#include <stdio.h>
#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"
#include <GL/GLU.h>

#define _USE_MATH_DEFINES
#include <math.h>

namespace SSDC
{
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
		window.create(sf::VideoMode(800, 600), "Stair Dismount Clone");

		// white clear colour
		glClearColor(1, 1, 1, 0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//gluLookAt(5, 6, 5, 5, 5, 0, 0, 1, 0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(75, window.getSize().x / (float)window.getSize().y, 1, 100);
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

		//glOrtho and gluOrtho2D make flat, incorrect perspective views

		//glViewport(0, 0, window.getSize().x, window.getSize().y);

		/*
		#glDepthFunc(GL_LESS)
		#glEnable(GL_DEPTH_TEST)
		#glEnable(GL_LIGHTING)
		#glEnable(GL_LIGHT0)
		#glEnable(GL_COLOR_MATERIAL)
		*/
	}

	void Application::draw()
	{

		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// look at before drawing
		gluLookAt(5, 6, 30, 5, 5, 0, 0, 1, 0);

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
			draw();

			window.display();
		}

		window.close();
	}


}
