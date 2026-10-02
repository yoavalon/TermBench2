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
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < size && y >= 0 && y < size && (x != i || y != j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : 0;
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