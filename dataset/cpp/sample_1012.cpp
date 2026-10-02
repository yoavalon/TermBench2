#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::vector<std::pair<int, int>> neighbors;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x != 0 || y != 0) {
                        neighbors.emplace_back(i + x, j + y);
                    }
                }
            }
            int live_neighbors = 0;
            for (const auto& [x, y] : neighbors) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    live_neighbors += grid[x][y];
                }
            }
            if (grid[i][j] && (live_neighbors == 2 || live_neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (!grid[i][j] && live_neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

void simulate(const std::vector<std::vector<int>>& grid) {
    display(grid);
    simulate(update_grid(grid));
}

void display(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        std::string line;
        for (int cell : row) {
            line += (cell ? '█' : ' ');
        }
        std::cout << line << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> initial_grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_grid);
    return 0;
}