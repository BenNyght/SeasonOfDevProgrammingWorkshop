
#pragma once

#include "raylib.h"

class Object 
{
public:
	void Draw();

	void Move(Vector2 direction, float speed);
	Rectangle rec { 10, 10, 10, 10 };
	Color colour { 255, 255, 255, 255 };
};