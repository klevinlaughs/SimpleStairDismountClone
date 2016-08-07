#pragma once 
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "BulletObject.h"
class Ragdoll
{
private:
	btDiscreteDynamicsWorld *world;
	BulletObject *bodyParts[15];
public:
	Ragdoll();
	Ragdoll(btDiscreteDynamicsWorld *world);
	~Ragdoll();
	void draw();
	void resetPosition();
};

