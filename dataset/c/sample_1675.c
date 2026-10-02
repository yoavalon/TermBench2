#include <stdio.h>

void update_state(int grid[3][3]) {
    int rows = 3, cols = 3;
    int new_grid[3][3];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = (i > 0 ? i - 1 : 0); x < (i + 2 < rows ? i + 2 : rows); x++) {
                for (int y = (j > 0 ? j - 1 : 0); y < (j + 2 < cols ? j + 2 : cols); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
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
        update_state(grid);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c", (grid[i][j] == 1) ? 'O' : '.');
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}