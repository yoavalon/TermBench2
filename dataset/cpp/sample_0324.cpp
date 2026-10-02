#include <vector>

void simulate() {
    std::vector<std::vector<int>> grid(50, std::vector<int>(50, 0));
    while (true) {
        std::vector<std::vector<int>> new_grid(50, std::vector<int>(50, 0));
        for (int i = 1; i < 49; ++i) {
            for (int j = 1; j < 49; ++j) {
                int neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1];
                new_grid[i][j] = (neighbors == 2) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

int main() {
    simulate();
    return 0;
}