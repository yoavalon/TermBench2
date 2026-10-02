#include <stdio.h>

void update_grid(int grid[3][3]) {
    int new_grid[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int live_neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (!(x == 0 && y == 0)) {
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
                            live_neighbors += grid[ni][nj];
                        }
                    }
                }
            }
            new_grid[i][j] = (live_neighbors == 3) || (grid[i][j] && live_neighbors == 2) ? 1 : 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void main() {
    int grid[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    for (int _ = 0; _ < 10; _++) {
        update_grid(grid);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c", grid[i][j] ? 'X' : ' ');
            }
            printf("\n");
        }
        printf("\n");
    }
}