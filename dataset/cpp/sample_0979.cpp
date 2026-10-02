#include <vector>

std::vector<std::vector<int>> fluid_dynamics(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> next_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(size, i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(size, j + 2); ++y) {
                    neighbors += grid[x][y];
                }
            }
            next_grid[i][j] = (neighbors > 4) ? 1 : 0;
        }
    }
    return fluid_dynamics(next_grid);
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[5][5] = 1;
    fluid_dynamics(grid);
    return 0;
}