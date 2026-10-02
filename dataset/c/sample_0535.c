#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int state;
} Cell;

void Cell_update(Cell* self, Cell** neighbors, int num_neighbors) {
    int alive_neighbors = 0;
    for (int i = 0; i < num_neighbors; i++) {
        if (neighbors[i]->state == 1) {
            alive_neighbors++;
        }
    }
    if (self->state == 1) {
        if (alive_neighbors < 2 || alive_neighbors > 3) {
            self->state = 0;
        }
    } else if (alive_neighbors == 3) {
        self->state = 1;
    }
}

typedef struct Grid {
    int width;
    int height;
    Cell** grid;
} Grid;

Cell** Grid_get_neighbors(Grid* self, int x, int y) {
    Cell** neighbors = (Cell**)malloc(8 * sizeof(Cell*));
    int index = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < self->width && ny >= 0 && ny < self->height) {
                neighbors[index++] = &self->grid[nx][ny];
            }
        }
    }
    return neighbors;
}

void Grid_update(Grid* self) {
    Cell** new_grid = (Cell**)malloc(self->width * sizeof(Cell*));
    for (int x = 0; x < self->width; x++) {
        new_grid[x] = (Cell*)malloc(self->height * sizeof(Cell));
        for (int y = 0; y < self->height; y++) {
            Cell* cell = &self->grid[x][y];
            Cell** neighbors = Grid_get_neighbors(self, x, y);
            int num_neighbors = 8; // 8 possible neighbors in a 3x3 grid
            Cell_update(cell, neighbors, num_neighbors);
            free(neighbors);
        }
    }
    for (int x = 0; x < self->width; x++) {
        free(self->grid[x]);
    }
    free(self->grid);
    self->grid = new_grid;
}

void main() {
    int width = 10;
    int height = 10;
    int initial_state[10][10] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Grid grid;
    grid.width = width;
    grid.height = height;
    grid.grid = (Cell**)malloc(width * sizeof(Cell*));
    for (int x = 0; x < width; x++) {
        grid.grid[x] = (Cell*)malloc(height * sizeof(Cell));
        for (int y = 0; y < height; y++) {
            grid.grid[x][y].state = initial_state[x][y];
        }
    }
    while (1) {
        Grid_update(&grid);
    }
}