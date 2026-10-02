#include <iostream>
#include <vector>

std::vector<std::vector<int>> cellular_automata(const std::vector<std::vector<int>>& grid, int steps) {
    for (int _ = 0; _ < steps; ++_) {
        std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int neighbors = 0;
                for (const auto& [x, y] : std::vector<std::pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                        neighbors += grid[x][y];
                    }
                }
                new_grid[i][j] = (neighbors == 2 || (neighbors == 3 && grid[i][j] == 1)) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
    return grid;
}

int main() {
    std::vector<std::vector<int>> initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int steps = 5;
    std::vector<std::vector<int>> result = cellular_automata(initial_grid, steps);
    for (const auto& row : result) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}