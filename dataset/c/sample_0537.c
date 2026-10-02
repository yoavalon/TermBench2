#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} Grid;

typedef struct {
    Grid* grid;
} Automaton;

Grid* Grid_init(int size) {
    Grid* self = (Grid*)malloc(sizeof(Grid));
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = 0;
        }
    }
    self->size = size;
    return self;
}

void Grid_update(Grid* self, int (*rule)(int, int*)) {
    int** new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)malloc(self->size * sizeof(int));
        for (int j = 0; j < self->size; j++) {
            int neighbors[8];
            int count = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                        neighbors[count++] = self->grid[nx][ny];
                    }
                }
            }
            new_grid[i][j] = rule(self->grid[i][j], neighbors);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

Automaton* Automaton_init(Grid* grid) {
    Automaton* self = (Automaton*)malloc(sizeof(Automaton));
    self->grid = grid;
    return self;
}

void Automaton_run(Automaton* self, int (*rule)(int, int*), int steps) {
    for (int _ = 0; _ < steps; _++) {
        Grid_update(self->grid, rule);
    }
}

int simple_rule(int center, int* neighbors) {
    int live_neighbors = 0;
    for (int i = 0; i < 8; i++) {
        live_neighbors += neighbors[i];
    }
    if (center == 1) {
        return (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
    } else {
        return (live_neighbors == 3) ? 1 : 0;
    }
}

void main() {
    int grid_size = 10;
    Grid* initial_grid = Grid_init(grid_size);
    initial_grid->grid[4][4] = 1;
    initial_grid->grid[5][5] = 1;
    initial_grid->grid[6][4] = 1;
    initial_grid->grid[5][3] = 1;
    initial_grid->grid[4][5] = 1;
    Automaton* automaton = Automaton_init(initial_grid);
    while (1) {
        Automaton_run(automaton, simple_rule, 1);
    }
}