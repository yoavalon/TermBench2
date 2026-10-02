#include <vector>
#include <iostream>

void simulate_flow(int width, int height) {
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    while (true) {
        std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int neighbors = 0;
                neighbors += grid[(y - 1 + height) % height][(x + width) % width];
                neighbors += grid[(y + 1) % height][(x + width) % width];
                neighbors += grid[(y + height) % height][(x - 1 + width) % width];
                neighbors += grid[(y + height) % height][(x + 1) % width];
                new_grid[y][x] = neighbors / 4;
            }
        }
        grid = new_grid;
    }
}

int main() {
    simulate_flow(10, 10);
    return 0;
}