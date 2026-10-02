#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int** state;
} Grid;

void Grid_init(Grid* grid, int size) {
    grid->size = size;
    grid->state = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid->state[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid->state[i][j] = 0;
        }
    }
}

void Grid_update(Grid* grid) {
    int** new_state = (int**)malloc(grid->size * sizeof(int*));
    for (int i = 0; i < grid->size; i++) {
        new_state[i] = (int*)malloc(grid->size * sizeof(int));
        for (int j = 0; j < grid->size; j++) {
            new_state[i][j] = 0;
        }
    }
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            int neighbors = 0;
            for (int ni = 0; ni < 3; ni++) {
                for (int nj = 0; nj < 3; nj++) {
                    int ii = i + ni - 1;
                    int jj = j + nj - 1;
                    if (ii >= 0 && ii < grid->size && jj >= 0 && jj < grid->size && (ii != i || jj != j)) {
                        if (grid->state[ii][jj] == 1) {
                            neighbors++;
                        }
                    }
                }
            }
            if (grid->state[i][j] == 0) {
                if (neighbors == 3) {
                    new_state[i][j] = 1;
                }
            } else if (neighbors == 2 || neighbors == 3) {
                new_state[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->state[i]);
    }
    free(grid->state);
    grid->state = new_state;
}

int Grid_count_neighbors(Grid* grid, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < grid->size && j >= 0 && j < grid->size && (i != x || j != y)) {
                if (grid->state[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void display(Grid* grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            printf("%c", grid->state[i][j] == 1 ? 'O' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void main() {
    int size = 50;
    Grid grid;
    Grid_init(&grid, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid.state[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
    }
    while (1) {
        display(&grid);
        Grid_update(&grid);
    }
}