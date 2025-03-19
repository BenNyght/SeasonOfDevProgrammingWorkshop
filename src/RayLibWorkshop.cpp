
#include "raylib.h"
#include "Player.h"
#include "Asteroid.h"

int main()
{
    InitWindow(800, 450, "Programming Workshop!");
    SetTargetFPS(60);

    Player player {};
    Asteroid asteroids[30];

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground({30, 30, 30, 255});

        player.Update();
        for (size_t i = 0; i < 30; i++)
        {
            asteroids[i].Update();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
