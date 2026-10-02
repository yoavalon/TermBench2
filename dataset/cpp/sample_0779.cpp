#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                }
            }
            new_grid[y][x] = (neighbors == 3) ? 1 : grid[y][x];
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int width, int height, int steps) {
    if (steps == 0) {
        return grid;
    }
    return simulate(update_grid(grid, width, height), width, height, steps - 1);
}

void main() {
    int width = 10, height = 10, steps = 5;
    std::vector<std::vector<int>> initial_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            initial_grid[y][x] = (x != y) ? 0 : 1;
        }
    }
    std::vector<std::vector<int>> final_grid = simulate(initial_grid, width, height, steps);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}