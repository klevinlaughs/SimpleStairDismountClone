#include "StateManager.h"
#include "State.h"		  
#include "StateReady.h"
#include "StateDismount.h"

StateManager::StateManager()
{
	_states[0] = new StateReady();
	_states[1] = new StateDismount();
	currentState = _states[0];
}


StateManager::~StateManager()
{
	/*for (int i = 0; i < 2;i++) {
		delete _states[i];
	}*/
	delete[] _states;
}

State *StateManager::getCurrentState()
{
	return currentState;
}

void StateManager::goTo(state nextState)
{
	switch (nextState)
	{
		case READY:
			currentState = _states[0];
			break;
		case DISMOUNT:
			currentState = _states[1];
			break;
	}

	currentState->init();
}
