
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
    int score = 0;

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

                score = 0;
                player.Spawn();
                for (int i = 0; i < 30; i++)
                {
                    asteroids[i].Spawn();
                }
            }
        }
        else
        {
            score += 1;

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

        DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
