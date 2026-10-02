#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int ni = std::max(i - 1, 0); ni < std::min(i + 2, rows); ++ni) {
                for (int nj = std::max(j - 1, 0); nj < std::min(j + 2, cols); ++nj) {
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

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int size = 10;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = rand() % 2;
        }
    }
    while (true) {
        grid = update_grid(grid);
    }
    return 0;
}