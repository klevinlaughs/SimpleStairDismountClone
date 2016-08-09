#include "StateManager.h"	  
#include "StateReady.h"
#include "StateDismount.h"
#include "BulletCollision/CollisionShapes/btStaticPlaneShape.h"
#include "btBulletDynamicsCommon.h" // motionstate

StateManager::StateManager()
{
	initWorld();
	initRagdoll();
	states[0] = new StateReady(world, ragdoll);
	states[1] = new StateDismount(world, ragdoll);
	currentState = states[0];
}


StateManager::~StateManager()
{
	// TODO : delete other objects	delete the *ground	  

	// delete ragdoll first
	delete ragdoll;

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


void StateManager::initWorld()
{	
	// reference : http://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-a-physics-library/
	broadphase = new btDbvtBroadphase();
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	solver = new btSequentialImpulseConstraintSolver();

	world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
	world->setGravity(btVector3(0, (btScalar) -9.81, 0));

	{
		btCollisionShape *ground = new btStaticPlaneShape(btVector3(0, 1, 0), 1);

		btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0,0,0)));

		btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, ground, btVector3(0, 0, 0));

		btRigidBody *groundRigidBody = new btRigidBody(groundRigidBodyCI);

		world->addRigidBody(groundRigidBody);
	}
}

void StateManager::initRagdoll()
{
	ragdoll = new Ragdoll(world, 2.0);
}


State *StateManager::getCurrentState()
{
	return currentState;
}

void StateManager::goTo(state nextState)
{
	currentState->exit();
	currentState = states[nextState];
	currentState->init();
}
