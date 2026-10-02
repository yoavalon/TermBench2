#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size));
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            int neighbors = 0;
            for (int ni = i - 1; ni <= i + 1; ++ni) {
                for (int nj = j - 1; nj <= j + 1; ++nj) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    return new_grid;
}

void main() {
    int grid_size = 50;
    std::srand(std::time(0));
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        grid = update_grid(grid);
    }
}