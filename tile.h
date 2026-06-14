#include <stdbool.h>

#include "chunk.h"

enum TileType {
    BONE,
    TISSUE,
    MOTOR,
    STEM,
};
enum Orientation {
    UP, RIGHT, LEFT, DOWN
};

typedef struct {
    bool present;
    enum TileType type;
    enum Orientation dir;
} Tile;

Tile getTileAt(short x, short y);
void createTile(short x, short y, enum TileType typ, enum Orientation dir);
void addTile(short x, short y, Tile t);