#include "GrLinkerSphereShape.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

GrLinkerSphereShape::GrLinkerSphereShape(double radius)
{
	this->radius = radius;
}


GrLinkerSphereShape::~GrLinkerSphereShape()
{
}

void GrLinkerSphereShape::draw()
{
	glScalef((GLfloat)radius * 2, (GLfloat)radius * 2, (GLfloat)radius * 2);

	glColor4f((GLfloat)r, (GLfloat)g, (GLfloat)b, (GLfloat)a);

	int numOfSegments = 8;
	double fractionI = 0;
	double fractionI2 = 0;
	double fractionJ = 0;

	GLfloat x, y, z;

	// up and down
	for (int i = 0; i <= numOfSegments/2; i++)
	{
		fractionI = i / (double)(numOfSegments/2);
		fractionI2 = (i + 1) / (double)(numOfSegments / 2);

		// top
		if (i == 0)
		{
			glBegin(GL_TRIANGLE_FAN);
			x = (GLfloat)0;
			y = (GLfloat)0.5;
			z = (GLfloat)0;

			glNormal3f(x, y, z);
			glVertex3f(x, y, z);

			for (int j = 0; j <= numOfSegments; j++)
			{
				fractionJ = j / (double)numOfSegments;
				x = (GLfloat)cos(fractionJ * 2 * M_PI) / 2;
				y = (GLfloat)cos(fractionI2 * M_PI) / 2;
				z = (GLfloat)sin(fractionJ * 2 * M_PI) / 2;

				glNormal3f(x, y, z);
				glVertex3f(x, y, z);
			}

			glEnd();
		}
		// bottom
		else if (i == (numOfSegments / 2))
		{
			glBegin(GL_TRIANGLE_FAN);
			x = (GLfloat)0;
			y = (GLfloat) -0.5;
			z = (GLfloat)0;

			glNormal3f(x, y, z);
			glVertex3f(x, y, z);

			for (int j = 0; j <= numOfSegments; j++)
			{
				fractionJ = j / (double)numOfSegments;
				x = (GLfloat)cos(fractionJ * 2 * M_PI) / 2;
				y = (GLfloat)cos(fractionI * M_PI) / 2;
				z = (GLfloat)sin(fractionJ * 2 * M_PI) / 2;

				glNormal3f(x, y, z);
				glVertex3f(x, y, z);
			}

			glEnd();
		}
		// other middle sections
		else
		{
			// around
			glBegin(GL_QUAD_STRIP);
			for (int j = 0; j <= numOfSegments; j++)
			{
				fractionJ = j / (double)numOfSegments;
				x = (GLfloat)cos(fractionJ * 2 * M_PI) / 2;
				y = (GLfloat)cos(fractionI * M_PI) / 2;
				z = (GLfloat)sin(fractionJ * 2 * M_PI) / 2;

				glNormal3f(x, y, z);
				glVertex3f(x, y, z);

				x = (GLfloat)cos(fractionJ * 2 * M_PI) / 2;
				y = (GLfloat)cos(fractionI2 * M_PI) / 2;
				z = (GLfloat)sin(fractionJ * 2 * M_PI) / 2;

				glNormal3f(x, y, z);
				glVertex3f(x, y, z);
			}
			glEnd();

		}
	}

/*
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
	glPopMatrix();
*/
}

void GrLinkerSphereShape::setRGBA(double r, double g, double b, double a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
