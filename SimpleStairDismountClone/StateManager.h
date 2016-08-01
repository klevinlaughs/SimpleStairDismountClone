#pragma once
#include "State.h"
#include <array>
class StateManager
{
private:
	State *currentState;
	std::array<State, 2> states;
public:
	StateManager();
	~StateManager();
	State *getCurrentState();
	void goTo(State::state nextState);
};

