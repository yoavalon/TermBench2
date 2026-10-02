#include <iostream>
#include <vector>

std::vector<std::vector<double>> update_grid(const std::vector<std::vector<double>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<double>> new_grid(rows, std::vector<double>(cols, 0.0));
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            double avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            new_grid[i][j] = (grid[i][j] + avg) / 2.0;
        }
    }
    return new_grid;
}

std::vector<std::vector<double>> simulate(const std::vector<std::vector<double>>& grid, int steps) {
    std::vector<std::vector<double>> current_grid = grid;
    for (int _ = 0; _ < steps; ++_) {
        current_grid = update_grid(current_grid);
    }
    return current_grid;
}

int main() {
    int grid_size = 10;
    int steps = 5;
    std::vector<std::vector<double>> grid(grid_size, std::vector<double>(grid_size, 0.0));
    grid[grid_size / 2][grid_size / 2] = 1.0;
    std::vector<std::vector<double>> result = simulate(grid, steps);
    for (const auto& row : result) {
        for (double x : row) {
            std::cout << std::fixed << std::setprecision(2) << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}