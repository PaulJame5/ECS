#pragma once
#include "../Components/AIComponent.h"

class AISystem
{

public:
	AISystem() {};
	~AISystem() {};

	static void addAIComponent(int entityId)
	{
		if (hasAIComponent(entityId))
		{
			return;
		}
		if (availablePool.size() > 0)
		{
			entities[entityId] = availablePool.at(0);
			availablePool.erase(availablePool.begin());
			return;
		}

		// No more available to add from Pool create new and add to map
		entities[entityId] = AIComponent();
	}

	static AIComponent getAIComponent(int entityId)
	{
		if (hasAIComponent(entityId))
		{
			std::map<int, AIComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	static void removeAIComponent(int entityId)
	{
		if (hasAIComponent(entityId))
		{
			availablePool.push_back(getAIComponent(entityId));
			entities.erase(entityId);
		}
	}

	static bool hasAIComponent(int entityId)
	{
		std::map<int, AIComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	static void update()
	{
		std::map<int, AIComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "Entity ID: " << it->first << ", AI Component Updated!" << std::endl;
		}
	}

private:
	static std::vector<AIComponent> availablePool;
	static std::map<int, AIComponent> entities;
};

std::vector<AIComponent> AISystem::availablePool = std::vector<AIComponent>();
std::map<int, AIComponent> AISystem::entities = {};
