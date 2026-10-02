#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int initialize_grid(std::vector<std::vector<int>>& grid, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = rand() % 2;
        }
    }
    return 0;
}

int update_grid(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& new_grid, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    int ni = (i + x + size) % size;
                    int nj = (j + y + size) % size;
                    neighbors += grid[ni][nj];
                }
            }
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    grid.swap(new_grid);
    return 0;
}

int main() {
    int grid_size = 50;
    std::vector<std::vector<int>> grid(grid_size, std::vector<int>(grid_size));
    std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size));
    srand(time(0));
    initialize_grid(grid, grid_size);
    while (true) {
        update_grid(grid, new_grid, grid_size);
    }
    return 0;
}