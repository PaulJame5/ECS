#pragma once
#include "Entity.h"
#include "Systems.h"
#include "PhysicsComponent.h"


class PhysicsSystem
{
	std::map<int, PhysicsComponent> entities;

public:
	PhysicsSystem() {};
	~PhysicsSystem() {};


	void addPhysicsComponent(int entityId)
	{
		if (hasPhysicsComponent(entityId))
		{
			return;
		}
		entities[entityId] = PhysicsComponent();
	}

	PhysicsComponent getPhysicsComponent(int entityId)
	{
		if (hasPhysicsComponent(entityId))
		{
			std::map<int, PhysicsComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	void removePhysicsComponent(int entityId)
	{
		if (hasPhysicsComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	bool hasPhysicsComponent(int entityId)
	{
		std::map<int, PhysicsComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	void update()
	{
		std::map<int, PhysicsComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "Entity ID: " << it->first << ", Physics Component Updated!" << std::endl;
		}
	}

private:


};