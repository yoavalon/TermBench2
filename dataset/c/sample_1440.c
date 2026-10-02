#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} Grid;

typedef struct {
    Grid *grid;
    int steps;
} Simulation;

Grid* Grid_new(int size) {
    Grid *grid = (Grid*)malloc(sizeof(Grid));
    grid->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid->grid[i][j] = 0;
        }
    }
    grid->size = size;
    return grid;
}

void Grid_update(Grid *grid) {
    int **new_grid = (int**)malloc(grid->size * sizeof(int*));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (int*)malloc(grid->size * sizeof(int));
    }
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            int neighbors = Grid_count_neighbors(grid, i, j);
            if (grid->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid->grid[i][j];
            }
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    grid->grid = new_grid;
}

int Grid_count_neighbors(Grid *grid, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if ((i != x || j != y) && i >= 0 && i < grid->size && j >= 0 && j < grid->size) {
                count += grid->grid[i][j];
            }
        }
    }
    return count;
}

Simulation* Simulation_new(Grid *grid) {
    Simulation *simulation = (Simulation*)malloc(sizeof(Simulation));
    simulation->grid = grid;
    simulation->steps = 0;
    return simulation;
}

void Simulation_run(Simulation *simulation, int max_steps) {
    while (simulation->steps < max_steps) {
        Grid_update(simulation->grid);
        simulation->steps++;
    }
}

void main() {
    int size = 50;
    int max_steps = 100;
    Grid *grid = Grid_new(size);
    Simulation *simulation = Simulation_new(grid);
    Simulation_run(simulation, max_steps);
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
    free(simulation);
}