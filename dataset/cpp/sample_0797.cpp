#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            int count = 0;
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !(x == i && y == j)) {
                        count += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (grid[i][j] && (count == 2 || count == 3)) || count == 3;
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int steps) {
    std::vector<std::vector<int>> current_grid = grid;
    for (int _ = 0; _ < steps; ++_) {
        current_grid = update_grid(current_grid);
    }
    return current_grid;
}

int main() {
    std::vector<std::vector<int>> initial_grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    std::vector<std::vector<int>> final_grid = simulate(initial_grid, 10);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}