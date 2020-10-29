#pragma once
#include "../Entities/Entity.h"
#include "../Components/GamePadComponent.h"
#include "../Systems/PhysicsSystem.h"

class GamePadSystem
{
public:

	GamePadSystem() { };
	~GamePadSystem() { };

	static void addGamePadComponent(int entityId)
	{
		if (hasGamePadComponent(entityId))
		{
			return;
		}
		entities[entityId] =  GamePadComponent();
	}

	static GamePadComponent getGamePadComponent(int entityId)
	{
		if (hasGamePadComponent(entityId))
		{
			std::map<int, GamePadComponent>::iterator it = entities.find(entityId);
			return it->second;
		}
	}

	static void removeGamePadComponent(int entityId)
	{
		if (hasGamePadComponent(entityId))
		{
			entities.erase(entityId);
		}
	}

	static bool hasGamePadComponent(int entityId)
	{
		std::map<int, GamePadComponent>::iterator it = entities.find(entityId);

		if (it != entities.end())
		{
			return true;
		}
		return false;
	}
	static void update()
	{
		std::map<int, GamePadComponent>::iterator it = entities.begin();
		for (; it != entities.end(); it++)
		{
			std::cout << "before update Input Entity ID: " << it->first << std::endl;

			if (it->second.getDown() == false)
			{
				Velocity vel = Velocity(5, 5);
				std::cout << "gamePadUpdate x" << vel.x << std::endl;
				std::cout << "gamePadUpdate y" << vel.y << std::endl;
				PhysicsSystem::jumpForce(it->first, vel);
				std::cout << "gamePadUpdate " << it->first << std::endl;
				std::cout << "phys x" << PhysicsSystem::getPhysicsComponent(it->first).getVelocity().x << std::endl;
				std::cout << "phys y" << PhysicsSystem::getPhysicsComponent(it->first).getVelocity().y << std::endl;
			}

			std::cout << "end of update Input Entity ID: " << it->first << std::endl;
			//std::cout << "physics component gravity: " << physicsSystem.getPhysicsComponent(it->first).getGravityScale() << std::endl;

			std::cout << "Entity ID: " << it->first << ", Game Pad Component Updated!" << std::endl;
		}
	}


private:
	static std::map<int, GamePadComponent> entities;
	static std::vector< GamePadComponent> pool;

};

std::map<int, GamePadComponent> GamePadSystem::entities = {};
std::vector<GamePadComponent> GamePadSystem::pool = std::vector<GamePadComponent>();

	