#include <iostream>
#include <vector>

std::vector<std::vector<double>> update_grid(const std::vector<std::vector<double>>& grid, int width, int height) {
    std::vector<std::vector<double>> new_grid(height, std::vector<double>(width, 0.0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double sum = 0.0;
            int count = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dy != 0 || dx != 0) {
                        sum += grid[(y + dy + height) % height][(x + dx + width) % width];
                        ++count;
                    }
                }
            }
            new_grid[y][x] = sum / count;
        }
    }
    return new_grid;
}

std::vector<std::vector<double>> simulate(int width, int height, int steps) {
    std::vector<std::vector<double>> grid(height, std::vector<double>(width, 0.0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = static_cast<double>(x + y);
        }
    }
    for (int step = 0; step < steps; ++step) {
        grid = update_grid(grid, width, height);
    }
    return grid;
}

void main() {
    int width = 10, height = 10, steps = 5;
    std::vector<std::vector<double>> final_grid = simulate(width, height, steps);
    for (const auto& row : final_grid) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}