#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10
#define STEPS 5

int** create_grid(int n, int m) {
    int** grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = (int*)malloc(m * sizeof(int));
    }
    return grid;
}

void free_grid(int** grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

void initialize_grid(int** grid, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int count_neighbors(int** grid, int n, int m, int i, int j) {
    int count = 0;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                count += grid[ni][nj];
            }
        }
    }
    return count;
}

void cellular_automata(int n, int m, int steps) {
    int** grid = create_grid(n, m);
    initialize_grid(grid, n, m);

    for (int step = 0; step < steps; step++) {
        int** new_grid = create_grid(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbors = count_neighbors(grid, n, m, i, j);
                new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j]) ? 1 : 0;
            }
        }
        free_grid(grid, n);
        grid = new_grid;
    }

    // Print the final grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free_grid(grid, n);
}

int main() {
    srand(time(NULL));
    cellular_automata(N, M, STEPS);
    return 0;
}