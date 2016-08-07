#include "GrBulletObject.h"
#include "SFML/OpenGL.hpp"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

GrBulletObject::GrBulletObject()
{
}

GrBulletObject::GrBulletObject(btRigidBody * rigidBody)
{
	this->rigidBody = rigidBody;

	{
		btTransform transform;
		rigidBody->getMotionState()->getWorldTransform(transform);
		origin.x = transform.getOrigin().getX();
		origin.y = transform.getOrigin().getY();
		origin.z = transform.getOrigin().getZ();
	}
	startOrigin = origin;

	{
		btTransform transform;
		rigidBody->getMotionState()->getWorldTransform(transform);
		rotationAxis.x = transform.getRotation().getAxis().getX();
		rotationAxis.y = transform.getRotation().getAxis().getY();
		rotationAxis.z = transform.getRotation().getAxis().getZ();
		rotationAngle = transform.getRotation().getAngle() * 180 / M_PI;
	}
	startRotationAxis = rotationAxis;
	startRotationAngle = rotationAngle;
}


GrBulletObject::~GrBulletObject()
{
	// TODO: remove shapes and objects
}

void GrBulletObject::draw()
{
	glColor3f(0, 1, 0);
	glPushMatrix();

	glTranslatef((GLfloat)origin.x, (GLfloat)origin.y, (GLfloat)origin.z);

	glRotatef((GLfloat)rotationAngle, (GLfloat)rotationAxis.x, (GLfloat)rotationAxis.y, (GLfloat)rotationAxis.z);

	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, 0.1);

	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glEnd();
	glPopMatrix();
}

void GrBulletObject::update()
{
	updateOrigin();
	updateRotation();
}

void GrBulletObject::updateOrigin()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	origin.x = transform.getOrigin().getX();
	origin.y = transform.getOrigin().getY();
	origin.z = transform.getOrigin().getZ();
}

void GrBulletObject::updateRotation()
{
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	rotationAxis.x = transform.getRotation().getAxis().getX();
	rotationAxis.y = transform.getRotation().getAxis().getY();
	rotationAxis.z = transform.getRotation().getAxis().getZ();
	rotationAngle = transform.getRotation().getAngle() * 180 / M_PI;
	//std::cout << rotationAxis.x << ", " << rotationAxis.y << ", " << rotationAxis.z << ": angle - " << rotationAngle << std::endl;
}

void GrBulletObject::resetPosition()
{
	// need to reset motion state
}