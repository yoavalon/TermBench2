#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    int **grid;
} Grid;

Grid* Grid_new(int size) {
    Grid* self = (Grid*)malloc(sizeof(Grid));
    self->size = size;
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)calloc(size, sizeof(int));
    }
    return self;
}

void Grid_update(Grid* self) {
    int **new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Grid_count_neighbors(self, i, j);
            if (self->grid[i][j] == 1) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int Grid_count_neighbors(Grid* self, int x, int y) {
    int count = 0;
    for (int i = (x > 0 ? x - 1 : 0); i < (x < self->size - 1 ? x + 2 : self->size); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j < (y < self->size - 1 ? y + 2 : self->size); j++) {
            if (i != x || j != y) {
                count += self->grid[i][j];
            }
        }
    }
    return count;
}

typedef struct {
    Grid* grid;
} Simulation;

Simulation* Simulation_new(int grid_size) {
    Simulation* self = (Simulation*)malloc(sizeof(Simulation));
    self->grid = Grid_new(grid_size);
    Simulation_populate_grid(self);
    return self;
}

void Simulation_populate_grid(Simulation* self) {
    for (int i = 0; i < self->grid->size; i++) {
        for (int j = 0; j < self->grid->size; j++) {
            self->grid->grid[i][j] = rand() % 2;
        }
    }
}

void Simulation_run(Simulation* self) {
    while (1) {
        Grid_update(self->grid);
    }
}

int main() {
    srand(time(NULL));
    Simulation* sim = Simulation_new(10);
    Simulation_run(sim);
    return 0;
}