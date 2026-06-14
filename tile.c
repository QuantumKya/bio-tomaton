#include "tile.h"
#include <stdint.h>

Tile getTileAt(short x, short y) {
    Tile t;

    if (x >= worldSize || y >= worldSize) {
        t.present = false;
        return t;
    }

    const int idx = x + y*worldSize;
    uint8_t* datum = &tileData[idx];
    
    int typeFlag = (*datum >> 2) & 3;
    int dirFlag = (*datum >> 0) & 3;

    t.present = (bool)(*datum >> 4);
    t.type = (enum TileType)typeFlag;
    t.dir = (enum Orientation)dirFlag;
    return t;
}

void createTile(short x, short y, enum TileType typ, enum Orientation dir) {
    int typeFlag = (int)typ;
    int dirFlag = (int)dir;
    uint8_t datum = (1 << 4) + (typeFlag << 2) + dirFlag;

    const int idx = x + y*worldSize;
    tileData[idx] = datum;
}
void addTile(short x, short y, Tile t) {
    createTile(x, y, t.type, t.dir);
}