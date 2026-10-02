#include <iostream>
#include <vector>

std::vector<std::vector<int>> init_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (x != 0 && x != size - 1 && y != 0 && y != size - 1) {
                grid[y][x] = 0;
            } else {
                grid[y][x] = 1;
            }
        }
    }
    return grid;
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int y = 1; y < size - 1; ++y) {
        for (int x = 1; x < size - 1; ++x) {
            int neighbors = grid[y - 1][x] + grid[y + 1][x] + grid[y][x - 1] + grid[y][x + 1];
            new_grid[y][x] = (neighbors >= 2) ? 1 : 0;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid) {
    while (true) {
        grid = update_grid(grid);
    }
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> grid = init_grid(size);
    simulate(grid);
    return 0;
}