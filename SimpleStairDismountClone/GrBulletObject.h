#pragma once
#include "GrObject.h"
#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "btBulletDynamicsCommon.h"

class GrBulletObject :
	public GrObject
{
private:
	virtual void updateOrigin();
	virtual void updateRotation();
public:
	GrBulletObject();
	GrBulletObject(btRigidBody *rigidBody);
	~GrBulletObject();
	virtual void draw();
	virtual void update();
	btCollisionShape *collisionShape;
	btRigidBody *rigidBody;
};

