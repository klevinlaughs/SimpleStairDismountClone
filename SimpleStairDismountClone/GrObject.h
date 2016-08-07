#pragma once
struct Vector {
	double x = 0;
	double y = 0;
	double z = 0;
};

class GrObject
{
protected:
	Vector origin;
	Vector rotationAxis;
	double rotationAngle;
public:
	GrObject();
	~GrObject();
	virtual void draw();
};

