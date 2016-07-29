#pragma once
class GrObject
{
protected:
	int x;
	int y;
	int z;
public:
	GrObject();
	~GrObject();
	virtual void draw();
};

