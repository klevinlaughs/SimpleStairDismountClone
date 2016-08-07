#include "StateDismount.h"	
#include "SFML/OpenGL.hpp"

StateDismount::StateDismount(btDiscreteDynamicsWorld *world, Ragdoll *ragdoll)
{
	this->world = world;
	this->ragdoll = ragdoll;
}

StateDismount::~StateDismount()
{
}

void StateDismount::init()
{
	clock.reset();
	  // TODO : set RNG launch
}

void StateDismount::enter()
{

}

void StateDismount::exit()
{

}

void StateDismount::draw()
{
	glColor3f(GLfloat(0.7), GLfloat(0.6), GLfloat(0.5));
	glBegin(GL_QUADS);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 0, -100);
	glVertex3f(-100, 0, -100);
	glVertex3f(-100, 0, 100);
	glEnd();

	ragdoll->draw();
}

void StateDismount::update()
{
	btScalar timeDiff = clock.getTimeSeconds();
	double speed = 1 / 5000.f;
	world->stepSimulation(timeDiff * speed);
	ragdoll->update();
}

std::string StateDismount::getName()
{
	return name;
}
