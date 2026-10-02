#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
} FluidCell;

typedef struct {
    FluidCell** grid;
    int size;
} FluidGrid;

void FluidCell_init(FluidCell* cell, int state) {
    cell->state = state;
}

void FluidCell_update_state(FluidCell* cell, FluidCell** neighbors, int num_neighbors) {
    int active_neighbors = 0;
    for (int i = 0; i < num_neighbors; i++) {
        if (neighbors[i]->state > 0) {
            active_neighbors++;
        }
    }
    if (active_neighbors > 4) {
        cell->state = 2;
    } else if (active_neighbors < 2) {
        cell->state = 0;
    } else {
        cell->state = 1;
    }
}

void FluidGrid_init(FluidGrid* grid, int size) {
    grid->size = size;
    grid->grid = (FluidCell**)malloc(size * sizeof(FluidCell*));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (FluidCell*)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            FluidCell_init(&grid->grid[i][j], 0);
        }
    }
}

void FluidGrid_get_neighbors(FluidGrid* grid, int x, int y, FluidCell** neighbors, int* num_neighbors) {
    *num_neighbors = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < grid->size && j >= 0 && j < grid->size && (i != x || j != y)) {
                neighbors[(*num_neighbors)++] = &grid->grid[i][j];
            }
        }
    }
}

void FluidGrid_update_grid(FluidGrid* grid) {
    FluidCell** new_grid = (FluidCell**)malloc(grid->size * sizeof(FluidCell*));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (FluidCell*)malloc(grid->size * sizeof(FluidCell));
        for (int j = 0; j < grid->size; j++) {
            FluidCell_init(&new_grid[i][j], 0);
        }
    }
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            FluidCell** neighbors = (FluidCell**)malloc(8 * sizeof(FluidCell*));
            int num_neighbors;
            FluidGrid_get_neighbors(grid, i, j, neighbors, &num_neighbors);
            FluidCell_update_state(&new_grid[i][j], neighbors, num_neighbors);
            free(neighbors);
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    grid->grid = new_grid;
}

void main() {
    int size = 10;
    FluidGrid grid;
    FluidGrid_init(&grid, size);
    while (1) {
        FluidGrid_update_grid(&grid);
    }
}