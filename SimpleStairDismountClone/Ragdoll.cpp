#include "Ragdoll.h"

// head, neck, torso, abdomen, pelvis; left and right upper arm, forearm, thigh, leg, foot
// joint head-neck, neck-torso, torso-abdomen, abdomen-pelvis, torso and left right upper arm, left right upper arm and forearm, pelvis and left and right thigh, left and right thigh and leg, left and right leg and foot

Ragdoll::Ragdoll()
{
}

Ragdoll::Ragdoll(btDiscreteDynamicsWorld * world)
{
	this->world = world;
	btCollisionShape *testShape = new btBoxShape(btVector3(0.5, 0.5, 0.5));
	btDefaultMotionState *motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 2, 0)));
	btVector3 inertia(0, 0, 0);
	testShape->calculateLocalInertia(5, inertia);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(5, motionState, testShape, inertia);
	btRigidBody *body = new btRigidBody(rbInfo);
	bodyParts[0] = new BulletObject(testShape, body);
	world->addRigidBody(body);
}


Ragdoll::~Ragdoll()
{
}

void Ragdoll::draw()
{
	bodyParts[0]->draw();
	for (int i = 0; i < 15; i++)
	{
		//bodyParts[i]->draw();
	}
}

void Ragdoll::update()
{
	bodyParts[0]->update();
	for (int i = 0; i < 15; i++)
	{
		//bodyParts[i]->update();
	}
}

void Ragdoll::resetPosition()
{
}
