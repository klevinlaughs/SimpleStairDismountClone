#pragma once
#include "GrLinkerObject.h"
class GrLinkerSphereShape :
	public GrLinkerObject
{
private:
	double r = 0.5, g = 0.4, b = 0.3, a = 0;
	double radius = 0;
public:
	GrLinkerSphereShape(double radius);
	~GrLinkerSphereShape();
	void draw();
	void setRGBA(double r, double g, double b, double a);
};

