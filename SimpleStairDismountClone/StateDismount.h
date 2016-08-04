#pragma once
#include "State.h"							  
#include "BulletCollision/BroadphaseCollision/btDbvtBroadphase.h"	   
#include "BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h"
#include "BulletCollision/CollisionDispatch/btCollisionDispatcher.h"
#include "BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h"
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "Ragdoll.h"

class StateDismount :
	public State
{
private:
	std::string name = "DISMOUNT";
	btBroadphaseInterface *broadphase;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;
	btDiscreteDynamicsWorld *world;
	Ragdoll *ragdoll;

public:
	StateDismount();
	~StateDismount();
	void init();
	void enter();
	void exit();
	void draw();
	void update();
	std::string getName();
};

