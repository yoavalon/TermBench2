#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    int** state;
} Grid;

void Grid_init(Grid* grid, int size, int** initial_state) {
    grid->size = size;
    grid->state = initial_state;
}

void Grid_update(Grid* grid) {
    int** new_state = (int**)malloc(grid->size * sizeof(int*));
    for (int i = 0; i < grid->size; i++) {
        new_state[i] = (int*)malloc(grid->size * sizeof(int));
        for (int j = 0; j < grid->size; j++) {
            new_state[i][j] = 0;
        }
    }

    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            int neighbors = Grid_count_neighbors(grid, i, j);
            if (grid->state[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_state[i][j] = 1;
            } else if (grid->state[i][j] == 0 && neighbors == 3) {
                new_state[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < grid->size; i++) {
        free(grid->state[i]);
    }
    free(grid->state);

    grid->state = new_state;
}

int Grid_count_neighbors(Grid* grid, int x, int y) {
    int count = 0;
    for (int i = fmax(0, x - 1); i < fmin(grid->size, x + 2); i++) {
        for (int j = fmax(0, y - 1); j < fmin(grid->size, y + 2); j++) {
            if ((i != x || j != y) && grid->state[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int** generate_initial_state(int size, double density) {
    int** state = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        state[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            if ((double)rand() / RAND_MAX < density) {
                state[i][j] = 1;
            } else {
                state[i][j] = 0;
            }
        }
    }
    return state;
}

void main() {
    srand(time(NULL));
    int size = 100;
    double density = 0.2;
    int** initial_state = generate_initial_state(size, density);
    Grid grid;
    Grid_init(&grid, size, initial_state);

    while (1) {
        Grid_update(&grid);
    }
}