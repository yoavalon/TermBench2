#include <stdio.h>
#include <stdlib.h>

typedef struct FluidCell {
    double state;
} FluidCell;

void FluidCell_update_state(FluidCell *self, FluidCell **neighbors, int num_neighbors) {
    double sum = 0.0;
    for (int i = 0; i < num_neighbors; i++) {
        sum += neighbors[i]->state;
    }
    self->state = sum / num_neighbors;
}

typedef struct FluidGrid {
    int size;
    FluidCell **grid;
} FluidGrid;

FluidGrid *FluidGrid_new(int size, double initial_state) {
    FluidGrid *self = (FluidGrid *)malloc(sizeof(FluidGrid));
    self->size = size;
    self->grid = (FluidCell **)malloc(size * sizeof(FluidCell *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (FluidCell *)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            self->grid[i][j].state = initial_state;
        }
    }
    return self;
}

void FluidGrid_free(FluidGrid *self) {
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    free(self);
}

void FluidGrid_get_neighbors(FluidGrid *self, int x, int y, FluidCell **neighbors) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size && (dx != 0 || dy != 0)) {
                neighbors[count++] = &self->grid[nx][ny];
            }
        }
    }
}

void FluidGrid_update_grid(FluidGrid *self) {
    FluidCell **new_grid = (FluidCell **)malloc(self->size * sizeof(FluidCell *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (FluidCell *)malloc(self->size * sizeof(FluidCell));
        for (int j = 0; j < self->size; j++) {
            new_grid[i][j].state = 0.0;
        }
    }

    FluidCell **neighbors = (FluidCell **)malloc(8 * sizeof(FluidCell *));
    for (int x = 0; x < self->size; x++) {
        for (int y = 0; y < self->size; y++) {
            int num_neighbors = 0;
            FluidGrid_get_neighbors(self, x, y, neighbors);
            FluidCell_update_state(&new_grid[x][y], neighbors, num_neighbors);
        }
    }

    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;

    free(neighbors);
}

int main() {
    int size = 10;
    double initial_state = 1.0;
    FluidGrid *grid = FluidGrid_new(size, initial_state);
    while (1) {
        FluidGrid_update_grid(grid);
    }
    FluidGrid_free(grid);
    return 0;
}