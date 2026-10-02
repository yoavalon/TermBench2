#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int size) {
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(size, i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(size, j + 2); ++y) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(int size, int steps) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = (i % 2) ? 0 : 1;
        }
    }
    for (int _ = 0; _ < steps; ++_) {
        grid = update_grid(grid, size);
    }
    return grid;
}

void main() {
    int size = 5;
    int steps = 10;
    std::vector<std::vector<int>> result = simulate(size, steps);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
}