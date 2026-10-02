#include <vector>
#include <iostream>

std::vector<std::vector<int>> cellular_automata(const std::vector<std::vector<int>>& grid, int steps) {
    if (steps == 0) {
        return grid;
    }
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            int neighbors = 0;
            for (const auto& [x, y] : std::vector<std::pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
                if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size()) {
                    neighbors += grid[x][y];
                }
            }
            new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0;
        }
    }
    return cellular_automata(new_grid, steps - 1);
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    auto result = cellular_automata(grid, 10);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}