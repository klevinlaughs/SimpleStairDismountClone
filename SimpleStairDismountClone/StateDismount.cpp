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

}

void StateDismount::update()
{

}

std::string StateDismount::getName()
{
	return name;
}
