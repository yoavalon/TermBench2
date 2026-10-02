#include <iostream>
#include <vector>

std::vector<std::vector<int>> initialize_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[size / 2][size / 2] = 1;
    return grid;
}

void apply_boundary_conditions(std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    for (int i = 0; i < size; ++i) {
        grid[0][i] = 0;
        grid[size - 1][i] = 0;
        grid[i][0] = 0;
        grid[i][size - 1] = 0;
    }
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

std::vector<std::vector<int>> simulate(int steps) {
    int size = 50;
    std::vector<std::vector<int>> grid = initialize_grid(size);
    apply_boundary_conditions(grid);
    for (int _ = 0; _ < steps; ++_) {
        grid = update_grid(grid);
        apply_boundary_conditions(grid);
    }
    return grid;
}

void main() {
    int steps = 100;
    std::vector<std::vector<int>> result = simulate(steps);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}