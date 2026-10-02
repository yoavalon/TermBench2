#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
} Cell;

void Cell_init(Cell *cell, int state) {
    cell->state = state;
}

void Cell_update(Cell *cell, Cell *neighbors, int num_neighbors) {
    int live_neighbors = 0;
    for (int i = 0; i < num_neighbors; i++) {
        if (neighbors[i].state == 1) {
            live_neighbors++;
        }
    }
    if (cell->state == 1) {
        cell->state = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
    } else {
        cell->state = (live_neighbors == 3) ? 1 : 0;
    }
}

typedef struct {
    int width;
    int height;
    Cell **grid;
} Grid;

void Grid_init(Grid *grid, int width, int height, int **initial_state) {
    grid->width = width;
    grid->height = height;
    grid->grid = (Cell **)malloc(height * sizeof(Cell *));
    for (int i = 0; i < height; i++) {
        grid->grid[i] = (Cell *)malloc(width * sizeof(Cell));
        for (int j = 0; j < width; j++) {
            Cell_init(&grid->grid[i][j], initial_state ? initial_state[i][j] : 0);
        }
    }
}

Cell *Grid_get_neighbors(Grid *grid, int x, int y, int *num_neighbors) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    Cell *neighbors = (Cell *)malloc(8 * sizeof(Cell));
    *num_neighbors = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 0 && nx < grid->width && ny >= 0 && ny < grid->height) {
            neighbors[(*num_neighbors)++] = grid->grid[ny][nx];
        }
    }
    return neighbors;
}

void Grid_update(Grid *grid) {
    Cell **new_grid = (Cell **)malloc(grid->height * sizeof(Cell *));
    for (int i = 0; i < grid->height; i++) {
        new_grid[i] = (Cell *)malloc(grid->width * sizeof(Cell));
        for (int j = 0; j < grid->width; j++) {
            Cell_init(&new_grid[i][j], grid->grid[i][j].state);
        }
    }
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            int num_neighbors;
            Cell *neighbors = Grid_get_neighbors(grid, j, i, &num_neighbors);
            Cell_update(&new_grid[i][j], neighbors, num_neighbors);
            free(neighbors);
        }
    }
    for (int i = 0; i < grid->height; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    grid->grid = new_grid;
}

void main() {
    int initial_state[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    Grid grid;
    Grid_init(&grid, 3, 3, (int **)initial_state);
    while (1) {
        Grid_update(&grid);
    }
}