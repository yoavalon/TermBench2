#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> update(const std::vector<std::vector<int>>& grid, int size) {
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid, int size) {
    for (const auto& row : grid) {
        std::string line;
        for (int cell : row) {
            line += (cell ? '#' : ' ');
        }
        std::cout << line << std::endl;
    }
    simulate(update(grid, size), size);
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[size / 2][size / 2] = 1;
    simulate(grid, size);
    return 0;
}