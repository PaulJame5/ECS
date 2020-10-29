#pragma once
#include "Entity.h"
#include "Systems.h"
#include "HealthComponent.h"


class HealthSystem
{
	std::map<int, HealthComponent> entities;

public:
	void addHealthComponent(int entityId)
	{
		if (hasHealthComponent(entityId))
		{
			return;
		}
		entities[entityId] = HealthComponent();
	}

	HealthComponent getHealthComponent(int entityId)
	{
		if (hasHealthComponent(entityId))
		{
			std::map<int, HealthComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	void removeHealthComponent(int entityId)
	{
		if (hasHealthComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	bool hasHealthComponent(int entityId)
	{
		std::map<int, HealthComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	void update() 
	{
		std::map<int, HealthComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++ ) 
		{ 
			std::cout << "Entity ID: " << it->first << ", Health Component Updated!" << std::endl;
		} 
	}

private:


};