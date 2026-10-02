#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} FluidSimulator;

typedef struct {
    FluidSimulator *simulator;
} BoundaryConditionApplier;

void FluidSimulator_init(FluidSimulator *self, int grid_size) {
    self->size = grid_size;
    self->grid = (int **)malloc(grid_size * sizeof(int *));
    for (int i = 0; i < grid_size; i++) {
        self->grid[i] = (int *)calloc(grid_size, sizeof(int));
    }
}

void FluidSimulator_update(FluidSimulator *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            new_grid[i][j] = FluidSimulator_apply_rules(self, i, j);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int FluidSimulator_apply_rules(FluidSimulator *self, int x, int y) {
    int neighbors[8];
    FluidSimulator_get_neighbors(self, x, y, neighbors);
    int count = 0;
    for (int i = 0; i < 8; i++) {
        count += neighbors[i];
    }
    if (self->grid[x][y] == 1) {
        return count > 1 ? 1 : 0;
    } else {
        return count == 3 ? 1 : 0;
    }
}

void FluidSimulator_get_neighbors(FluidSimulator *self, int x, int y, int *neighbors) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int nx = (x + dx + self->size) % self->size;
        int ny = (y + dy + self->size) % self->size;
        neighbors[i] = self->grid[nx][ny];
    }
}

void BoundaryConditionApplier_init(BoundaryConditionApplier *self, FluidSimulator *simulator) {
    self->simulator = simulator;
}

void BoundaryConditionApplier_apply(BoundaryConditionApplier *self) {
    for (int i = 0; i < self->simulator->size; i++) {
        self->simulator->grid[i][0] = 1;
        self->simulator->grid[i][self->simulator->size - 1] = 1;
        self->simulator->grid[0][i] = 1;
        self->simulator->grid[self->simulator->size - 1][i] = 1;
    }
}

int main() {
    int grid_size = 10;
    FluidSimulator simulator;
    BoundaryConditionApplier boundary_conditions;

    FluidSimulator_init(&simulator, grid_size);
    BoundaryConditionApplier_init(&boundary_conditions, &simulator);

    while (1) {
        BoundaryConditionApplier_apply(&boundary_conditions);
        FluidSimulator_update(&simulator);
    }

    return 0;
}