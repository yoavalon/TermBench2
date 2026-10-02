#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
} FluidCell;

void FluidCell_update(FluidCell *self, FluidCell **neighbors, int num_neighbors) {
    int sum = 0;
    for (int i = 0; i < num_neighbors; i++) {
        sum += neighbors[i]->state;
    }
    self->state = sum / num_neighbors;
}

typedef struct {
    int width;
    int height;
    FluidCell **grid;
} Grid;

Grid *Grid_new(int width, int height, int initial_state) {
    Grid *self = (Grid *)malloc(sizeof(Grid));
    self->width = width;
    self->height = height;
    self->grid = (FluidCell **)malloc(height * sizeof(FluidCell *));
    for (int y = 0; y < height; y++) {
        self->grid[y] = (FluidCell *)malloc(width * sizeof(FluidCell));
        for (int x = 0; x < width; x++) {
            self->grid[y][x].state = initial_state;
        }
    }
    return self;
}

void Grid_free(Grid *self) {
    for (int y = 0; y < self->height; y++) {
        free(self->grid[y]);
    }
    free(self->grid);
    free(self);
}

FluidCell **Grid_get_neighbors(Grid *self, int x, int y, int *num_neighbors) {
    int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    FluidCell **neighbors = (FluidCell **)malloc(4 * sizeof(FluidCell *));
    *num_neighbors = 0;
    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < self->width && ny >= 0 && ny < self->height) {
            neighbors[(*num_neighbors)++] = &self->grid[ny][nx];
        }
    }
    return neighbors;
}

void Grid_update_cells(Grid *self) {
    for (int y = 0; y < self->height; y++) {
        for (int x = 0; x < self->width; x++) {
            int num_neighbors;
            FluidCell **neighbors = Grid_get_neighbors(self, x, y, &num_neighbors);
            FluidCell_update(&self->grid[y][x], neighbors, num_neighbors);
            free(neighbors);
        }
    }
}

typedef struct {
    Grid *grid;
} Simulation;

Simulation *Simulation_new(Grid *grid) {
    Simulation *self = (Simulation *)malloc(sizeof(Simulation));
    self->grid = grid;
    return self;
}

void Simulation_free(Simulation *self) {
    Grid_free(self->grid);
    free(self);
}

void Simulation_run(Simulation *self) {
    while (1) {
        Grid_update_cells(self->grid);
    }
}

int main() {
    Grid *grid = Grid_new(10, 10, 50);
    Simulation *simulation = Simulation_new(grid);
    Simulation_run(simulation);
    return 0;
}