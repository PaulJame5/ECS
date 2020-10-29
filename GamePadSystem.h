#pragma once
#include "Entity.h"
#include "Global.h"
#include "GamePadComponent.h"


class GamePadSystem
{
	std::map<int, GamePadComponent> entities;

public:

	GamePadSystem() { }
	~GamePadSystem() {};

	void addGamePadComponent(int entityId)
	{
		if (hasGamePadComponent(entityId))
		{
			return;
		}
		entities[entityId] = GamePadComponent();
	}

	GamePadComponent getGamePadComponent(int entityId)
	{
		if (hasGamePadComponent(entityId))
		{
			std::map<int, GamePadComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	void removeGamePadComponent(int entityId)
	{
		if (hasGamePadComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	bool hasGamePadComponent(int entityId)
	{
		std::map<int, GamePadComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}
	void update();


private:


};

void GamePadSystem::update()
{
	std::map<int, GamePadComponent>::iterator it = entities.begin();
	for (; it != entities.end(); it++)
	{
		std::cout << "before update Input Entity ID: " << it->first;
		//std::cout << "physics component gravity: " << physicsSystem.getPhysicsComponent(it->first).getGravityScale() << std::endl;
		if (it->second.getDown() == false)
		{
			physicsSystem.getPhysicsComponent(it->first).getGravityScale();
		}

		std::cout << "end of update Input Entity ID: " << it->first;
		//std::cout << "physics component gravity: " << physicsSystem.getPhysicsComponent(it->first).getGravityScale() << std::endl;

		std::cout << "Entity ID: " << it->first << ", Game Pad Component Updated!" << std::endl;
	}
}