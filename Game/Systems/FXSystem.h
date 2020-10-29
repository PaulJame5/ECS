#pragma once
#include "../Components/FXComponent.h"


class FXSystem
{

public:
	FXSystem() {};
	~FXSystem() {};


	static void addFXComponent(int entityId)
	{
		if (hasFXComponent(entityId))
		{
			return;
		}
		entities[entityId] = FXComponent();
	}

	static FXComponent getFXComponent(int entityId)
	{
		if (hasFXComponent(entityId))
		{
			std::map<int, FXComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	static void removeFXComponent(int entityId)
	{
		if (hasFXComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	static bool hasFXComponent(int entityId)
	{
		std::map<int, FXComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	static void update()
	{
		std::map<int, FXComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "Entity ID: " << it->first << ", FX Component Updated!" << std::endl;
		}
	}

private:

	static std::map<int, FXComponent> entities;
	static std::vector<FXComponent> availablePool;

};
std::map<int, FXComponent> FXSystem::entities = {};
std::vector<FXComponent> FXSystem::availablePool = std::vector<FXComponent>();