#pragma once
#include "State.h"	  
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "Ragdoll.h"

class StateReady :
	public State
{
private:
	std::string name = "READY";
	btDiscreteDynamicsWorld *world;
	Ragdoll *ragdoll;
public:
	StateReady(btDiscreteDynamicsWorld *world, Ragdoll *ragdoll);
	~StateReady();
	void init();
	void enter();
	void exit();
	void draw();
	void update();
	std::string getName();
};

