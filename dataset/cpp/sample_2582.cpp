#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> initialize_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    return grid;
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if ((di != 0 || dj != 0)) {
                        neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (grid[i][j] && neighbors == 2)) ? 1 : 0;
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(int steps, int size) {
    std::vector<std::vector<int>> grid = initialize_grid(size);
    for (int _ = 0; _ < steps; ++_) {
        grid = update_grid(grid);
    }
    return grid;
}

void main() {
    int steps = 10, size = 5;
    std::vector<std::vector<int>> result = simulate(steps, size);
    for (const auto& row : result) {
        for (int cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}