#include <stdio.h>
#include <stdlib.h>

typedef struct FluidCell {
    double pressure;
    double velocity;
} FluidCell;

void update_state(FluidCell* self, FluidCell** neighbor_states, int num_neighbors) {
    double new_pressure = 0.0;
    double new_velocity = 0.0;
    for (int i = 0; i < num_neighbors; i++) {
        new_pressure += neighbor_states[i]->pressure;
        new_velocity += neighbor_states[i]->velocity;
    }
    self->pressure = new_pressure / num_neighbors;
    self->velocity = new_velocity / num_neighbors;
}

FluidCell** initialize_grid(int size, double initial_pressure, double initial_velocity) {
    FluidCell** grid = (FluidCell**)malloc(size * sizeof(FluidCell*));
    for (int i = 0; i < size; i++) {
        grid[i] = (FluidCell*)malloc(size * sizeof(FluidCell));
        for (int j = 0; j < size; j++) {
            grid[i][j].pressure = initial_pressure;
            grid[i][j].velocity = initial_velocity;
        }
    }
    return grid;
}

void simulate(FluidCell** grid, int size) {
    while (1) {
        FluidCell** new_grid = (FluidCell**)malloc(size * sizeof(FluidCell*));
        for (int i = 0; i < size; i++) {
            new_grid[i] = (FluidCell*)malloc(size * sizeof(FluidCell));
            for (int j = 0; j < size; j++) {
                FluidCell* neighbors[8];
                int num_neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) {
                            continue;
                        }
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                            neighbors[num_neighbors++] = &grid[ni][nj];
                        }
                    }
                }
                update_state(&new_grid[i][j], neighbors, num_neighbors);
            }
            free(grid[i]);
        }
        free(grid);
        grid = new_grid;
    }
}

int main() {
    int grid_size = 10;
    double initial_pressure = 1.0;
    double initial_velocity = 0.0;
    FluidCell** grid = initialize_grid(grid_size, initial_pressure, initial_velocity);
    simulate(grid, grid_size);
    return 0;
}