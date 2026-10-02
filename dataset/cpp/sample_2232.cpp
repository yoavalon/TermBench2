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

std::vector<std::vector<int>> evolve(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> next_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                next_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                next_grid[i][j] = 1;
            } else {
                next_grid[i][j] = grid[i][j];
            }
        }
    }
    return next_grid;
}

int main() {
    int grid_size = 100;
    std::srand(std::time(0));
    std::vector<std::vector<int>> grid = initialize_grid(grid_size);
    while (true) {
        grid = evolve(grid);
    }
    return 0;
}