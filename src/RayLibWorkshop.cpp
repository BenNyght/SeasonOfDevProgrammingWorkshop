
#include "raylib.h"
#include "Player.h"
#include "Asteroid.h"
#include "Input.h"

int main()
{
    InitWindow(800, 450, "Programming Workshop!");
    SetTargetFPS(60);

    Player player {};
    Asteroid asteroids[30];
    int gameOver = false;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground({30, 30, 30, 255});

        if (gameOver) 
        {
            DrawText("Move [WASD] to play again", 20, 80, 40, GRAY);

            Vector2 movementDirection = Input::GetMovementDirection();
            if (movementDirection.x != 0 || movementDirection.y != 0) 
            {
                gameOver = false;

                player.Spawn();
                for (int i = 0; i < 30; i++)
                {
                    asteroids[i].Spawn();
                }
            }
        }
        else
        {
            player.Update();
            for (int i = 0; i < 30; i++)
            {
                asteroids[i].Update();

                if (CheckCollisionRecs(player.rec, asteroids[i].rec)) 
                {
                    gameOver = true;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
