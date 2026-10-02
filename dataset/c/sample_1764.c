#include <stdio.h>
#include <stdlib.h>

typedef struct FluidCell {
    int state;
} FluidCell;

typedef struct Grid {
    int size;
    FluidCell **grid;
} Grid;

void FluidCell_init(FluidCell *cell, int state) {
    cell->state = state;
}

void FluidCell_update_state(FluidCell *cell, FluidCell **neighbors, int neighbor_count) {
    int count = 0;
    for (int i = 0; i < neighbor_count; i++) {
        if (neighbors[i]->state == 1) {
            count++;
        }
    }
    if (count == 3) {
        cell->state = 1;
    } else if (count < 2 || count > 3) {
        cell->state = 0;
    }
}

void Grid_init(Grid *grid, int size, int **initial_state) {
    grid->size = size;
    grid->grid = (FluidCell **)malloc(size * sizeof(FluidCell *));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (FluidCell *)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            FluidCell_init(&grid->grid[i][j], initial_state[i][j]);
        }
    }
}

void Grid_get_neighbors(Grid *grid, int x, int y, FluidCell **neighbors) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int neighbor_count = 0;
    for (int i = 0; i < 8; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < grid->size && ny >= 0 && ny < grid->size) {
            neighbors[neighbor_count++] = &grid->grid[nx][ny];
        }
    }
}

void Grid_update_grid(Grid *grid) {
    int **new_grid = (int **)malloc(grid->size * sizeof(int *));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (int *)malloc(grid->size * sizeof(int));
        for (int j = 0; j < grid->size; j++) {
            FluidCell *cell = &grid->grid[i][j];
            FluidCell *neighbors[8];
            Grid_get_neighbors(grid, i, j, neighbors);
            FluidCell_update_state(cell, neighbors, 8);
            new_grid[i][j] = cell->state;
        }
    }
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            FluidCell_init(&grid->grid[i][j], new_grid[i][j]);
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(new_grid[i]);
    }
    free(new_grid);
}

int main() {
    int size = 10;
    int initial_state[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Grid grid;
    Grid_init(&grid, size, (int **)initial_state);
    while (1) {
        Grid_update_grid(&grid);
    }
    return 0;
}