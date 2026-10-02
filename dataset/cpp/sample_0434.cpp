#include <vector>
#include <iostream>

int update_cell(int state, const std::vector<int>& neighbors) {
    int active_neighbors = 0;
    for (int neighbor : neighbors) {
        active_neighbors += neighbor;
    }
    if (state == 1) {
        return (active_neighbors == 2 || active_neighbors == 3) ? 1 : 0;
    } else {
        return (active_neighbors == 3) ? 1 : 0;
    }
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::vector<int> neighbors;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors.push_back(grid[ni][nj]);
                    }
                }
            }
            new_grid[i][j] = update_cell(grid[i][j], neighbors);
        }
    }
    return new_grid;
}

void main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    while (true) {
        grid = simulate(grid);
    }
}