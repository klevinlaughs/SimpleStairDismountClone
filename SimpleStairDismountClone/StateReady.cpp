#include "StateReady.h"
#include "SFML/OpenGL.hpp"
#include <GL/GLU.h>

StateReady::StateReady(btDiscreteDynamicsWorld *world, Ragdoll *ragdoll)
{
	this->world = world;
	this->ragdoll = ragdoll;
}


StateReady::~StateReady()
{
}

void StateReady::init()
{

}

void StateReady::enter()
{
	
}

void StateReady::exit()
{
	
}

void StateReady::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// look at before drawing
	gluLookAt(2.5, 2.5, 2.5, 0, 1.5, 0, 0, 1, 0);

	// draw...		 
	//red
	/*glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 2);
	glVertex3f(3, 10, 0);
	glEnd();*/

	glColor3f(GLfloat(0.7), GLfloat(0.6), GLfloat(0.5));
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 0, -100);
	glVertex3f(-100, 0, -100);
	glVertex3f(-100, 0, 100);
	glEnd();

	ragdoll->draw();
}

void StateReady::update()
{
}		   

std::string StateReady::getName()
{
	return name;
}

