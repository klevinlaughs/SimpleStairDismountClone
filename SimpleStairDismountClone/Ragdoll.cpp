#include "Ragdoll.h"

Ragdoll::Ragdoll()
{
}

Ragdoll::Ragdoll(btDiscreteDynamicsWorld * world)
{
	this->world = world;

	// create bullet objects
	btCollisionShape *testShape = new btBoxShape(btVector3(0.5, 0.5, 0.5));
	btDefaultMotionState *motionState = new btDefaultMotionState(btTransform(btQuaternion(0.38, 0.38, 0, 0.92), btVector3(0, 2, 0)));
	btVector3 inertia(0, 0, 0);
	testShape->calculateLocalInertia(5, inertia);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(5, motionState, testShape, inertia);
	btRigidBody *body = new btRigidBody(rbInfo);
	bodyParts[0] = new GrBulletObject(testShape, body);


	// create joints
	world->addRigidBody(body);
}


Ragdoll::~Ragdoll()
{
	//TODO: remove constraints, bullet objects
}

void Ragdoll::draw()
{
	bodyParts[0]->draw();
	for (int i = 0; i < BODYPART_COUNT; i++)
	{
		//bodyParts[i]->draw();
	}
}

void Ragdoll::update()
{
	bodyParts[0]->update();
	for (int i = 0; i < BODYPART_COUNT; i++)
	{
		//bodyParts[i]->update();
	}
}

void Ragdoll::resetPosition()
{
}
