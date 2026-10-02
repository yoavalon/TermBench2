#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 1) {
                new_grid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    for (int _ = 0; _ < 10; ++_) {
        initial_grid = update_grid(initial_grid);
        for (const auto& row : initial_grid) {
            for (int cell : row) {
                std::cout << (cell ? '#' : ' ');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}