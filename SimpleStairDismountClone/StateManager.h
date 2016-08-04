#pragma once
#include "State.h"
#include <array>
class StateManager
{
private:
	State *currentState;
	State *_states[2];
public:
	enum state { READY, DISMOUNT };
	StateManager();
	~StateManager();
	State *getCurrentState();
	void goTo(state nextState);
};

