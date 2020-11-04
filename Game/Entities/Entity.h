#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "../Systems/HealthSystem.h"
#include "../Systems/AISystem.h"
#include "../Systems/FXSystem.h"
#include "../Systems/GamePadSystem.h"
#include "../Systems/PhysicsSystem.h"

// Will auto increment when new entity created
static int availableEntityId = 0;

class Entity
{
	int entityId_;
public:
	Entity() 
	{ 
		if (pool.size() > 0)
		{
			this->entityId_ = pool.at(0);
			pool.erase(pool.begin());
			return;
		}
		this->entityId_ = availableEntityId++; 
	}
	~Entity()
	{ 
		pool.push_back(entityId_); 
		// Destroy/Remove all components 
		AISystem::removeAIComponent(entityId_);
		FXSystem::removeFXComponent(entityId_);
		GamePadSystem::removeGamePadComponent(entityId_);
		HealthSystem::removeHealthComponent(entityId_);
		PhysicsSystem::removePhysicsComponent(entityId_);
	};

	int entityId() const { return entityId_; }
	
private:
	std::vector<int> pool;
};