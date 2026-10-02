#include <vector>
#include <iostream>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(rows, i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(cols, j + 2); ++y) {
                    if ((x, y) != (i, j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2);
        }
    }
    return new_grid;
}

void simulate(const std::vector<std::vector<int>>& grid) {
    simulate(update_grid(grid));
}

int main() {
    int grid_size = 10;
    std::vector<std::vector<int>> initial_grid(grid_size, std::vector<int>(grid_size, 0));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            initial_grid[i][j] = (i % 2 == 0 || j % 2 == 0) ? 0 : 1;
        }
    }
    simulate(initial_grid);
    return 0;
}