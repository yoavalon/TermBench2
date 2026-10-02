#include <vector>
#include <iostream>

std::vector<std::vector<double>> update_state(const std::vector<std::vector<double>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<double>> new_grid(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::vector<std::pair<int, int>> neighbors = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
            double value = 0.0;
            for (const auto& [x, y] : neighbors) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    value += grid[x][y];
                }
            }
            new_grid[i][j] = value / 4.0;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<double>>& grid) {
    while (true) {
        grid = update_state(grid);
    }
}

void main() {
    int grid_size = 10;
    std::vector<std::vector<double>> initial_grid(grid_size, std::vector<double>(grid_size, 0.0));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            initial_grid[i][j] = static_cast<double>(i * j);
        }
    }
    simulate(initial_grid);
}

int main() {
    main();
    return 0;
}