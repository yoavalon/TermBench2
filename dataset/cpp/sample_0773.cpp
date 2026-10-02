#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int ny = std::max(0, y - 1); ny < std::min(height, y + 2); ++ny) {
                for (int nx = std::max(0, x - 1); nx < std::min(width, x + 2); ++nx) {
                    neighbors += grid[ny][nx];
                }
            }
            neighbors -= grid[y][x];
            new_grid[y][x] = (neighbors == 3 || (neighbors == 2 && grid[y][x] == 1)) ? 1 : 0;
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int width, int height, int steps) {
    std::vector<std::vector<int>> current_grid = grid;
    for (int _ = 0; _ < steps; ++_) {
        current_grid = update_grid(current_grid, width, height);
    }
    return current_grid;
}

int main() {
    int width = 10, height = 10;
    int steps = 5;
    std::vector<std::vector<int>> initial_grid(height, std::vector<int>(width, 0));
    initial_grid[5][5] = 1;
    std::vector<std::vector<int>> result = simulate(initial_grid, width, height, steps);
    for (const auto& row : result) {
        for (int cell : row) {
            std::cout << (cell ? 'O' : ' ');
        }
        std::cout << '\n';
    }
    return 0;
}