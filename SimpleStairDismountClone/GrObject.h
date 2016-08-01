#pragma once
struct Center {
	int x = 0;
	int y = 0;
	int z = 0;
};

class GrObject
{
protected:
	Center center;
public:
	GrObject();
	~GrObject();
	virtual void draw() = 0;
};

