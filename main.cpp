#include "raylib.h"
#include "utils/constants.h"


int main()
{
    InitWindow(windowWidth, windowHeight, "Visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);



        EndDrawing();
    }

    CloseWindow();

    return 0;
}
