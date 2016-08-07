#include "Ragdoll.h"

#define _USE_MATH_DEFINES
#include <math.h>

Ragdoll::Ragdoll()
{
}

Ragdoll::Ragdoll(btDiscreteDynamicsWorld * world)
{
	this->world = world;

	// left foot
	btCollisionShape *bpShape = new btBoxShape(btVector3(0.12, 0.025, 0.075));
	btQuaternion bpRotation(0, 0, 0, 1);
	btVector3 bpTranslation(0.4, 0.025, -0.167);
	btDefaultMotionState *bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	btVector3 bpInertia(0, 0, 0);
	double bpMass = 0.996;
	bpShape->calculateLocalInertia(bpMass, bpInertia);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(bpMass, bpMotionState, bpShape, bpInertia);
	btRigidBody *body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_FOOT] = new GrBulletObject(body);

	// left leg
	bpShape = new btBoxShape(btVector3(0.055, 0.17, 0.055));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 0.22, -0.167);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 3.535;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_LEG] = new GrBulletObject(body);

	// left thigh  h=0.316
	bpShape = new btBoxShape(btVector3(0.07, 0.16, 0.07));
	bpRotation = btQuaternion(1 * sin((12 * M_PI) / (2 * 180)), 0, 0, cos((12 * M_PI) / (2 * 180)));
	bpTranslation = btVector3(0, 0.22, -0.1336);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 7.7875;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_THIGH] = new GrBulletObject(body);

	// right foot
	bpShape = new btBoxShape(btVector3(0.12, 0.025, 0.075));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0.4, 0.025, 0.167);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 0.996;
	bpShape->calculateLocalInertia(bpMass, bpInertia);
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_FOOT] = new GrBulletObject(body);

	// right leg
	bpShape = new btBoxShape(btVector3(0.055, 0.17, 0.055));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 0.22, 0.167);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 3.535;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_LEG] = new GrBulletObject(body);

	// right thigh  h=0.316	, ends at 0.706
	bpShape = new btBoxShape(btVector3(0.07, 0.16, 0.07));
	bpRotation = btQuaternion(-1 * sin((12 * M_PI) / (2 *180)), 0, 0, cos((12 * M_PI) / (2 * 180)));
	bpTranslation = btVector3(0, 0.22, 0.1336);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 7.7875;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_THIGH] = new GrBulletObject(body);

	// pelvis 
	bpShape = new btBoxShape(btVector3(0.095, 0.075, 0.175));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 0.781, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 10.367;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_PELVIS] = new GrBulletObject(body);

	// abdomen
	bpShape = new btBoxShape(btVector3(0.065, 0.0565, 0.134));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 0.9125, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 8.855;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_ABDOMEN] = new GrBulletObject(body);

	// thorax 
	bpShape = new btBoxShape(btVector3(0.1, 0.169, 0.17));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 1.138, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 12.992;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_THORAX] = new GrBulletObject(body);

	// left upper arm  
	bpShape = new btBoxShape(btVector3(0.04, 0.125, 0.04));
	bpRotation = btQuaternion(1 * sin((30 * M_PI) / (2 * 180)), 0, 0, cos((30 * M_PI) / (2 * 180)));
	bpTranslation = btVector3(0, 1.138, -0.4025);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 2.1525;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_UPPER_ARM] = new GrBulletObject(body);

	// left lower arm  
	bpShape = new btBoxShape(btVector3(0.035, 0.14, 0.035));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 0.873, -0.4025);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 1.6065;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_LOWER_ARM] = new GrBulletObject(body);

	// right upper arm  
	bpShape = new btBoxShape(btVector3(0.04, 0.125, 0.04));
	bpRotation = btQuaternion(-1 * sin((30 * M_PI) / (2 * 180)), 0, 0, cos((30 * M_PI) / (2 * 180)));
	bpTranslation = btVector3(0, 1.138, 0.4025);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 2.1525;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_UPPER_ARM] = new GrBulletObject(body);

	// right lower arm  
	bpShape = new btBoxShape(btVector3(0.035, 0.14, 0.035));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 0.873, 0.4025);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 1.6065;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_LOWER_ARM] = new GrBulletObject(body);
	
	// neck	  
	bpShape = new btBoxShape(btVector3(0.05, 0.02, 0.05));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 1.326, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 0.761;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_NECK] = new GrBulletObject(body);

	// head	 
	bpShape = new btBoxShape(btVector3(0.1, 0.1415, 0.1));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, 1.4875, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = 5.0;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_HEAD] = new GrBulletObject(body);

	// create joints
}


Ragdoll::~Ragdoll()
{
	//TODO: remove constraints, bullet objects, which probably have to delete motion states
}

void Ragdoll::draw()
{
	//bodyParts[0]->draw();
	for (int i = 0; i < BODYPART_COUNT; i++)
	{
		bodyParts[i]->draw();
	}
}

void Ragdoll::update()
{
	//bodyParts[0]->update();
	for (int i = 0; i < BODYPART_COUNT; i++)
	{
		bodyParts[i]->update();
	}
}

void Ragdoll::resetPosition()
{
	for (int i = 0; i < BODYPART_COUNT; i++)
	{
		bodyParts[i]->resetPosition();
	}
}
