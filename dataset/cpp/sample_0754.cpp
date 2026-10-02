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
            new_grid[y][x] = (neighbors == 3 || (grid[y][x] && neighbors == 2)) ? 1 : 0;
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

int main() {
    int width = 5, height = 5, steps = 5;
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = (x + y) % 2 ? 1 : 0;
        }
    }
    std::vector<std::vector<int>> final_grid = simulate(grid, width, height, steps);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << (cell ? 'O' : ' ');
        }
        std::cout << std::endl;
    }
    return 0;
}