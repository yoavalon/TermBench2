#include <vector>
#include <iostream>

std::vector<std::vector<int>> initialize_grid(int rows, int cols) {
    return std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !(x == i && y == j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors < 2 || neighbors > 3) ? 0 : grid[i][j];
        }
    }
    return new_grid;
}

int main() {
    int rows = 50, cols = 50;
    std::vector<std::vector<int>> grid = initialize_grid(rows, cols);
    while (true) {
        grid = update_grid(grid);
    }
    return 0;
}