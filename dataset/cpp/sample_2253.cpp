#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(i + 2, static_cast<int>(grid.size())); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(j + 2, static_cast<int>(grid[0].size())); ++y) {
                    if ((x, y) != (i, j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors < 2 || neighbors > 3) ? 0 : grid[i][j];
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    while (true) {
        grid = update_state(grid);
        for (const auto& row : grid) {
            for (int val : row) {
                std::cout << val << ' ';
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < grid[0].size() * 2; ++i) {
            std::cout << '-';
        }
        std::cout << std::endl;
    }
}