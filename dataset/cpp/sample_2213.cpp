#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<double>> initialize_grid(int size) {
    std::vector<std::vector<double>> grid(size, std::vector<double>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }
    return grid;
}

std::vector<std::vector<double>> evolve(const std::vector<std::vector<double>>& grid, int steps) {
    int size = grid.size();
    std::vector<std::vector<double>> new_grid(size, std::vector<double>(size));
    for (int step = 0; step < steps; ++step) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int sum = grid[(i + 1) % size][j] + grid[(i - 1 + size) % size][j] +
                          grid[i][(j + 1) % size] + grid[i][(j - 1 + size) % size];
                new_grid[i][j] = std::max(0.0, std::min(1.0, sum));
            }
        }
        grid = new_grid;
    }
    return grid;
}

void print_grid(const std::vector<std::vector<double>>& grid) {
    for (const auto& row : grid) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int size = 100;
    std::srand(std::time(0));
    std::vector<std::vector<double>> grid = initialize_grid(size);
    while (true) {
        grid = evolve(grid, 10);
        print_grid(grid);
    }
    return 0;
}