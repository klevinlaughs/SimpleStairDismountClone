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

void StateManager::goTo(state nextState)
{
	switch (nextState)
	{
		case READY:
			return;
		case DISMOUNT:
			return;
	}
}
