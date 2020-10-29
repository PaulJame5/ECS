#pragma once
#include "Component.h"


class GamePadComponent : public Component
{
public:
	GamePadComponent() {};
	~GamePadComponent() {};

	bool getUp() { return up; };
	bool getDown() { return down; };
	bool getLeft() { return left; };
	bool getRight() { return right; };

	void setUp(bool up) { this->up = up; };
	void setDown(bool down) { this->down = down; };
	void setLeft(bool left) { this->left = left; };
	void setRight(bool right) { this->right = right; };
private:
	bool up = false, down = false, left = false, right = false;
};