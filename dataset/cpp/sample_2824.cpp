#include <vector>
#include <iostream>

std::vector<std::vector<int>> init_grid(int rows, int cols) {
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    grid[rows / 2][cols / 2] = 1;
    return grid;
}

std::vector<std::vector<int>> update_grid(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            if (i > 0) neighbors += grid[i - 1][j];
            if (i < rows - 1) neighbors += grid[i + 1][j];
            if (j > 0) neighbors += grid[i][j - 1];
            if (j < cols - 1) neighbors += grid[i][j + 1];
            new_grid[i][j] = (neighbors == 1) ? 1 : 0;
        }
    }
    return new_grid;
}

int main() {
    std::vector<std::vector<int>> grid = init_grid(10, 10);
    while (true) {
        grid = update_grid(grid);
    }
    return 0;
}