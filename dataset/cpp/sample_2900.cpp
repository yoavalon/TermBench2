#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> initialize_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
        }
    }
    return new_grid;
}

void main() {
    srand(time(0));
    std::vector<std::vector<int>> grid = initialize_grid(10);
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell ? 'O' : ' ');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}