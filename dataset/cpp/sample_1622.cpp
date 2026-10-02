#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int live_neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    live_neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                }
            }
            if (grid[i][j]) {
                new_grid[i][j] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (live_neighbors == 3) ? 1 : 0;
            }
        }
    }
    return new_grid;
}

void main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    int size = 10;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = dis(gen);
        }
    }
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}