#include <stdio.h>

#define GRID_SIZE 10

typedef struct {
    int grid[GRID_SIZE][GRID_SIZE];
    int size;
} FluidSimulator;

void FluidSimulator_init(FluidSimulator *simulator, int grid_size) {
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            simulator->grid[i][j] = 0;
        }
    }
    simulator->size = grid_size;
}

void FluidSimulator_update(FluidSimulator *simulator) {
    int new_grid[GRID_SIZE][GRID_SIZE];
    for (int x = 0; x < simulator->size; x++) {
        for (int y = 0; y < simulator->size; y++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < simulator->size && ny >= 0 && ny < simulator->size) {
                        neighbors += simulator->grid[nx][ny];
                    }
                }
            }
            if (simulator->grid[x][y] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[x][y] = 0;
                } else {
                    new_grid[x][y] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[x][y] = 1;
            }
        }
    }
    for (int i = 0; i < simulator->size; i++) {
        for (int j = 0; j < simulator->size; j++) {
            simulator->grid[i][j] = new_grid[i][j];
        }
    }
}

void FluidSimulator_display(FluidSimulator *simulator) {
    for (int i = 0; i < simulator->size; i++) {
        for (int j = 0; j < simulator->size; j++) {
            printf("%c", simulator->grid[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    FluidSimulator simulator;
    FluidSimulator_init(&simulator, GRID_SIZE);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    simulator.grid[5][5] = 1;
    while (1) {
        FluidSimulator_display(&simulator);
        FluidSimulator_update(&simulator);
    }
    return 0;
}