#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                }
            }
            if (grid[y][x] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 0 && neighbors == 3) {
                new_grid[y][x] = 1;
            } else {
                new_grid[y][x] = grid[y][x];
            }
        }
    }
    return new_grid;
}

int main() {
    int width = 10, height = 10;
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = (x + y) % 2;
        }
    }
    while (true) {
        grid = update_grid(grid, width, height);
    }
    return 0;
}