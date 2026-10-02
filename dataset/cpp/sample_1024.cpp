#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, const std::vector<int>& rules) {
    std::vector<std::vector<int>> new_grid = grid;
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            int neighbors = 0;
            for (int x = std::max(0, static_cast<int>(i - 1)); x < std::min(static_cast<int>(grid.size()), static_cast<int>(i + 2)); ++x) {
                for (int y = std::max(0, static_cast<int>(j - 1)); y < std::min(static_cast<int>(grid[0].size()), static_cast<int>(j + 2)); ++y) {
                    neighbors += grid[x][y];
                }
            }
            neighbors -= grid[i][j];
            new_grid[i][j] = rules[neighbors];
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid, const std::vector<int>& rules) {
    system("clear");
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell ? '#' : '.');
        }
        std::cout << std::endl;
    }
    simulate(update_grid(grid, rules), rules);
}

int main() {
    int width = 20, height = 20;
    std::vector<std::vector<int>> initial_grid(height, std::vector<int>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            initial_grid[i][j] = ((i + j) % 2 == 0);
        }
    }
    std::vector<int> rules = {0, 0, 1, 1, 0, 0, 0, 0, 0};
    simulate(initial_grid, rules);
    return 0;
}