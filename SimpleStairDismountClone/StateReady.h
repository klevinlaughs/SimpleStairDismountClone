#pragma once
#include "State.h"
class StateReady :
	public State
{
public:
	StateReady();
	~StateReady();
	void init();
	void enter();
	void exit();
	void draw();
	void update();
};

