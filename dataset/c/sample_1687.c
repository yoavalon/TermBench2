#include <stdio.h>

void update_grid(int grid[3][3]) {
    int rows = 3;
    int cols = 3;
    int new_grid[3][3];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if ((x != i || y != j) && x >= 0 && x < rows && y >= 0 && y < cols) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if ((grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) || (grid[i][j] == 0 && neighbors == 3)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (1) {
        update_grid(grid);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}