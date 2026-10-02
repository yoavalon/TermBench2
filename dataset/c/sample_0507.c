#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    int **grid;
} Grid;

void Grid_init(Grid *self, int size) {
    self->size = size;
    self->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = rand() % 2;
        }
    }
}

void Grid_update(Grid *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)malloc(self->size * sizeof(int));
        for (int j = 0; j < self->size; j++) {
            int state = self->grid[i][j];
            int neighbors = self->count_neighbors(i, j);
            if (state == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = state;
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
    for (int i = fmax(0, x - 1); i < fmin(x + 2, self->size); i++) {
        for (int j = fmax(0, y - 1); j < fmin(y + 2, self->size); j++) {
            if (i != x || j != y) {
                count += self->grid[i][j];
            }
        }
    }
    return count;
}

typedef struct {
    Grid *grid;
} Simulation;

void Simulation_init(Simulation *self, Grid *grid) {
    self->grid = grid;
}

void Simulation_run(Simulation *self) {
    while (1) {
        Grid_update(self->grid);
        Simulation_display(self);
    }
}

void Simulation_display(Simulation *self) {
    for (int i = 0; i < self->grid->size; i++) {
        for (int j = 0; j < self->grid->size; j++) {
            printf("%c", self->grid->grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
    for (int i = 0; i < self->grid->size; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size = 50;
    Grid grid;
    Grid_init(&grid, size);
    Simulation simulation;
    Simulation_init(&simulation, &grid);
    Simulation_run(&simulation);
    return 0;
}