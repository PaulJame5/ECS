#pragma once
#include "../Components/PhysicsComponent.h"


static bool set = false;
class PhysicsSystem
{

public:
	PhysicsSystem() {};
	~PhysicsSystem() {};

	static void addPhysicsComponent(int entityId)
	{
		if (hasPhysicsComponent(entityId))
		{
			return;
		}
		entities[entityId] = PhysicsComponent();
	}

	static PhysicsComponent getPhysicsComponent(int entityId)
	{
		if (hasPhysicsComponent(entityId))
		{
			std::map<int, PhysicsComponent>::iterator it = entities.find(entityId);
			std::cout << "Physics Has Entity of ID: " << entityId << std::endl;
			return it->second;
		}

	}

	static void removePhysicsComponent(int entityId)
	{
		if (hasPhysicsComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	static bool hasPhysicsComponent(int entityId)
	{
		std::map<int, PhysicsComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	static void update()
	{
		std::map<int, PhysicsComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "Entity ID: " << it->first << ", Velocity X: " << it->second.getVelocity().x << ", Velocity Y: " << it->second.getVelocity().y << std::endl;
			std::cout << "Entity ID: " << it->first << ", Physics Component Updated!" << std::endl;

			if (!set)
			{
				std::cout << "============================================================" << std::endl;
				it->second.setVelocity(Velocity(2, 3));
				std::cout << "Entity ID: " << it->first << ", Velocity X: " << it->second.getVelocity().x << ", Velocity Y: " << it->second.getVelocity().y << std::endl;

				std::cout << "============================================================" << std::endl;
				set = true;
			}
		}
	}


	static void jumpForce(int entityID, Velocity v)
	{

		std::map<int, PhysicsComponent>::iterator it = entities.find(entityID);
		if (it != entities.end())
		{
			it->second.setVelocity(v);
		}
	}

private:
	static std::map<int, PhysicsComponent> entities;
	static std::vector<PhysicsComponent> pool;

};

std::map<int, PhysicsComponent> PhysicsSystem::entities = {};
std::vector<PhysicsComponent> PhysicsSystem::pool = std::vector<PhysicsComponent>();