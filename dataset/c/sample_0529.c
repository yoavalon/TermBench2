#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} Grid;

void Grid_init(Grid *self, int size) {
    self->size = size;
    self->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = 0;
        }
    }
}

void Grid_update(Grid *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)malloc(self->size * sizeof(int));
        for (int j = 0; j < self->size; j++) {
            new_grid[i][j] = 0;
        }
    }

    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Grid_count_neighbors(self, i, j);
            if (self->grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);

    self->grid = new_grid;
}

int Grid_count_neighbors(Grid *self, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if ((i != x || j != y) && i >= 0 && i < self->size && j >= 0 && j < self->size) {
                count += self->grid[i][j];
            }
        }
    }
    return count;
}

typedef struct {
    Grid *grid;
} Simulation;

void Simulation_init(Simulation *self, int grid_size) {
    self->grid = (Grid *)malloc(sizeof(Grid));
    Grid_init(self->grid, grid_size);
}

void Simulation_run(Simulation *self) {
    while (1) {
        Grid_update(self->grid);
    }
}

void main() {
    Simulation simulation;
    Simulation_init(&simulation, 10);
    Simulation_run(&simulation);
}