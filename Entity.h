#pragma once
#include <iostream>
#include <vector>
#include <map>

// Will auto increment when new entity created
static int availableEntityId = 0;

class Entity
{
	int entityId_;
public:
	Entity() { this->entityId_ = availableEntityId++; }
	~Entity() {};

	int entityId() const { return entityId_; }
	
private:
};