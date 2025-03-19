
#include "raylib.h"
#include "Player.h"

int main()
{
    InitWindow(800, 450, "Programming Workshop!");
    SetTargetFPS(60);

    Player player {};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground({30, 30, 30, 255});

        player.Update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
