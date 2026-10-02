#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int alive_neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        alive_neighbors += grid[ni][nj];
                    }
                }
            }
            alive_neighbors -= grid[i][j];
            if (grid[i][j] == 1 && (alive_neighbors < 2 || alive_neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && alive_neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

void simulate(int grid_size) {
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size, 0));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        grid = update_grid(grid);
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::srand(std::time(0));
    simulate(10);
    return 0;
}