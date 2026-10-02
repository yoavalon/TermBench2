#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> update_cells(const std::vector<std::vector<int>>& grid) {
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
            new_grid[i][j] = (neighbors == 3) ? 1 : grid[i][j];
        }
    }
    return new_grid;
}

void display_grid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        std::string line;
        for (int cell : row) {
            line += (cell ? 'O' : '.');
        }
        std::cout << line << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (true) {
        display_grid(grid);
        grid = update_cells(grid);
    }
    return 0;
}