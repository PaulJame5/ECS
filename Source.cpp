// thread example
#include <iostream>       // std::cout
#include "Global.h"
#include "Entity.h"


int main()
{

	Entity player, dog, troll, orc, cat, pig;

	// setup player
	physicsSystem.addPhysicsComponent(player.entityId());
	fxSystem.addFXComponent(player.entityId());

	// setup dog
	aiSystem.addAIComponent(dog.entityId());
	physicsSystem.addPhysicsComponent(dog.entityId());
	gamePadSystem.addGamePadComponent(dog.entityId());

	//setup troll
	aiSystem.addAIComponent(troll.entityId());
	fxSystem.addFXComponent(troll.entityId());

	// set up orc
	aiSystem.addAIComponent(orc.entityId());
	physicsSystem.addPhysicsComponent(orc.entityId());

	// set up cat
	aiSystem.addAIComponent(cat.entityId());
	physicsSystem.addPhysicsComponent(cat.entityId());
	fxSystem.addFXComponent(cat.entityId());

	// set up pig
	aiSystem.addAIComponent(pig.entityId());
	physicsSystem.addPhysicsComponent(pig.entityId());
	fxSystem.addFXComponent(pig.entityId());

	gamePadSystem.update();
	physicsSystem.update();
	fxSystem.update();
	aiSystem.update();
	healthSytem.update();


	
	return 0;
}