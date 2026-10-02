#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<float>> update_grid(const std::vector<std::vector<float>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<float>> new_grid(rows, std::vector<float>(cols, 0.0f));
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            float sum = 0.0f;
            for (int ii = i - 1; ii <= i + 1; ++ii) {
                for (int jj = j - 1; jj <= j + 1; ++jj) {
                    sum += grid[ii][jj];
                }
            }
            new_grid[i][j] = sum - grid[i][j];
        }
    }
    return new_grid;
}

std::vector<std::vector<float>> simulate_flow(int iterations) {
    std::srand(std::time(0));
    int rows = 10;
    int cols = 10;
    std::vector<std::vector<float>> grid(rows, std::vector<float>(cols, 0.0f));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = static_cast<float>(std::rand()) / RAND_MAX;
        }
    }
    for (int _ = 0; _ < iterations; ++_) {
        grid = update_grid(grid);
    }
    return grid;
}

void main() {
    std::vector<std::vector<float>> result = simulate_flow(100);
    for (const auto& row : result) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}