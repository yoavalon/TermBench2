#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int size;
    int **state;
} Grid;

void init(Grid *grid, int size) {
    grid->size = size;
    grid->state = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid->state[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid->state[i][j] = 0;
        }
    }
}

void update(Grid *grid) {
    int **new_state = (int **)malloc(grid->size * sizeof(int *));
    for (int i = 0; i < grid->size; i++) {
        new_state[i] = (int *)malloc(grid->size * sizeof(int));
        for (int j = 0; j < grid->size; j++) {
            int neighbors = 0;
            for (int k = max(0, i - 1); k < min(i + 2, grid->size); k++) {
                for (int l = max(0, j - 1); l < min(j + 2, grid->size); l++) {
                    if ((k != i || l != j) && grid->state[k][l] == 1) {
                        neighbors++;
                    }
                }
            }
            if (grid->state[i][j] == 0 && neighbors == 3) {
                new_state[i][j] = 1;
            } else if (grid->state[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_state[i][j] = 0;
            } else {
                new_state[i][j] = grid->state[i][j];
            }
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->state[i]);
        grid->state[i] = new_state[i];
    }
    free(new_state);
}

int get_neighbors(Grid *grid, int x, int y) {
    int count = 0;
    for (int i = max(0, x - 1); i < min(x + 2, grid->size); i++) {
        for (int j = max(0, y - 1); j < min(y + 2, grid->size); j++) {
            if ((i != x || j != y) && grid->state[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void display(Grid *grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            printf("%c", grid->state[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Grid grid;
    init(&grid, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                grid.state[i][j] = 1;
            }
        }
    }
    while (1) {
        display(&grid);
        update(&grid);
    }
    return 0;
}