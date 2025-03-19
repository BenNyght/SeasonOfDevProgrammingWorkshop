
#include "Player.h"
#include "raylib.h"
#include "Input.h"

Player::Player()
{
	Spawn();
}

void Player::Update()
{
	const float movementSpeed = 2.5f;
	Vector2 movementDirection = Input::GetMovementDirection();
	Move(movementDirection, movementSpeed);

	Draw();
}

void Player::Spawn()
{
	rec.x = 30;
	rec.y = 30;
	rec.height = 30;
	rec.width = 30;
	colour = { 35, 121, 174, 255 };
}
