#pragma once 
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "BulletObject.h"
class Ragdoll
{
private:	// head, neck, torso, abdomen, pelvis; left and right upper arm, forearm, thigh, leg, foot
	enum bodyParts 
	{
		HEAD = 0, 
		NECK, 
		TORSO,
		ABDOMEN,
		PELVIS,
		ARM_UPPER_LEFT,
		ARM_UPPER_RIGHT,
		ARM_LOWER_LEFT,
		ARM_LOWER_RIGHT,
		THIGH_LEFT,
		THIGH_RIGHT,
		LEG_LEFT,
		LEG_RIGHT,
		FOOT_LEFT,
		FOOT_RIGHT,
		
		BODYPART_COUNT
	};
	btDiscreteDynamicsWorld *world;
	BulletObject *bodyParts[15];
public:
	Ragdoll();
	Ragdoll(btDiscreteDynamicsWorld *world);
	~Ragdoll();
	void draw();
	void update();
	void resetPosition();
};

