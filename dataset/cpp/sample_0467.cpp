#include <vector>

std::vector<std::vector<int>> initialize_grid(int size) {
    return std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid);
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            int neighbors = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[i].size()) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : 0;
        }
    }
    return new_grid;
}

int main() {
    int grid_size = 10;
    std::vector<std::vector<int>> grid = initialize_grid(grid_size);
    while (true) {
        grid = update_grid(grid);
    }
    return 0;
}