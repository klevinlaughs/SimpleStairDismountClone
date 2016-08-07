#include "StateDismount.h"			

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
