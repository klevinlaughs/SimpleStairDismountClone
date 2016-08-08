#include "GrLinkerBoxShape.h"
#include "SFML/OpenGL.hpp"

GrLinkerBoxShape::GrLinkerBoxShape(double halfX, double halfY, double halfZ)
{
	xSize = 2*halfX;
	ySize = 2*halfY;
	zSize = 2*halfZ;
}


GrLinkerBoxShape::~GrLinkerBoxShape()
{
}

void GrLinkerBoxShape::draw()
{
	glScalef((GLfloat)xSize, (GLfloat)ySize, (GLfloat)zSize);

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

	glEnd();
}

void GrLinkerBoxShape::setRGBA(double r, double g, double b, double a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
