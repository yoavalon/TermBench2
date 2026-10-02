#include <iostream>
#include <vector>

std::vector<std::vector<double>> update_grid(const std::vector<std::vector<double>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<double>> new_grid(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i > 0 && j > 0 && i < rows - 1 && j < cols - 1) {
                new_grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return new_grid;
}

std::vector<std::vector<double>> simulate(int n, int size) {
    std::vector<std::vector<double>> grid(size, std::vector<double>(size, 0.0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = static_cast<double>(i == size / 2 && j == size / 2);
        }
    }
    for (int _ = 0; _ < n; ++_) {
        grid = update_grid(grid);
    }
    return grid;
}

void main() {
    std::vector<std::vector<double>> result = simulate(10, 5);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}