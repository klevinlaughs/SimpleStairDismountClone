#include "GrLinkerObject.h"

#define _USE_MATH_DEFINES
#include <math.h>

GrLinkerObject::GrLinkerObject()
{
}


GrLinkerObject::~GrLinkerObject()
{
}

void GrLinkerObject::drawTransform(Vector translation, Vector rotationAxis, double rotationAngle)
{
	glColor3f(0, 1, 0);
	glPushMatrix();

	//glTranslatef((GLfloat)translation.getX(), (GLfloat)translation.getY(), (GLfloat)translation.getZ());
	glTranslatef((GLfloat)translation.x, (GLfloat)translation.y, (GLfloat)translation.z);

	//glRotatef((GLfloat)rotation.getAngle() * 180 /(GLfloat) M_PI, (GLfloat)rotation.getX(), (GLfloat)rotation.getY(), (GLfloat)rotation.getZ());
	glRotatef((GLfloat)rotationAngle, (GLfloat)rotationAxis.x, (GLfloat)rotationAxis.y, (GLfloat)rotationAxis.z);

	draw();

	glPopMatrix();
}

void GrLinkerObject::draw()
{

}
