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
            int neighbors = grid[i][(j - 1 + cols) % cols] + grid[i][(j + 1) % cols] + grid[(i - 1 + rows) % rows][j] + grid[(i + 1) % rows][j] + grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols] + grid[(i - 1 + rows) % rows][(j + 1) % cols] + grid[(i + 1) % rows][(j - 1 + cols) % cols] + grid[(i + 1) % rows][(j + 1) % cols];
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
    int grid_size = 10;
    std::srand(std::time(nullptr));
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size, 0));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::string(20, '-') << std::endl;
    }
}