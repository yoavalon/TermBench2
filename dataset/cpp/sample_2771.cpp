#include <vector>
#include <cstdlib>

void simulate() {
    int grid_size = 30;
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size, 0));
    while (true) {
        std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size, 0));
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                int neighbors = 0;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        if (x == 0 && y == 0) continue;
                        neighbors += grid[(i + x + grid_size) % grid_size][(j + y + grid_size) % grid_size];
                    }
                }
                if ((grid[i][j] && neighbors >= 2 && neighbors <= 3) || (!grid[i][j] && neighbors == 3)) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
}

int main() {
    simulate();
    return 0;
}