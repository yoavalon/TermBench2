#include <vector>
#include <iostream>

std::vector<std::vector<int>> initialize_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[size / 2][size / 2] = 1;
    return grid;
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(size, i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(size, j + 2); ++y) {
                    neighbors += grid[x][y];
                }
            }
            if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> grid = initialize_grid(size);
    while (true) {
        grid = update_grid(grid);
    }
    return 0;
}