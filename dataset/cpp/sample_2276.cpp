#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void update_grid(std::vector<std::vector<int>>& grid) {
    int grid_size = grid.size();
    std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size, 0));
    for (int i = 1; i < grid_size - 1; ++i) {
        for (int j = 1; j < grid_size - 1; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    grid = new_grid;
}

void simulate() {
    int grid_size = 50;
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size, 0));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        update_grid(grid);
    }
}

int main() {
    std::srand(std::time(0));
    simulate();
    return 0;
}