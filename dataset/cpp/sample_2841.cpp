#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, const std::map<std::vector<int>, int>& rules) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            std::vector<int> neighbors;
            for (size_t x = std::max(0, int(i - 1)); x < std::min(int(grid.size()), int(i + 2)); ++x) {
                for (size_t y = std::max(0, int(j - 1)); y < std::min(int(grid[0].size()), int(j + 2)); ++y) {
                    if (x != i || y != j) {
                        neighbors.push_back(grid[x][y]);
                    }
                }
            }
            std::sort(neighbors.begin(), neighbors.end());
            new_grid[i][j] = rules.find(neighbors) != rules.end() ? rules.at(neighbors) : 0;
        }
    }
    return new_grid;
}

int main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    std::map<std::vector<int>, int> rules = {
        {{0, 0, 0, 0, 0, 0, 0, 0}, 0},
        {{1, 1, 1, 1, 1, 1, 1, 1}, 1},
        {{0, 0, 0, 1, 1, 1, 0, 0}, 1}
    };
    while (true) {
        grid = update_grid(grid, rules);
    }
    return 0;
}