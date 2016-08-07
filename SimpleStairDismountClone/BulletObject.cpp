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
}

void BulletObject::updateOrigin()
{
}

void BulletObject::updateAxis()
{
}
