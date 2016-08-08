#include "GrLinkerBoxShape.h"

GrLinkerBoxShape::GrLinkerBoxShape(double halfX, double halfY, double halfZ)
{
}


GrLinkerBoxShape::~GrLinkerBoxShape()
{
}

void GrLinkerBoxShape::draw()
{
	glColor4f( (GLfloat)r, (GLfloat)g, (GLfloat)b, (GLfloat)a );

	glBegin(GL_QUAD_STRIP);
	glNormal3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glNormal3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glNormal3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glNormal3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glNormal3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glNormal3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glNormal3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glNormal3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glNormal3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glNormal3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glNormal3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glNormal3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);


	glNormal3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glNormal3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glNormal3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glNormal3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
}

void GrLinkerBoxShape::setRGBA(double r, double g, double b, double a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
