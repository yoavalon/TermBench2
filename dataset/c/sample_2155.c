#include <stdio.h>

void simulate_flow(int n) {
    double grid[n][n];
    double new_grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0.0;
        }
    }
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                new_grid[i][j] = (grid[i][(j - 1 + n) % n] + grid[i][(j + 1) % n] + grid[(i - 1 + n) % n][j] + grid[(i + 1) % n][j]) / 4;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    simulate_flow(10);
    return 0;
}