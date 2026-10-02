#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int** update_state(int** grid) {
    int** new_grid = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        new_grid[i] = (int*)malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            int neighbors[] = {
                grid[(i - 1 + ROWS) % ROWS][(j - 1 + COLS) % COLS],
                grid[(i - 1 + ROWS) % ROWS][j],
                grid[(i - 1 + ROWS) % ROWS][(j + 1) % COLS],
                grid[i][(j - 1 + COLS) % COLS],
                grid[i][(j + 1) % COLS],
                grid[(i + 1) % ROWS][(j - 1 + COLS) % COLS],
                grid[(i + 1) % ROWS][j],
                grid[(i + 1) % ROWS][(j + 1) % COLS]
            };
            int live_neighbors = 0;
            for (int k = 0; k < 8; k++) {
                live_neighbors += neighbors[k];
            }
            if (grid[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if (live_neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    return new_grid;
}

void free_grid(int** grid) {
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
}

void print_grid(int** grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int** grid = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (int*)malloc(COLS * sizeof(int));
    }
    grid[0][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;

    while (1) {
        int** new_grid = update_state(grid);
        print_grid(new_grid);
        free_grid(grid);
        grid = new_grid;
    }

    free_grid(grid);
    return 0;
}