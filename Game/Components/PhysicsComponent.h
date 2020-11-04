#pragma once
#include "Component.h"


struct Velocity
{
	float x;
	float y;
	Velocity()
	{
		 x = 0;
		 y = 0;
	};

	Velocity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};
class PhysicsComponent : public Component
{
	
public:
	PhysicsComponent() { };
	~PhysicsComponent() {};

	

	void setGravityScale(float gravityScale) { this->gravityScale = gravityScale; }

	void setVelocity(Velocity v) 
	{
		std::cout << "before: x: " << velocity.x << " before: y: " << velocity.y << std::endl;
		std::cout << "applying: x: " << v.x << " applying: y " << v.y << std::endl;
		velocity = v;
		std::cout << "After: x " << velocity.x << " After: y" << velocity.y << std::endl;
	}
	float getGravityScale() { return gravityScale; }
	Velocity getVelocity() { return velocity; }
private:

	float gravityScale = 0;

	Velocity velocity = Velocity(0, 0);
};
