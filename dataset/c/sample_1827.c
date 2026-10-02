#include <stdio.h>

#define n 10

void simulate(double grid[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                grid[i][j] = 1.0;
            } else {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            }
        }
    }
}

int main() {
    double grid[n][n];
    simulate(grid);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}