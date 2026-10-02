#include <stdio.h>
#include <stdlib.h>

typedef struct FluidCell {
    double state;
} FluidCell;

void FluidCell_init(FluidCell *self, double state) {
    self->state = state;
}

void FluidCell_update(FluidCell *self, FluidCell **neighbors, int num_neighbors) {
    double sum = 0.0;
    for (int i = 0; i < num_neighbors; i++) {
        sum += neighbors[i]->state;
    }
    self->state = sum / num_neighbors;
}

typedef struct Grid {
    int size;
    FluidCell **cells;
} Grid;

void Grid_init(Grid *self, int size, double initial_state) {
    self->size = size;
    self->cells = (FluidCell **)malloc(size * sizeof(FluidCell *));
    for (int i = 0; i < size; i++) {
        self->cells[i] = (FluidCell *)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            FluidCell_init(&self->cells[i][j], initial_state);
        }
    }
}

void Grid_free(Grid *self) {
    for (int i = 0; i < self->size; i++) {
        free(self->cells[i]);
    }
    free(self->cells);
}

int Grid_get_neighbors(Grid *self, int x, int y, FluidCell **neighbors) {
    int num_neighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                neighbors[num_neighbors++] = &self->cells[nx][ny];
            }
        }
    }
    return num_neighbors;
}

void Grid_update(Grid *self) {
    FluidCell **new_cells = (FluidCell **)malloc(self->size * sizeof(FluidCell *));
    for (int i = 0; i < self->size; i++) {
        new_cells[i] = (FluidCell *)malloc(self->size * sizeof(FluidCell));
        for (int j = 0; j < self->size; j++) {
            FluidCell_init(&new_cells[i][j], self->cells[i][j].state);
        }
    }

    FluidCell **neighbors = (FluidCell **)malloc(8 * sizeof(FluidCell *));
    for (int x = 0; x < self->size; x++) {
        for (int y = 0; y < self->size; y++) {
            int num_neighbors = Grid_get_neighbors(self, x, y, neighbors);
            FluidCell_update(&new_cells[x][y], neighbors, num_neighbors);
        }
    }

    for (int i = 0; i < self->size; i++) {
        free(self->cells[i]);
    }
    free(self->cells);
    self->cells = new_cells;

    free(neighbors);
}

void main() {
    int grid_size = 10;
    double initial_state = 0.5;
    Grid grid;
    Grid_init(&grid, grid_size, initial_state);
    while (1) {
        Grid_update(&grid);
    }
    Grid_free(&grid);
}