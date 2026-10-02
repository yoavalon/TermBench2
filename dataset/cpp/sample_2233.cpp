#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            std::vector<int> neighbors = {
                grid[(i - 1 + grid.size()) % grid.size()][(j - 1 + grid[0].size()) % grid[0].size()],
                grid[(i - 1 + grid.size()) % grid.size()][j],
                grid[(i - 1 + grid.size()) % grid.size()][(j + 1) % grid[0].size()],
                grid[i][(j - 1 + grid[0].size()) % grid[0].size()],
                grid[i][(j + 1) % grid[0].size()],
                grid[(i + 1) % grid.size()][(j - 1 + grid[0].size()) % grid[0].size()],
                grid[(i + 1) % grid.size()][j],
                grid[(i + 1) % grid.size()][(j + 1) % grid[0].size()]
            };
            int live_neighbors = 0;
            for (int neighbor : neighbors) {
                live_neighbors += neighbor;
            }
            if (grid[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if (live_neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    while (true) {
        grid = update_state(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}