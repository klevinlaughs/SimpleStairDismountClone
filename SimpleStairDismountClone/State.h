#pragma once
#include <string>
class State
{
public:		
	virtual ~State() {};
	virtual void init() = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;
	//virtual void resume() = 0;
	//virtual void pause() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual std::string getName() = 0;
};

