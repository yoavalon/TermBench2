#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dy == 0 && dx == 0) {
                        continue;
                    }
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[y][x] = 0;
                } else {
                    new_grid[y][x] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[y][x] = 1;
            }
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> run_simulation(const std::vector<std::vector<int>>& grid, int width, int height, int steps) {
    if (steps == 0) {
        return grid;
    } else {
        std::vector<std::vector<int>> new_grid = update_state(grid, width, height);
        return run_simulation(new_grid, width, height, steps - 1);
    }
}

void main() {
    int width = 10;
    int height = 10;
    std::vector<std::vector<int>> initial_grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int steps = 10;
    std::vector<std::vector<int>> final_grid = run_simulation(initial_grid, width, height, steps);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}