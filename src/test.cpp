#include <iostream>
#include <unordered_map>
#include <array>
#include <algorithm>
#include "/home/saszombie/raylib-cpp/include/raylib-cpp.hpp"



int main()
{
    constexpr size_t MAX_PLAYERS = 2;
    constexpr size_t width = 300, height = 200;


    raylib::Window window{width, height, "Game"};
    SetTargetFPS(60);
    while (!window.ShouldClose())
    {
        BeginDrawing();
        // DrawCircle(20, 20, 20, RED);
        // DrawTriangle({20 - 5, 20 - 10}, {20, 20 + 7}, {20 + 5, 20 - 10}, RED);
        DrawRing((Vector2){ width / 2, height / 2 }, 100, 50, 0, 360, 32, RED);
        EndDrawing();
    }
}
