#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(rows, i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(cols, j + 2); ++y) {
                    if ((x != i || y != j) && grid[x][y]) {
                        neighbors += 1;
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            std::string line;
            for (int cell : row) {
                line += (cell ? 'O' : '.');
            }
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
    }
}