#include <stdio.h>

int cellular_automata(int grid[10][10], int (*rule)(int[8])) {
    int new_grid[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int neighbors[8];
            int index = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x != 0 || y != 0) {
                        neighbors[index++] = grid[(i + x + 10) % 10][(j + y + 10) % 10];
                    }
                }
            }
            int sorted_neighbors[8] = {0};
            for (int k = 0; k < 8; k++) {
                sorted_neighbors[k] = neighbors[k];
            }
            for (int k = 0; k < 7; k++) {
                for (int l = k + 1; l < 8; l++) {
                    if (sorted_neighbors[k] > sorted_neighbors[l]) {
                        int temp = sorted_neighbors[k];
                        sorted_neighbors[k] = sorted_neighbors[l];
                        sorted_neighbors[l] = temp;
                    }
                }
            }
            new_grid[i][j] = rule(sorted_neighbors);
        }
    }
    return cellular_automata(new_grid, rule);
}

int rule(int n[8]) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += n[i];
    }
    return sum == 3 ? 1 : 0;
}

int main() {
    int initial_grid[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            initial_grid[i][j] = i == j ? 1 : 0;
        }
    }
    cellular_automata(initial_grid, rule);
    return 0;
}