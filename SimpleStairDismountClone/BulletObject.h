#pragma once
#include "GrObject.h"
#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "btBulletDynamicsCommon.h"

class BulletObject :
	public GrObject
{
private:
	virtual void updateOrigin();
	virtual void updateAxis();
public:
	BulletObject();
	BulletObject(btCollisionShape *collisionShape, btRigidBody *rigidBody);
	~BulletObject();
	virtual void draw();
	virtual void update();
	btCollisionShape *collisionShape;
	btRigidBody *rigidBody;
};

