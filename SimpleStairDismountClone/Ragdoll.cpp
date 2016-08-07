#include "Ragdoll.h"

#define _USE_MATH_DEFINES
#include <math.h>

Ragdoll::Ragdoll()
{
}

Ragdoll::Ragdoll(btDiscreteDynamicsWorld * world, double heightOffset)
{
	this->world = world;

	double bodyMass = 70.0;

	// feet definition
	double footLength = 0.24, footHeight = 0.05, footWidth = 0.15;
	double footTop = footHeight + heightOffset;
	double footXOffset = 0.4, footZOffset = 0.167;
	double footMass = bodyMass * 1.38/100;

	// left foot
	btCollisionShape *bpShape = new btBoxShape(btVector3(footLength/2, footHeight/2, footWidth/2));
	btQuaternion bpRotation(0, 0, 0, 1);
	btVector3 bpTranslation(footXOffset, footTop-footHeight/2, -footZOffset);
	btDefaultMotionState *bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	btVector3 bpInertia(0, 0, 0);
	double bpMass = footMass;
	bpShape->calculateLocalInertia(bpMass, bpInertia);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(bpMass, bpMotionState, bpShape, bpInertia);
	btRigidBody *body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_FOOT] = new GrBulletObject(body);

	// right foot				 
	bpShape = new btBoxShape(btVector3(footLength / 2, footHeight / 2, footWidth / 2));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(footXOffset, footTop - footHeight / 2, footZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = footMass;
	bpShape->calculateLocalInertia(bpMass, bpInertia);
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_FOOT] = new GrBulletObject(body);

	// legs definition
	double legRadius = 0.055, legHeight = 0.34;
	double legTop = footTop + legHeight;
	double legMass = bodyMass * 5.05/100;

	// left leg
	bpShape = new btBoxShape(btVector3(legRadius, legHeight/2, legRadius));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, legTop-legHeight/2, -footZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = legMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_LEG] = new GrBulletObject(body);

	// right leg											 
	bpShape = new btBoxShape(btVector3(legRadius, legHeight, legRadius));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, legTop - legHeight / 2, footZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = legMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_LEG] = new GrBulletObject(body);

	// thighs definition
	double thighRadius = 0.07, thighHeight = 0.32;
	double thighAngle = 12 * M_PI / 180;
	double thighAngledHeight = thighHeight * cos(thighAngle);
	double thighTop = legTop + thighAngledHeight;
	double thighZOffset = 0.1136;
	double thighMass = bodyMass * 11.125/100;

	// left thigh  h=0.316
	bpShape = new btBoxShape(btVector3(thighRadius, thighHeight/2, thighRadius));
	bpRotation = btQuaternion(1 * sin(thighAngle/2), 0, 0, cos(thighAngle/2));
	bpTranslation = btVector3(0, thighTop - thighAngledHeight/2, -thighZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = thighMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_THIGH] = new GrBulletObject(body);

	// right thigh  h=0.316	, ends at 0.706				  
	bpShape = new btBoxShape(btVector3(thighRadius, thighHeight / 2, thighRadius));
	bpRotation = btQuaternion(-1 * sin(thighAngle / 2), 0, 0, cos(thighAngle / 2));
	bpTranslation = btVector3(0, thighTop - thighAngledHeight / 2, thighZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = thighMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_THIGH] = new GrBulletObject(body);

	// pelvis definition
	double pelvisLength = 0.19, pelvisHeight = 0.15, pelvisWidth = 0.35;
	double pelvisTop = thighTop + pelvisHeight;
	double pelvisMass = bodyMass * 14.81/100;

	// pelvis 
	bpShape = new btBoxShape(btVector3(pelvisLength/2, pelvisHeight/2, pelvisWidth/2));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, pelvisTop - pelvisHeight/2, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = pelvisMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_PELVIS] = new GrBulletObject(body);	 

	// abdomen definition
	double abdomenLength = 0.13, abdomenHeight = 0.113, abdomenWidth = 0.268;
	double abdomenTop = pelvisTop + abdomenHeight;
	double abdomenMass = bodyMass *  12.65 / 100;

	// abdomen
	bpShape = new btBoxShape(btVector3(abdomenLength/2, abdomenHeight/2, abdomenWidth/2));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, abdomenTop - abdomenHeight/2, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = abdomenMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_ABDOMEN] = new GrBulletObject(body);

	// thorax definition
	double thoraxLength = 0.2, thoraxHeight = 0.338, thoraxWidth = 0.34;
	double thoraxTop = abdomenTop + thoraxHeight;
	double thoraxMass = bodyMass * 18.56/100;

	// thorax 
	bpShape = new btBoxShape(btVector3(thoraxLength/2, thoraxHeight/2, thoraxWidth/2));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, thoraxTop-thoraxHeight/2, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = thoraxMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_THORAX] = new GrBulletObject(body);

	// upper arms definition
	double upperArmRadius = 0.04, upperArmHeight = 0.25;
	double upperArmAngle = 25 * M_PI / 180;
	double upperArmAngledHeight = upperArmHeight * cos(upperArmAngle);
	double upperArmBottom = thoraxTop - upperArmAngledHeight;
	double upperArmZOffset = 0.223;
	double upperArmMass = bodyMass * 3.075 / 100;

	// left upper arm  
	bpShape = new btBoxShape(btVector3(upperArmRadius, upperArmHeight/2, upperArmRadius));
	bpRotation = btQuaternion(1 * sin(upperArmAngle/2), 0, 0, cos(upperArmAngle/2));
	bpTranslation = btVector3(0, upperArmBottom + upperArmAngledHeight/2, -upperArmZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = upperArmMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_UPPER_ARM] = new GrBulletObject(body);

	// right upper arm  									 
	bpShape = new btBoxShape(btVector3(upperArmRadius, upperArmHeight / 2, upperArmRadius));
	bpRotation = btQuaternion(-1 * sin(upperArmAngle / 2), 0, 0, cos(upperArmAngle / 2));
	bpTranslation = btVector3(0, upperArmBottom + upperArmAngledHeight / 2, upperArmZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = upperArmMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_UPPER_ARM] = new GrBulletObject(body);

	// lower arms definition
	double lowerArmRadius = 0.035, lowerArmHeight = 0.28;
	double lowerArmTop = upperArmBottom;
	double lowerArmZOffset = 0.276;
	double lowerArmMass = bodyMass * 1.72 / 100;

	// left lower arm  
	bpShape = new btBoxShape(btVector3(lowerArmRadius, lowerArmHeight/2, lowerArmRadius));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, lowerArmTop - lowerArmHeight/2, -lowerArmZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = lowerArmMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_LEFT_LOWER_ARM] = new GrBulletObject(body);

	// right lower arm     
	bpShape = new btBoxShape(btVector3(lowerArmRadius, lowerArmHeight / 2, lowerArmRadius));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, lowerArmTop - lowerArmHeight / 2, lowerArmZOffset);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = lowerArmMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_RIGHT_LOWER_ARM] = new GrBulletObject(body);

	// neck definition
	double neckRadius = 0.05, neckHeight = 0.04;
	double neckTop = thoraxTop + neckHeight;
	double neckMass = 0.5;
	
	// neck	  
	bpShape = new btBoxShape(btVector3(neckRadius, neckHeight/2, neckRadius));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, neckTop - neckHeight/2, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = neckMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_NECK] = new GrBulletObject(body);

	// head definition
	double headRadius = 0.1, headHeight = 0.283;
	double headTop = neckTop + headHeight;
	double headMass = 5.0;

	// head	 
	bpShape = new btBoxShape(btVector3(headRadius, headHeight/2, headRadius));
	bpRotation = btQuaternion(0, 0, 0, 1);
	bpTranslation = btVector3(0, headTop - headHeight/2, 0);
	bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
	bpInertia = btVector3(0, 0, 0);
	bpMass = headMass;
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
	body = new btRigidBody(rbInfo);
	world->addRigidBody(body);
	bodyParts[BODYPART_HEAD] = new GrBulletObject(body);

	// create joints
}


Ragdoll::~Ragdoll()
{

	for (int i = 0; i < JOINT_COUNT;i++)
	{
		// TODO: remove constraints and delete constraints
	}

	for (int i = 0; i < BODYPART_COUNT; i++)
	{
		// TODO: doesn't like
		//world->removeRigidBody(bodyParts[i]->rigidBody);
		delete bodyParts[i];
	}
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
		bodyParts[i]->activate();
	}
}
