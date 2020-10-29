#pragma once
#include "../Components/HealthComponent.h"


class HealthSystem
{

public:
	HealthSystem() {};
	~HealthSystem() {};


	static void addHealthComponent(int entityId)
	{
		if (hasHealthComponent(entityId))
		{
			return;
		}
		entities[entityId] = HealthComponent();
	}

	static HealthComponent getHealthComponent(int entityId)
	{
		if (hasHealthComponent(entityId))
		{
			std::map<int, HealthComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	static void removeHealthComponent(int entityId)
	{
		if (hasHealthComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	static bool hasHealthComponent(int entityId)
	{
		std::map<int, HealthComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	static void update() 
	{
		std::map<int, HealthComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++ ) 
		{ 
			std::cout << "Entity ID: " << it->first << ", Health Component Updated!" << std::endl;
		} 
	}

private:

	static std::map<int, HealthComponent> entities;
	static std::vector<HealthComponent> pool;

};


std::map<int, HealthComponent> HealthSystem::entities = {};
std::vector<HealthComponent> HealthSystem::pool = std::vector<HealthComponent>();