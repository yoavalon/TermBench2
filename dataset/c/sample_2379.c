#include <stdio.h>

typedef struct {
    int x;
    int y;
    double pressure;
    double velocity[2];
} FluidCell;

void FluidCell_init(FluidCell *cell, int x, int y) {
    cell->x = x;
    cell->y = y;
    cell->pressure = 0.0;
    cell->velocity[0] = 0.0;
    cell->velocity[1] = 0.0;
}

void FluidCell_update_pressure(FluidCell *cell, FluidCell *neighbors, int num_neighbors) {
    double total_pressure = 0.0;
    for (int i = 0; i < num_neighbors; i++) {
        total_pressure += neighbors[i].pressure;
    }
    cell->pressure = total_pressure / num_neighbors;
}

void FluidCell_update_velocity(FluidCell *cell, FluidCell *neighbors, int num_neighbors) {
    double dx = 0.0;
    double dy = 0.0;
    for (int i = 0; i < num_neighbors; i++) {
        dx += neighbors[i].velocity[0];
        dy += neighbors[i].velocity[1];
    }
    cell->velocity[0] = dx / num_neighbors;
    cell->velocity[1] = dy / num_neighbors;
}

int get_neighbors(FluidCell *grid, int width, int height, int x, int y, FluidCell *neighbors) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int num_neighbors = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            neighbors[num_neighbors++] = grid[nx * height + ny];
        }
    }
    return num_neighbors;
}

void simulate(FluidCell *grid, int width, int height) {
    while (1) {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                FluidCell *cell = &grid[x * height + y];
                FluidCell neighbors[4];
                int num_neighbors = get_neighbors(grid, width, height, x, y, neighbors);
                FluidCell_update_pressure(cell, neighbors, num_neighbors);
                FluidCell_update_velocity(cell, neighbors, num_neighbors);
            }
        }
    }
}

int main() {
    int width = 10;
    int height = 10;
    FluidCell grid[100];
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            FluidCell_init(&grid[x * height + y], x, y);
        }
    }
    simulate(grid, width, height);
    return 0;
}