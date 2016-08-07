#include "BulletObject.h"
#include "SFML/OpenGL.hpp"
#include <iostream>

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
	// TODO: remove shapes and objects
}

void BulletObject::draw()
{
	glColor3f(0, 1, 0);
	glPushMatrix();

	glTranslatef(origin.x, origin.y, origin.z);

	glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);

	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();
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
	origin.x = transform.getOrigin().getX();
	origin.y = transform.getOrigin().getY();
	origin.z = transform.getOrigin().getZ();
	std::cout << origin.x << ", " << origin.y << ", " << origin.z << std::endl;
}

void BulletObject::updateRotation()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	rotationAxis.x = transform.getRotation().getAxis().getX();
	rotationAxis.y = transform.getRotation().getAxis().getY();
	rotationAxis.z = transform.getRotation().getAxis().getZ();
	rotationAngle = transform.getRotation().getAngle();
}
