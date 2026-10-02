#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} Grid;

typedef struct {
    Grid *grid;
} Simulation;

Grid* Grid_init(int size) {
    Grid *self = (Grid*)malloc(sizeof(Grid));
    self->size = size;
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = 0;
        }
    }
    return self;
}

void Grid_update(Grid *self) {
    int **new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)malloc(self->size * sizeof(int));
        for (int j = 0; j < self->size; j++) {
            int neighbors = Grid_get_neighbors(self, i, j);
            if (self->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (self->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = self->grid[i][j];
            }
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int Grid_get_neighbors(Grid *self, int x, int y) {
    int count = 0;
    for (int i = fmax(0, x - 1); i < fmin(self->size, x + 2); i++) {
        for (int j = fmax(0, y - 1); j < fmin(self->size, y + 2); j++) {
            if ((i != x || j != y) && self->grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

Simulation* Simulation_init(Grid *grid) {
    Simulation *self = (Simulation*)malloc(sizeof(Simulation));
    self->grid = grid;
    return self;
}

void Simulation_run(Simulation *self) {
    while (1) {
        Grid_update(self->grid);
    }
}

int main() {
    int size = 50;
    Grid *grid = Grid_init(size);
    Simulation *simulation = Simulation_init(grid);
    Simulation_run(simulation);
    return 0;
}