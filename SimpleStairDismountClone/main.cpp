#include <stdio.h>
#include <stdlib.h>		 
#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"
#include <GL/GLU.h>

#include "Application.h"

int main(void) 
{

	// Start application
	SSDC::Application app;
	app.init();
	app.run();

	return app.getExitStatus();
}