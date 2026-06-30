#include "classes/bar.h"
#include "raylib.h"
#include "utils/constants.h"
#include <cmath>
#include <vector>


std::vector<Bar> bars;

void InitializeBars();
void GenerateBars();
void AmplifyBars();
void ShrinkBars();


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

            if (IsKeyPressed(KEY_SPACE))
                AmplifyBars();
            else
                ShrinkBars();

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void InitializeBars()
{
    constexpr float barArea = windowWidth;
    constexpr int numBars = barArea / (barWidth + gap);

    for (int i = 0; i < numBars; ++i)
    {
        float posX = i * (barWidth + gap);
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

void AmplifyBars()
{
    const int n = bars.size();
    if (n <= 0) return;

    for (int i = 0; i < n; ++i)
    {
        float weight = (n > 1) ? std::sin(3.1415926535f * i / (n - 1)) : 1.0f;
        bars[i].Grow(weight);
    }
}

void ShrinkBars()
{
    for (auto& bar : bars)
        bar.Shrink();
}
