
#pragma once

#include "Object.h"

class Asteroid : public Object
{
public:
	Asteroid();

	void Update();
	void Spawn();
};