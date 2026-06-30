#include "classes/bar.h"
#include "raylib.h"
#include "utils/constants.h"
#include <iostream>
#include <vector>


std::vector<Bar> bars;

void InitializeBars();
void GenerateBars();


int main()
{
    InitWindow(windowWidth, windowHeight, "Visualizer");
    SetTargetFPS(60);

    InitializeBars();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        {
            GenerateBars();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void InitializeBars()
{
    constexpr float barArea = windowWidth / 2;
    constexpr int numBars = barArea / (barWidth + gap);

    for (int i = 0; i < numBars; ++i)
    {
        float posX = (windowWidth / 3) + i * (barWidth + gap);
        bars.push_back(
                Bar{ posX, windowHeight, barWidth, 200 }
                );
    }
}

void GenerateBars()
{
    for (const auto& bar : bars)
        bar.Draw();
}
