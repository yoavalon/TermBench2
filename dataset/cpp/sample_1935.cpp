#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int ni = std::max(0, i - 1); ni < std::min(rows, i + 2); ++ni) {
                for (int nj = std::max(0, j - 1); nj < std::min(cols, j + 2); ++nj) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
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
    int grid_size = 10;
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size, 0));
    grid[grid_size / 2][grid_size / 2] = 1;
    int steps = 50;

    for (int _ = 0; _ < steps; ++_) {
        grid = update_grid(grid);
    }

    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}