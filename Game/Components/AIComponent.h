#pragma once
#include "Component.h"


class AIComponent : public Component
{
public :
	AIComponent() {};
	~AIComponent() {};

	int getState() { return state; }

	void setState(int state) { this->state = state; }

private :
	int state = 0;
};