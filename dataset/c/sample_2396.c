#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
} FluidCell;

typedef struct {
    FluidCell **grid;
    int size;
} FluidGrid;

void FluidCell_update(FluidCell *self, FluidCell **neighbors, int num_neighbors) {
    double sum = 0.0;
    for (int i = 0; i < num_neighbors; i++) {
        sum += neighbors[i]->value;
    }
    self->value = sum / num_neighbors;
}

FluidGrid *FluidGrid_new(int size) {
    FluidGrid *self = (FluidGrid *)malloc(sizeof(FluidGrid));
    self->size = size;
    self->grid = (FluidCell **)malloc(size * sizeof(FluidCell *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (FluidCell *)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            self->grid[i][j].value = 0.0;
        }
    }
    return self;
}

FluidCell **FluidGrid_get_neighbors(FluidGrid *self, int x, int y) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    FluidCell **neighbors = (FluidCell **)malloc(4 * sizeof(FluidCell *));
    int num_neighbors = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
            neighbors[num_neighbors++] = &self->grid[nx][ny];
        }
    }
    return neighbors;
}

void FluidGrid_update_cells(FluidGrid *self) {
    FluidGrid *new_grid = FluidGrid_new(self->size);
    for (int x = 0; x < self->size; x++) {
        for (int y = 0; y < self->size; y++) {
            FluidCell **neighbors = FluidGrid_get_neighbors(self, x, y);
            FluidCell_update(&new_grid->grid[x][y], neighbors, 4);
            free(neighbors);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid->grid;
    free(new_grid);
}

void main() {
    int size = 100;
    FluidGrid *fluid_grid = FluidGrid_new(size);
    for (int j = 0; j < size; j++) {
        fluid_grid->grid[0][j].value = 1.0;
    }
    while (1) {
        FluidGrid_update_cells(fluid_grid);
    }
}