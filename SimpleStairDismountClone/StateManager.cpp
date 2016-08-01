#include "StateManager.h"
#include "State.h"

StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

State *StateManager::getCurrentState()
{
	//return &currentState;
	return nullptr;
}

void StateManager::goTo(State::state nextState)
{
	switch (nextState)
	{
		case State::READY:
			return;
		case State::DISMOUNT:
			return;
	}
}
