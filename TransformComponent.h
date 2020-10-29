#pragma once
#include "Component.h"


class TransformComponent : public Component
{
public:
	TransformComponent() {};
	~TransformComponent() {};

private:
	struct Position
	{
		float x = 0;
		float y = 0;
		float z = 0;
	} position;

	struct Rotation
	{
		float x = 0;
		float y = 0;
		float z = 0;
	} rotation;

	struct Scale
	{
		float x = 0;
		float y = 0;
		float z = 0;
	} scale;
};