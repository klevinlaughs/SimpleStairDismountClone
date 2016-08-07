#include "BulletObject.h"


BulletObject::BulletObject()
{
}

BulletObject::BulletObject(btCollisionShape * collisionShape, btRigidBody * rigidBody)
{
	this->collisionShape = collisionShape;
	this->rigidBody = rigidBody;
}


BulletObject::~BulletObject()
{
}

void BulletObject::draw()
{
}

void BulletObject::update()
{
	updateOrigin();
	updateAxis();
}

void BulletObject::updateOrigin()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	origin.x = transform.getOrigin().x;
	origin.y = transform.getOrigin().y;
	origin.z = transform.getOrigin().z;
}

void BulletObject::updateAxis()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	//axis.x
}
