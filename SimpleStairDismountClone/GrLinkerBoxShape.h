#pragma once
#include "GrLinkerObject.h"
#include "SFML/OpenGL.hpp"

class GrLinkerBoxShape :
	public GrLinkerObject
{
private:
	double r = 0.5, g = 0.4, b = 0.3, a = 0;
public:
	GrLinkerBoxShape(double halfX, double halfY, double halfZ);
	~GrLinkerBoxShape();
	void draw();
	void setRGBA(double r, double g, double b, double a);
};

