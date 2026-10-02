#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int ni = std::max(0, i - 1); ni < std::min(rows, i + 2); ++ni) {
                for (int nj = std::max(0, j - 1); nj < std::min(cols, j + 2); ++nj) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return new_grid;
}

void simulate() {
    int size = 100;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        grid = update_grid(grid);
    }
}

int main() {
    simulate();
    return 0;
}