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
	clock.reset();
	btScalar timeDiff = clock.getTimeSeconds();
	world->stepSimulation(timeDiff);
	ragdoll->update();
}

std::string StateDismount::getName()
{
	return name;
}
