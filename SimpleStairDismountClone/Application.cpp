#include "Application.h"
#include <string>
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"
#include <GL/GLU.h>

#define _USE_MATH_DEFINES
#include <math.h>

namespace SSDC
{
	Application::Application()
	{
		//printf("%s\n", glGetString(GL_VERSION));
		exitStatus = 0;
	}

	Application::~Application()
	{
	}

	// exit status denoting type of exit, e.g. success or failure
	int Application::getExitStatus()
	{
		return exitStatus;
	}

	void Application::init()
	{
		sf::ContextSettings settings;
		settings.depthBits = 24;
		settings.stencilBits = 8;
		settings.antialiasingLevel = 4;

		window.create(sf::VideoMode(800, 600), "Stair Dismount Clone", sf::Style::Default, settings);

		// white clear colour
		glClearColor(1, 1, 1, 0);

		glEnable(GL_DEPTH_TEST);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//gluLookAt(5, 6, 5, 5, 5, 0, 0, 1, 0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(75, window.getSize().x / (float)window.getSize().y, 1, 200);
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

	// method to render/draw the objects for a given state/scene
	void Application::draw()
	{

		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//------------------------------------------------
		stateManager.getCurrentState()->draw();

		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();


		//------------------------------------------------
		glFlush();
	}

	void Application::update()
	{
		State *currentState = stateManager.getCurrentState();
		currentState->update();
	}

	// method to run the application using game loop
	int Application::run()
	{
		gameLoop();
		return exitStatus;
	}

	// game looping function, exits when game is closed somehow
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
				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Space)
					{
						//TODO: do something
						//window.close();
						isRunning = false;
					}
				}
				else if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (stateManager.getCurrentState()->getName() == "READY")
						{
							stateManager.goTo(stateManager.DISMOUNT);
						}
						else
						{
							stateManager.goTo(stateManager.READY);
							// TODO: RNG launch if state is ready
						}
					}
				}
			}

			//update and do drawing and rendering
			update();
			draw();

			window.display();
		}

		window.close();
	}

	// TODO: dereference things after game ends


}
