cpp
#include <iostream>
#include <vector>

std::vector<std::vector<double>> update_state(const std::vector<std::vector<double>>& grid) {
    std::vector<std::vector<double>> new_grid(grid.size(), std::vector<double>(grid[0].size(), 0.0));
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            double neighbors = 0.0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = neighbors / 9.0;
        }
    }
    return new_grid;
}

std::vector<std::vector<double>> run_simulation(int steps, int size) {
    std::vector<std::vector<double>> grid(size, std::vector<double>(size, 0.0));
    for (int i = 0; i < size; ++i) {
        grid[i][i] = 1.0;
    }
    for (int _ = 0; _ < steps; ++_) {
        grid = update_state(grid);
    }
    return grid;
}

int main() {
    std::vector<std::vector<double>> result = run_simulation(10, 5);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}