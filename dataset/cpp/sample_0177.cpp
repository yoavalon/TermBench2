#include <iostream>
#include <vector>

std::vector<std::vector<int>> init_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[size / 2][size / 2] = 1;
    return grid;
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

void print_grid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> grid = init_grid(size);
    int steps = 50;
    for (int _ = 0; _ < steps; ++_) {
        grid = update_grid(grid);
    }
    print_grid(grid);
    return 0;
}