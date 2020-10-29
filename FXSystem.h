#pragma once
#include "Entity.h"
#include "Systems.h"
#include "FXComponent.h"


class FXSystem
{
	std::map<int, FXComponent> entities;

public:
	void addFXComponent(int entityId)
	{
		if (hasFXComponent(entityId))
		{
			return;
		}
		entities[entityId] = FXComponent();
	}

	FXComponent getFXComponent(int entityId)
	{
		if (hasFXComponent(entityId))
		{
			std::map<int, FXComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	void removeFXComponent(int entityId)
	{
		if (hasFXComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	bool hasFXComponent(int entityId)
	{
		std::map<int, FXComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}

	void update()
	{
		std::map<int, FXComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "Entity ID: " << it->first << ", FX Component Updated!" << std::endl;
		}
	}

private:


};