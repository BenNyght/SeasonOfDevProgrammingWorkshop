
#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Programming Workshop!");
    SetTargetFPS(60);

    Rectangle rec { 30, 30, 30, 30 };
    Color color { 35, 121, 174, 255 };

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground({30, 30, 30, 255});

        float movementSpeed = 2.5f;
        if (IsKeyDown(KEY_D)) 
        {
            rec.x += movementSpeed;
        }
        if (IsKeyDown(KEY_A)) 
        {
            rec.x -= movementSpeed;
        }
        if (IsKeyDown(KEY_W)) 
        {
            rec.y -= movementSpeed;
        }
        if (IsKeyDown(KEY_S)) 
        {
            rec.y += movementSpeed;
        }

        DrawRectangleRec(rec, color);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
