#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int nx = (x + i + width) % width;
                    int ny = (y + j + height) % height;
                    neighbors += grid[ny][nx];
                }
            }
            new_grid[y][x] = (neighbors > 2 && neighbors < 4) ? 1 : 0;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid, int width, int height) {
    print_grid(grid, width, height);
    simulate(update_grid(grid, width, height), width, height);
}

void print_grid(const std::vector<std::vector<int>>& grid, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << (grid[y][x] ? '#' : ' ');
        }
        std::cout << std::endl;
    }
}

int main() {
    int width = 50;
    int height = 50;
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    grid[25][25] = 1;
    simulate(grid, width, height);
    return 0;
}