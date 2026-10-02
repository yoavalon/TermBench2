#include <iostream>
#include <vector>
#include <functional>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, std::function<int(const std::vector<int>&, int)> rule) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            std::vector<int> neighbors;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (!(di == 0 && dj == 0)) {
                        neighbors.push_back(grid[(i + di) % grid.size()][(j + dj) % grid[0].size()]);
                    }
                }
            }
            new_grid[i][j] = rule(neighbors, grid[i][j]);
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> evolve(const std::vector<std::vector<int>>& grid, std::function<int(const std::vector<int>&, int)> rule, int steps) {
    std::vector<std::vector<int>> current_grid = grid;
    for (int _ = 0; _ < steps; ++_) {
        current_grid = update_grid(current_grid, rule);
    }
    return current_grid;
}

int rule(const std::vector<int>& neighbors, int cell) {
    return (std::accumulate(neighbors.begin(), neighbors.end(), 0) == 3) ? 1 : 0;
}

int main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (true) {
        grid = evolve(grid, rule, 1);
    }
    return 0;
}