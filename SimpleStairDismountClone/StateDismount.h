#pragma once
#include "State.h"	
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "Ragdoll.h"

class StateDismount :
	public State
{
private:
	std::string name = "DISMOUNT";
	btDiscreteDynamicsWorld *world;
	Ragdoll *ragdoll;
	btClock clock;
public:
	StateDismount(btDiscreteDynamicsWorld *world, Ragdoll *ragdoll);
	~StateDismount();
	void init();
	void enter();
	void exit();
	void draw();
	void update();
	std::string getName();
};

