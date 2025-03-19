
#include "Asteroid.h"

Asteroid::Asteroid()
{
	Spawn();
}

void Asteroid::Update()
{
	Move({-1, 0}, 3);

	if (rec.x < 0) 
	{
		Spawn();
	}

	Draw();
}

void Asteroid::Spawn()
{
	rec.x = GetRandomValue(800, 1800);
    rec.y = GetRandomValue(0, 450);
}
