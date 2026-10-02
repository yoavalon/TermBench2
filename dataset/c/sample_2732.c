#include <stdio.h>

void simulate(int grid[3][3], int rules[9]) {
    while (1) {
        int new_grid[3][3] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int neighbors[8] = {0};
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx != 0 || dy != 0) {
                            int ni = i + dx;
                            int nj = j + dy;
                            if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
                                neighbors[(dx + 1) * 3 + (dy + 1)] = grid[ni][nj];
                            }
                        }
                    }
                }
                int sum = 0;
                for (int k = 0; k < 8; k++) {
                    sum += neighbors[k];
                }
                new_grid[i][j] = rules[sum];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

void main() {
    int initial_grid[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
    int transition_rules[9] = {0, 1, 1, 1, 0, 0, 0, 0, 0};
    simulate(initial_grid, transition_rules);
}