#include <iostream>
#include <vector>

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
            new_grid[i][j] = (neighbors == 3 || (grid[i][j] && neighbors == 2)) ? 1 : 0;
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int steps) {
    std::vector<std::vector<int>> current_grid = grid;
    for (int _ = 0; _ < steps; ++_) {
        current_grid = update_grid(current_grid);
    }
    return current_grid;
}

int main() {
    std::vector<std::vector<int>> initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int steps = 5;
    std::vector<std::vector<int>> final_grid = simulate(initial_grid, steps);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}