#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int size) {
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            int neighbors_sum = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    neighbors_sum += grid[i + di][j + dj];
                }
            }
            if (grid[i][j] == 0 && neighbors_sum > 2) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 1 && (neighbors_sum < 2 || neighbors_sum > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return new_grid;
}

void main() {
    int size = 50;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[size / 2][size / 2] = 1;
    while (true) {
        grid = update_grid(grid, size);
    }
}