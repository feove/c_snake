#include "../headers/terrain.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Terrain *terrain = NULL;

void grid_init(struct Grid *grid){

    grid->cells = malloc(HEIGHT * sizeof *grid->cells);

    if (grid->cells == NULL) {
        puts("Failed Grid init");
        exit(1);
    }

    for (int j = 0; j < HEIGHT; ++j){

        grid->cells[j] = malloc(WIDTH * sizeof *grid->cells[j]);

        if (grid->cells[j] == NULL) {


            for (int k = 0; k < j; ++k){

                free(grid->cells[k]);
            }

            free(grid->cells);

            puts("Failed Grid init");
            exit(1);
        }

        for (int k = 0; k < WIDTH; ++k){

            grid->cells[j][k].snake_in = 0;

        }
    }

    //Harcode test

    grid->cells[4][5].snake_in = 1;
    grid->cells[5][5].snake_in = 1;
    grid->cells[6][5].snake_in = 1;
}

void grid_deinit(struct Grid *grid){


    for (int k = 0; k < terrain->height; ++k){

        free(grid->cells[k]);
    }

    free(grid->cells);
}

void terrain_init(void){

	terrain = malloc(sizeof(struct Terrain));

	if (terrain == NULL){
		puts("Failed Malloc");
	}

	terrain->width = WIDTH;
	terrain->height = HEIGHT;

	grid_init(&terrain->grid);

	return;
}

void terrain_deinit(void){

    grid_deinit(&terrain->grid);
    free(terrain);
    terrain = NULL;

    //need to free others attr btw
}

void display_terrain(void) {
    if (terrain == NULL){

        return;
    }

    size_t line_len = terrain->width * 2 + 1;
    char *line = malloc(line_len + 1);

    if (!line) {
        puts("Failed display allocation");
        return;
    }

    for (int j = 0; j < terrain->height; ++j){
        int pos = 0;

        for (int i = 0; i < terrain->width; ++i){
            char edge = (i == 0) ? '[' : '|';
            char cell = terrain->grid.cells[j][i].snake_in ? 'X' : ' ';

            line[pos++] = edge;
            line[pos++] = cell;
        }

        line[pos++] = ']';
        line[pos] = '\0';
        puts(line);
    }

    free(line);
}



void hello_terrain(void){

	if (terrain == NULL){
		printf("Terrain is Null\n");
		exit(1);
	}

	display_terrain();
}
