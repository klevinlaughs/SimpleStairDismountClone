#pragma once
#include "GrObject.h"
class BulletObject :
	public GrObject
{
private:
	virtual void updateOrigin();
	virtual void updateAxis();
public:
	BulletObject();
	~BulletObject();
	virtual void draw();
	virtual void update();
};

