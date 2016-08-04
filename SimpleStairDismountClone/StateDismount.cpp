#include "StateDismount.h"			

StateDismount::StateDismount()
{
	// reference : http://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-a-physics-library/
	broadphase = new btDbvtBroadphase();
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	solver = new btSequentialImpulseConstraintSolver();

	world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
	world->setGravity(btVector3(0, -9.81, 0));
}

StateDismount::~StateDismount()
{
	// TODO : delete other objects

	// remove from memory
	delete world;
	delete solver;
	delete dispatcher;
	delete collisionConfiguration;
	delete broadphase;

}

void StateDismount::init()
{
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

}

void StateDismount::update()
{

}

std::string StateDismount::getName()
{
	return name;
}
