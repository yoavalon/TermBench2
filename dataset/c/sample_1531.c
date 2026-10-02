#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 50

void cellular_automata(int width, int height) {
    int grid[HEIGHT][WIDTH];
    int new_grid[HEIGHT][WIDTH];
    int i, j, k, l, neighbors;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }

    while (1) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                new_grid[i][j] = grid[i][j];
            }
        }

        for (i = 1; i < height - 1; i++) {
            for (j = 1; j < width - 1; j++) {
                neighbors = 0;
                for (k = i - 1; k <= i + 1; k++) {
                    for (l = j - 1; l <= j + 1; l++) {
                        neighbors += grid[k][l];
                    }
                }
                neighbors -= grid[i][j];

                if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (!grid[i][j] && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }

        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    cellular_automata(WIDTH, HEIGHT);
    return 0;
}