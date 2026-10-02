#include <vector>

std::vector<std::vector<int>> update_grid(std::vector<std::vector<int>>& grid, int width, int height) {
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
            if (grid[y][x]) {
                new_grid[y][x] = (neighbors == 2 || neighbors == 3);
            } else {
                new_grid[y][x] = (neighbors == 3);
            }
        }
    }
    return new_grid;
}

void main() {
    int width = 50, height = 50;
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = ((x + y) % 2) ? 0 : 1;
        }
    }
    while (true) {
        grid = update_grid(grid, width, height);
    }
}