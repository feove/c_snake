#ifndef TERRAIN_H
#define TERRAIN_H

#define WIDTH 16
#define HEIGHT 16

struct Cell {
    int snake_in;
};

struct Grid {
    struct Cell **cells;
};

struct Terrain {
    int width;
    int height;
    struct Grid grid;
};

void terrain_init(void);
void hello_terrain(void);
void terrain_deinit(void);

#endif
