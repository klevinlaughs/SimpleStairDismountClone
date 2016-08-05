#pragma once
#include "State.h"								  
#include "BulletCollision/BroadphaseCollision/btDbvtBroadphase.h"	   
#include "BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h"
#include "BulletCollision/CollisionDispatch/btCollisionDispatcher.h"
#include "BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h"
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "Ragdoll.h"
#include <array>

class StateManager
{
private:
	Ragdoll *ragdoll;
	btBroadphaseInterface *broadphase;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;
	btDiscreteDynamicsWorld *world;

	State *currentState;
	State *_states[2];

	void initWorld();
	void initRagdoll();
public:
	enum state { READY, DISMOUNT };
	StateManager();
	~StateManager();
	State *getCurrentState();
	void goTo(state nextState);
};

