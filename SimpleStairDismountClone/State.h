#pragma once
class State
{
public:
	State();
	~State();
	virtual void init() {};
	virtual void enter() {};
	virtual void exit() {};
	//virtual void resume() = 0;
	//virtual void pause() = 0;
	virtual void draw() {};
	//virtual void update() = 0;
};

