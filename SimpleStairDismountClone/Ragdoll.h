#pragma once 
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
class Ragdoll
{
private:
	btDiscreteDynamicsWorld *world;
public:
	Ragdoll();
	Ragdoll(btDiscreteDynamicsWorld *world);
	~Ragdoll();
	void draw();
	void resetPosition();
};

