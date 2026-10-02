#include <stdio.h>
#include <stdlib.h>

typedef struct FluidCell {
    int state;
} FluidCell;

typedef struct Grid {
    int size;
    FluidCell** cells;
} Grid;

typedef struct Simulation {
    Grid grid;
    int steps;
} Simulation;

void FluidCell_init(FluidCell* cell, int state) {
    cell->state = state;
}

void FluidCell_update(FluidCell* cell, FluidCell** neighbors, int neighbor_count) {
    int sum = 0;
    for (int i = 0; i < neighbor_count; i++) {
        sum += neighbors[i]->state;
    }
    cell->state = sum / neighbor_count;
}

void Grid_init(Grid* grid, int size) {
    grid->size = size;
    grid->cells = (FluidCell**)malloc(size * sizeof(FluidCell*));
    for (int i = 0; i < size; i++) {
        grid->cells[i] = (FluidCell*)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            FluidCell_init(&grid->cells[i][j], 0);
        }
    }
}

void Grid_free(Grid* grid) {
    for (int i = 0; i < grid->size; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
}

void Grid_get_neighbors(Grid* grid, int x, int y, FluidCell** neighbors, int* neighbor_count) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    *neighbor_count = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 0 && nx < grid->size && ny >= 0 && ny < grid->size) {
            neighbors[*neighbor_count] = &grid->cells[nx][ny];
            (*neighbor_count)++;
        }
    }
}

void Grid_update(Grid* grid) {
    FluidCell** new_grid = (FluidCell**)malloc(grid->size * sizeof(FluidCell*));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (FluidCell*)malloc(grid->size * sizeof(FluidCell));
        for (int j = 0; j < grid->size; j++) {
            FluidCell_init(&new_grid[i][j], 0);
        }
    }

    for (int x = 0; x < grid->size; x++) {
        for (int y = 0; y < grid->size; y++) {
            FluidCell* neighbors[4];
            int neighbor_count;
            Grid_get_neighbors(grid, x, y, neighbors, &neighbor_count);
            FluidCell_update(&new_grid[x][y], neighbors, neighbor_count);
        }
    }

    for (int i = 0; i < grid->size; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    grid->cells = new_grid;
}

void Simulation_init(Simulation* simulation, int grid_size, int steps) {
    Grid_init(&simulation->grid, grid_size);
    simulation->steps = steps;
}

void Simulation_free(Simulation* simulation) {
    Grid_free(&simulation->grid);
}

void Simulation_run(Simulation* simulation) {
    for (int i = 0; i < simulation->steps; i++) {
        Grid_update(&simulation->grid);
    }
}

int main() {
    Simulation simulation;
    Simulation_init(&simulation, 10, 50);
    Simulation_run(&simulation);
    Simulation_free(&simulation);
    return 0;
}