#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int **data;
} Grid;

Grid* Grid_init(int size) {
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    grid->size = size;
    grid->data = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid->data[i] = (int *)calloc(size, sizeof(int));
    }
    return grid;
}

void Grid_update(Grid *grid) {
    int **new_data = (int **)malloc(grid->size * sizeof(int *));
    for (int i = 0; i < grid->size; i++) {
        new_data[i] = (int *)calloc(grid->size, sizeof(int));
    }
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            new_data[i][j] = Grid__calculate_next_state(grid, i, j);
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->data[i]);
    }
    free(grid->data);
    grid->data = new_data;
}

int Grid__calculate_next_state(Grid *grid, int i, int j) {
    int alive_count = 0;
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < grid->size && y >= 0 && y < grid->size && !(x == i && y == j)) {
                alive_count += grid->data[x][y];
            }
        }
    }
    if (grid->data[i][j] == 1) {
        return alive_count == 2 || alive_count == 3 ? 1 : 0;
    } else {
        return alive_count == 3 ? 1 : 0;
    }
}

void Grid_free(Grid *grid) {
    for (int i = 0; i < grid->size; i++) {
        free(grid->data[i]);
    }
    free(grid->data);
    free(grid);
}

void main() {
    int grid_size = 10;
    Grid *grid = Grid_init(grid_size);
    int steps = 50;
    for (int _ = 0; _ < steps; _++) {
        Grid_update(grid);
    }
    Grid_free(grid);
}