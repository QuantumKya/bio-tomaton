#include "include/raylib.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

extern const int worldSize;

// tile data is stored as follows:
// upper bit: empty flag (0 = empty, 1 = full),
// next 2 bits: type flag (as per enum TileType in tile.h),
// last 2 bits: orientation flag (as per enum Orientation in tile.h)
extern uint8_t* tileData;

extern volatile Vector2* camPos;
extern volatile float* zoom; // in pixels per tile

bool initMemory();

Vector2 getMouseTile();