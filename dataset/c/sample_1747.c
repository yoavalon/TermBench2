#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int **state;
} FluidSimulator;

FluidSimulator* FluidSimulator_init(int size, int **initial_state) {
    FluidSimulator *simulator = (FluidSimulator *)malloc(sizeof(FluidSimulator));
    simulator->size = size;
    simulator->state = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        simulator->state[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            simulator->state[i][j] = initial_state[i][j];
        }
    }
    return simulator;
}

void FluidSimulator_update_state(FluidSimulator *simulator) {
    int **new_state = (int **)malloc(simulator->size * sizeof(int *));
    for (int i = 0; i < simulator->size; i++) {
        new_state[i] = (int *)malloc(simulator->size * sizeof(int));
    }
    for (int i = 0; i < simulator->size; i++) {
        for (int j = 0; j < simulator->size; j++) {
            int neighbors[8];
            int count = 0;
            int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            for (int k = 0; k < 8; k++) {
                int dx = directions[k][0];
                int dy = directions[k][1];
                int nx = i + dx;
                int ny = j + dy;
                if (nx >= 0 && nx < simulator->size && ny >= 0 && ny < simulator->size) {
                    neighbors[count++] = simulator->state[nx][ny];
                }
            }
            int active_neighbors = 0;
            for (int k = 0; k < count; k++) {
                active_neighbors += neighbors[k];
            }
            if (simulator->state[0][0] == 1) {
                new_state[i][j] = (active_neighbors >= 2) ? 1 : 0;
            } else {
                new_state[i][j] = (active_neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < simulator->size; i++) {
        free(simulator->state[i]);
    }
    free(simulator->state);
    simulator->state = new_state;
}

int** initialize_grid(int size) {
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = (i % 2 && j % 2) ? 0 : 1;
        }
    }
    return grid;
}

void main() {
    int grid_size = 10;
    int **initial_state = initialize_grid(grid_size);
    FluidSimulator *simulator = FluidSimulator_init(grid_size, initial_state);
    while (1) {
        FluidSimulator_update_state(simulator);
    }
}