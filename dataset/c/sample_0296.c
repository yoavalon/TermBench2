#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int **grid;
    int size;
} Grid;

void Grid_init(Grid *self, int size) {
    self->size = size;
    self->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int *)calloc(size, sizeof(int));
    }
}

void Grid_update(Grid *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)calloc(self->size, sizeof(int));
    }

    for (int i = 1; i < self->size - 1; i++) {
        for (int j = 1; j < self->size - 1; j++) {
            int neighbors[9];
            int index = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    neighbors[index++] = self->grid[i + di][j + dj];
                }
            }
            new_grid[i][j] = Grid_rules(self, neighbors);
        }
    }

    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int Grid_rules(Grid *self, int neighbors[9]) {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        count += neighbors[i];
    }
    count -= self->grid[1][1];

    if (self->grid[1][1] == 1 && (count < 2 || count > 3)) {
        return 0;
    } else if (self->grid[1][1] == 0 && count == 3) {
        return 1;
    }
    return self->grid[1][1];
}

typedef struct {
    // No additional fields needed for this handler
} BoundaryHandler;

void BoundaryHandler_apply(BoundaryHandler *self, Grid *grid) {
    for (int j = 0; j < grid->size; j++) {
        grid->grid[0][j] = grid->grid[grid->size - 2][j];
        grid->grid[grid->size - 1][j] = grid->grid[1][j];
    }
    for (int i = 0; i < grid->size; i++) {
        grid->grid[i][0] = grid->grid[i][grid->size - 2];
        grid->grid[i][grid->size - 1] = grid->grid[i][1];
    }
}

typedef struct {
    Grid *grid;
    BoundaryHandler *boundary_handler;
    int iterations;
} Simulator;

void Simulator_run(Simulator *self) {
    for (int i = 0; i < self->iterations; i++) {
        Grid_update(self->grid);
        BoundaryHandler_apply(self->boundary_handler, self->grid);
    }
}

void main() {
    Grid grid;
    BoundaryHandler boundary_handler;
    Simulator simulator;

    Grid_init(&grid, SIZE);
    BoundaryHandler_apply(&boundary_handler, &grid); // Initialize boundary condition
    Simulator simulator_init = {&grid, &boundary_handler, 50};
    simulator = simulator_init;
    Simulator_run(&simulator);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid.grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < SIZE; i++) {
        free(grid.grid[i]);
    }
    free(grid.grid);
}