
#include "Input.h"

Vector2 Input::GetMovementDirection() 
{
    Vector2 movementDirection {};

	if (IsKeyDown(KEY_D)) 
    {
        movementDirection.x += 1;
    }
    if (IsKeyDown(KEY_A)) 
    {
        movementDirection.x -= 1;
    }
    if (IsKeyDown(KEY_W)) 
    {
        movementDirection.y -= 1;
    }
    if (IsKeyDown(KEY_S)) 
    {
        movementDirection.y += 1;
    }

    return movementDirection;
}