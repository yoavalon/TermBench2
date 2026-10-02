#include <vector>
#include <iostream>

std::vector<std::vector<double>> update_grid(const std::vector<std::vector<double>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<double>> new_grid(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double total = 0.0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        total += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = total / 9.0;
        }
    }
    return new_grid;
}

void simulate() {
    std::vector<std::vector<double>> grid(10, std::vector<double>(10, 0.0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = static_cast<double>(i + j);
        }
    }
    while (true) {
        grid = update_grid(grid);
    }
}

int main() {
    simulate();
    return 0;
}