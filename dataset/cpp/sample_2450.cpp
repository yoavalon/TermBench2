#include <vector>

std::vector<std::vector<int>> simulate_cells(int rows, int cols, int steps) {
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    for (int step = 0; step < steps; ++step) {
        std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int neighbors = 0;
                for (int x = std::max(0, i - 1); x < std::min(rows, i + 2); ++x) {
                    for (int y = std::max(0, j - 1); y < std::min(cols, j + 2); ++y) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
    return grid;
}

int main() {
    simulate_cells(10, 10, 5);
    return 0;
}