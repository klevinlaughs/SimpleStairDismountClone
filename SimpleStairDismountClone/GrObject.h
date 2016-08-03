#pragma once
struct Origin {
	int x = 0;
	int y = 0;
	int z = 0;
};

class GrObject
{
protected:
	Origin center;
public:
	GrObject();
	~GrObject();
	virtual void draw() = 0;
};

