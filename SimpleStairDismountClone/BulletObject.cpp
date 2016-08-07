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
	updateRotation();
}

void BulletObject::updateOrigin()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	origin.x = transform.getOrigin().x;
	origin.y = transform.getOrigin().y;
	origin.z = transform.getOrigin().z;
}

void BulletObject::updateRotation()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	rotationAxis.x = transform.getRotation().getAxis().x;
	rotationAxis.y = transform.getRotation().getAxis().y;
	rotationAxis.z = transform.getRotation().getAxis().z;
	rotationAngle = transform.getRotation().getAngle();
}
