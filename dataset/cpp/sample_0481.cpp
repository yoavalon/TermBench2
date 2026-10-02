#include <iostream>
#include <vector>

std::vector<std::vector<int>> initialize_grid(int size) {
    return std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    return new_grid;
}

int main() {
    int size = 50;
    std::vector<std::vector<int>> grid = initialize_grid(size);
    while (true) {
        grid = update_grid(grid);
    }
    return 0;
}