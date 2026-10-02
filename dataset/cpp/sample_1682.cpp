#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            int neighbors = 0;
            for (const auto& [x, y] : std::vector<std::pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                    neighbors += grid[x][y];
                }
            }
            new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2) ? 1 : 0;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid) {
    while (true) {
        grid = update_state(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::vector<int>> initial_grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_grid);
    return 0;
}