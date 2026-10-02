#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int** grid;
} Grid;

Grid* Grid_init(int size) {
    Grid* self = (Grid*)malloc(sizeof(Grid));
    self->size = size;
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)calloc(size, sizeof(int));
    }
    return self;
}

void Grid_update(Grid* self) {
    int** new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)calloc(self->size, sizeof(int));
    }

    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Grid_count_neighbors(self, i, j);
            if (self->grid[i][j] == 0) {
                new_grid[i][j] = neighbors == 3 ? 1 : 0;
            } else {
                new_grid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int Grid_count_neighbors(Grid* self, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int ni = x + i, nj = y + j;
            if (0 <= ni && ni < self->size && 0 <= nj && nj < self->size) {
                count += self->grid[ni][nj];
            }
        }
    }
    return count;
}

void display(Grid* grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main() {
    int size = 10;
    Grid* grid = Grid_init(size);
    while (1) {
        display(grid);
        Grid_update(grid);
    }
}