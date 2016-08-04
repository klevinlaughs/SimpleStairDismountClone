#pragma once
#include "State.h"
class StateDismount :
	public State
{
private:
	std::string name = "DISMOUNT";
public:
	StateDismount();
	~StateDismount();
	void init();
	void enter();
	void exit();
	void draw();
	void update();
};

