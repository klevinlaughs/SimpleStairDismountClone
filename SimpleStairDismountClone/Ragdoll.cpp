#include "Ragdoll.h"

// head, neck, torso, abdomen, pelvis; left and right upper arm, forearm, thigh, leg, foot
// joint head-neck, neck-torso, torso-abdomen, abdomen-pelvis, torso and left right upper arm, left right upper arm and forearm, pelvis and left and right thigh, left and right thigh and leg, left and right leg and foot

Ragdoll::Ragdoll()
{
}

Ragdoll::Ragdoll(btDiscreteDynamicsWorld * world)
{
	this->world = world;
}


Ragdoll::~Ragdoll()
{
}

void Ragdoll::draw()
{
	for (int i = 0; i < 15; i++)
	{
		//bodyParts[i]->draw();
	}
}

void Ragdoll::update()
{
	for (int i = 0; i < 15; i++)
	{
		//bodyParts[i]->update();
	}
}

void Ragdoll::resetPosition()
{
}
