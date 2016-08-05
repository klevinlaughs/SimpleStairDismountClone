#include "StateManager.h"
#include "State.h"		  
#include "StateReady.h"
#include "StateDismount.h"

StateManager::StateManager()
{
	// reference : http://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-a-physics-library/
	broadphase = new btDbvtBroadphase();
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	solver = new btSequentialImpulseConstraintSolver();

	world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
	world->setGravity(btVector3(0, -9.81, 0));

	ragdoll = new Ragdoll(world);

	_states[0] = new StateReady(world, ragdoll);
	_states[1] = new StateDismount(world, ragdoll);
	currentState = _states[0];
}


StateManager::~StateManager()
{
	// TODO : delete other objects

	// remove from memory
	delete world;
	delete solver;
	delete dispatcher;
	delete collisionConfiguration;
	delete broadphase;

	/*for (int i = 0; i < 2;i++) {
		delete _states[i];
	}*/
	//delete[] _states;
}

State *StateManager::getCurrentState()
{
	return currentState;
}

void StateManager::goTo(state nextState)
{
	currentState->exit();
	currentState = _states[nextState];
	currentState->init();
}
