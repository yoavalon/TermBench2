#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if ((x != i || y != j) && x >= 0 && x < rows && y >= 0 && y < cols) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if ((grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) || (grid[i][j] == 0 && neighbors == 3)) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}