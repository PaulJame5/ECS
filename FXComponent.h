#pragma once
#include "Component.h"



class FXComponent : public Component
{
public:
	FXComponent() {};
	~FXComponent() {};

	void setSparkleFX() { fxType = 1; }
	void setExplosionFX() { fxType = 2; }

	int getFXType() { return this->fxType; }
private:

	int fxType = 0;
};