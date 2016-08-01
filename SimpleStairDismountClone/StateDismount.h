#pragma once
#include "State.h"
class StateDismount :
	public State
{
public:
	StateDismount();
	~StateDismount();
	void init();
	void enter();
	void exit();
	void draw();
};

