#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
} AutomatonCell;

void AutomatonCell_init(AutomatonCell *cell, int state) {
    cell->state = state;
}

void AutomatonCell_update_state(AutomatonCell *cell, AutomatonCell **neighbors, int num_neighbors) {
    int alive_neighbors = 0;
    for (int i = 0; i < num_neighbors; i++) {
        if (neighbors[i]->state == 1) {
            alive_neighbors++;
        }
    }
    if (cell->state == 1) {
        if (alive_neighbors < 2 || alive_neighbors > 3) {
            cell->state = 0;
        }
    } else if (alive_neighbors == 3) {
        cell->state = 1;
    }
}

typedef struct {
    AutomatonCell **grid;
    int size;
} AutomatonGrid;

void AutomatonGrid_init(AutomatonGrid *grid, int size) {
    grid->size = size;
    grid->grid = (AutomatonCell **)malloc(size * sizeof(AutomatonCell *));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (AutomatonCell *)malloc(size * sizeof(AutomatonCell));
        for (int j = 0; j < size; j++) {
            AutomatonCell_init(&grid->grid[i][j], rand() % 2);
        }
    }
}

void AutomatonGrid_get_neighbors(AutomatonGrid *grid, int x, int y, AutomatonCell **neighbors, int *num_neighbors) {
    *num_neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < grid->size && ny >= 0 && ny < grid->size) {
                neighbors[(*num_neighbors)++] = &grid->grid[nx][ny];
            }
        }
    }
}

void AutomatonGrid_update_grid(AutomatonGrid *grid) {
    AutomatonCell **new_grid = (AutomatonCell **)malloc(grid->size * sizeof(AutomatonCell *));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (AutomatonCell *)malloc(grid->size * sizeof(AutomatonCell));
        for (int j = 0; j < grid->size; j++) {
            AutomatonCell_init(&new_grid[i][j], 0);
        }
    }
    for (int x = 0; x < grid->size; x++) {
        for (int y = 0; y < grid->size; y++) {
            AutomatonCell *neighbors[8];
            int num_neighbors;
            AutomatonGrid_get_neighbors(grid, x, y, neighbors, &num_neighbors);
            AutomatonCell_update_state(&new_grid[x][y], neighbors, num_neighbors);
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    grid->grid = new_grid;
}

void simulate() {
    int size = 50;
    AutomatonGrid grid;
    AutomatonGrid_init(&grid, size);
    while (1) {
        AutomatonGrid_update_grid(&grid);
    }
}

int main() {
    simulate();
    return 0;
}