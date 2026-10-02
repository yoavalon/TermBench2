c
#include <stdio.h>

int simulate(int a, int b, int c, int d) {
    if (c > d) {
        return b;
    }
    return simulate(b, a, c + 1, d);
}

int** fluid_dynamics(int n, int m) {
    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = simulate(i, j, 0, n);
        }
    }
    return grid;
}

void main() {
    int n = 5, m = 5;
    int** result = fluid_dynamics(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++) {
        free(result[i]);
    }
    free(result);
}