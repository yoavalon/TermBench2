#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void update_grid(int grid[ROWS][COLS], int new_grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = (i - 1 < 0 ? 0 : i - 1); x <= (i + 1 > ROWS - 1 ? ROWS - 1 : i + 1); x++) {
                for (int y = (j - 1 < 0 ? 0 : j - 1); y <= (j + 1 > COLS - 1 ? COLS - 1 : j + 1); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
}

void simulate(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    update_grid(grid, new_grid);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    print_grid(grid);
    simulate(grid);
}

void print_grid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int initial_grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    simulate(initial_grid);
    return 0;
}