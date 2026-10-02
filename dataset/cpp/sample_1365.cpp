#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int live_neighbors = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        live_neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = (live_neighbors == 3) || (grid[i][j] && live_neighbors == 2) ? 1 : 0;
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    for (int _ = 0; _ < 10; ++_) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell ? 'X' : ' ');
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}