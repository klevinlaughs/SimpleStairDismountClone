#pragma once
class IDrawable
{
public:
	virtual ~IDrawable() = 0;
	virtual void draw() = 0;
};

