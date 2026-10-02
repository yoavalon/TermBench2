#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size_x = grid.size();
    int size_y = grid[0].size();
    std::vector<std::vector<int>> new_grid(size_x, std::vector<int>(size_y, 0));
    for (int i = 1; i < size_x - 1; ++i) {
        for (int j = 1; j < size_y - 1; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (!grid[i][j] && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(const std::vector<std::vector<int>>& grid, int steps) {
    std::vector<std::vector<int>> current_grid = grid;
    for (int step = 0; step < steps; ++step) {
        current_grid = update_grid(current_grid);
    }
    return current_grid;
}

void main() {
    int size = 50;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int i = 20; i < 25; ++i) {
        for (int j = 20; j < 25; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    std::vector<std::vector<int>> final_grid = simulate(grid, 100);
    for (const auto& row : final_grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    main();
    return 0;
}