
#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Programming Workshop!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        Rectangle rec { 30, 30, 30, 30 };
        Color color { 35, 121, 174, 255 };
        DrawRectangleRec(rec, color);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
