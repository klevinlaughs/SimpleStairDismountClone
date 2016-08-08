#pragma once
#include "GrLinkerObject.h"
class GrLinkerCylinderShape :
	public GrLinkerObject
{
private:
	double r = 0.5, g = 0.4, b = 0.3, a = 0;
	double radius = 0, height = 0;
public:
	GrLinkerCylinderShape(double radius, double height);
	~GrLinkerCylinderShape();	
	void draw();
	void setRGBA(double r, double g, double b, double a);
};

