#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int state;
} Cell;

void Cell_update(Cell *self, Cell *neighbors, int size) {
    int live_neighbors = 0;
    for (int i = 0; i < size; i++) {
        if (neighbors[i].state == 1) {
            live_neighbors++;
        }
    }
    if (self->state == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
        self->state = 0;
    } else if (self->state == 0 && live_neighbors == 3) {
        self->state = 1;
    }
}

typedef struct Grid {
    int size;
    Cell **cells;
} Grid;

Grid *Grid_new(int size, int **initial_state) {
    Grid *self = (Grid *)malloc(sizeof(Grid));
    self->size = size;
    self->cells = (Cell **)malloc(size * sizeof(Cell *));
    for (int i = 0; i < size; i++) {
        self->cells[i] = (Cell *)malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            self->cells[i][j].state = initial_state[i][j];
        }
    }
    return self;
}

Cell *Grid_get_neighbors(Grid *self, int x, int y) {
    Cell *neighbors = (Cell *)malloc(8 * sizeof(Cell));
    int index = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                neighbors[index++] = self->cells[nx][ny];
            } else {
                neighbors[index].state = 0;
                index++;
            }
        }
    }
    return neighbors;
}

void Grid_update(Grid *self) {
    Cell **new_cells = (Cell **)malloc(self->size * sizeof(Cell *));
    for (int i = 0; i < self->size; i++) {
        new_cells[i] = (Cell *)malloc(self->size * sizeof(Cell));
        for (int j = 0; j < self->size; j++) {
            new_cells[i][j].state = self->cells[i][j].state;
        }
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            Cell *neighbors = Grid_get_neighbors(self, i, j);
            Cell_update(&new_cells[i][j], neighbors, 8);
            free(neighbors);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->cells[i]);
    }
    free(self->cells);
    self->cells = new_cells;
}

int main() {
    int size = 10;
    int **initial_state = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        initial_state[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            initial_state[i][j] = 0;
        }
    }
    initial_state[4][4] = 1;
    initial_state[4][5] = 1;
    initial_state[5][4] = 1;
    initial_state[5][5] = 1;
    Grid *grid = Grid_new(size, initial_state);
    while (1) {
        Grid_update(grid);
    }
    return 0;
}