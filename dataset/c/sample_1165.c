#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} FluidGrid;

void FluidGrid_init(FluidGrid *self, int size) {
    self->size = size;
    self->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int *)calloc(size, sizeof(int));
    }
}

void FluidGrid_update(FluidGrid *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            new_grid[i][j] = FluidGrid_calculate_next_state(self, i, j);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int FluidGrid_calculate_next_state(FluidGrid *self, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                count += self->grid[nx][ny];
            }
        }
    }
    if (self->grid[x][y] == 0) {
        return count > 2 ? 1 : 0;
    } else {
        return count == 2 || count == 3 ? 1 : 0;
    }
}

void FluidGrid_free(FluidGrid *self) {
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
}

int main() {
    int size = 10;
    FluidGrid grid;
    FluidGrid_init(&grid, size);
    while (1) {
        FluidGrid_update(&grid);
    }
    FluidGrid_free(&grid);
    return 0;
}