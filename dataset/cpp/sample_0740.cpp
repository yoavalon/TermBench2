#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dy == 0 && dx == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (0 <= nx && nx < width && 0 <= ny && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] == 1) {
                new_grid[y][x] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int width, int height, int steps) {
    if (steps == 0) {
        return grid;
    } else {
        return simulate(update_state(grid, width, height), width, height, steps - 1);
    }
}

void main() {
    int width = 50;
    int height = 50;
    int steps = 100;
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = ((x + y) % 2) ? 1 : 0;
        }
    }
    std::vector<std::vector<int>> final_grid = simulate(grid, width, height, steps);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << (cell ? 'O' : ' ');
        }
        std::cout << std::endl;
    }
}