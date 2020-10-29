#pragma once
#include "Component.h"



class PhysicsComponent : public Component
{
	
public:
	PhysicsComponent() {};
	~PhysicsComponent() {};

	  struct Velocity
	  {
		  float x = 0;
		  float y = 0;
	  };

	void setGravityScale(float gravityScale) { this->gravityScale = gravityScale; }
	void setVelocity(Velocity velocity) { this->velocity = velocity; }
	float getGravityScale() { return gravityScale; }
private:

	float gravityScale = 0;

	Velocity velocity;
};
