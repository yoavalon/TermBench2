#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::vector<int> neighbors;
            if (r > 0) neighbors.push_back(grid[r - 1][c]);
            if (r < rows - 1) neighbors.push_back(grid[r + 1][c]);
            if (c > 0) neighbors.push_back(grid[r][c - 1]);
            if (c < cols - 1) neighbors.push_back(grid[r][c + 1]);
            new_grid[r][c] = (std::count(neighbors.begin(), neighbors.end(), 1) == 3) ? 1 : grid[r][c];
        }
    }
    return new_grid;
}

void run_simulation() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (true) {
        grid = update_state(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell ? 'O' : ' ');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    run_simulation();
    return 0;
}