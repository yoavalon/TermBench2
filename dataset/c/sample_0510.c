#include <stdio.h>
#include <stdlib.h>

typedef struct FluidCell {
    int state;
} FluidCell;

void FluidCell_init(FluidCell *cell, int state) {
    cell->state = state;
}

void FluidCell_update_state(FluidCell *cell, FluidCell **neighbors, int num_neighbors) {
    int active_neighbors = 0;
    for (int i = 0; i < num_neighbors; i++) {
        if (neighbors[i]->state == 1) {
            active_neighbors++;
        }
    }
    if (active_neighbors == 2 || active_neighbors == 3) {
        cell->state = 1;
    } else {
        cell->state = 0;
    }
}

typedef struct Grid {
    int size;
    FluidCell **grid;
} Grid;

void Grid_init(Grid *grid, int size) {
    grid->size = size;
    grid->grid = (FluidCell **)malloc(size * sizeof(FluidCell *));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (FluidCell *)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            FluidCell_init(&grid->grid[i][j], 0);
        }
    }
}

int get_neighbors(Grid *grid, int x, int y, FluidCell **neighbors) {
    int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    int num_neighbors = 0;
    for (int i = 0; i < 8; i++) {
        int dx = directions[i][0], dy = directions[i][1];
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < grid->size && ny >= 0 && ny < grid->size) {
            neighbors[num_neighbors++] = &grid->grid[nx][ny];
        }
    }
    return num_neighbors;
}

void Grid_update_grid(Grid *grid) {
    FluidCell **new_grid = (FluidCell **)malloc(grid->size * sizeof(FluidCell *));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (FluidCell *)malloc(grid->size * sizeof(FluidCell));
        for (int j = 0; j < grid->size; j++) {
            FluidCell_init(&new_grid[i][j], grid->grid[i][j].state);
        }
    }

    for (int x = 0; x < grid->size; x++) {
        for (int y = 0; y < grid->size; y++) {
            FluidCell *neighbors[8];
            int num_neighbors = get_neighbors(grid, x, y, neighbors);
            FluidCell_update_state(&new_grid[x][y], neighbors, num_neighbors);
        }
    }

    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    grid->grid = new_grid;
}

void main() {
    int grid_size = 50;
    Grid simulation;
    Grid_init(&simulation, grid_size);
    while (1) {
        Grid_update_grid(&simulation);
    }
}