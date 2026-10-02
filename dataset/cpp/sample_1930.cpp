#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> update_grid(const std::vector<std::vector<double>>& grid, int precision) {
    int size = grid.size();
    std::vector<std::vector<double>> new_grid(size, std::vector<double>(size, 0.0));
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            double sum = 0.0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    sum += grid[i + di][j + dj];
                }
            }
            double avg = sum / 9.0;
            new_grid[i][j] = std::round(avg * std::pow(10, precision)) / std::pow(10, precision);
        }
    }
    return new_grid;
}

std::vector<std::vector<double>> run_simulation(int steps, int precision) {
    int grid_size = 10;
    std::vector<std::vector<double>> grid(grid_size, std::vector<double>(grid_size));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    for (int step = 0; step < steps; ++step) {
        grid = update_grid(grid, precision);
    }
    return grid;
}

int main() {
    int steps = 50;
    int precision = 3;
    std::vector<std::vector<double>> result = run_simulation(steps, precision);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}