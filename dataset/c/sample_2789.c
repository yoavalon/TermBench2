#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cellular_automata() {
    int grid[100];
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        grid[i] = rand() % 2;
    }
    while (1) {
        int new_grid[100];
        for (int i = 0; i < 100; i++) {
            int left = grid[(i - 1 + 100) % 100];
            int center = grid[i];
            int right = grid[(i + 1) % 100];
            new_grid[i] = (left + center + right == 2) ? 1 : 0;
        }
        for (int i = 0; i < 100; i++) {
            grid[i] = new_grid[i];
        }
    }
}

int main() {
    cellular_automata();
    return 0;
}