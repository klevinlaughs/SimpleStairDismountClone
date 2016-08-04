#pragma once
#include "State.h"
class StateReady :
	public State
{
private:
	std::string name = "READY";
public:
	StateReady();
	~StateReady();
	void init();
	void enter();
	void exit();
	void draw();
	void update();
	std::string getName();
};

