#pragma once
#include "GrObject.h"
#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "btBulletDynamicsCommon.h"

class GrBulletObject :
	public GrObject
{
private:
	Vector startOrigin;
	Vector startRotationAxis;
	double startRotationAngle;

	virtual void updateOrigin();
	virtual void updateRotation();
public:
	GrBulletObject();
	GrBulletObject(btRigidBody *rigidBody);
	~GrBulletObject();
	virtual void draw();
	virtual void update();
	void resetPosition();
	void activate();
	btRigidBody *rigidBody;
};

