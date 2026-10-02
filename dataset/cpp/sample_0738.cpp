#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int size) {
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(size, i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(size, j + 2); ++y) {
                    if ((x, y) != (i, j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int size, int steps) {
    if (steps == 0) {
        return grid;
    }
    return simulate(update_grid(grid, size), size, steps - 1);
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> initial_grid(size, std::vector<int>(size, 0));
    initial_grid[5][5] = 1;
    initial_grid[5][6] = 1;
    initial_grid[6][5] = 1;
    initial_grid[6][6] = 1;
    std::vector<std::vector<int>> final_grid = simulate(initial_grid, size, 10);
    for (const auto& row : final_grid) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}