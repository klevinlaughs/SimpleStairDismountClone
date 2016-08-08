#include "GrLinkerCylinderShape.h"
#include "SFML/OpenGL.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

GrLinkerCylinderShape::GrLinkerCylinderShape(double radius, double height)
{
	this->radius = radius;
	this->height = height;
}


GrLinkerCylinderShape::~GrLinkerCylinderShape()
{
}

void GrLinkerCylinderShape::draw()
{
	glScalef((GLfloat)radius, (GLfloat)height, (GLfloat)radius);

	glColor4f((GLfloat)r, (GLfloat)g, (GLfloat)b, (GLfloat)a);

	glBegin(GL_QUAD_STRIP);
	int numOfSides = 8;
	for (int i = 0; i <= numOfSides; i++)
	{
		double fraction = i / (double)numOfSides;
		GLfloat x = (GLfloat) cos(fraction * 2 * M_PI) / 2;
		GLfloat y = 1/2.0;
		GLfloat z = (GLfloat) sin(fraction * 2 * M_PI) / 2;
		glNormal3f(x, y, z);
		glVertex3f(x, y, z);

		glNormal3f(x, -y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
}

void GrLinkerCylinderShape::setRGBA(double r, double g, double b, double a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
