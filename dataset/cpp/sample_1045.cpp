#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::vector<int> neighbors = {
                grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols],
                grid[(i - 1 + rows) % rows][j],
                grid[(i - 1 + rows) % rows][(j + 1) % cols],
                grid[i][(j - 1 + cols) % cols],
                grid[i][(j + 1) % cols],
                grid[(i + 1) % rows][(j - 1 + cols) % cols],
                grid[(i + 1) % rows][j],
                grid[(i + 1) % rows][(j + 1) % cols]
            };
            new_grid[i][j] = std::accumulate(neighbors.begin(), neighbors.end(), 0) / 8;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid) {
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> initial_grid = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    simulate(initial_grid);
    return 0;
}