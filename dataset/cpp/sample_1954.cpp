#include <iostream>
#include <vector>

std::vector<std::vector<double>> update_grid(std::vector<std::vector<double>>& grid, int width, int height) {
    std::vector<std::vector<double>> new_grid(height, std::vector<double>(width, 0.0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double neighbors = 0.0;
            for (int dy = -1; dy < 2; ++dy) {
                for (int dx = -1; dx < 2; ++dx) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < width && 0 <= ny && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x]);
        }
    }
    return new_grid;
}

void main() {
    int width = 10, height = 10;
    std::vector<std::vector<double>> grid(height, std::vector<double>(width, 0.0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = (x == y) ? 0.0 : 1.0;
        }
    }
    for (int _ = 0; _ < 100; ++_) {
        grid = update_grid(grid, width, height);
    }
    for (const auto& row : grid) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}