#include "include/raylib.h"
#include "include/raymath.h"
#include "include/rlgl.h"
#include <math.h>
#include <stdio.h>

#include "chunk.h"
#include "tile.h"

#define SCR_W 1080
#define SCR_H 720



int main() {

    // init memory
    if (!initMemory()) {
        printf("Failed to initialize memory, quitting...");
        return 1;
    }

    // init graphics
    InitWindow(SCR_W, SCR_H, "Bio-tomaton!");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // input stuff
        *zoom += GetMouseWheelMove();
        int kP = GetKeyPressed();
        Vector2 cMove = Vector2Zero();
        switch (kP) {
            case KEY_W:
                cMove.y -= 1;
                break;
            case KEY_A:
                cMove.x -= 1;
                break;
            case KEY_S:
                cMove.y += 1;
                break;
            case KEY_D:
                cMove.x += 1;
                break;
            default:
                break;
        }
        *camPos = Vector2Add(*camPos, cMove);

        // draw loop
        BeginDrawing();
            DrawRectangle(0, 0, SCR_W, SCR_H, BLACK);
            DrawText("Stuff Here", 10, 10, 20, WHITE);

            const Vector2 mP = getMouseTile();
            DrawText(TextFormat("(%02i, %02i)", (int)mP.x, (int)mP.y), SCR_W - 100, 10, 20, WHITE);
            
            float z = *zoom;
            int timesX = ceilf((float)SCR_W / z); float offsetX = z - fmodf(camPos->x, z);
            int timesY = ceilf((float)SCR_H / z); float offsetY = z - fmodf(camPos->y, z);
            for (int i = 0; i <= timesX; i++) {
                float x = offsetY + i*z;
                DrawLine(x, 0, x, SCR_H, GRAY);
            }
            for (int j = 0; j <= timesY; j++) {
                float y = offsetY + j*z;
                DrawLine(0, y, SCR_W, y, GRAY);
            }

        EndDrawing();
    }

    return 0;
}