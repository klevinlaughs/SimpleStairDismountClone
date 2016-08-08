#include "GrLinkerObject.h"



GrLinkerObject::GrLinkerObject()
{
}


GrLinkerObject::~GrLinkerObject()
{
}

void GrLinkerObject::draw(btQuaternion rotation, btVector3 translation)
{
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef((GLfloat)origin.x, (GLfloat)origin.y, (GLfloat)origin.z);
	glRotatef((GLfloat)rotationAngle, (GLfloat)rotationAxis.x, (GLfloat)rotationAxis.y, (GLfloat)rotationAxis.z);

	draw();

	glPopMatrix();
}

void GrLinkerObject::draw()
{

}
