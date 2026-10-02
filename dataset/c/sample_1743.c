#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
} FluidCell;

void FluidCell_update_state(FluidCell *self, FluidCell **neighbors, int num_neighbors) {
    int sum = 0;
    for (int i = 0; i < num_neighbors; i++) {
        sum += neighbors[i]->state;
    }
    self->state = sum / num_neighbors;
}

typedef struct {
    int size;
    FluidCell **cells;
} Grid;

Grid *Grid_init(int size) {
    Grid *self = (Grid *)malloc(sizeof(Grid));
    self->size = size;
    self->cells = (FluidCell **)malloc(size * sizeof(FluidCell *));
    for (int i = 0; i < size; i++) {
        self->cells[i] = (FluidCell *)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            self->cells[i][j].state = 0;
        }
    }
    return self;
}

FluidCell **Grid_get_neighbors(Grid *self, int x, int y, int *num_neighbors) {
    FluidCell **neighbors = (FluidCell **)malloc(8 * sizeof(FluidCell *));
    *num_neighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                neighbors[(*num_neighbors)++] = &self->cells[nx][ny];
            }
        }
    }
    return neighbors;
}

void Grid_update_grid(Grid *self) {
    FluidCell **new_cells = (FluidCell **)malloc(self->size * sizeof(FluidCell *));
    for (int i = 0; i < self->size; i++) {
        new_cells[i] = (FluidCell *)malloc(self->size * sizeof(FluidCell));
        for (int j = 0; j < self->size; j++) {
            int num_neighbors;
            FluidCell **neighbors = Grid_get_neighbors(self, i, j, &num_neighbors);
            FluidCell_update_state(&new_cells[i][j], neighbors, num_neighbors);
            free(neighbors);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->cells[i]);
    }
    free(self->cells);
    self->cells = new_cells;
}

void main() {
    int grid_size = 10;
    Grid *grid = Grid_init(grid_size);
    while (1) {
        Grid_update_grid(grid);
    }
}