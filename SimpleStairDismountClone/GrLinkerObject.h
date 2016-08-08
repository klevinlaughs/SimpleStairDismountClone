#pragma once
#include "GrObject.h"
#include "SFML/OpenGL.hpp"

class GrLinkerObject :
	public GrObject
{
public:
	GrLinkerObject();
	~GrLinkerObject();
	virtual void drawTransform(Vector translation, Vector rotationAxis, double rotationAngle);
	virtual void draw();

};

