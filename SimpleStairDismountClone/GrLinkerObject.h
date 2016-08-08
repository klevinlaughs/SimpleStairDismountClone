#pragma once
#include "GrObject.h"
#include "btBulletDynamicsCommon.h"
#include "SFML/OpenGL.hpp"

class GrLinkerObject :
	public GrObject
{
public:
	GrLinkerObject();
	~GrLinkerObject();
	virtual void draw(btQuaternion rotation, btVector3 translation);
	virtual void draw();

};

