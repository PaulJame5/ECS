#pragma once
#include "Entity.h"
#include "Systems.h"
#include "AIComponent.h"

class AISystem
{
	std::map<int, AIComponent> entities;

public:
	void addAIComponent(int entityId)
	{
		if (hasAIComponent(entityId))
		{
			return;
		}
		entities[entityId] = AIComponent();
	}

	AIComponent getAIComponent(int entityId)
	{
		if (hasAIComponent(entityId))
		{
			std::map<int, AIComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	void removeAIComponent(int entityId)
	{
		if (hasAIComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	bool hasAIComponent(int entityId)
	{
		std::map<int, AIComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	void update()
	{
		std::map<int, AIComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "Entity ID: " << it->first << ", AI Component Updated!" << std::endl;
		}
	}

private:


};