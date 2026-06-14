#include "include/raylib.h"
#include "include/raymath.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "chunk.h"

const int worldSize = 2048;
uint8_t* tileData;
volatile Vector2* camPos;
volatile float* zoom;

bool initMemory() {
    tileData = malloc(worldSize*worldSize);
    if (tileData == NULL) return false;

    camPos = malloc(sizeof(Vector2));
    if (camPos == NULL) return false;
    zoom = malloc(sizeof(float));
    if (zoom == NULL) return false;

    camPos->x = 0.0f;
    camPos->y = 0.0f;
    *zoom = 50.0f;
    
    return true;
}

Vector2 getMouseTile() {
    Vector2 mp = GetMousePosition();

    Vector2 vout = Vector2Add(mp, *camPos);
    vout = Vector2Scale(vout, 1 / *zoom);
    vout.x = floorf(vout.x); vout.y = floorf(vout.y);
    return vout;
}