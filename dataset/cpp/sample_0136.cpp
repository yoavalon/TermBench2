#include <iostream>
#include <vector>

std::vector<std::vector<int>> initialize_grid(int size) {
    return std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            }
        }
    }
    return new_grid;
}

void main() {
    int grid_size = 50;
    int iterations = 100;
    auto grid = initialize_grid(grid_size);
    for (int _ = 0; _ < iterations; ++_) {
        grid = update_grid(grid);
    }
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}