// thread example
#include <iostream>  
#include "Entities/Entity.h"
#include "Systems/HealthSystem.h"
#include "Systems/AISystem.h"
#include "Systems/FXSystem.h"
#include "Systems/GamePadSystem.h"
#include "Systems/PhysicsSystem.h"
#include <SFML/Graphics.hpp>

int main()
{

	//HealthSystem healthSytem = HealthSystem();
	//AISystem aiSystem;
	//FXSystem fxSystem = FXSystem();
	//PhysicsSystem physicsSystem = PhysicsSystem();
	//GamePadSystem gamePadSystem = GamePadSystem();

	Entity player, dog, troll, orc, cat, pig;

	// setup player
	PhysicsSystem::addPhysicsComponent(player.entityId());
	FXSystem::addFXComponent(player.entityId());

	// setup dog
	AISystem::addAIComponent(dog.entityId());
	PhysicsSystem::addPhysicsComponent(dog.entityId());
	GamePadSystem::addGamePadComponent(dog.entityId());

	//setup troll
	AISystem::addAIComponent(troll.entityId());
	FXSystem::addFXComponent(troll.entityId());

	// set up orc
	AISystem::addAIComponent(orc.entityId());
	PhysicsSystem::addPhysicsComponent(orc.entityId());

	// set up cat
	AISystem::addAIComponent(cat.entityId());
	PhysicsSystem::addPhysicsComponent(cat.entityId());
	FXSystem::addFXComponent(cat.entityId());

	// set up pig
	AISystem::addAIComponent(pig.entityId());
	PhysicsSystem::addPhysicsComponent(pig.entityId());
	FXSystem::addFXComponent(pig.entityId());

	PhysicsSystem::update();
	GamePadSystem::update();
	PhysicsSystem::update();
	FXSystem::update();

	// update and test pooling 
	std::cout << "===================TEST POOLING====================" << std::endl;
	AISystem::update();
	std::cout << "Remove AI PIG" << std::endl;
	AISystem::removeAIComponent(pig.entityId());
	AISystem::update();

	std::cout << "Add AI PIG" << std::endl;
	AISystem::addAIComponent(pig.entityId());
	AISystem::update();


	// update and test pooling 
	std::cout << "===================TEST DESTROY Player ENTITY====================" << std::endl;

	int playerEntityID = player.entityId();


	std::cout << "Player not destroyed first 2 should come out as true (1) " << std::endl;
	std::cout << PhysicsSystem::hasPhysicsComponent(playerEntityID) << std::endl;
	std::cout << FXSystem::hasFXComponent(playerEntityID) << std::endl;
	std::cout << AISystem::hasAIComponent(playerEntityID) << std::endl;
	std::cout << GamePadSystem::hasGamePadComponent(playerEntityID) << std::endl;
	std::cout << HealthSystem::hasHealthComponent(playerEntityID) << std::endl;

	player.~Entity();

	std::cout << "Player destroyed everthing should cout as false (0) " << std::endl;

	std::cout << PhysicsSystem::hasPhysicsComponent(playerEntityID) << std::endl;
	std::cout << FXSystem::hasFXComponent(playerEntityID) << std::endl;
	std::cout << AISystem::hasAIComponent(playerEntityID) << std::endl;
	std::cout << GamePadSystem::hasGamePadComponent(playerEntityID) << std::endl;
	std::cout << HealthSystem::hasHealthComponent(playerEntityID) << std::endl;

	
	return 0;
}