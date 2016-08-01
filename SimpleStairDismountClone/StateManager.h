#pragma once
#include "State.h"
#include <array>
class StateManager
{
private:
	State *currentState;
	std::array<State, 2> states;
public:
	enum state { READY, DISMOUNT };
	StateManager();
	~StateManager();
	State *getCurrentState();
	void goTo(state nextState);
};

