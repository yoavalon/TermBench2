#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

void main() {
    int size = 100;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        grid = update_state(grid);
    }
}