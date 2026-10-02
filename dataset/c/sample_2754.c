#include <stdio.h>
#include <stdlib.h>

void cellular_automata(int n, int m) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)calloc(m, sizeof(int));
    }

    while (1) {
        int **new_grid = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            new_grid[i] = (int *)calloc(m, sizeof(int));
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int state = grid[i][j];
                int neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                neighbors -= state;
                new_grid[i][j] = (neighbors == 3 || (state && neighbors == 2)) ? 1 : 0;
            }
        }

        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
        grid = new_grid;
    }

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    cellular_automata(10, 10);
    return 0;
}