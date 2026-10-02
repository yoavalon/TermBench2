#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    int **grid;
} Grid;

Grid* Grid_new(int width, int height) {
    Grid* self = (Grid*)malloc(sizeof(Grid));
    self->width = width;
    self->height = height;
    self->grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        self->grid[i] = (int*)calloc(width, sizeof(int));
    }
    return self;
}

void Grid_update(Grid* self) {
    int **new_grid = (int**)malloc(self->height * sizeof(int*));
    for (int i = 0; i < self->height; i++) {
        new_grid[i] = (int*)calloc(self->width, sizeof(int));
    }
    for (int y = 0; y < self->height; y++) {
        for (int x = 0; x < self->width; x++) {
            int neighbors = Grid_count_neighbors(self, x, y);
            if (self->grid[y][x] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[y][x] = 0;
                } else {
                    new_grid[y][x] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < self->height; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int Grid_count_neighbors(Grid* self, int x, int y) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = ((x + i) % self->width + self->width) % self->width;
            int ny = ((y + j) % self->height + self->height) % self->height;
            count += self->grid[ny][nx];
        }
    }
    return count;
}

void Grid_display(Grid* self) {
    for (int i = 0; i < self->height; i++) {
        for (int j = 0; j < self->width; j++) {
            printf("%c", self->grid[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
}

typedef struct {
    Grid* grid;
} Simulation;

Simulation* Simulation_new(Grid* grid) {
    Simulation* self = (Simulation*)malloc(sizeof(Simulation));
    self->grid = grid;
    return self;
}

void Simulation_run(Simulation* self) {
    while (1) {
        Grid_update(self->grid);
        Grid_display(self->grid);
        for (int i = 0; i < self->grid->width; i++) {
            printf("-");
        }
        printf("\n");
    }
}

int main() {
    int width = 20, height = 20;
    Grid* grid = Grid_new(width, height);
    for (int _ = 0; _ < 50; _++) {
        int x = rand() % width;
        int y = rand() % height;
        grid->grid[y][x] = 1;
    }
    Simulation* simulation = Simulation_new(grid);
    Simulation_run(simulation);
    return 0;
}