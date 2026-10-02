#include <vector>
#include <iostream>

std::vector<std::vector<int>> simulate(std::vector<std::vector<int>>& grid, const std::vector<int>& rules) {
    while (true) {
        std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = rules[neighbors];
            }
        }
        grid = new_grid;
    }
    return grid; // This return is just to make the function compile, it will never be reached.
}

int main() {
    std::vector<std::vector<int>> initial_grid = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
    std::vector<int> transition_rules = {0, 1, 1, 1, 0, 0, 0, 0, 0};
    simulate(initial_grid, transition_rules);
    return 0;
}