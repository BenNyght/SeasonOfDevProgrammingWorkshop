
#include "Object.h"
#include "raylib.h"

void Object::Draw()
{
	DrawRectangleRec(rec, colour);
}

void Object::Move(Vector2 direction, float speed)
{
	rec.x += direction.x * speed;
	rec.y += direction.y * speed;
}
